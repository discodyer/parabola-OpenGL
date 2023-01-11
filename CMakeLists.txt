cmake_minimum_required( VERSION 3.1 )

project( Parabola-OpenGL )

list(APPEND CMAKE_PREFIX_PATH "C:/OpenGL/")

find_package(glfw3 3.3 REQUIRED)

set( Parabola-OpenGL-SRC
     main.cpp
     glad.c
     )

add_executable( Parabola-OpenGL WIN32 ${Parabola-OpenGL-SRC} )

target_link_libraries(Parabola-OpenGL ${OPENGL_LIBRARIES} glfw)

if( MSVC )
    if(${CMAKE_VERSION} VERSION_LESS "3.6.0") 
        message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'GLFW-CMake-starter' as StartUp Project in Visual Studio.\n" )
    else()
        set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT GLFW-CMake-starter )
    endif()
endif()