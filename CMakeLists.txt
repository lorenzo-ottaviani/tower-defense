cmake_minimum_required(VERSION 3.15)
project(tower_defense CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the compiler for Windows MSYS2
if (WIN32)
    set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")
endif()

# Add G++-specific compilation options
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)
endif()

# === SFML 2.6.2 ===
if (WIN32)
    set(SFML_INCLUDE_DIR "C:/msys64/SFML-2.6.2/include")
    set(SFML_LIBRARY_DIR "C:/msys64/SFML-2.6.2/lib")
    include_directories(${SFML_INCLUDE_DIR})
    link_directories(${SFML_LIBRARY_DIR})

endif()

# === Program ===
file(GLOB SOURCES "src/models/*.cpp" "src/*.cpp")
add_executable(tower_defense ${SOURCES})
include_directories(include)

if(WIN32)
    target_link_libraries(tower_defense PRIVATE
            gdi32
            opengl32
            winmm
            sfml-graphics
            sfml-window
            sfml-system
            sfml-network
            sfml-audio
    )
endif()

# Enable detailed build output
set(CMAKE_VERBOSE_MAKEFILE ON)
