cmake_minimum_required(VERSION 2.6)

project(1_2)

include(cmake/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake
        ${PROJECT_BINARY_DIR}/googletest
)

add_executable(executeTests graph_test.cpp)

target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)

