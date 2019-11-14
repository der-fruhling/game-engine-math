//
// Created by liam on 11/13/19.
//

#ifndef GAME_ENGINE_MATH_PLANE_H
#define GAME_ENGINE_MATH_PLANE_H


#include "game_engine_math_decls.h"

namespace game_engine_math {
    struct Plane {
        float x, y, z, w;

        Plane() = default;

        Plane(float nx, float ny, float nz, float d) {
            x = nx;
            y = ny;
            z = nz;
            w = d;
        }

        Plane(const Vector3D& n, float d);
        const Vector3D& Normal();
    };

    float DotProduct(const Plane& f, const Vector3D& v);
    float DotProduct(const Plane& f, const Point3D& p);
}


#endif //GAME_ENGINE_MATH_PLANE_H
