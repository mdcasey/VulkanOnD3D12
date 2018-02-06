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

#include <algorithm>

VKAPI_ATTR VkResult VKAPI_CALL vkMapMemory(
    VkDevice         device,
    VkDeviceMemory   memory,
    VkDeviceSize     offset,
    VkDeviceSize     size,
    VkMemoryMapFlags flags,
    void**           ppData)
{
    VkDeviceSize creationSize = size;
    if (size == VK_WHOLE_SIZE)
    {
        creationSize = memory->allocationSize;
    }

    HRESULT hr = device->device->CreateCommittedResource(
        &CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD),
        D3D12_HEAP_FLAG_NONE,
        &CD3DX12_RESOURCE_DESC::Buffer(creationSize),
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(memory->resourceUpload.GetAddressOf()));
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    hr = memory->resourceUpload->Map(0, &CD3DX12_RANGE(offset, offset + creationSize), &memory->data);
    if (FAILED(hr))
    {
        return VkResultFromHRESULT(hr);
    }

    *ppData = memory->data;

    return VK_SUCCESS;
}
