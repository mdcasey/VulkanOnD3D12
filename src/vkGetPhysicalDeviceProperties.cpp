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

VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties(
    VkPhysicalDevice            physicalDevice,
    VkPhysicalDeviceProperties* pProperties)
{
    VkPhysicalDeviceLimits limits = {};
    limits.maxImageDimension1D    = D3D12_REQ_TEXTURE1D_U_DIMENSION;
    limits.maxImageDimension2D    = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
    limits.maxImageDimension3D    = D3D12_REQ_TEXTURE3D_U_V_OR_W_DIMENSION;
    limits.maxImageDimensionCube  = D3D12_REQ_TEXTURECUBE_DIMENSION;
    limits.maxImageArrayLayers    = D3D12_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION;
    limits.maxTexelBufferElements;
    limits.maxUniformBufferRange;
    limits.maxStorageBufferRange;
    limits.maxPushConstantsSize;
    limits.maxMemoryAllocationCount;
    limits.maxSamplerAllocationCount;
    limits.bufferImageGranularity;
    limits.sparseAddressSpaceSize;
    limits.maxBoundDescriptorSets;
    limits.maxPerStageDescriptorSamplers;
    limits.maxPerStageDescriptorUniformBuffers;
    limits.maxPerStageDescriptorStorageBuffers;
    limits.maxPerStageDescriptorSampledImages;
    limits.maxPerStageDescriptorStorageImages;
    limits.maxPerStageDescriptorInputAttachments;
    limits.maxPerStageResources;
    limits.maxDescriptorSetSamplers;
    limits.maxDescriptorSetUniformBuffers;
    limits.maxDescriptorSetUniformBuffersDynamic;
    limits.maxDescriptorSetStorageBuffers;
    limits.maxDescriptorSetStorageBuffersDynamic;
    limits.maxDescriptorSetSampledImages;
    limits.maxDescriptorSetStorageImages;
    limits.maxDescriptorSetInputAttachments;
    limits.maxVertexInputAttributes;
    limits.maxVertexInputBindings;
    limits.maxVertexInputAttributeOffset;
    limits.maxVertexInputBindingStride;
    limits.maxVertexOutputComponents;
    limits.maxTessellationGenerationLevel;
    limits.maxTessellationPatchSize;
    limits.maxTessellationControlPerVertexInputComponents;
    limits.maxTessellationControlPerVertexOutputComponents;
    limits.maxTessellationControlPerPatchOutputComponents;
    limits.maxTessellationControlTotalOutputComponents;
    limits.maxTessellationEvaluationInputComponents;
    limits.maxTessellationEvaluationOutputComponents;
    limits.maxGeometryShaderInvocations;
    limits.maxGeometryInputComponents;
    limits.maxGeometryOutputComponents;
    limits.maxGeometryOutputVertices;
    limits.maxGeometryTotalOutputComponents;
    limits.maxFragmentInputComponents;
    limits.maxFragmentOutputAttachments;
    limits.maxFragmentDualSrcAttachments;
    limits.maxFragmentCombinedOutputResources;
    limits.maxComputeSharedMemorySize;
    limits.maxComputeWorkGroupCount[0];
    limits.maxComputeWorkGroupCount[1];
    limits.maxComputeWorkGroupCount[2];
    limits.maxComputeWorkGroupInvocations = D3D12_CS_THREAD_GROUP_MAX_THREADS_PER_GROUP;
    limits.maxComputeWorkGroupSize[0]     = D3D12_CS_THREAD_GROUP_MAX_X;
    limits.maxComputeWorkGroupSize[1]     = D3D12_CS_THREAD_GROUP_MAX_Y;
    limits.maxComputeWorkGroupSize[2]     = D3D12_CS_THREAD_GROUP_MAX_Z;
    limits.subPixelPrecisionBits          = D3D12_SUBPIXEL_FRACTIONAL_BIT_COUNT;
    limits.subTexelPrecisionBits          = D3D12_SUBTEXEL_FRACTIONAL_BIT_COUNT;
    limits.mipmapPrecisionBits;
    limits.maxDrawIndexedIndexValue;
    limits.maxDrawIndirectCount;
    limits.maxSamplerLodBias;
    limits.maxSamplerAnisotropy;
    limits.maxViewports;
    limits.maxViewportDimensions[0];
    limits.maxViewportDimensions[1];
    limits.viewportBoundsRange[0];
    limits.viewportBoundsRange[1];
    limits.viewportSubPixelBits;
    limits.minMemoryMapAlignment;
    limits.minTexelBufferOffsetAlignment;
    limits.minUniformBufferOffsetAlignment;
    limits.minStorageBufferOffsetAlignment;
    limits.minTexelOffset = D3D12_COMMONSHADER_TEXEL_OFFSET_MAX_NEGATIVE;
    limits.maxTexelOffset = D3D12_COMMONSHADER_TEXEL_OFFSET_MAX_POSITIVE;
    limits.minTexelGatherOffset;
    limits.maxTexelGatherOffset;
    limits.minInterpolationOffset;
    limits.maxInterpolationOffset;
    limits.subPixelInterpolationOffsetBits;
    limits.maxFramebufferWidth;
    limits.maxFramebufferHeight;
    limits.maxFramebufferLayers;
    limits.framebufferColorSampleCounts;
    limits.framebufferDepthSampleCounts;
    limits.framebufferStencilSampleCounts;
    limits.framebufferNoAttachmentsSampleCounts;
    limits.maxColorAttachments;
    limits.sampledImageColorSampleCounts;
    limits.sampledImageIntegerSampleCounts;
    limits.sampledImageDepthSampleCounts;
    limits.sampledImageStencilSampleCounts;
    limits.storageImageSampleCounts;
    limits.maxSampleMaskWords;
    limits.timestampComputeAndGraphics;
    limits.timestampPeriod;
    limits.maxClipDistances                = D3D12_CLIP_OR_CULL_DISTANCE_COUNT;
    limits.maxCullDistances                = D3D12_CLIP_OR_CULL_DISTANCE_COUNT;
    limits.maxCombinedClipAndCullDistances = D3D12_CLIP_OR_CULL_DISTANCE_COUNT;
    limits.discreteQueuePriorities;
    limits.pointSizeRange[0];
    limits.pointSizeRange[1];
    limits.lineWidthRange[0];
    limits.lineWidthRange[1];
    limits.pointSizeGranularity;
    limits.lineWidthGranularity;
    limits.strictLines;
    limits.standardSampleLocations;
    limits.optimalBufferCopyOffsetAlignment;
    limits.optimalBufferCopyRowPitchAlignment;
    limits.nonCoherentAtomSize;

    VkPhysicalDeviceSparseProperties sparseProperties = {};
    sparseProperties.residencyStandard2DBlockShape;
    sparseProperties.residencyStandard2DMultisampleBlockShape;
    sparseProperties.residencyStandard3DBlockShape;
    sparseProperties.residencyAlignedMipSize;
    sparseProperties.residencyNonResidentStrict;

    VkPhysicalDeviceProperties properties = {};
    properties.apiVersion                 = VK_MAKE_VERSION(VK_VERSION_MAJOR(VK_API_VERSION_1_0), VK_VERSION_MINOR(VK_API_VERSION_1_0), VK_VERSION_PATCH(VK_HEADER_VERSION));
    properties.driverVersion              = physicalDevice->adapterDesc.Revision;
    properties.vendorID                   = physicalDevice->adapterDesc.VendorId;
    properties.deviceID                   = physicalDevice->adapterDesc.DeviceId;
    properties.deviceType                 = VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU;
    properties.limits                     = limits;
    properties.sparseProperties           = sparseProperties;

    // Set the device name
    wcstombs_s(nullptr, properties.deviceName, physicalDevice->adapterDesc.Description, VK_MAX_PHYSICAL_DEVICE_NAME_SIZE);

    // Set the pipeline cache UUID
    snprintf(reinterpret_cast<char*>(&properties.pipelineCacheUUID), VK_UUID_SIZE, "D3D12-%i", physicalDevice->adapterDesc.AdapterLuid.LowPart);

    *pProperties = properties;
}
