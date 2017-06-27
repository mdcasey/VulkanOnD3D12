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

VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures(
    VkPhysicalDevice          physicalDevice,
    VkPhysicalDeviceFeatures* pFeatures)
{
    VkPhysicalDeviceFeatures features = {};
    features.robustBufferAccess;
    features.fullDrawIndexUint32;
    features.imageCubeArray;
    features.independentBlend;
    features.geometryShader     = VK_TRUE;
    features.tessellationShader = VK_TRUE;
    features.sampleRateShading;
    features.dualSrcBlend;
    features.logicOp;
    features.multiDrawIndirect;
    features.drawIndirectFirstInstance;
    features.depthClamp;
    features.depthBiasClamp;
    features.fillModeNonSolid;
    features.depthBounds;
    features.wideLines;
    features.largePoints;
    features.alphaToOne;
    features.multiViewport;
    features.samplerAnisotropy;
    features.textureCompressionETC2     = VK_FALSE;
    features.textureCompressionASTC_LDR = VK_FALSE;
    features.textureCompressionBC       = VK_TRUE;
    features.occlusionQueryPrecise;
    features.pipelineStatisticsQuery;
    features.vertexPipelineStoresAndAtomics;
    features.fragmentStoresAndAtomics;
    features.shaderTessellationAndGeometryPointSize;
    features.shaderImageGatherExtended;
    features.shaderStorageImageExtendedFormats;
    features.shaderStorageImageMultisample;
    features.shaderStorageImageReadWithoutFormat;
    features.shaderStorageImageWriteWithoutFormat;
    features.shaderUniformBufferArrayDynamicIndexing;
    features.shaderSampledImageArrayDynamicIndexing;
    features.shaderStorageBufferArrayDynamicIndexing;
    features.shaderStorageImageArrayDynamicIndexing;
    features.shaderClipDistance;
    features.shaderCullDistance;
    features.shaderFloat64 = VK_TRUE;
    features.shaderInt64   = VK_FALSE;
    features.shaderInt16   = VK_FALSE;
    features.shaderResourceResidency;
    features.shaderResourceMinLod;
    features.sparseBinding;
    features.sparseResidencyBuffer;
    features.sparseResidencyImage2D;
    features.sparseResidencyImage3D;
    features.sparseResidency2Samples;
    features.sparseResidency4Samples;
    features.sparseResidency8Samples;
    features.sparseResidency16Samples;
    features.sparseResidencyAliased;
    features.variableMultisampleRate;
    features.inheritedQueries;

    *pFeatures = features;
}
