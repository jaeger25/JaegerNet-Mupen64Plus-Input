# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.10.0)
project ("JaegerNet-Mupen64Plus-Input")

set(JaegerNet_VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

# cotire
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/CMake)

include(cotire)

add_compile_options(/W4 /WX /wd4201)

set(Dependency_Install_Path ${CMAKE_SOURCE_DIR}/../Dependencies/installed/${VCPKG_TARGET_TRIPLET})
include_directories(${Dependency_Install_Path}/include)
include_directories(./inc)

set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include sub-projects.
add_subdirectory ("dll")