cmake_minimum_required(VERSION 3.0)
project(c_raylib_platformer C)
set(CMAKE_C_STANDARD 99)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

# -- raylib configuration
include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)
FetchContent_Declare(raylib GIT_REPOSITORY https://github.com/raysan5/raylib.git GIT_TAG master)
FetchContent_MakeAvailable(raylib)

# -- Include source files
set(SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/src")

# Grab all source files and put in PROJECT_SOURCES
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${SOURCE_DIR}/*.c")

# Define PROJECT_INCLUDE
set(PROJECT_INCLUDE "${SOURCE_DIR}/")

# Declaring our executable
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# -- Setting ASSETS_PATH

# Set the asset path macro to the absolute path on the dev machine
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_FOLDER_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")

# Set the asset path macro in release mode to a relative path that assumes the assets folder is in the same directory as the game executable
# target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_FOLDER_PATH="./assets") 
