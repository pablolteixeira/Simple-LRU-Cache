# Specify the minimum version of CMake required to build the project
cmake_minimum_required(VERSION 3.10)

# Define the project name and the programming language used
project(SimpleLRUCache)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add the executable target
add_executable(simple_lru_cache ${SOURCES})