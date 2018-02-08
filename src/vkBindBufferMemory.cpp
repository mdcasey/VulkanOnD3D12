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

VKAPI_ATTR VkResult VKAPI_CALL vkBindBufferMemory(
    VkDevice       device,
    VkBuffer       buffer,
    VkDeviceMemory memory,
    VkDeviceSize   memoryOffset)
{
    // Adapters that only support heap tier 1 must set two flags.
    // We recreate the heap here since we're using buffers.
    // https://msdn.microsoft.com/en-us/library/windows/desktop/dn986730(v=vs.85).aspx
    if (device->dataOptions.ResourceHeapTier == D3D12_RESOURCE_HEAP_TIER_1)
    {
        D3D12_HEAP_DESC heapDesc = memory->heap->GetDesc();
        heapDesc.Flags           = D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES | D3D12_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES;

        HRESULT hr = device->device->CreateHeap(
            &heapDesc,
            IID_PPV_ARGS(memory->heap.GetAddressOf()));
        if (FAILED(hr))
        {
            return VkResultFromHRESULT(hr);
        }
    }

    HRESULT hr = device->device->CreatePlacedResource(
        memory->heap.Get(),
        memoryOffset,
        &buffer->resourceDesc,
        D3D12_RESOURCE_STATE_COMMON,
        nullptr,
        IID_PPV_ARGS(memory->resource.GetAddressOf()));
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    buffer->memory = memory;

    return VK_SUCCESS;
}
