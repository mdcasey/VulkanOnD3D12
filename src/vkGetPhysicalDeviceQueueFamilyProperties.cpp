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

VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice         physicalDevice,
    uint32_t*                pQueueFamilyPropertyCount,
    VkQueueFamilyProperties* pQueueFamilyProperties)
{
    if (pQueueFamilyProperties)
    {
        VkQueueFamilyProperties queueFamilyProperties     = {};
        queueFamilyProperties.queueFlags                  = VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT;
        queueFamilyProperties.queueCount                  = 1;
        queueFamilyProperties.timestampValidBits          = 0;
        queueFamilyProperties.minImageTransferGranularity = VkExtent3D{1, 1, 1};

        VkQueueFamilyProperties copyQueueFamilyProperties     = {};
        copyQueueFamilyProperties.queueFlags                  = VK_QUEUE_TRANSFER_BIT;
        copyQueueFamilyProperties.queueCount                  = 1;
        copyQueueFamilyProperties.timestampValidBits          = 0;
        copyQueueFamilyProperties.minImageTransferGranularity = VkExtent3D{1, 1, 1};

        pQueueFamilyProperties[0] = queueFamilyProperties;
        pQueueFamilyProperties[1] = copyQueueFamilyProperties;
    }

    *pQueueFamilyPropertyCount = 2;
}
