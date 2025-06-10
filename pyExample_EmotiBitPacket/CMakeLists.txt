# TODO: move this inside of the pyExample_alg01 folder, and follow a similar approach to the ofExample CMakeLists.txt file of doing so

cmake_minimum_required(VERSION 3.4...3.18)
project(EmotiBitPacket)

# See pybind11Config.cmake, instructions for pybind11_DIR
# According to CMake convention, find_package searches in path set in the <package_name>_DIR variable

set(pybind11_DIR "${CMAKE_CURRENT_SOURCE_DIR}\\..\\py_envs\\emotibit_plugins\\Lib\\site-packages\\pybind11\\share\\cmake\\pybind11")

find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

set(SOURCES src/EmotiBitPacket.cpp)

# CMake function is a convenience helper provided by the Pybind11 project
pybind11_add_module(EmotiBitPacket ${SOURCES})

# for the pre-processor gaurd around pybind11 definitions in cpp file
target_compile_definitions(EmotiBitPacket PRIVATE PYBIND11_ENABLED)