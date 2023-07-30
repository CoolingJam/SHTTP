#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Sockpp::sockpp" for configuration "RelWithDebInfo"
set_property(TARGET Sockpp::sockpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Sockpp::sockpp PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/sockpp.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/sockpp.dll"
  )

list(APPEND _cmake_import_check_targets Sockpp::sockpp )
list(APPEND _cmake_import_check_files_for_Sockpp::sockpp "${_IMPORT_PREFIX}/lib/sockpp.lib" "${_IMPORT_PREFIX}/bin/sockpp.dll" )

# Import target "Sockpp::sockpp-static" for configuration "RelWithDebInfo"
set_property(TARGET Sockpp::sockpp-static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Sockpp::sockpp-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/sockpp-static.lib"
  )

list(APPEND _cmake_import_check_targets Sockpp::sockpp-static )
list(APPEND _cmake_import_check_files_for_Sockpp::sockpp-static "${_IMPORT_PREFIX}/lib/sockpp-static.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
