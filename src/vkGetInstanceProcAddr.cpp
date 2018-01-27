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

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(
    VkInstance  instance,
    const char* pName)
{
    HMODULE dll = nullptr;
#if WINAPI_FAMILY == WINAPI_FAMILY_PC_APP
    dll = LoadPackagedLibrary(L"VulkanOnD3D12", 0);
#elif WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP
    dll = LoadLibrary(L"VulkanOnD3D12");
#endif
    return reinterpret_cast<PFN_vkVoidFunction>(GetProcAddress(dll, pName));
}
