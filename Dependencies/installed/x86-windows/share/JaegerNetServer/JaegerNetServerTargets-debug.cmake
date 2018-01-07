#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "JaegerNet::JaegerNetServer" for configuration "Debug"
set_property(TARGET JaegerNet::JaegerNetServer APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(JaegerNet::JaegerNetServer PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/JaegerNetServerd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/JaegerNetServerd.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS JaegerNet::JaegerNetServer )
list(APPEND _IMPORT_CHECK_FILES_FOR_JaegerNet::JaegerNetServer "${_IMPORT_PREFIX}/lib/JaegerNetServerd.lib" "${_IMPORT_PREFIX}/bin/JaegerNetServerd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
