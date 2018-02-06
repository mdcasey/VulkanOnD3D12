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

#pragma once

#include <Windows.h>

#include <d3d12.h>
#include <d3dcompiler.h>
#include <dxgi1_6.h>
#include <wrl.h>

#include "d3dx12.h"
#include "d3dx12Residency.h"

using namespace Microsoft::WRL;

#include <vulkan/vulkan.h>

#include <vector>

inline VkResult VkResultFromHRESULT(HRESULT hr)
{
    switch (hr)
    {
    case 0:
        break;
    default:
        break;
    }
    return VK_ERROR_INCOMPATIBLE_DRIVER;
}

inline DXGI_ALPHA_MODE VkCompositeAlphaFlagBitsKHRToDXGI_ALPHA_MODE(VkCompositeAlphaFlagBitsKHR flags)
{
    switch (flags)
    {
    case VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR:
        break;
    case VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR:
        return DXGI_ALPHA_MODE_PREMULTIPLIED;
    case VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR:
        break;
    case VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR:
        break;
    default:
        break;
    }
    return DXGI_ALPHA_MODE_UNSPECIFIED;
}

struct VkInstance_T
{
    VkApplicationInfo        applicationInfo;
    std::vector<std::string> enabledLayerNames;
    std::vector<std::string> enabledExtensionNames;
    ComPtr<IDXGIFactory5>    dxgiFactory;
};

struct VkPhysicalDevice_T
{
    ComPtr<IDXGIAdapter1> adapter;
    DXGI_ADAPTER_DESC1    adapterDesc;
    D3D12_FEATURE         features;
    uint32_t              index;
    VkInstance            instance;
};

struct VkDevice_T
{
    ComPtr<ID3D12Device>             device;
    std::vector<VkQueue>             queues;
    VkPhysicalDevice                 physicalDevice;
    D3D12_FEATURE_DATA_D3D12_OPTIONS d3d12Options;
};

struct VkQueue_T
{
    ComPtr<ID3D12CommandQueue> commandQueue;
};

struct VkSemaphore_T
{
    ComPtr<ID3D12Fence> fence;
};

struct VkCommandBuffer_T
{
    ComPtr<ID3D12CommandList> commandList;
    ID3D12CommandAllocator*   commandAllocator;
};

struct VkFence_T
{
    ComPtr<ID3D12Fence> fence;
};

struct VkDeviceMemory_T
{
    ComPtr<ID3D12Heap>     heap;
    ComPtr<ID3D12Resource> resource;
    ComPtr<ID3D12Resource> resourceUpload;
    VkDeviceSize           allocationSize;
    void*                  data;
};

struct VkBuffer_T
{
    VkDeviceMemory               memory;
    D3D12_RESOURCE_DESC          resourceDesc;
    ComPtr<ID3D12DescriptorHeap> descriptorHeap;
};

struct VkImage_T
{
    VkDeviceMemory               memory;
    D3D12_RESOURCE_DESC          resourceDesc;
    ComPtr<ID3D12DescriptorHeap> descriptorHeap;
};

struct VkEvent_T
{
    HANDLE event;
};

struct VkQueryPool_T
{
};

struct VkBufferView_T
{
};

struct VkImageView_T
{
};

struct VkShaderModule_T
{
    D3D12_SHADER_BYTECODE bytecode;
};

struct VkPipelineCache_T
{
    D3D12_CACHED_PIPELINE_STATE pipelineCache;
};

struct VkPipelineLayout_T
{
};

struct VkRenderPass_T
{
};

struct VkPipeline_T
{
    ComPtr<ID3D12PipelineState> pipeline;
};

struct VkDescriptorSetLayout_T
{
};

struct VkSampler_T
{
};

struct VkDescriptorPool_T
{
};

struct VkDescriptorSet_T
{
};

struct VkFramebuffer_T
{
};

struct VkCommandPool_T
{
    ComPtr<ID3D12CommandAllocator> commandAllocator;
};

struct VkSurfaceKHR_T
{
#if WINAPI_FAMILY == WINAPI_FAMILY_PC_APP
    IUnknown* window;
#elif WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP
    HINSTANCE hinstance;
    HWND      hwnd;
#endif
};

struct VkSwapchainKHR_T
{
    ComPtr<IDXGISwapChain1> swapChain;
    std::vector<VkImage>    images;
};

struct VkDebugReportCallbackEXT_T
{
};

