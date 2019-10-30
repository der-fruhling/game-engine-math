#ifndef POINT3D_H
#define POINT3D_H

#include "../game_engine_math_decls.h"
#include "../vector/Vector3D.h"

namespace game_engine_math {
    struct Point3D : public Vector3D {
        Point3D() = default;

        Point3D(float a, float b, float c) : Vector3D(a, b, c) {}
    };

    inline Point3D operator+(const Point3D &a, const Vector3D &b) {
        return {
                a.x + b.x, a.y + b.y, a.z + b.z
        };
    }

    inline Point3D operator-(const Point3D &a, const Vector3D &b) {
        return {
                a.x - b.x, a.y - b.y, a.z - b.z
        };
    }
}

#endif

