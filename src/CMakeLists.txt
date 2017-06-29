cmake_minimum_required(VERSION 3.0)

include_directories(../include)

if(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
add_subdirectory(vulkaninfo)
endif()

add_definitions("/DUNICODE /D_UNICODE /W4 /WX /Yu_vulkan.h /wd4100 /wd4324")
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
target_link_libraries(VulkanOnD3D12 d3d12 dxgi)
