cmake_minimum_required(VERSION 2.6)

add_definitions(-Wall -std=c++0x -D HOME)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(executeTests graph_test.cpp)

target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)
