cmake_minimum_required(VERSION 3.13)

add_executable(game_engine_math src/main.cpp src/vector/Vector3D.cpp)
add_subdirectory(test)

install(PROGRAMS game_engine_math DESTINATION /usr/bin/game_engine_math)