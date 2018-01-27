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

VKAPI_ATTR void VKAPI_CALL vkCmdSetScissor(
    VkCommandBuffer commandBuffer,
    uint32_t        firstScissor,
    uint32_t        scissorCount,
    const VkRect2D* pScissors)
{
    std::vector<D3D12_RECT> rects(scissorCount - firstScissor);
    for (uint32_t i = firstScissor; i < scissorCount; ++i)
    {
        rects[i] = CD3DX12_RECT(pScissors[i].offset.x, pScissors[i].offset.y, pScissors[i].offset.x + pScissors[i].extent.width, pScissors[i].offset.y + pScissors[i].extent.height);
    }

    static_cast<ID3D12GraphicsCommandList*>(commandBuffer->Get())->RSSetScissorRects(scissorCount - firstScissor, rects.data());
}
