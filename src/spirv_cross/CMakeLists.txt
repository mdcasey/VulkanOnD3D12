cmake_minimum_required(VERSION 3.0)

add_definitions("/DUNICODE /D_UNICODE /W4 /WX /wd4146 /wd4245 /wd4702 /wd4706")

file(GLOB HEADERS *.h)
file(GLOB SOURCES *.cpp)

add_library(spirv_cross STATIC ${HEADERS} ${SOURCES})
