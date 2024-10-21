cmake_minimum_required(VERSION 3.4...3.18)

project(rounder)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/../../src)
set(SOURCES ${SRC_DIR}/alg01.cpp)

add_library(rounder SHARED ${SOURCES})

set_target_properties(rounder PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES)

add_executable(rounder_test ${SRC_DIR}/driver.cpp)

target_link_libraries(rounder_test PRIVATE rounder)
target_include_directories(rounder_test PRIVATE ${SRC_DIR})
