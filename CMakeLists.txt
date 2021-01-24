cmake_minimum_required(VERSION 3.15)
project(libintrin VERSION 2.0 
                    DESCRIPTION "Some SSE Intrinsics"
                    LANGUAGES C)
                    
# Basic Includes
include( GNUInstallDirs)
include( CMakePackageConfigHelpers)

add_subdirectory(lib)

# install the headers 
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
    	DESTINATION include)
    	
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
         