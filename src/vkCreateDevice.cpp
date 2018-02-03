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

VKAPI_ATTR VkResult VKAPI_CALL vkCreateDevice(
    VkPhysicalDevice             physicalDevice,
    const VkDeviceCreateInfo*    pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDevice*                    pDevice)
{
    VkDevice device = nullptr;
    if (pAllocator)
    {
        device = static_cast<VkDevice>(pAllocator->pfnAllocation(nullptr, sizeof(VkDevice_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE));
    }
    else
    {
        device = new VkDevice_T();
    }

    HRESULT hr;
#if !defined(NDEBUG)
    ComPtr<ID3D12Debug> debug;
    hr = D3D12GetDebugInterface(IID_PPV_ARGS(debug.GetAddressOf()));
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    debug->EnableDebugLayer();
#endif // !defined(NDEBUG)

    hr = D3D12CreateDevice(
        physicalDevice->Get(),
        D3D_FEATURE_LEVEL_11_0,
        IID_PPV_ARGS(device->GetAddressOf()));
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    for (uint32_t i = 0; i < pCreateInfo->queueCreateInfoCount; ++i)
    {
        VkQueue queue = nullptr;
        if (pAllocator)
        {
            queue = static_cast<VkQueue>(pAllocator->pfnAllocation(nullptr, sizeof(VkQueue_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_DEVICE));
        }
        else
        {
            queue = new VkQueue_T();
        }

        D3D12_COMMAND_QUEUE_DESC queueDesc = {};
        queueDesc.Type                     = D3D12_COMMAND_LIST_TYPE_DIRECT;
        queueDesc.Priority                 = static_cast<int>(pCreateInfo->pQueueCreateInfos->pQueuePriorities[i]) <= 0 ? D3D12_COMMAND_QUEUE_PRIORITY_NORMAL : D3D12_COMMAND_QUEUE_PRIORITY_HIGH;
        queueDesc.Flags                    = D3D12_COMMAND_QUEUE_FLAG_NONE;
        queueDesc.NodeMask                 = 0;

        hr = device->Get()->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(queue->GetAddressOf()));
        if (FAILED(hr))
        {
            return VkResultFromHRESULT(hr);
        }
        device->queues.push_back(queue);
    }

    device->SetPhysicalDevice(physicalDevice);

    *pDevice = device;

    return VK_SUCCESS;
}
