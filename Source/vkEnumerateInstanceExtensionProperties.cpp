// Copyright 2017 Chabloom LC
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

VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(
    const char*            pLayerName,
    uint32_t*              pPropertyCount,
    VkExtensionProperties* pProperties)
{
    constexpr uint32_t propertyCount = 5;
    // clang-format off
    constexpr VkExtensionProperties properties[propertyCount] =
    {
        {VK_KHR_SURFACE_EXTENSION_NAME, VK_KHR_SURFACE_SPEC_VERSION},
#if WINAPI_FAMILY == WINAPI_FAMILY_PC_APP
        {VK_CHB_UWP_SURFACE_EXTENSION_NAME, VK_CHB_UWP_SURFACE_SPEC_VERSION},
#elif WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP
        {VK_KHR_WIN32_SURFACE_EXTENSION_NAME, VK_KHR_WIN32_SURFACE_SPEC_VERSION},
#endif
        {VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME, VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_SPEC_VERSION},
        {VK_CHB_DXBC_SHADER_EXTENSION_NAME, VK_CHB_DXBC_SHADER_SPEC_VERSION},
        {VK_EXT_DEBUG_REPORT_EXTENSION_NAME, VK_EXT_DEBUG_REPORT_SPEC_VERSION}
    };
    // clang-format on

    *pPropertyCount = propertyCount;

    if (pProperties)
    {
        for (int32_t i = 0; i < propertyCount; ++i)
        {
            pProperties[i] = properties[i];
        }
    }

    return VK_SUCCESS;
}
