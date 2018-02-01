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

VKAPI_ATTR void VKAPI_CALL vkGetImageMemoryRequirements(
    VkDevice              device,
    VkImage               image,
    VkMemoryRequirements* pMemoryRequirements)
{
    auto desc = image->resource->GetDesc();
    auto allocationInfo = device->device->GetResourceAllocationInfo(device->physicalDevice->index, 1, &desc);

    VkMemoryRequirements memoryRequirements = {};
    memoryRequirements.size = allocationInfo.SizeInBytes;
    memoryRequirements.alignment = allocationInfo.Alignment;
    memoryRequirements.memoryTypeBits = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;

    *pMemoryRequirements = memoryRequirements;
}
