include_directories(../lib)

find_package(JaegerNetServer CONFIG REQUIRED)

add_library(JaegerNet-Mupen64Plus-Input SHARED
    "Module.cpp"
    "Player.cpp" "Player.h")

target_link_libraries(JaegerNet-Mupen64Plus-Input
    PUBLIC JaegerNet::JaegerNetServer)

cotire(JaegerNet-Mupen64Plus-Input)
