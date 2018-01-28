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

VKAPI_ATTR VkResult VKAPI_CALL vkCreateSwapchainKHR(
    VkDevice                        device,
    const VkSwapchainCreateInfoKHR* pCreateInfo,
    const VkAllocationCallbacks*    pAllocator,
    VkSwapchainKHR*                 pSwapchain)
{
    VkSwapchainKHR swapchain = nullptr;
    if (pAllocator)
    {
        swapchain = static_cast<VkSwapchainKHR>(pAllocator->pfnAllocation(nullptr, sizeof(VkSwapchainKHR_T), 8, VK_SYSTEM_ALLOCATION_SCOPE_DEVICE));
    }
    else
    {
        swapchain = new VkSwapchainKHR_T();
    }

    ComPtr<IDXGISwapChain1> swapChain;
    if (pCreateInfo->oldSwapchain)
    {
        HRESULT hr = pCreateInfo->oldSwapchain->swapChain->ResizeBuffers(
            pCreateInfo->minImageCount,
            pCreateInfo->imageExtent.width,
            pCreateInfo->imageExtent.height,
            VkFormatToD3D12(pCreateInfo->imageFormat),
            0);

        if (FAILED(hr))
        {
            return VkResultFromHRESULT(hr);
        }
    }
    else
    {
        DXGI_SWAP_CHAIN_DESC1 desc = {};
        desc.Width                 = pCreateInfo->imageExtent.width;
        desc.Height                = pCreateInfo->imageExtent.height;
        desc.Format                = VkFormatToD3D12(pCreateInfo->imageFormat);
        desc.Stereo                = FALSE;
        desc.SampleDesc.Count      = 1;
        desc.SampleDesc.Quality    = 0;
        desc.BufferUsage           = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        desc.BufferCount           = pCreateInfo->minImageCount;
        desc.Scaling               = DXGI_SCALING_NONE;
        desc.SwapEffect            = DXGI_SWAP_EFFECT_FLIP_DISCARD;
        desc.AlphaMode             = VkCompositeAlphaFlagBitsKHRToDXGI_ALPHA_MODE(pCreateInfo->compositeAlpha);
        desc.Flags                 = 0;

#if WINAPI_FAMILY == WINAPI_FAMILY_PC_APP
        HRESULT hr = device->physicalDevice->instance->dxgiFactory->CreateSwapChainForCoreWindow(
            device->queues[0]->Get(),
            pCreateInfo->surface->window,
            &desc,
            nullptr,
            swapChain.GetAddressOf());
#elif WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP
        HRESULT hr = device->physicalDevice->instance->dxgiFactory->CreateSwapChainForHwnd(
            device->queues[0]->Get(),
            pCreateInfo->surface->hwnd,
            &desc,
            nullptr,
            nullptr,
            swapChain.GetAddressOf());
#endif
        if (FAILED(hr))
        {
            return VkResultFromHRESULT(hr);
        }
    }

    swapchain->images.clear();

    for (uint32_t i = 0; i < pCreateInfo->minImageCount; ++i)
    {
        ComPtr<ID3D12Resource> resource;

        HRESULT hr = swapChain->GetBuffer(i, IID_PPV_ARGS(resource.GetAddressOf()));
        if (FAILED(hr))
        {
            return VkResultFromHRESULT(hr);
        }

        D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc = {};
        descriptorHeapDesc.Type                       = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
        descriptorHeapDesc.NumDescriptors             = 1;
        descriptorHeapDesc.Flags                      = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
        descriptorHeapDesc.NodeMask                   = device->physicalDevice->index;

        ComPtr<ID3D12DescriptorHeap> descriptorHeap;
        hr = device->device->CreateDescriptorHeap(&descriptorHeapDesc, IID_PPV_ARGS(descriptorHeap.GetAddressOf()));
        if (FAILED(hr))
        {
            return VkResultFromHRESULT(hr);
        }

        VkImage image         = new VkImage_T();
        image->resource       = resource;
        image->descriptorHeap = descriptorHeap;

        swapchain->images.push_back(image);
    }

    swapchain->swapChain = swapChain;

    *pSwapchain = swapchain;

    return VK_SUCCESS;
}
