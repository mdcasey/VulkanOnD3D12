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

inline DXGI_FORMAT VkFormatToDXGI_FORMAT(VkFormat format)
{
    switch (format)
    {
    case VK_FORMAT_UNDEFINED:
        break;
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
        break;
    case VK_FORMAT_R8G8B8A8_SNORM:
        break;
    case VK_FORMAT_R8G8B8A8_USCALED:
        break;
    case VK_FORMAT_R8G8B8A8_SSCALED:
        break;
    case VK_FORMAT_R8G8B8A8_UINT:
        break;
    case VK_FORMAT_R8G8B8A8_SINT:
        break;
    case VK_FORMAT_R8G8B8A8_SRGB:
        break;
    case VK_FORMAT_B8G8R8A8_UNORM:
        return DXGI_FORMAT_B8G8R8A8_UNORM;
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
        break;
    case VK_FORMAT_R16_SNORM:
        break;
    case VK_FORMAT_R16_USCALED:
        break;
    case VK_FORMAT_R16_SSCALED:
        break;
    case VK_FORMAT_R16_UINT:
        break;
    case VK_FORMAT_R16_SINT:
        break;
    case VK_FORMAT_R16_SFLOAT:
        break;
    case VK_FORMAT_R16G16_UNORM:
        break;
    case VK_FORMAT_R16G16_SNORM:
        break;
    case VK_FORMAT_R16G16_USCALED:
        break;
    case VK_FORMAT_R16G16_SSCALED:
        break;
    case VK_FORMAT_R16G16_UINT:
        break;
    case VK_FORMAT_R16G16_SINT:
        break;
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
        break;
    case VK_FORMAT_R32_SINT:
        break;
    case VK_FORMAT_R32_SFLOAT:
        break;
    case VK_FORMAT_R32G32_UINT:
        break;
    case VK_FORMAT_R32G32_SINT:
        break;
    case VK_FORMAT_R32G32_SFLOAT:
        break;
    case VK_FORMAT_R32G32B32_UINT:
        break;
    case VK_FORMAT_R32G32B32_SINT:
        break;
    case VK_FORMAT_R32G32B32_SFLOAT:
        break;
    case VK_FORMAT_R32G32B32A32_UINT:
        break;
    case VK_FORMAT_R32G32B32A32_SINT:
        break;
    case VK_FORMAT_R32G32B32A32_SFLOAT:
        break;
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
        break;
    case VK_FORMAT_X8_D24_UNORM_PACK32:
        break;
    case VK_FORMAT_D32_SFLOAT:
        break;
    case VK_FORMAT_S8_UINT:
        break;
    case VK_FORMAT_D16_UNORM_S8_UINT:
        break;
    case VK_FORMAT_D24_UNORM_S8_UINT:
        break;
    case VK_FORMAT_D32_SFLOAT_S8_UINT:
        break;
    case VK_FORMAT_BC1_RGB_UNORM_BLOCK:
        break;
    case VK_FORMAT_BC1_RGB_SRGB_BLOCK:
        break;
    case VK_FORMAT_BC1_RGBA_UNORM_BLOCK:
        break;
    case VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
        break;
    case VK_FORMAT_BC2_UNORM_BLOCK:
        break;
    case VK_FORMAT_BC2_SRGB_BLOCK:
        break;
    case VK_FORMAT_BC3_UNORM_BLOCK:
        break;
    case VK_FORMAT_BC3_SRGB_BLOCK:
        break;
    case VK_FORMAT_BC4_UNORM_BLOCK:
        break;
    case VK_FORMAT_BC4_SNORM_BLOCK:
        break;
    case VK_FORMAT_BC5_UNORM_BLOCK:
        break;
    case VK_FORMAT_BC5_SNORM_BLOCK:
        break;
    case VK_FORMAT_BC6H_UFLOAT_BLOCK:
        break;
    case VK_FORMAT_BC6H_SFLOAT_BLOCK:
        break;
    case VK_FORMAT_BC7_UNORM_BLOCK:
        break;
    case VK_FORMAT_BC7_SRGB_BLOCK:
        break;
    case VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK:
        break;
    case VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK:
        break;
    case VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK:
        break;
    case VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK:
        break;
    case VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK:
        break;
    case VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK:
        break;
    case VK_FORMAT_EAC_R11_UNORM_BLOCK:
        break;
    case VK_FORMAT_EAC_R11_SNORM_BLOCK:
        break;
    case VK_FORMAT_EAC_R11G11_UNORM_BLOCK:
        break;
    case VK_FORMAT_EAC_R11G11_SNORM_BLOCK:
        break;
    case VK_FORMAT_ASTC_4x4_UNORM_BLOCK:
        break;
    case VK_FORMAT_ASTC_4x4_SRGB_BLOCK:
        break;
    case VK_FORMAT_ASTC_5x4_UNORM_BLOCK:
        break;
    case VK_FORMAT_ASTC_5x4_SRGB_BLOCK:
        break;
    case VK_FORMAT_ASTC_5x5_UNORM_BLOCK:
        break;
    case VK_FORMAT_ASTC_5x5_SRGB_BLOCK:
        break;
    case VK_FORMAT_ASTC_6x5_UNORM_BLOCK:
        break;
    case VK_FORMAT_ASTC_6x5_SRGB_BLOCK:
        break;
    case VK_FORMAT_ASTC_6x6_UNORM_BLOCK:
        break;
    case VK_FORMAT_ASTC_6x6_SRGB_BLOCK:
        break;
    case VK_FORMAT_ASTC_8x5_UNORM_BLOCK:
        break;
    case VK_FORMAT_ASTC_8x5_SRGB_BLOCK:
        break;
    case VK_FORMAT_ASTC_8x6_UNORM_BLOCK:
        break;
    case VK_FORMAT_ASTC_8x6_SRGB_BLOCK:
        break;
    case VK_FORMAT_ASTC_8x8_UNORM_BLOCK:
        break;
    case VK_FORMAT_ASTC_8x8_SRGB_BLOCK:
        break;
    case VK_FORMAT_ASTC_10x5_UNORM_BLOCK:
        break;
    case VK_FORMAT_ASTC_10x5_SRGB_BLOCK:
        break;
    case VK_FORMAT_ASTC_10x6_UNORM_BLOCK:
        break;
    case VK_FORMAT_ASTC_10x6_SRGB_BLOCK:
        break;
    case VK_FORMAT_ASTC_10x8_UNORM_BLOCK:
        break;
    case VK_FORMAT_ASTC_10x8_SRGB_BLOCK:
        break;
    case VK_FORMAT_ASTC_10x10_UNORM_BLOCK:
        break;
    case VK_FORMAT_ASTC_10x10_SRGB_BLOCK:
        break;
    case VK_FORMAT_ASTC_12x10_UNORM_BLOCK:
        break;
    case VK_FORMAT_ASTC_12x10_SRGB_BLOCK:
        break;
    case VK_FORMAT_ASTC_12x12_UNORM_BLOCK:
        break;
    case VK_FORMAT_ASTC_12x12_SRGB_BLOCK:
        break;
    case VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG:
        break;
    case VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG:
        break;
    case VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG:
        break;
    case VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG:
        break;
    case VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG:
        break;
    case VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG:
        break;
    case VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG:
        break;
    case VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG:
        break;
    default:
        break;
    }
    return DXGI_FORMAT_B8G8R8A8_UNORM;
}

