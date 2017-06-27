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

#include <CppUnitTest.h>

#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(Instance)
{
public:
    TEST_METHOD(CreateInstance)
    {
        VkApplicationInfo applicationInfo  = {};
        applicationInfo.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        applicationInfo.pNext              = nullptr;
        applicationInfo.pApplicationName   = "VulkanOnD3D12";
        applicationInfo.applicationVersion = 1;
        applicationInfo.pEngineName        = "VulkanOnD3D12";
        applicationInfo.engineVersion      = 1;
        applicationInfo.apiVersion         = VK_API_VERSION_1_0;

        VkInstanceCreateInfo instanceCreateInfo    = {};
        instanceCreateInfo.sType                   = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        instanceCreateInfo.pNext                   = nullptr;
        instanceCreateInfo.flags                   = 0;
        instanceCreateInfo.pApplicationInfo        = &applicationInfo;
        instanceCreateInfo.enabledLayerCount       = 0;
        instanceCreateInfo.ppEnabledLayerNames     = nullptr;
        instanceCreateInfo.enabledExtensionCount   = 0;
        instanceCreateInfo.ppEnabledExtensionNames = nullptr;

        VkResult res = vkCreateInstance(&instanceCreateInfo, nullptr, &instance);
        if (res != VK_SUCCESS)
        {
            Assert::Fail(L"res != VK_SUCCESS");
        }
        Assert::IsNotNull(instance);
    }

    TEST_METHOD(DestroyInstance)
    {
        vkDestroyInstance(instance, nullptr);

        Assert::IsNull(instance);
    }

private:
    VkInstance instance;
};

TEST_CLASS(PhysicalDevices)
{
public:
    TEST_METHOD_INITIALIZE(Initialize)
    {
        VkApplicationInfo applicationInfo  = {};
        applicationInfo.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        applicationInfo.pNext              = nullptr;
        applicationInfo.pApplicationName   = "VulkanOnD3D12";
        applicationInfo.applicationVersion = 1;
        applicationInfo.pEngineName        = "VulkanOnD3D12";
        applicationInfo.engineVersion      = 1;
        applicationInfo.apiVersion         = VK_API_VERSION_1_0;

        VkInstanceCreateInfo instanceCreateInfo    = {};
        instanceCreateInfo.sType                   = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        instanceCreateInfo.pNext                   = nullptr;
        instanceCreateInfo.flags                   = 0;
        instanceCreateInfo.pApplicationInfo        = &applicationInfo;
        instanceCreateInfo.enabledLayerCount       = 0;
        instanceCreateInfo.ppEnabledLayerNames     = nullptr;
        instanceCreateInfo.enabledExtensionCount   = 0;
        instanceCreateInfo.ppEnabledExtensionNames = nullptr;

        VkResult res = vkCreateInstance(&instanceCreateInfo, nullptr, &instance);
        if (res != VK_SUCCESS)
        {
            Assert::Fail(L"res != VK_SUCCESS");
        }
        Assert::IsNotNull(instance);
    }

    TEST_METHOD_CLEANUP(Cleanup)
    {
        vkDestroyInstance(instance, nullptr);
    }

    TEST_METHOD(EnumeratePhysicalDevices)
    {
        uint32_t physicalDeviceCount = 0;
        VkResult res                 = vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, nullptr);
        if (res != VK_SUCCESS)
        {
            Assert::Fail(L"res != VK_SUCCESS");
        }
        physicalDevices.resize(physicalDeviceCount);
        res = vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, physicalDevices.data());
        if (res != VK_SUCCESS)
        {
            Assert::Fail(L"res != VK_SUCCESS");
        }

        for (uint32_t i = 0; i < static_cast<uint32_t>(physicalDevices.size()); ++i)
        {
            Assert::IsNotNull(physicalDevices[i]);
        }
    }

private:
    VkInstance                    instance;
    std::vector<VkPhysicalDevice> physicalDevices;
};
