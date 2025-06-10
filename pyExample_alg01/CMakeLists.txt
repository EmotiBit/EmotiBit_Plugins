# TODO: move this inside of the pyExample_alg01 folder, and follow a similar approach to the ofExample CMakeLists.txt file of doing so

cmake_minimum_required(VERSION 3.4...3.18)
project(rounder)

set(pybind11_DIR "${CMAKE_CURRENT_SOURCE_DIR}\\..\\py_envs\\emotibit_plugins\\Lib\\site-packages\\pybind11\\share\\cmake\\pybind11")

find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

set(SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/../src/alg01.cpp")

pybind11_add_module(rounder ${SOURCES})

target_compile_definitions(rounder PRIVATE PYBIND11_ENABLED)
