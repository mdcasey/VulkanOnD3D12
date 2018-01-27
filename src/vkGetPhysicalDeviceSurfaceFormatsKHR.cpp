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

VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceFormatsKHR(
    VkPhysicalDevice    physicalDevice,
    VkSurfaceKHR        surface,
    uint32_t*           pSurfaceFormatCount,
    VkSurfaceFormatKHR* pSurfaceFormats)
{
    constexpr uint32_t surfaceFormatCount = 2;
    // clang-format off
    constexpr VkSurfaceFormatKHR surfaceFormats[surfaceFormatCount] =
    {
        {VK_FORMAT_B8G8R8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR},
        {VK_FORMAT_R8G8B8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR}
    };
    // clang-format on

    *pSurfaceFormatCount = surfaceFormatCount;

    if (pSurfaceFormats)
    {
        for (uint32_t i = 0; i < surfaceFormatCount; ++i)
        {
            pSurfaceFormats[i] = surfaceFormats[i];
        }
    }

    return VK_SUCCESS;
}
