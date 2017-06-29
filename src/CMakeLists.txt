cmake_minimum_required(VERSION 3.0)

add_definitions("/DUNICODE /D_UNICODE /W4 /WX /Yu_vulkan.h /wd4100 /wd4324")
if(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
add_definitions("/DVK_USE_PLATFORM_WIN32_KHR")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL WindowsStore)
add_definitions("/DVK_USE_PLATFORM_UWP_CHB")
endif()

include_directories(../include)

file(GLOB HEADERS *.h)
file(GLOB SOURCES *.cpp)

set_source_files_properties(_vulkan.cpp PROPERTIES COMPILE_FLAGS "/Yc_vulkan.h")

add_library(VulkanOnD3D12 STATIC ${HEADERS} ${SOURCES})
