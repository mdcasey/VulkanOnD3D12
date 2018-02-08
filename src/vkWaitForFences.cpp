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

VKAPI_ATTR VkResult VKAPI_CALL vkWaitForFences(
    VkDevice       device,
    uint32_t       fenceCount,
    const VkFence* pFences,
    VkBool32       waitAll,
    uint64_t       timeout)
{
    for (uint32_t i = 0; i < fenceCount; ++i)
    {
        if (pFences[i]->fence->GetCompletedValue() == 0)
        {
            auto fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);

            HRESULT hr = pFences[i]->fence->SetEventOnCompletion(pFences[i]->fenceValue, fenceEvent);
            if (FAILED(hr))
            {
                return VkResultFromHRESULT(hr);
            }

            WaitForSingleObjectEx(fenceEvent, INFINITE, FALSE);
        }
    }
    return VK_SUCCESS;
}
