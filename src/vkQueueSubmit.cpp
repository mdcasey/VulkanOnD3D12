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

VKAPI_ATTR VkResult VKAPI_CALL vkQueueSubmit(
    VkQueue             queue,
    uint32_t            submitCount,
    const VkSubmitInfo* pSubmits,
    VkFence             fence)
{
    for (uint32_t i = 0; i < submitCount; ++i)
    {
        if (pSubmits[i].waitSemaphoreCount > 0)
        {
            std::vector<HANDLE> waitSemaphoreHandles(pSubmits[i].waitSemaphoreCount);
            for (uint32_t j = 0; j < pSubmits[i].waitSemaphoreCount; ++j)
            {
                waitSemaphoreHandles[j] = CreateEvent(nullptr, FALSE, FALSE, nullptr);
                pSubmits[i].pWaitSemaphores[j]->fence->SetEventOnCompletion(1, waitSemaphoreHandles[j]);
            }
            WaitForMultipleObjects(pSubmits[i].waitSemaphoreCount, waitSemaphoreHandles.data(), TRUE, INFINITE);
        }

        std::vector<ID3D12CommandList*> commandLists;
        for (uint32_t j = 0; j < pSubmits[i].commandBufferCount; ++j)
        {
            commandLists.push_back(pSubmits[i].pCommandBuffers[j]->commandList.Get());
        }

        queue->commandQueue->ExecuteCommandLists(static_cast<UINT>(commandLists.size()), commandLists.data());

        if (pSubmits[i].signalSemaphoreCount > 0)
        {
            for (uint32_t j = 0; j < pSubmits[i].signalSemaphoreCount; ++j)
            {
                queue->commandQueue->Signal(pSubmits[i].pSignalSemaphores[j]->fence.Get(), 1);
            }
        }

        if (fence)
        {
            HRESULT hr = queue->commandQueue->Signal(fence->fence.Get(), 1);
            if (FAILED(hr))
            {
                return VkResultFromHRESULT(hr);
            }
        }
    }

    return VK_SUCCESS;
}