inline VkFormat VkFormatFromDXGI_FORMAT(DXGI_FORMAT format)
{
    switch (format)
    {
    case DXGI_FORMAT_UNKNOWN:
        break;
    case DXGI_FORMAT_R32G32B32A32_TYPELESS:
        break;
    case DXGI_FORMAT_R32G32B32A32_FLOAT:
        break;
    case DXGI_FORMAT_R32G32B32A32_UINT:
        break;
    case DXGI_FORMAT_R32G32B32A32_SINT:
        break;
    case DXGI_FORMAT_R32G32B32_TYPELESS:
        break;
    case DXGI_FORMAT_R32G32B32_FLOAT:
        break;
    case DXGI_FORMAT_R32G32B32_UINT:
        break;
    case DXGI_FORMAT_R32G32B32_SINT:
        break;
    case DXGI_FORMAT_R16G16B16A16_TYPELESS:
        break;
    case DXGI_FORMAT_R16G16B16A16_FLOAT:
        break;
    case DXGI_FORMAT_R16G16B16A16_UNORM:
        break;
    case DXGI_FORMAT_R16G16B16A16_UINT:
        break;
    case DXGI_FORMAT_R16G16B16A16_SNORM:
        break;
    case DXGI_FORMAT_R16G16B16A16_SINT:
        break;
    case DXGI_FORMAT_R32G32_TYPELESS:
        break;
    case DXGI_FORMAT_R32G32_FLOAT:
        break;
    case DXGI_FORMAT_R32G32_UINT:
        break;
    case DXGI_FORMAT_R32G32_SINT:
        break;
    case DXGI_FORMAT_R32G8X24_TYPELESS:
        break;
    case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:
        break;
    case DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS:
        break;
    case DXGI_FORMAT_X32_TYPELESS_G8X24_UINT:
        break;
    case DXGI_FORMAT_R10G10B10A2_TYPELESS:
        break;
    case DXGI_FORMAT_R10G10B10A2_UNORM:
        break;
    case DXGI_FORMAT_R10G10B10A2_UINT:
        break;
    case DXGI_FORMAT_R11G11B10_FLOAT:
        break;
    case DXGI_FORMAT_R8G8B8A8_TYPELESS:
        break;
    case DXGI_FORMAT_R8G8B8A8_UNORM:
        break;
    case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
        break;
    case DXGI_FORMAT_R8G8B8A8_UINT:
        break;
    case DXGI_FORMAT_R8G8B8A8_SNORM:
        break;
    case DXGI_FORMAT_R8G8B8A8_SINT:
        break;
    case DXGI_FORMAT_R16G16_TYPELESS:
        break;
    case DXGI_FORMAT_R16G16_FLOAT:
        break;
    case DXGI_FORMAT_R16G16_UNORM:
        break;
    case DXGI_FORMAT_R16G16_UINT:
        break;
    case DXGI_FORMAT_R16G16_SNORM:
        break;
    case DXGI_FORMAT_R16G16_SINT:
        break;
    case DXGI_FORMAT_R32_TYPELESS:
        break;
    case DXGI_FORMAT_D32_FLOAT:
        break;
    case DXGI_FORMAT_R32_FLOAT:
        break;
    case DXGI_FORMAT_R32_UINT:
        break;
    case DXGI_FORMAT_R32_SINT:
        break;
    case DXGI_FORMAT_R24G8_TYPELESS:
        break;
    case DXGI_FORMAT_D24_UNORM_S8_UINT:
        break;
    case DXGI_FORMAT_R24_UNORM_X8_TYPELESS:
        break;
    case DXGI_FORMAT_X24_TYPELESS_G8_UINT:
        break;
    case DXGI_FORMAT_R8G8_TYPELESS:
        break;
    case DXGI_FORMAT_R8G8_UNORM:
        break;
    case DXGI_FORMAT_R8G8_UINT:
        break;
    case DXGI_FORMAT_R8G8_SNORM:
        break;
    case DXGI_FORMAT_R8G8_SINT:
        break;
    case DXGI_FORMAT_R16_TYPELESS:
        break;
    case DXGI_FORMAT_R16_FLOAT:
        break;
    case DXGI_FORMAT_D16_UNORM:
        break;
    case DXGI_FORMAT_R16_UNORM:
        break;
    case DXGI_FORMAT_R16_UINT:
        break;
    case DXGI_FORMAT_R16_SNORM:
        break;
    case DXGI_FORMAT_R16_SINT:
        break;
    case DXGI_FORMAT_R8_TYPELESS:
        break;
    case DXGI_FORMAT_R8_UNORM:
        break;
    case DXGI_FORMAT_R8_UINT:
        break;
    case DXGI_FORMAT_R8_SNORM:
        break;
    case DXGI_FORMAT_R8_SINT:
        break;
    case DXGI_FORMAT_A8_UNORM:
        break;
    case DXGI_FORMAT_R1_UNORM:
        break;
    case DXGI_FORMAT_R9G9B9E5_SHAREDEXP:
        break;
    case DXGI_FORMAT_R8G8_B8G8_UNORM:
        break;
    case DXGI_FORMAT_G8R8_G8B8_UNORM:
        break;
    case DXGI_FORMAT_BC1_TYPELESS:
        break;
    case DXGI_FORMAT_BC1_UNORM:
        break;
    case DXGI_FORMAT_BC1_UNORM_SRGB:
        break;
    case DXGI_FORMAT_BC2_TYPELESS:
        break;
    case DXGI_FORMAT_BC2_UNORM:
        break;
    case DXGI_FORMAT_BC2_UNORM_SRGB:
        break;
    case DXGI_FORMAT_BC3_TYPELESS:
        break;
    case DXGI_FORMAT_BC3_UNORM:
        break;
    case DXGI_FORMAT_BC3_UNORM_SRGB:
        break;
    case DXGI_FORMAT_BC4_TYPELESS:
        break;
    case DXGI_FORMAT_BC4_UNORM:
        break;
    case DXGI_FORMAT_BC4_SNORM:
        break;
    case DXGI_FORMAT_BC5_TYPELESS:
        break;
    case DXGI_FORMAT_BC5_UNORM:
        break;
    case DXGI_FORMAT_BC5_SNORM:
        break;
    case DXGI_FORMAT_B5G6R5_UNORM:
        break;
    case DXGI_FORMAT_B5G5R5A1_UNORM:
        break;
    case DXGI_FORMAT_B8G8R8A8_UNORM:
        return VK_FORMAT_B8G8R8A8_UNORM;
    case DXGI_FORMAT_B8G8R8X8_UNORM:
        break;
    case DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM:
        break;
    case DXGI_FORMAT_B8G8R8A8_TYPELESS:
        break;
    case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:
        return VK_FORMAT_B8G8R8A8_SRGB;
    case DXGI_FORMAT_B8G8R8X8_TYPELESS:
        break;
    case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB:
        break;
    case DXGI_FORMAT_BC6H_TYPELESS:
        break;
    case DXGI_FORMAT_BC6H_UF16:
        break;
    case DXGI_FORMAT_BC6H_SF16:
        break;
    case DXGI_FORMAT_BC7_TYPELESS:
        break;
    case DXGI_FORMAT_BC7_UNORM:
        break;
    case DXGI_FORMAT_BC7_UNORM_SRGB:
        break;
    case DXGI_FORMAT_AYUV:
        break;
    case DXGI_FORMAT_Y410:
        break;
    case DXGI_FORMAT_Y416:
        break;
    case DXGI_FORMAT_NV12:
        break;
    case DXGI_FORMAT_P010:
        break;
    case DXGI_FORMAT_P016:
        break;
    case DXGI_FORMAT_420_OPAQUE:
        break;
    case DXGI_FORMAT_YUY2:
        break;
    case DXGI_FORMAT_Y210:
        break;
    case DXGI_FORMAT_Y216:
        break;
    case DXGI_FORMAT_NV11:
        break;
    case DXGI_FORMAT_AI44:
        break;
    case DXGI_FORMAT_IA44:
        break;
    case DXGI_FORMAT_P8:
        break;
    case DXGI_FORMAT_A8P8:
        break;
    case DXGI_FORMAT_B4G4R4A4_UNORM:
        break;
    case DXGI_FORMAT_P208:
        break;
    case DXGI_FORMAT_V208:
        break;
    case DXGI_FORMAT_V408:
        break;
    case DXGI_FORMAT_FORCE_UINT:
        break;
    default:
        break;
    }
    return VK_FORMAT_B8G8R8A8_UNORM;
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
    VkInstance            instance;
    ComPtr<IDXGIAdapter4> dxgiAdapter;
    DXGI_ADAPTER_DESC3    dxdiAdapterDesc;
    D3D12_FEATURE         d3dFeatures;
    uint32_t              index;
};

struct VkDevice_T
{
    VkPhysicalDevice      physicalDevice;
    std::vector<VkQueue>  queues;
    ComPtr<ID3D12Device2> d3dDevice;
};

struct VkQueue_T
{
    VkDevice                   device;
    ComPtr<ID3D12CommandQueue> d3dQueue;
};

struct VkSemaphore_T
{
    ComPtr<ID3D12Fence> d3dFence;
};

struct VkCommandBuffer_T
{
};

struct VkFence_T
{
    ComPtr<ID3D12Fence> d3dFence;
};

struct VkDeviceMemory_T
{
};

struct VkBuffer_T
{
};

struct VkImage_T
{
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
};

struct VkPipelineCache_T
{
};

struct VkPipelineLayout_T
{
};

struct VkRenderPass_T
{
};

struct VkPipeline_T
{
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
    VkDevice                device;
    ComPtr<IDXGISwapChain4> dxgiSwapChain;
};

struct VkDebugReportCallbackEXT_T
{
};
