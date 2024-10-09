cmake_minimum_required(VERSION 3.4...3.18)
project(rounder)

find_package(Python COMPONENTS Interpreter Development)
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(rounder driver.cpp)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ cxode as a
# define (VERSION_INFO) here.
target_compile_definitions(rounder
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})