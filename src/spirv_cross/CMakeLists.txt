cmake_minimum_required(VERSION 3.1)

add_definitions("/D_CRT_SECURE_NO_WARNINGS /D_USE_MATH_DEFINES /wd4146")

file(GLOB HEADERS *.h)
file(GLOB SOURCES *.cpp)

add_library(spirv_cross STATIC ${HEADERS} ${SOURCES})
set_property(TARGET spirv_cross PROPERTY CXX_STANDARD 14)
