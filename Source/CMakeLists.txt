cmake_minimum_required (VERSION 3.0)

set (PROJECT_NAME raytracer)
set (BINARY_NAME  ${PROJECT_NAME}-bin)

project (${PROJECT_NAME})

include_directories(../3rdParty/glm-0.9.7.5)
include_directories(../3rdParty/lodepng)
include_directories(../3rdParty/tinyxml2)

add_subdirectory(../3rdParty/lodepng ${CMAKE_BINARY_DIR}/lodepng)
add_subdirectory(../3rdParty/tinyxml2 ${CMAKE_BINARY_DIR}/tinyxml2)

CONFIGURE_FILE(../Assets/Config/SystemConfig.xml ./Assets/Config/SystemConfig.xml COPYONLY)

set ( HDR
	Common.hpp
	Raytracer.hpp
	2D/ImagePNG.hpp
	System/SystemConfig.hpp
	Debugging/Log.hpp
	Debugging/LogDefault.hpp
	ResourceCache/IOManager.hpp
	ResourceCache/IOManagerDefault.hpp
	Utility/String.hpp
    )

set ( SRC
        main.cpp
	2D/ImagePNG.cpp
	System/SystemConfig.cpp
	Debugging/Log.cpp
	Debugging/LogDefault.cpp
	ResourceCache/IOManagerDefault.cpp
	Utility/String.cpp
    )
	
# Executable
add_executable(${BINARY_NAME}
                ${HDR} 
                ${SRC} 
            )


target_link_libraries(${BINARY_NAME} 
                            lodepng
                            tinyxml2)

