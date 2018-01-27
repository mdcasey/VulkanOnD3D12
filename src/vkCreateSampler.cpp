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

VKAPI_ATTR VkResult VKAPI_CALL vkCreateSampler(
    VkDevice                     device,
    const VkSamplerCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkSampler*                   pSampler)
{
    VkSampler sampler = nullptr;
    if (pAllocator)
    {
        sampler = static_cast<VkSampler>(pAllocator->pfnAllocation(nullptr, sizeof(VkSampler_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_DEVICE));
    }
    else
    {
        sampler = new VkSampler_T();
    }

    *pSampler = sampler;

    return VK_SUCCESS;
}
