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

VKAPI_ATTR VkResult VKAPI_CALL vkCreateQueryPool(
    VkDevice                     device,
    const VkQueryPoolCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkQueryPool*                 pQueryPool)
{
    VkQueryPool queryPool = nullptr;
    if (pAllocator)
    {
        queryPool = static_cast<VkQueryPool>(pAllocator->pfnAllocation(nullptr, sizeof(VkQueryPool_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_DEVICE));
    }
    else
    {
        queryPool = new VkQueryPool_T();
    }

    D3D12_QUERY_HEAP_DESC queryHeapDesc = {};
    queryHeapDesc.Count                 = pCreateInfo->queryCount;
    queryHeapDesc.NodeMask              = device->physicalDevice->index;

    switch (pCreateInfo->queryType)
    {
    case VK_QUERY_TYPE_OCCLUSION:
        queryHeapDesc.Type = D3D12_QUERY_HEAP_TYPE_OCCLUSION;
    case VK_QUERY_TYPE_PIPELINE_STATISTICS:
        queryHeapDesc.Type = D3D12_QUERY_HEAP_TYPE_PIPELINE_STATISTICS;
    case VK_QUERY_TYPE_TIMESTAMP:
        queryHeapDesc.Type = D3D12_QUERY_HEAP_TYPE_TIMESTAMP;
    default:
        break;
    }

    HRESULT hr = device->device->CreateQueryHeap(&queryHeapDesc, IID_PPV_ARGS(queryPool->queryHeap.GetAddressOf()));
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    *pQueryPool = queryPool;

    return VK_SUCCESS;
}
