#include "VectorConv.h"

Vector2D v2d_v3d(Vector3D v) {
    return Vector2D(v.x, v.y);
}

Vector3D v3d_v2d(Vector2D v) {
    return Vector3D(v.x, v.y, 0);
}