constexpr inline DXGI_FORMAT VkFormatToD3D12(VkFormat format)
{
    switch (format)
    {
    case VK_FORMAT_UNDEFINED:
        return DXGI_FORMAT_UNKNOWN;
    case VK_FORMAT_R4G4_UNORM_PACK8:
        break;
    case VK_FORMAT_R4G4B4A4_UNORM_PACK16:
        break;
    case VK_FORMAT_B4G4R4A4_UNORM_PACK16:
        break;
    case VK_FORMAT_R5G6B5_UNORM_PACK16:
        break;
    case VK_FORMAT_B5G6R5_UNORM_PACK16:
        break;
    case VK_FORMAT_R5G5B5A1_UNORM_PACK16:
        break;
    case VK_FORMAT_B5G5R5A1_UNORM_PACK16:
        break;
    case VK_FORMAT_A1R5G5B5_UNORM_PACK16:
        break;
    case VK_FORMAT_R8_UNORM:
        break;
    case VK_FORMAT_R8_SNORM:
        break;
    case VK_FORMAT_R8_USCALED:
        break;
    case VK_FORMAT_R8_SSCALED:
        break;
    case VK_FORMAT_R8_UINT:
        break;
    case VK_FORMAT_R8_SINT:
        break;
    case VK_FORMAT_R8_SRGB:
        break;
    case VK_FORMAT_R8G8_UNORM:
        break;
    case VK_FORMAT_R8G8_SNORM:
        break;
    case VK_FORMAT_R8G8_USCALED:
        break;
    case VK_FORMAT_R8G8_SSCALED:
        break;
    case VK_FORMAT_R8G8_UINT:
        break;
    case VK_FORMAT_R8G8_SINT:
        break;
    case VK_FORMAT_R8G8_SRGB:
        break;
    case VK_FORMAT_R8G8B8_UNORM:
        break;
    case VK_FORMAT_R8G8B8_SNORM:
        break;
    case VK_FORMAT_R8G8B8_USCALED:
        break;
    case VK_FORMAT_R8G8B8_SSCALED:
        break;
    case VK_FORMAT_R8G8B8_UINT:
        break;
    case VK_FORMAT_R8G8B8_SINT:
        break;
    case VK_FORMAT_R8G8B8_SRGB:
        break;
    case VK_FORMAT_B8G8R8_UNORM:
        break;
    case VK_FORMAT_B8G8R8_SNORM:
        break;
    case VK_FORMAT_B8G8R8_USCALED:
        break;
    case VK_FORMAT_B8G8R8_SSCALED:
        break;
    case VK_FORMAT_B8G8R8_UINT:
        break;
    case VK_FORMAT_B8G8R8_SINT:
        break;
    case VK_FORMAT_B8G8R8_SRGB:
        break;
    case VK_FORMAT_R8G8B8A8_UNORM:
        return DXGI_FORMAT_R8G8B8A8_UNORM;
        break;
    case VK_FORMAT_R8G8B8A8_SNORM:
        return DXGI_FORMAT_R8G8B8A8_SNORM;
        break;
    case VK_FORMAT_R8G8B8A8_USCALED:
        break;
    case VK_FORMAT_R8G8B8A8_SSCALED:
        break;
    case VK_FORMAT_R8G8B8A8_UINT:
        return DXGI_FORMAT_R8G8B8A8_UINT;
        break;
    case VK_FORMAT_R8G8B8A8_SINT:
        return DXGI_FORMAT_R8G8B8A8_SINT;
        break;
    case VK_FORMAT_R8G8B8A8_SRGB:
        return DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
        break;
    case VK_FORMAT_B8G8R8A8_UNORM:
        return DXGI_FORMAT_B8G8R8A8_UNORM;
        break;
    case VK_FORMAT_B8G8R8A8_SNORM:
        break;
    case VK_FORMAT_B8G8R8A8_USCALED:
        break;
    case VK_FORMAT_B8G8R8A8_SSCALED:
        break;
    case VK_FORMAT_B8G8R8A8_UINT:
        break;
    case VK_FORMAT_B8G8R8A8_SINT:
        break;
    case VK_FORMAT_B8G8R8A8_SRGB:
        return DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;
        break;
    case VK_FORMAT_A8B8G8R8_UNORM_PACK32:
        break;
    case VK_FORMAT_A8B8G8R8_SNORM_PACK32:
        break;
    case VK_FORMAT_A8B8G8R8_USCALED_PACK32:
        break;
    case VK_FORMAT_A8B8G8R8_SSCALED_PACK32:
        break;
    case VK_FORMAT_A8B8G8R8_UINT_PACK32:
        break;
    case VK_FORMAT_A8B8G8R8_SINT_PACK32:
        break;
    case VK_FORMAT_A8B8G8R8_SRGB_PACK32:
        break;
    case VK_FORMAT_A2R10G10B10_UNORM_PACK32:
        break;
    case VK_FORMAT_A2R10G10B10_SNORM_PACK32:
        break;
    case VK_FORMAT_A2R10G10B10_USCALED_PACK32:
        break;
    case VK_FORMAT_A2R10G10B10_SSCALED_PACK32:
        break;
    case VK_FORMAT_A2R10G10B10_UINT_PACK32:
        break;
    case VK_FORMAT_A2R10G10B10_SINT_PACK32:
        break;
    case VK_FORMAT_A2B10G10R10_UNORM_PACK32:
        break;
    case VK_FORMAT_A2B10G10R10_SNORM_PACK32:
        break;
    case VK_FORMAT_A2B10G10R10_USCALED_PACK32:
        break;
    case VK_FORMAT_A2B10G10R10_SSCALED_PACK32:
        break;
    case VK_FORMAT_A2B10G10R10_UINT_PACK32:
        break;
    case VK_FORMAT_A2B10G10R10_SINT_PACK32:
        break;
    case VK_FORMAT_R16_UNORM:
        return DXGI_FORMAT_R16_UNORM;
    case VK_FORMAT_R16_SNORM:
        return DXGI_FORMAT_R16_SNORM;
    case VK_FORMAT_R16_USCALED:
        break;
    case VK_FORMAT_R16_SSCALED:
        break;
    case VK_FORMAT_R16_UINT:
        return DXGI_FORMAT_R16_UINT;
    case VK_FORMAT_R16_SINT:
        return DXGI_FORMAT_R16_SINT;
    case VK_FORMAT_R16_SFLOAT:
        return DXGI_FORMAT_R16_FLOAT;
    case VK_FORMAT_R16G16_UNORM:
        return DXGI_FORMAT_R16G16_UNORM;
    case VK_FORMAT_R16G16_SNORM:
        return DXGI_FORMAT_R16G16_SNORM;
    case VK_FORMAT_R16G16_USCALED:
        break;
    case VK_FORMAT_R16G16_SSCALED:
        break;
    case VK_FORMAT_R16G16_UINT:
        return DXGI_FORMAT_R16G16_UINT;
    case VK_FORMAT_R16G16_SINT:
        return DXGI_FORMAT_R16G16_SINT;
    case VK_FORMAT_R16G16_SFLOAT:
        break;
    case VK_FORMAT_R16G16B16_UNORM:
        break;
    case VK_FORMAT_R16G16B16_SNORM:
        break;
    case VK_FORMAT_R16G16B16_USCALED:
        break;
    case VK_FORMAT_R16G16B16_SSCALED:
        break;
    case VK_FORMAT_R16G16B16_UINT:
        break;
    case VK_FORMAT_R16G16B16_SINT:
        break;
    case VK_FORMAT_R16G16B16_SFLOAT:
        break;
    case VK_FORMAT_R16G16B16A16_UNORM:
        break;
    case VK_FORMAT_R16G16B16A16_SNORM:
        break;
    case VK_FORMAT_R16G16B16A16_USCALED:
        break;
    case VK_FORMAT_R16G16B16A16_SSCALED:
        break;
    case VK_FORMAT_R16G16B16A16_UINT:
        break;
    case VK_FORMAT_R16G16B16A16_SINT:
        break;
    case VK_FORMAT_R16G16B16A16_SFLOAT:
        break;
    case VK_FORMAT_R32_UINT:
        return DXGI_FORMAT_R32_UINT;
    case VK_FORMAT_R32_SINT:
        return DXGI_FORMAT_R32_SINT;
    case VK_FORMAT_R32_SFLOAT:
        return DXGI_FORMAT_R32_FLOAT;
    case VK_FORMAT_R32G32_UINT:
        return DXGI_FORMAT_R32G32_UINT;
    case VK_FORMAT_R32G32_SINT:
        return DXGI_FORMAT_R32G32B32A32_SINT;
    case VK_FORMAT_R32G32_SFLOAT:
        return DXGI_FORMAT_R32G32_FLOAT;
    case VK_FORMAT_R32G32B32_UINT:
        return DXGI_FORMAT_R32G32B32_UINT;
    case VK_FORMAT_R32G32B32_SINT:
        return DXGI_FORMAT_R32G32B32_SINT;
    case VK_FORMAT_R32G32B32_SFLOAT:
        return DXGI_FORMAT_R32G32B32_FLOAT;
    case VK_FORMAT_R32G32B32A32_UINT:
        return DXGI_FORMAT_R32G32B32A32_UINT;
    case VK_FORMAT_R32G32B32A32_SINT:
        return DXGI_FORMAT_R32G32B32A32_SINT;
    case VK_FORMAT_R32G32B32A32_SFLOAT:
        return DXGI_FORMAT_R32G32B32A32_FLOAT;
    case VK_FORMAT_R64_UINT:
        break;
    case VK_FORMAT_R64_SINT:
        break;
    case VK_FORMAT_R64_SFLOAT:
        break;
    case VK_FORMAT_R64G64_UINT:
        break;
    case VK_FORMAT_R64G64_SINT:
        break;
    case VK_FORMAT_R64G64_SFLOAT:
        break;
    case VK_FORMAT_R64G64B64_UINT:
        break;
    case VK_FORMAT_R64G64B64_SINT:
        break;
    case VK_FORMAT_R64G64B64_SFLOAT:
        break;
    case VK_FORMAT_R64G64B64A64_UINT:
        break;
    case VK_FORMAT_R64G64B64A64_SINT:
        break;
    case VK_FORMAT_R64G64B64A64_SFLOAT:
        break;
    case VK_FORMAT_B10G11R11_UFLOAT_PACK32:
        break;
    case VK_FORMAT_E5B9G9R9_UFLOAT_PACK32:
        break;
    case VK_FORMAT_D16_UNORM:
        return DXGI_FORMAT_D16_UNORM;
    case VK_FORMAT_X8_D24_UNORM_PACK32:
        break;
    case VK_FORMAT_D32_SFLOAT:
        return DXGI_FORMAT_D32_FLOAT;
    case VK_FORMAT_S8_UINT:
        break;
    case VK_FORMAT_D16_UNORM_S8_UINT:
        break;
    case VK_FORMAT_D24_UNORM_S8_UINT:
        return DXGI_FORMAT_D24_UNORM_S8_UINT;
    case VK_FORMAT_D32_SFLOAT_S8_UINT:
        return DXGI_FORMAT_D32_FLOAT_S8X24_UINT;
    case VK_FORMAT_BC1_RGB_UNORM_BLOCK:
        return DXGI_FORMAT_BC1_UNORM;
    case VK_FORMAT_BC1_RGB_SRGB_BLOCK:
        return DXGI_FORMAT_BC1_UNORM_SRGB;
    case VK_FORMAT_BC1_RGBA_UNORM_BLOCK:
        return DXGI_FORMAT_BC1_UNORM;
    case VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
        return DXGI_FORMAT_BC1_UNORM_SRGB;
    case VK_FORMAT_BC2_UNORM_BLOCK:
        return DXGI_FORMAT_BC2_UNORM;
    case VK_FORMAT_BC2_SRGB_BLOCK:
        return DXGI_FORMAT_BC2_UNORM_SRGB;
    case VK_FORMAT_BC3_UNORM_BLOCK:
        return DXGI_FORMAT_BC3_UNORM;
    case VK_FORMAT_BC3_SRGB_BLOCK:
        return DXGI_FORMAT_BC3_UNORM_SRGB;
    case VK_FORMAT_BC4_UNORM_BLOCK:
        return DXGI_FORMAT_BC4_UNORM;
    case VK_FORMAT_BC4_SNORM_BLOCK:
        return DXGI_FORMAT_BC4_SNORM;
    case VK_FORMAT_BC5_UNORM_BLOCK:
        return DXGI_FORMAT_BC5_UNORM;
    case VK_FORMAT_BC5_SNORM_BLOCK:
        return DXGI_FORMAT_BC5_SNORM;
    case VK_FORMAT_BC6H_UFLOAT_BLOCK:
        return DXGI_FORMAT_BC6H_UF16;
    case VK_FORMAT_BC6H_SFLOAT_BLOCK:
        return DXGI_FORMAT_BC6H_SF16;
    case VK_FORMAT_BC7_UNORM_BLOCK:
        return DXGI_FORMAT_BC7_UNORM;
    case VK_FORMAT_BC7_SRGB_BLOCK:
        return DXGI_FORMAT_BC7_UNORM_SRGB;
    default:
        break;
    }
    return DXGI_FORMAT_UNKNOWN;
}
