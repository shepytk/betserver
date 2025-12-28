cmake_minimum_required(VERSION 3.14)
project(betserver)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include FetchContent module for downloading dependencies
include(FetchContent)

# Fetch vix.cpp from GitHub
FetchContent_Declare(
    vix
    GIT_REPOSITORY https://github.com/vixcpp/vix.git
    GIT_TAG main
)

FetchContent_MakeAvailable(vix)

# Add executable
add_executable(betserver main.cpp)

# Link vix library
target_link_libraries(betserver PRIVATE vix)

# Set output directory
set_target_properties(betserver PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
