// Copyright 2017 Chabloom LC
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

VKAPI_ATTR VkResult VKAPI_CALL vkCreateSemaphore(
    VkDevice                     device,
    const VkSemaphoreCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkSemaphore*                 pSemaphore)
{
    VkSemaphore semaphore = nullptr;
    if (pAllocator)
    {
        semaphore = static_cast<VkSemaphore>(pAllocator->pfnAllocation(nullptr, sizeof(VkSemaphore_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_DEVICE));
    }
    else
    {
        semaphore = new VkSemaphore_T();
    }

    HRESULT hr = device->d3dDevice->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&semaphore->d3dFence));
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    *pSemaphore = semaphore;

    return VK_SUCCESS;
}
