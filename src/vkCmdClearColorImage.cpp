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

VKAPI_ATTR void VKAPI_CALL vkCmdClearColorImage(
    VkCommandBuffer                commandBuffer,
    VkImage                        image,
    VkImageLayout                  imageLayout,
    const VkClearColorValue*       pColor,
    uint32_t                       rangeCount,
    const VkImageSubresourceRange* pRanges)
{
    const float color[4] = {pColor->float32[0], pColor->float32[1], pColor->float32[2], pColor->float32[3]};

    static_cast<ID3D12GraphicsCommandList*>(commandBuffer->commandList.Get())->ClearRenderTargetView(CD3DX12_CPU_DESCRIPTOR_HANDLE(image->descriptorHeap->GetCPUDescriptorHandleForHeapStart()), color, 0, nullptr);
}
