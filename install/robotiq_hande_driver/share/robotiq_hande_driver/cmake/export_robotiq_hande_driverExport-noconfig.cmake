#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "robotiq_hande_driver::robotiq_hande_driver" for configuration ""
set_property(TARGET robotiq_hande_driver::robotiq_hande_driver APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(robotiq_hande_driver::robotiq_hande_driver PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/librobotiq_hande_driver.so"
  IMPORTED_SONAME_NOCONFIG "librobotiq_hande_driver.so"
  )

list(APPEND _cmake_import_check_targets robotiq_hande_driver::robotiq_hande_driver )
list(APPEND _cmake_import_check_files_for_robotiq_hande_driver::robotiq_hande_driver "${_IMPORT_PREFIX}/lib/librobotiq_hande_driver.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
