cmake_minimum_required(VERSION 3.4...3.18)
project(rounder)

find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

set(SOURCES alg01.cpp)

pybind11_add_module(rounder ${SOURCES})

target_compile_definitions(rounder PRIVATE PYBIND11_ENABLED)

target_compile_definitions(rounder PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
