cmake_minimum_required(VERSION 3.0)

include_directories(../include)

include_directories(spirv_cross)
add_subdirectory(spirv_cross)

if(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
add_subdirectory(cube)
add_subdirectory(vulkaninfo)
endif()

add_definitions("/DUNICODE /D_UNICODE /DNOMINMAX /DWIN32_LEAN_AND_MEAN /W4 /WX /Yu_vulkan.h /wd4100 /wd4238 /wd4324")
add_definitions("/DVULKANOND3D12_BUILD")
if(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
add_definitions("/DVK_USE_PLATFORM_WIN32_KHR")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL WindowsStore)
add_definitions("/DVK_USE_PLATFORM_UWP_CHB")
endif()

file(GLOB HEADERS *.h)
file(GLOB SOURCES *.cpp)

set_source_files_properties(_vulkan.cpp PROPERTIES COMPILE_FLAGS "/Yc_vulkan.h")

add_library(VulkanOnD3D12 SHARED ${HEADERS} ${SOURCES})
set_property(TARGET VulkanOnD3D12 PROPERTY CXX_STANDARD 14)
target_link_libraries(VulkanOnD3D12 spirv_cross d3d12 d3dcompiler dxgi)
