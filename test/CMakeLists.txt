cmake_minimum_required(VERSION 3.12)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
link_libraries(${GTEST_LIBRARIES} pthread)
add_executable(Vector3D_test Vector3D_test.cpp)
add_executable(Matrix3D_test Matrix3D_test.cpp)
add_executable(Quaternion_test Quaternion_test.cpp)
