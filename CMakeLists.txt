cmake_minimum_required(VERSION 3.13)

add_executable(game_engine_math 
    src/main.cpp 
    src/vector/Vector3D.cpp
        src/vector/Vector3D.h
    src/vector/Vector2D.cpp
        src/vector/Vector2D.h
    src/vector/VectorConv.cpp
        src/vector/VectorConv.h
        src/matrix/Matrix3D.cpp src/matrix/Matrix3D.h)
add_library(game_engine_math_lib SHARED
    src/vector/Vector3D.cpp
        src/vector/Vector3D.h
    src/vector/Vector2D.cpp
        src/vector/Vector2D.h
    src/vector/VectorConv.cpp
        src/vector/VectorConv.h
        src/matrix/Matrix3D.cpp src/matrix/Matrix3D.h)
add_subdirectory(test)

install(TARGETS game_engine_math_lib
        LIBRARY
          DESTINATION /usr/lib
          COMPONENT Libraries
          NAMELINK_COMPONENT Development
        PUBLIC_HEADER
          DESTINATION /usr/include
          COMPONENT Development
)
    
install(TARGETS game_engine_math
       RUNTIME
         DESTINATION /usr/bin
         COMPONENT Executables
         PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ
       PUBLIC_HEADER
         DESTINATION /usr/include
         COMPONENT Development
)

install(FILES src/game_engine_math.h DESTINATION /usr/include/game_engine_math)
install(FILES src/vector/Vector3D.h DESTINATION /usr/include/game_engine_math/vector)