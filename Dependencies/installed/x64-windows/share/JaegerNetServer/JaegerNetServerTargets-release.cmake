#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "JaegerNet::JaegerNetServer" for configuration "Release"
set_property(TARGET JaegerNet::JaegerNetServer APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(JaegerNet::JaegerNetServer PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/JaegerNetServer.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/JaegerNetServer.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS JaegerNet::JaegerNetServer )
list(APPEND _IMPORT_CHECK_FILES_FOR_JaegerNet::JaegerNetServer "${_IMPORT_PREFIX}/lib/JaegerNetServer.lib" "${_IMPORT_PREFIX}/bin/JaegerNetServer.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
