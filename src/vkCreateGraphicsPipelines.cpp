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

constexpr inline D3D12_CULL_MODE VkCullModeToD3D12(VkCullModeFlags cullMode)
{
    switch (cullMode)
    {
    case VK_CULL_MODE_NONE:
        return D3D12_CULL_MODE_NONE;
    case VK_CULL_MODE_FRONT_BIT:
        return D3D12_CULL_MODE_FRONT;
    case VK_CULL_MODE_BACK_BIT:
        return D3D12_CULL_MODE_BACK;
    case VK_CULL_MODE_FRONT_AND_BACK:
        return static_cast<D3D12_CULL_MODE>(D3D12_CULL_MODE_FRONT | D3D12_CULL_MODE_BACK);
    }
    return D3D12_CULL_MODE_NONE;
}

constexpr inline D3D12_COMPARISON_FUNC VkCompareOpToD3D12(VkCompareOp compareOp)
{
    switch (compareOp)
    {
    case VK_COMPARE_OP_NEVER:
        return D3D12_COMPARISON_FUNC_NEVER;
    case VK_COMPARE_OP_LESS:
        return D3D12_COMPARISON_FUNC_LESS;
    case VK_COMPARE_OP_EQUAL:
        return D3D12_COMPARISON_FUNC_EQUAL;
    case VK_COMPARE_OP_LESS_OR_EQUAL:
        return D3D12_COMPARISON_FUNC_LESS_EQUAL;
    case VK_COMPARE_OP_GREATER:
        return D3D12_COMPARISON_FUNC_GREATER;
    case VK_COMPARE_OP_NOT_EQUAL:
        return D3D12_COMPARISON_FUNC_NOT_EQUAL;
    case VK_COMPARE_OP_GREATER_OR_EQUAL:
        return D3D12_COMPARISON_FUNC_GREATER_EQUAL;
    case VK_COMPARE_OP_ALWAYS:
        return D3D12_COMPARISON_FUNC_ALWAYS;
    }
    return D3D12_COMPARISON_FUNC_NEVER;
}

constexpr inline D3D12_STENCIL_OP VkStencilOpToD3D12(VkStencilOp stencilOp)
{
    switch (stencilOp)
    {
    case VK_STENCIL_OP_KEEP:
        return D3D12_STENCIL_OP_KEEP;
    case VK_STENCIL_OP_ZERO:
        return D3D12_STENCIL_OP_ZERO;
    case VK_STENCIL_OP_REPLACE:
        return D3D12_STENCIL_OP_REPLACE;
    case VK_STENCIL_OP_INCREMENT_AND_CLAMP:
        return D3D12_STENCIL_OP_INCR_SAT;
    case VK_STENCIL_OP_DECREMENT_AND_CLAMP:
        return D3D12_STENCIL_OP_DECR_SAT;
    case VK_STENCIL_OP_INVERT:
        return D3D12_STENCIL_OP_INVERT;
    case VK_STENCIL_OP_INCREMENT_AND_WRAP:
        return D3D12_STENCIL_OP_INCR;
    case VK_STENCIL_OP_DECREMENT_AND_WRAP:
        return D3D12_STENCIL_OP_DECR;
    }
    return D3D12_STENCIL_OP_KEEP;
}

