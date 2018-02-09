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
#include "spirv_hlsl.hpp"

using namespace spv;
using namespace spirv_cross;

VKAPI_ATTR VkResult VKAPI_CALL vkCreateShaderModule(
    VkDevice                        device,
    const VkShaderModuleCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*    pAllocator,
    VkShaderModule*                 pShaderModule)
{
    VkShaderModule shaderModule = nullptr;
    if (pAllocator)
    {
        shaderModule = static_cast<VkShaderModule>(pAllocator->pfnAllocation(nullptr, sizeof(VkShaderModule_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_DEVICE));
    }
    else
    {
        shaderModule = new VkShaderModule_T();
    }

    bool isSpirv = false;
    if (pCreateInfo->codeSize >= 2)
    {
        switch (pCreateInfo->pCode[1])
        {
        case 0x10000: // SPIR-V 1.0
        case 0x10100: // SPIR-V 1.1
        case 0x10200: // SPIR-V 1.2
            isSpirv = true;
            break;
        default:
            break;
        }
    }

    if (isSpirv)
    {
        CompilerHLSL compiler(pCreateInfo->pCode, pCreateInfo->codeSize);

        auto options = compiler.get_options();

        options.shader_model = 50;

        compiler.set_options(options);

        auto shaderSource = compiler.compile();

        std::string hlslTarget;
        switch (compiler.get_execution_model())
        {
        case ExecutionModelVertex:
            hlslTarget = "vs_5_0";
            break;
        case ExecutionModelTessellationControl:
            hlslTarget = "hs_5_0";
            break;
        case ExecutionModelTessellationEvaluation:
            hlslTarget = "ds_5_0";
            break;
        case ExecutionModelGeometry:
            hlslTarget = "gs_5_0";
            break;
        case ExecutionModelFragment:
            hlslTarget = "ps_5_0";
            break;
        case ExecutionModelGLCompute:
            hlslTarget = "cs_5_0";
            break;
        case ExecutionModelKernel:
            hlslTarget = "cs_5_0";
            break;
        default:
            return VK_ERROR_INCOMPATIBLE_DRIVER;
        }

        ComPtr<ID3DBlob> shaderBlob;
        HRESULT          hr = D3DCompile(
            shaderSource.data(),
            shaderSource.size(),
            nullptr,
            nullptr,
            nullptr,
            "main",
            hlslTarget.c_str(),
            D3DCOMPILE_OPTIMIZATION_LEVEL3,
            0,
            shaderBlob.GetAddressOf(),
            nullptr);
        if (FAILED(hr))
        {
            return VkResultFromHRESULT(hr);
        }

        shaderModule->bytecode = CD3DX12_SHADER_BYTECODE(shaderBlob.Get());
    }
    else
    {
        shaderModule->bytecode = CD3DX12_SHADER_BYTECODE(pCreateInfo->pCode, pCreateInfo->codeSize);
    }

    *pShaderModule = shaderModule;

    return VK_SUCCESS;
}
