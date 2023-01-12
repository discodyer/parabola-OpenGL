cmake_minimum_required( VERSION 3.1 )

project( Parabola-OpenGL )

# if(MSVC)
#     list(APPEND CMAKE_PREFIX_PATH "C:/Program Files (x86)/GLFW/lib/cmake/glfw3")
# else()
#     list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake/glfw3")
# endif()

if (CMAKE_COMPILER_IS_GNUCC)
    execute_process(COMMAND ${CMAKE_C_COMPILER} -dumpmachine OUTPUT_VARIABLE GCC_TARGET)
    if(GCC_TARGET MATCHES "i686-w64-mingw32" )
        list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/i686/lib/cmake/glfw3")
    elseif(GCC_TARGET MATCHES "x86_64-w64-mingw32" )
        list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake/glfw3")
    endif()
    # list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake/glfw3")
    # endif()
endif()

find_package(glfw3 3.3 REQUIRED)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib/stb/")


set( Parabola-OpenGL-SRC
    src/main.cpp
    src/glad.c
    src/shader.cpp
    src/texture.cpp
    )

add_executable( Parabola-OpenGL WIN32 ${Parabola-OpenGL-SRC} )

target_link_libraries(Parabola-OpenGL ${OPENGL_LIBRARIES} glfw)

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb -static")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -static")

if( MSVC )
    if(${CMAKE_VERSION} VERSION_LESS "3.6.0") 
        message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'GLFW-CMake-starter' as StartUp Project in Visual Studio.\n" )
    else()
        set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Parabola-OpenGL )
    endif()
endif()