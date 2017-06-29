### Vulkan On D3D12

VulkanOnD3D12 aims to make the Vulkan API available to platforms where only a
D3D12 driver is available, such as Windows UWP.

### Usage

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
