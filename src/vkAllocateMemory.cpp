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

VKAPI_ATTR VkResult VKAPI_CALL vkAllocateMemory(
    VkDevice                     device,
    const VkMemoryAllocateInfo*  pAllocateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDeviceMemory*              pMemory)
{
    VkDeviceMemory memory = nullptr;
    if (pAllocator)
    {
        memory = static_cast<VkDeviceMemory>(pAllocator->pfnAllocation(nullptr, sizeof(VkDeviceMemory_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_DEVICE));
    }
    else
    {
        memory = new VkDeviceMemory_T();
    }

    D3D12_HEAP_DESC heapDesc = {};
    heapDesc.SizeInBytes = pAllocateInfo->allocationSize;
    heapDesc.Properties.Type = D3D12_HEAP_TYPE_DEFAULT;
    heapDesc.Properties.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    heapDesc.Properties.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
    heapDesc.Properties.CreationNodeMask = device->physicalDevice->index;
    heapDesc.Properties.VisibleNodeMask = device->physicalDevice->index;
    heapDesc.Alignment = D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT;
    heapDesc.Flags = D3D12_HEAP_FLAG_DENY_BUFFERS | D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES;

    ComPtr<ID3D12Heap> heap;
    HRESULT hr = device->device->CreateHeap(&heapDesc, IID_PPV_ARGS(heap.GetAddressOf()));
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    memory->heap = heap;

    *pMemory = memory;

    return VK_SUCCESS;
}
