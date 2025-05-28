cmake_minimum_required(VERSION 3.29)
project(CSES)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES "*/**.cpp")
foreach(src ${SOURCES})
    get_filename_component(exe ${src} NAME_WE)
    add_executable(${exe} ${src})
endforeach()