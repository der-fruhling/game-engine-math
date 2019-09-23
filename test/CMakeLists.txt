cmake_minimum_required(VERSION 3.13)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(Vector3D_test Vector3D_test.cpp)
target_link_libraries(Vector3D_test ${GTEST_LIBRARIES} pthread)
