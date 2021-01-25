cmake_minimum_required(VERSION 3.15)
project(libintrin VERSION 2.0 
                    DESCRIPTION "Some SSE Intrinsics"
                    LANGUAGES C)
                    
# Basic Includes
include( GNUInstallDirs)
include( CMakePackageConfigHelpers)

# Create xpath_reader_config_internal.h
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/libintrin_config_internal.h.cmake.in
			   ${CMAKE_CURRENT_BINARY_DIR}/include/libintrin_config_internal.h)

# Mark file for installation
install( FILES ${CMAKE_CURRENT_BINARY_DIR}/include/libintrin_config_internal.h DESTINATION include)
	
			   
add_subdirectory(lib)

# install the headers 
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
    	DESTINATION ${CMAKE_INSTALL_PREFIX}
    	FILES_MATCHING PATTERN "*.h")
    	
 # write the file exporting the targets
install(EXPORT libintrin
        FILE libintrin.cmake
        NAMESPACE libintrin::
        DESTINATION lib/cmake/libintrin
) 
 
# Create a Package Config file.
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/libintrinConfig.cmake"
  INSTALL_DESTINATION lib/cmake/libintrin
)

install(FILES
          "${CMAKE_CURRENT_BINARY_DIR}/libintrinConfig.cmake"
        DESTINATION lib/cmake/libintrin
) 
 
# generate the version file for the config file
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/libintrinConfigVersion.cmake"
  VERSION "${libintrin_VERSION_MAJOR}.${libintrin_VERSION_MINOR}"
  COMPATIBILITY AnyNewerVersion
)

# install it
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/libintrinConfigVersion.cmake
  DESTINATION lib/cmake/libintrin
)

# export package. Does nothing by default, but
# can have uses in specially set up configurations
export(PACKAGE libintrin)  
        