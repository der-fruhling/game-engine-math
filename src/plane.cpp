//
// Created by liam on 11/13/19.
//

#include "plane.h"
#include "vector/Vector3D.h"
#include "point/Point3D.h"

namespace game_engine_math {
    Plane::Plane(const Vector3D &n, float d) {
        x = n.x;
        y = n.y;
        z = n.z;
        w = d;
    }

    const Vector3D &Plane::Normal() {
        return reinterpret_cast<const Vector3D &>(x);
    }

    float DotProduct(const Plane &f, const Vector3D &v) {
        return f.x * v.x + f.y * v.y + f.z * v.z;
    }

    float DotProduct(const Plane& f, const Point3D& p) {
        return f.x * p.x + f.y * p.y + f.z * p.z + f.w;
    }
}
