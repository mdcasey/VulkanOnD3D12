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

    CD3DX12_HEAP_DESC heapDesc(pAllocateInfo->allocationSize, D3D12_HEAP_TYPE_DEFAULT);
    heapDesc.Properties.CreationNodeMask = device->physicalDevice->index;
    heapDesc.Properties.VisibleNodeMask  = device->physicalDevice->index;

    // Adapters that only support heap tier 1 must set two flags.
    // https://msdn.microsoft.com/en-us/library/windows/desktop/dn986730(v=vs.85).aspx
    if (device->d3d12Options.ResourceHeapTier == D3D12_RESOURCE_HEAP_TIER_1)
    {
        heapDesc.Flags |= D3D12_HEAP_FLAG_DENY_BUFFERS;
        heapDesc.Flags |= D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES;
    }

    HRESULT hr = device->device->CreateHeap(
        &heapDesc,
        IID_PPV_ARGS(memory->heap.GetAddressOf()));
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    memory->allocationSize = pAllocateInfo->allocationSize;

    *pMemory = memory;

    return VK_SUCCESS;
}
