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

VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice                  physicalDevice,
    VkPhysicalDeviceMemoryProperties* pMemoryProperties)
{
    VkPhysicalDeviceMemoryProperties memoryProperties = {};
    memoryProperties.memoryTypeCount                  = 3;
    memoryProperties.memoryTypes[0].propertyFlags     = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
    memoryProperties.memoryTypes[0].heapIndex         = 0;
    memoryProperties.memoryTypes[1].propertyFlags     = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
    memoryProperties.memoryTypes[1].heapIndex         = 1;
    memoryProperties.memoryTypes[2].propertyFlags     = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
    memoryProperties.memoryTypes[2].heapIndex         = 2;
    memoryProperties.memoryHeapCount                  = 3;
    memoryProperties.memoryHeaps[0].size              = physicalDevice->GetAdapterDesc().DedicatedVideoMemory;
    memoryProperties.memoryHeaps[0].flags             = VK_MEMORY_HEAP_DEVICE_LOCAL_BIT;
    memoryProperties.memoryHeaps[1].size              = physicalDevice->GetAdapterDesc().DedicatedSystemMemory;
    memoryProperties.memoryHeaps[1].flags             = 0;
    memoryProperties.memoryHeaps[2].size              = physicalDevice->GetAdapterDesc().SharedSystemMemory;
    memoryProperties.memoryHeaps[2].flags             = 0;

    *pMemoryProperties = memoryProperties;
}
