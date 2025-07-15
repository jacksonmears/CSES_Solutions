cmake_minimum_required(VERSION 3.29)
project(CSES)

set(CMAKE_CXX_STANDARD 20)

# Add main executable explicitly
add_executable(main main.cpp)

# Recursively find all other .cpp files, EXCLUDING CMake internal files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "*.cpp"
)

# Add each .cpp file as its own executable
foreach(src ${SOURCES})
    # Skip main.cpp (already added above)
    if(NOT src STREQUAL "${CMAKE_SOURCE_DIR}/main.cpp")
        # Skip anything inside CMakeFiles or build artifacts
        if(NOT src MATCHES "CMakeFiles|CMakeCXXCompilerId")
            get_filename_component(exe ${src} NAME_WE)
            add_executable(${exe} ${src})
        endif()
    endif()
endforeach()
