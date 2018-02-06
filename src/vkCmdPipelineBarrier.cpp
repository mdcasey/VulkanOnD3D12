// Copyright 2017-2018 Chabloom LC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "_vulkan.h"

inline auto VkAccessFlagsToD3D12(VkAccessFlags accessFlags)
{
    switch (accessFlags)
    {
    case VK_ACCESS_INDIRECT_COMMAND_READ_BIT:
        return D3D12_RESOURCE_STATE_GENERIC_READ;
    case VK_ACCESS_INDEX_READ_BIT:
        return D3D12_RESOURCE_STATE_GENERIC_READ;
    case VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT:
        return D3D12_RESOURCE_STATE_GENERIC_READ;
    case VK_ACCESS_UNIFORM_READ_BIT:
        return D3D12_RESOURCE_STATE_GENERIC_READ;
    case VK_ACCESS_INPUT_ATTACHMENT_READ_BIT:
        return D3D12_RESOURCE_STATE_GENERIC_READ;
    case VK_ACCESS_SHADER_READ_BIT:
        return D3D12_RESOURCE_STATE_GENERIC_READ;
    case VK_ACCESS_SHADER_WRITE_BIT:
        return D3D12_RESOURCE_STATE_COPY_DEST;
    case VK_ACCESS_COLOR_ATTACHMENT_READ_BIT:
        return D3D12_RESOURCE_STATE_GENERIC_READ;
    case VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT:
        return D3D12_RESOURCE_STATE_RENDER_TARGET;
    case VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT:
        return D3D12_RESOURCE_STATE_DEPTH_READ;
    case VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT:
        return D3D12_RESOURCE_STATE_DEPTH_WRITE;
    case VK_ACCESS_TRANSFER_READ_BIT:
        return D3D12_RESOURCE_STATE_COPY_SOURCE;
    case VK_ACCESS_TRANSFER_WRITE_BIT:
        return D3D12_RESOURCE_STATE_COPY_DEST;
    case VK_ACCESS_HOST_READ_BIT:
        return D3D12_RESOURCE_STATE_GENERIC_READ;
    case VK_ACCESS_HOST_WRITE_BIT:
        return D3D12_RESOURCE_STATE_COPY_DEST;
    case VK_ACCESS_MEMORY_READ_BIT:
        return D3D12_RESOURCE_STATE_GENERIC_READ;
    case VK_ACCESS_MEMORY_WRITE_BIT:
        return D3D12_RESOURCE_STATE_COPY_DEST;
    default:
        return D3D12_RESOURCE_STATE_GENERIC_READ;
    }
}

VKAPI_ATTR void VKAPI_CALL vkCmdPipelineBarrier(
    VkCommandBuffer              commandBuffer,
    VkPipelineStageFlags         srcStageMask,
    VkPipelineStageFlags         dstStageMask,
    VkDependencyFlags            dependencyFlags,
    uint32_t                     memoryBarrierCount,
    const VkMemoryBarrier*       pMemoryBarriers,
    uint32_t                     bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier* pBufferMemoryBarriers,
    uint32_t                     imageMemoryBarrierCount,
    const VkImageMemoryBarrier*  pImageMemoryBarriers)
{
    if (bufferMemoryBarrierCount > 0)
    {
        std::vector<D3D12_RESOURCE_BARRIER> bufferMemoryBarriers;
        for (uint32_t i = 0; i < bufferMemoryBarrierCount; ++i)
        {
            bufferMemoryBarriers.push_back(CD3DX12_RESOURCE_BARRIER::Aliasing(
                nullptr,
                pImageMemoryBarriers[i].image->memory->resource.Get()));

            bufferMemoryBarriers.push_back(CD3DX12_RESOURCE_BARRIER::Transition(
                pImageMemoryBarriers[i].image->memory->resource.Get(),
                VkAccessFlagsToD3D12(srcStageMask),
                VkAccessFlagsToD3D12(dstStageMask)));
        }
        static_cast<ID3D12GraphicsCommandList*>(commandBuffer->commandList.Get())->ResourceBarrier(static_cast<UINT>(bufferMemoryBarriers.size()), bufferMemoryBarriers.data());
    }

    if (imageMemoryBarrierCount > 0)
    {
        std::vector<D3D12_RESOURCE_BARRIER> imageMemoryBarriers;
        for (uint32_t i = 0; i < imageMemoryBarrierCount; ++i)
        {
            imageMemoryBarriers.push_back(CD3DX12_RESOURCE_BARRIER::Aliasing(
                nullptr,
                pImageMemoryBarriers[i].image->memory->resource.Get()));

            imageMemoryBarriers.push_back(CD3DX12_RESOURCE_BARRIER::Transition(
                pImageMemoryBarriers[i].image->memory->resource.Get(),
                VkAccessFlagsToD3D12(srcStageMask),
                VkAccessFlagsToD3D12(dstStageMask)));
        }
        static_cast<ID3D12GraphicsCommandList*>(commandBuffer->commandList.Get())->ResourceBarrier(static_cast<UINT>(imageMemoryBarriers.size()), imageMemoryBarriers.data());
    }
}
