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

VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDevices(
    VkInstance        instance,
    uint32_t*         pPhysicalDeviceCount,
    VkPhysicalDevice* pPhysicalDevices)
{
    uint32_t              curAdapter  = 0;
    uint32_t              numAdapters = 0;
    ComPtr<IDXGIAdapter1> adapter;
    while (instance->dxgiFactory->EnumAdapters1(curAdapter, &adapter) != DXGI_ERROR_NOT_FOUND)
    {
        DXGI_ADAPTER_DESC1 desc = {};
        adapter->GetDesc1(&desc);
        if (desc.Flags == DXGI_ADAPTER_FLAG_NONE)
        {
            if (pPhysicalDevices)
            {
                VkPhysicalDevice physicalDevice = new VkPhysicalDevice_T();

                physicalDevice->adapter = adapter;

                DXGI_ADAPTER_DESC1 adapterDesc;
                HRESULT            hr = physicalDevice->adapter->GetDesc1(&adapterDesc);
                if (FAILED(hr))
                {
                    return VkResultFromHRESULT(hr);
                }

                physicalDevice->instance    = instance;
                physicalDevice->adapterDesc = adapterDesc;
                physicalDevice->index       = curAdapter;

                pPhysicalDevices[curAdapter] = physicalDevice;
            }
            ++numAdapters;
        }
        ++curAdapter;
    }

    *pPhysicalDeviceCount = numAdapters;

    return VK_SUCCESS;
}
