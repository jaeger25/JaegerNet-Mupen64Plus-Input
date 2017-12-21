include_directories(../lib)

add_library(JaegerNet-Mupen64Plus-Input SHARED
    "Module.cpp")

cotire(JaegerNet-Mupen64Plus-Input)