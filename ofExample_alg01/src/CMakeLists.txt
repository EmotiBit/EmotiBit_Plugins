cmake_minimum_required(VERSION 3.4...3.18)
project(rounder)

# Find source files using relative path
set(SRC_DIR ${CMAKE_SOURCE_DIR}/../../src)
set(SOURCES ${SRC_DIR}/alg01.cpp)

# Create the shared library
add_library(rounder SHARED ${SOURCES})

set_target_properties(rounder PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES)

# Add the driver exe from the src/ foulder
add_executable(rounder_test ${SRC_DIR}/driver.cpp)

# Link the driver exe to the rounder shared library and includes the header file location
target_link_libraries(rounder_test PRIVATE rounder)
target_include_directories(rounder_test PRIVATE ${SRC_DIR})