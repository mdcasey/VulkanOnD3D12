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

VKAPI_ATTR VkResult VKAPI_CALL vkBeginCommandBuffer(
    VkCommandBuffer                 commandBuffer,
    const VkCommandBufferBeginInfo* pBeginInfo)
{
    HRESULT hr = static_cast<ID3D12GraphicsCommandList*>(commandBuffer->commandList.Get())->Close();
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    hr = static_cast<ID3D12GraphicsCommandList*>(commandBuffer->commandList.Get())->Reset(commandBuffer->commandAllocator, nullptr);
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    return VK_SUCCESS;
}
