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

VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfacePresentModesKHR(
    VkPhysicalDevice  physicalDevice,
    VkSurfaceKHR      surface,
    uint32_t*         pPresentModeCount,
    VkPresentModeKHR* pPresentModes)
{
    *pPresentModeCount = 3;

    if (pPresentModes)
    {
        pPresentModes[0] = VK_PRESENT_MODE_FIFO_KHR;
        pPresentModes[1] = VK_PRESENT_MODE_FIFO_RELAXED_KHR;
        pPresentModes[2] = VK_PRESENT_MODE_MAILBOX_KHR;
    }

    return VK_SUCCESS;
}
