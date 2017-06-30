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

#if WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP
VKAPI_ATTR VkResult VKAPI_CALL vkCreateWin32SurfaceKHR(
    VkInstance                         instance,
    const VkWin32SurfaceCreateInfoKHR* pCreateInfo,
    const VkAllocationCallbacks*       pAllocator,
    VkSurfaceKHR*                      pSurface)
{
    VkSurfaceKHR surface = nullptr;
    if (pAllocator)
    {
        surface = static_cast<VkSurfaceKHR>(pAllocator->pfnAllocation(nullptr, sizeof(VkSurfaceKHR_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE));
    }
    else
    {
        surface = new VkSurfaceKHR_T();
    }

    surface->hinstance = pCreateInfo->hinstance;
    surface->hwnd      = pCreateInfo->hwnd;

    *pSurface = surface;

    return VK_SUCCESS;
}
#endif
