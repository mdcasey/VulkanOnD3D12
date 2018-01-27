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

VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    VkPhysicalDevice                                 physicalDevice,
    const VkPhysicalDeviceSparseImageFormatInfo2KHR* pFormatInfo,
    uint32_t*                                        pPropertyCount,
    VkSparseImageFormatProperties2KHR*               pProperties)
{
    VkSparseImageFormatProperties2KHR properties = {};
    properties.sType                             = VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2_KHR;
    properties.pNext                             = nullptr;

    vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, pFormatInfo->format, pFormatInfo->type, pFormatInfo->samples, pFormatInfo->usage, pFormatInfo->tiling, pPropertyCount, &properties.properties);

    *pProperties = properties;
}
