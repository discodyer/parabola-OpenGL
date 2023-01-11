cmake_minimum_required( VERSION 3.1 )

project( Parabola-OpenGL )

if(MSVC)
    list(APPEND CMAKE_PREFIX_PATH "C:/Program Files (x86)/GLFW/lib/cmake/glfw3")
else()
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake/glfw3")
endif()

# list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake/glfw3")

find_package(glfw3 3.3 REQUIRED)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")

set( Parabola-OpenGL-SRC
    src/main.cpp
    src/glad.c
    )

add_executable( Parabola-OpenGL WIN32 ${Parabola-OpenGL-SRC} )

target_link_libraries(Parabola-OpenGL ${OPENGL_LIBRARIES} glfw)

if( MSVC )
    if(${CMAKE_VERSION} VERSION_LESS "3.6.0") 
        message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'GLFW-CMake-starter' as StartUp Project in Visual Studio.\n" )
    else()
        set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Parabola-OpenGL )
    endif()
endif()