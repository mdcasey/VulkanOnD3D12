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

VKAPI_ATTR VkResult VKAPI_CALL vkCreateComputePipelines(
    VkDevice                           device,
    VkPipelineCache                    pipelineCache,
    uint32_t                           createInfoCount,
    const VkComputePipelineCreateInfo* pCreateInfos,
    const VkAllocationCallbacks*       pAllocator,
    VkPipeline*                        pPipelines)
{
    for (uint32_t i = 0; i < createInfoCount; ++i)
    {
        VkPipeline pipeline = nullptr;
        if (pAllocator)
        {
            pipeline = static_cast<VkPipeline>(pAllocator->pfnAllocation(nullptr, sizeof(VkPipeline_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_DEVICE));
        }
        else
        {
            pipeline = new VkPipeline_T();
        }

        D3D12_COMPUTE_PIPELINE_STATE_DESC pipelineDesc = {};
        pipelineDesc.pRootSignature                    = nullptr;
        pipelineDesc.CS                                = pCreateInfos[i].stage.module->bytecode;
        pipelineDesc.NodeMask                          = device->physicalDevice->index;
        pipelineDesc.CachedPSO                         = pipelineCache->pipelineCache;
        pipelineDesc.Flags                             = D3D12_PIPELINE_STATE_FLAG_NONE;

        HRESULT hr = device->d3dDevice->CreateComputePipelineState(&pipelineDesc, IID_PPV_ARGS(&pipeline->pipeline));
        if (FAILED(hr))
        {
            return VkResultFromHRESULT(hr);
        }

        pPipelines[i] = pipeline;
    }
    return VK_SUCCESS;
}
