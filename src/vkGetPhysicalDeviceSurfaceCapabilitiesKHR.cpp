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

VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkPhysicalDevice          physicalDevice,
    VkSurfaceKHR              surface,
    VkSurfaceCapabilitiesKHR* pSurfaceCapabilities)
{
    VkSurfaceCapabilitiesKHR surfaceCapabilities = {};
    surfaceCapabilities.minImageCount            = 1;
    surfaceCapabilities.maxImageCount            = 0;
    surfaceCapabilities.minImageExtent.width     = 1;
    surfaceCapabilities.minImageExtent.height    = 1;
    surfaceCapabilities.maxImageArrayLayers      = 1;
    surfaceCapabilities.supportedCompositeAlpha  = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR | VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR | VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR;
    surfaceCapabilities.supportedUsageFlags      = VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT;

#if WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP
    RECT windowRect = {};
    GetWindowRect(surface->hwnd, &windowRect);

    surfaceCapabilities.currentExtent.width   = windowRect.right - windowRect.left;
    surfaceCapabilities.currentExtent.height  = windowRect.bottom - windowRect.top;
    surfaceCapabilities.maxImageExtent.width  = GetSystemMetrics(SM_CXSCREEN);
    surfaceCapabilities.maxImageExtent.height = GetSystemMetrics(SM_CYSCREEN);
    surfaceCapabilities.supportedTransforms   = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
    surfaceCapabilities.currentTransform      = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
#endif

    *pSurfaceCapabilities = surfaceCapabilities;

    return VK_SUCCESS;
}
