cmake_minimum_required(VERSION 3.0)

add_definitions("/DUNICODE /D_UNICODE /D_CRT_SECURE_NO_WARNINGS /wd4133")
if(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
add_definitions("/DVK_USE_PLATFORM_WIN32_KHR")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL WindowsStore)
add_definitions("/DVK_USE_PLATFORM_UWP_CHB")
endif()

add_executable(vulkaninfo vulkaninfo.c)
target_link_libraries(vulkaninfo VulkanOnD3D12)
