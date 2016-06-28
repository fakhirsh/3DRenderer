cmake_minimum_required(VERSION 2.8)

# Set include directories
#include_directories(../zlib-1.2.8)

# Add library subdirectories
#add_subdirectory(../zlib-1.2.8 ${CMAKE_BINARY_DIR}/libz)

ADD_LIBRARY(lodepng STATIC
		lodepng.cpp
		#lodepng_util.cpp
		#pngdetail.cpp
	)

target_link_libraries( lodepng 
			#z
			  )