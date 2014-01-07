cmake_minimum_required(VERSION 2.8)

project (DLLAPIMEAL)
set(CMAKE_BUILD_TYPE Release)

add_definitions(-DDLLApimeal)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
add_library(DLLAPIMEAL SHARED CgiModule.cpp)