VKAPI_ATTR VkResult VKAPI_CALL vkCreateGraphicsPipelines(
    VkDevice                            device,
    VkPipelineCache                     pipelineCache,
    uint32_t                            createInfoCount,
    const VkGraphicsPipelineCreateInfo* pCreateInfos,
    const VkAllocationCallbacks*        pAllocator,
    VkPipeline*                         pPipelines)
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

        D3D12_RASTERIZER_DESC rasterizerState = {};
        rasterizerState.FillMode              = VK_POLYGON_MODE_FILL ? D3D12_FILL_MODE_SOLID : D3D12_FILL_MODE_WIREFRAME;
        rasterizerState.CullMode              = VkCullModeToD3D12(pCreateInfos[i].pRasterizationState->cullMode);
        rasterizerState.FrontCounterClockwise = pCreateInfos[i].pRasterizationState->frontFace == VK_FRONT_FACE_COUNTER_CLOCKWISE ? TRUE : FALSE;
        rasterizerState.DepthBias;
        rasterizerState.DepthBiasClamp       = pCreateInfos[i].pRasterizationState->depthBiasClamp;
        rasterizerState.SlopeScaledDepthBias = pCreateInfos[i].pRasterizationState->depthBiasSlopeFactor;
        rasterizerState.DepthClipEnable      = pCreateInfos[i].pRasterizationState->depthClampEnable ? FALSE : TRUE;
        rasterizerState.MultisampleEnable;
        rasterizerState.AntialiasedLineEnable;
        rasterizerState.ForcedSampleCount;
        rasterizerState.ConservativeRaster;

        D3D12_DEPTH_STENCIL_DESC depthStencilState     = {};
        depthStencilState.DepthEnable                  = pCreateInfos[i].pDepthStencilState->depthTestEnable;
        depthStencilState.DepthWriteMask               = pCreateInfos[i].pDepthStencilState->depthWriteEnable ? D3D12_DEPTH_WRITE_MASK_ALL : D3D12_DEPTH_WRITE_MASK_ZERO;
        depthStencilState.DepthFunc                    = VkCompareOpToD3D12(pCreateInfos[i].pDepthStencilState->depthCompareOp);
        depthStencilState.StencilEnable                = pCreateInfos[i].pDepthStencilState->stencilTestEnable;
        depthStencilState.StencilReadMask              = D3D12_DEFAULT_STENCIL_READ_MASK;
        depthStencilState.StencilWriteMask             = D3D12_DEFAULT_STENCIL_WRITE_MASK;
        depthStencilState.FrontFace.StencilFailOp      = VkStencilOpToD3D12(pCreateInfos[i].pDepthStencilState->front.failOp);
        depthStencilState.FrontFace.StencilDepthFailOp = VkStencilOpToD3D12(pCreateInfos[i].pDepthStencilState->front.depthFailOp);
        depthStencilState.FrontFace.StencilPassOp      = VkStencilOpToD3D12(pCreateInfos[i].pDepthStencilState->front.passOp);
        depthStencilState.FrontFace.StencilFunc        = VkCompareOpToD3D12(pCreateInfos[i].pDepthStencilState->front.compareOp);
        depthStencilState.FrontFace.StencilFailOp      = VkStencilOpToD3D12(pCreateInfos[i].pDepthStencilState->back.failOp);
        depthStencilState.FrontFace.StencilDepthFailOp = VkStencilOpToD3D12(pCreateInfos[i].pDepthStencilState->back.depthFailOp);
        depthStencilState.FrontFace.StencilPassOp      = VkStencilOpToD3D12(pCreateInfos[i].pDepthStencilState->back.passOp);
        depthStencilState.FrontFace.StencilFunc        = VkCompareOpToD3D12(pCreateInfos[i].pDepthStencilState->back.compareOp);

        D3D12_GRAPHICS_PIPELINE_STATE_DESC pipelineDesc = {};
        pipelineDesc.pRootSignature;
        pipelineDesc.StreamOutput;
        pipelineDesc.BlendState;
        pipelineDesc.SampleMask;
        pipelineDesc.RasterizerState   = rasterizerState;
        pipelineDesc.DepthStencilState = depthStencilState;
        pipelineDesc.InputLayout;
        pipelineDesc.IBStripCutValue;
        pipelineDesc.PrimitiveTopologyType;
        pipelineDesc.NumRenderTargets;
        pipelineDesc.RTVFormats[8];
        pipelineDesc.DSVFormat;
        pipelineDesc.SampleDesc.Count   = 1;
        pipelineDesc.SampleDesc.Quality = 0;
        pipelineDesc.NodeMask           = device->GetPhysicalDevice()->GetIndex();
        pipelineDesc.CachedPSO          = pipelineCache->pipelineCache;
        pipelineDesc.Flags              = D3D12_PIPELINE_STATE_FLAG_NONE;

        for (uint32_t j = 0; j < pCreateInfos[i].stageCount; ++j)
        {
            switch (pCreateInfos[i].pStages[j].stage)
            {
            case VK_SHADER_STAGE_VERTEX_BIT:
                pipelineDesc.VS = pCreateInfos[i].pStages[j].module->bytecode;
                break;
            case VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT:
                pipelineDesc.HS = pCreateInfos[i].pStages[j].module->bytecode;
                break;
            case VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT:
                pipelineDesc.DS = pCreateInfos[i].pStages[j].module->bytecode;
                break;
            case VK_SHADER_STAGE_GEOMETRY_BIT:
                pipelineDesc.GS = pCreateInfos[i].pStages[j].module->bytecode;
                break;
            case VK_SHADER_STAGE_FRAGMENT_BIT:
                pipelineDesc.PS = pCreateInfos[i].pStages[j].module->bytecode;
                break;
            default:
                break;
            }
        }

        HRESULT hr = device->Get()->CreateGraphicsPipelineState(&pipelineDesc, IID_PPV_ARGS(&pipeline->pipeline));
        if (FAILED(hr))
        {
            return VkResultFromHRESULT(hr);
        }

        pPipelines[i] = pipeline;
    }
    return VK_SUCCESS;
}
