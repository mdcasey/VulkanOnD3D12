### Vulkan On D3D12

VulkanOnD3D12 aims to make the Vulkan API available to platforms where only a
D3D12 driver is available, such as Windows UWP.

**This project is currently a work in progress and as such, some or most things
may not work at all.**

#### Building

VulkanOnD3D12 uses the CMake build system and requires a shadowed build root.

`mkdir VulkanOnD3D12-build`<br/>
`cd VulkanOnD3D12-build`<br/>

*For Windows Desktop*<br/>
`cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_SYSTEM_NAME=Windows
-DCMAKE_SYSTEM_VERSION=10.0 ..\VulkanOnD3D12`

*For Windows UWP*<br/>
`cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_SYSTEM_NAME=WindowsStore
-DCMAKE_SYSTEM_VERSION=10.0 ..\VulkanOnD3D12`

This will generate a .sln project you can then open with Visual Studio.

#### Usage

An example using the VK_CHB_uwp_surface extension to create a VkSurface for a
Windows::UI::Core::CoreWindow.

```
void App::SetWindow(CoreWindow^ window)
{
    VkUWPSurfaceCreateInfoCHB surfaceCreateInfo = {};
    surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_UWP_SURFACE_CREATE_INFO_CHB;
    surfaceCreateInfo.pNext = nullptr;
    surfaceCreateInfo.flags = 0;
    surfaceCreateInfo.window = reinterpret_cast<IUnknown*>(window);

    VkResult res;
    VkSurfaceKHR surface;
    res = vkCreateUWPSurfaceCHB(instance, &surfaceCreateInfo, nullptr, &surface);
    if (res != VK_SUCCESS)
    {
        // Handle error here
    }
}
```
