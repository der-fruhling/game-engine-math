//
// Created by liam on 10/29/19.
//

#include "Transform4D.h"

game_engine_math::Transform4D::Transform4D(const Vector3D &a, const Vector3D &b, const Vector3D &c, const Point3D &p) {
    n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
    n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
    n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
    n[3][0] = p.x; n[3][1] = p.y; n[3][2] = p.z;

    n[0][3] = n[1][3] = n[2][3] = 0.0f;
    n[3][3] = 1.0f;
}

void game_engine_math::Transform4D::SetTranslation(const game_engine_math::Point3D &p) {
    n[3][0] = p.x;
    n[3][1] = p.y;
    n[3][2] = p.z;
}

game_engine_math::Transform4D game_engine_math::Inverse(const game_engine_math::Transform4D &H) {
    const Vector3D& a = H[0],
                    b = H[1],
                    c = H[2],
                    d = H[3];

    Vector3D s = CrossProduct(a, b),
             t = CrossProduct(c, d);

    float invDet = 1.0f / DotProduct(s, c);

    s *= invDet;
    t *= invDet;
    Vector3D v = c * invDet;

    Vector3D r0 = CrossProduct(b, v),
            r1 = CrossProduct(v, a);

    return {
            r0.x, r0.y, r0.z, -DotProduct(b, t),
            r1.x, r1.y, r1.z, -DotProduct(a, t),
            s.x,  s.y,  s.z, -DotProduct(d, s)
    };
}

game_engine_math::Transform4D
game_engine_math::operator*(const game_engine_math::Transform4D &A, const game_engine_math::Transform4D &B) {
    return {
            A(0,0) * B(0,0) + A(0,1) * B(1,0) + A(0,2) * B(2,0),
            A(0,0) * B(0,1) + A(0,1) * B(1,1) + A(0,2) * B(2,1),
            A(0,0) * B(0,2) + A(0,1) * B(1,2) + A(0,2) * B(2,2),
            A(0,0) * B(0,3) + A(0,1) * B(1,3) + A(0,2) * B(2,3) + A(0,3),
            A(1,0) * B(0,0) + A(1,1) * B(1,0) + A(1,2) * B(2,0),
            A(1,0) * B(0,1) + A(1,1) * B(1,1) + A(1,2) * B(2,1),
            A(1,0) * B(0,2) + A(1,1) * B(1,2) + A(1,2) * B(2,2),
            A(1,0) * B(0,3) + A(1,1) * B(1,3) + A(1,2) * B(2,3) + A(1,3),
            A(2,0) * B(0,0) + A(2,1) * B(1,0) + A(2,2) * B(2,0),
            A(2,0) * B(0,1) + A(2,1) * B(1,1) + A(2,2) * B(2,1),
            A(2,0) * B(0,2) + A(2,1) * B(1,2) + A(2,2) * B(2,2),
            A(2,0) * B(0,3) + A(2,1) * B(1,3) + A(2,2) * B(2,3) + A(2,3)
    };
}
