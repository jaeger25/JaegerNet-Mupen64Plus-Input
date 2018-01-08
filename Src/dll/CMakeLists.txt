include_directories(../lib)

find_package(JaegerNetServer CONFIG REQUIRED)

add_library(JaegerNet-Mupen64Plus-Input SHARED
    "Module.cpp"
    "Player.cpp" "Player.h")

target_link_libraries(JaegerNet-Mupen64Plus-Input
    PUBLIC JaegerNet::JaegerNetServer)

install(TARGETS JaegerNet-Mupen64Plus-Input EXPORT JaegerNet-Mupen64Plus-InputTargets
    RUNTIME DESTINATION bin
)

FILE(GLOB DependencyBinaries ${Dependency_Install_Path}/bin/*)
INSTALL(FILES ${DependencyBinaries} DESTINATION bin)

cotire(JaegerNet-Mupen64Plus-Input)
