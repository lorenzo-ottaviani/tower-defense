cmake_minimum_required(VERSION 3.22)
project(SeaVsHumans)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SFML
find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)

# Include directories for SFML
include_directories(${SFML_INCLUDE_DIRS})

# Source files
set(SOURCES
    src/main.cpp
    src/MainMenu.cpp
    src/Screen.cpp
    src/ScreenManager.cpp
)

# Create the executable
add_executable(SeaVsHumans ${SOURCES})

# Link SFML libraries
target_link_libraries(SeaVsHumans sfml-graphics sfml-window sfml-system)

# Optional, set the output directory for the executable
set_target_properties(SeaVsHumans PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
