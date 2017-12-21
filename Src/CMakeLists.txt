# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.10.0)
project ("JaegerNet-Mupen64Plus-Input")

set(CMAKE_CXX_STANDARD 17)

# cotire
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake")

include(cotire)

add_compile_options(/W4 /WX)

# Include sub-projects.
#add_subdirectory ("dll")
#add_subdirectory ("lib")