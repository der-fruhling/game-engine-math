#ifndef VECTOR_CONV_HPP
#define VECTOR_CONV_HPP

#include "Vector2D.h"
#include "Vector3D.h"

namespace game_engine_math {
    extern Vector2D v2d_v3d(Vector3D);
    extern Vector3D v3d_v2d(Vector2D);
}
#endif