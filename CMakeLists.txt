cmake_minimum_required(VERSION 3.17)
project(LibIntrin VERSION 2.0 
                    DESCRIPTION "Some SSE Intrinsics"
                    LANGUAGES C)
                    
# Basic Includes
include( GNUInstallDirs)
include( CMakePackageConfigHelpers)

# Enable Address address and undefined behaviour sanitizers
option(LibIntrin_ENABLE_SANITIZERS "Enable Address and Undefined Behaviour Sanitizers" OFF)

# Create xpath_reader_config_internal.h
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/libintrin_config_internal.h.cmake.in
	       ${CMAKE_CURRENT_BINARY_DIR}/include/libintrin_config_internal.h)

# Mark file for installation
install( FILES ${CMAKE_CURRENT_BINARY_DIR}/include/libintrin_config_internal.h DESTINATION include)
	
# Deal with Sanitizer
if( LibIntrin_ENABLE_SANITIZERS )
  if( ( CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 3.1)
     OR ( CMAKE_CXX_COMPILER_ID MATCHES "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 4.8) )
      message(STATUS "LibIntrin: Setting Sanitizer options")
      set(LibIntrin_SANITIZER_OPTS "-fsanitize=address,undefined")
  else()
    message(STATUS "Don't know how to enable sanitizers for ${CMAKE_CXX_COMPILER_ID}... Ignoring")
  endif()
endif()    
add_subdirectory(lib)

# install the headers 
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
    	DESTINATION .
    	FILES_MATCHING PATTERN "*.h")
    	
 # write the file exporting the targets

# Create a Package Config file.
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/LibIntrinConfig.cmake"
  INSTALL_DESTINATION lib/cmake/LibIntrin
)

# generate the version file for the config file
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/LibIntrinConfigVersion.cmake"
  VERSION "${LibIntrin_VERSION_MAJOR}.${LibIntrin_VERSION_MINOR}"
  COMPATIBILITY AnyNewerVersion
)

# install it
install(FILES
          "${CMAKE_CURRENT_BINARY_DIR}/LibIntrinConfig.cmake"
           ${CMAKE_CURRENT_BINARY_DIR}/LibIntrinConfigVersion.cmake
        DESTINATION 
           lib/cmake/LibIntrin
)

# export package. Does nothing by default, but
# can have uses in specially set up configurations
export(PACKAGE libintrin)  
        
