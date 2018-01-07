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

get_target_property(JaegerNetServer_Location JaegerNet::JaegerNetServer IMPORTED_LOCATION_RELEASE)
get_target_property(JaegerNetServer_Location_Debug JaegerNet::JaegerNetServer IMPORTED_LOCATION_DEBUG)

install(
  FILES
    "${JaegerNetServer_Location}"
  DESTINATION
    bin
  CONFIGURATIONS
    Release
)

install(
  FILES
    "${JaegerNetServer_Location_Debug}"
  DESTINATION
    bin
  CONFIGURATIONS
    Debug
)

unset(_importedLocation)

cotire(JaegerNet-Mupen64Plus-Input)
