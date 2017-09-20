PROJECT(test)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#SET(CMAKE_CXX_COMPILER "g++")

add_definitions(-Wall -std=c++11)

#AUX_SOURCE_DIRECTORY(src/ DIR_SRCS)

#set(DIR_SRCS src/)

#link_directories(${HELLO_BINARY_DIR}/.)

#include_directories("${DIR_SRCS}")

add_executable( ${PROJECT_NAME} test.cpp skiplist.hpp )

