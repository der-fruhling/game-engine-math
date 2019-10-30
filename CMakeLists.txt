cmake_minimum_required(VERSION 3.12)
project(game_engine_math)

add_compile_options(-Wall)

set(SOURCE_FILES src/vector/Vector3D.h src/vector/Vector2D.cpp src/vector/Vector2D.h src/vector/Vector4D.h src/vector/VectorConv.cpp src/vector/VectorConv.h src/matrix/Matrix3D.cpp src/matrix/Matrix3D.h src/vector/Quaternion.h src/vector/Quaternion.cpp src/matrix/Matrix4D.h src/matrix/Transform4D.h src/point/Point3D.h src/point/Point3D.cpp src/game_engine_math.h src/matrix/Transform4D.cpp src/vector/Vector3D.cpp src/game_engine_math_decls.h)

add_executable(game_engine_math src/main.cpp)
add_library(game_engine_math_lib STATIC ${SOURCE_FILES})
add_subdirectory(test)
add_dependencies(game_engine_math game_engine_math_lib)
target_link_libraries(game_engine_math game_engine_math_lib)
