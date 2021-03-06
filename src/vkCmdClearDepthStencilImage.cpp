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

VKAPI_ATTR void VKAPI_CALL vkCmdClearDepthStencilImage(
    VkCommandBuffer                 commandBuffer,
    VkImage                         image,
    VkImageLayout                   imageLayout,
    const VkClearDepthStencilValue* pDepthStencil,
    uint32_t                        rangeCount,
    const VkImageSubresourceRange*  pRanges)
{
    static_cast<ID3D12GraphicsCommandList*>(commandBuffer->commandList.Get())->ClearDepthStencilView(CD3DX12_CPU_DESCRIPTOR_HANDLE(image->descriptorHeap->GetCPUDescriptorHandleForHeapStart()), D3D12_CLEAR_FLAG_DEPTH | D3D12_CLEAR_FLAG_STENCIL, pDepthStencil->depth, static_cast<uint8_t>(pDepthStencil->stencil), 0, nullptr);
}
