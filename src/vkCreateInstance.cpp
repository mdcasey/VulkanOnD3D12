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

VKAPI_ATTR VkResult VKAPI_CALL vkCreateInstance(
    const VkInstanceCreateInfo*  pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkInstance*                  pInstance)
{
    VkInstance instance = nullptr;
    if (pAllocator)
    {
        instance = static_cast<VkInstance>(pAllocator->pfnAllocation(nullptr, sizeof(VkInstance_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE));
    }
    else
    {
        instance = new VkInstance_T();
    }

    instance->applicationInfo = *pCreateInfo->pApplicationInfo;
    for (uint32_t i = 0; i < pCreateInfo->enabledLayerCount; ++i)
    {
        instance->enabledLayerNames.push_back(pCreateInfo->ppEnabledLayerNames[i]);
    }
    for (uint32_t i = 0; i < pCreateInfo->enabledExtensionCount; ++i)
    {
        instance->enabledExtensionNames.push_back(pCreateInfo->ppEnabledExtensionNames[i]);
    }

    HRESULT hr = CreateDXGIFactory2(0, IID_PPV_ARGS(&instance->dxgiFactory));
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    *pInstance = instance;

    return VK_SUCCESS;
}
