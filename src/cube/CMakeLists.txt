cmake_minimum_required(VERSION 3.1)

add_definitions("/D_CRT_SECURE_NO_WARNINGS /D_USE_MATH_DEFINES")
if(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
add_definitions("/DVK_USE_PLATFORM_WIN32_KHR")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL WindowsStore)
add_definitions("/DVK_USE_PLATFORM_UWP_CHB")
endif()

file(GLOB HEADERS *.h)

add_executable(cube WIN32 ${HEADERS} cube.c)
target_link_libraries(cube VulkanOnD3D12)

add_executable(cubepp WIN32 ${HEADERS} cube.cpp)
set_property(TARGET cubepp PROPERTY CXX_STANDARD 14)
target_link_libraries(cubepp VulkanOnD3D12)

add_custom_command(TARGET cube POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/cube-frag.spv ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/\$\(Configuration\)/cube-frag.spv)
add_custom_command(TARGET cube POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/cube-vert.spv ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/\$\(Configuration\)/cube-vert.spv)
add_custom_command(TARGET cube POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/cube-frag.cso ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/\$\(Configuration\)/cube-frag.cso)
add_custom_command(TARGET cube POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/cube-vert.cso ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/\$\(Configuration\)/cube-vert.cso)
add_custom_command(TARGET cube POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/lunarg.ppm ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/\$\(Configuration\)/lunarg.ppm)

add_custom_command(TARGET cube POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/cube-frag.spv ${CMAKE_CURRENT_BINARY_DIR}/cube-frag.spv)
add_custom_command(TARGET cube POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/cube-vert.spv ${CMAKE_CURRENT_BINARY_DIR}/cube-vert.spv)
add_custom_command(TARGET cube POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/cube-frag.cso ${CMAKE_CURRENT_BINARY_DIR}/cube-frag.cso)
add_custom_command(TARGET cube POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/cube-vert.cso ${CMAKE_CURRENT_BINARY_DIR}/cube-vert.cso)
add_custom_command(TARGET cube POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/lunarg.ppm ${CMAKE_CURRENT_BINARY_DIR}/lunarg.ppm)
