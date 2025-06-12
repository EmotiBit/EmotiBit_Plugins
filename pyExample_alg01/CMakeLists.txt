# TODO: move this inside of the pyExample_alg01 folder, and follow a similar approach to the ofExample CMakeLists.txt file of doing so

cmake_minimum_required(VERSION 3.4...3.18)
project(rounder)

set(pybind11_DIR "${CMAKE_CURRENT_SOURCE_DIR}\\..\\py_envs\\emotibit_plugins\\Lib\\site-packages\\pybind11\\share\\cmake\\pybind11")

find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

# Add your C++ library source file
add_library(alg01 STATIC "${CMAKE_CURRENT_SOURCE_DIR}/../src/alg01.cpp")
target_include_directories(alg01 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../src/") # Include its own header

pybind11_add_module(rounder bindings_alg01.cpp)

# Link your pybind11 module to your C++ library
target_link_libraries(rounder PRIVATE alg01)
target_include_directories(rounder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../src/")