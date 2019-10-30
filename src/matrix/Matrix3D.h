//
// Created by liamcoal on 9/25/19.
//

#ifndef GAME_ENGINE_MATH_MATRIX3D_H
#define GAME_ENGINE_MATH_MATRIX3D_H


#include "../game_engine_math_decls.h"
#include "../vector/Vector3D.h"

namespace game_engine_math {
    struct Matrix3D {
    private:
        float n[3][3]{};
    public:
        Matrix3D() = default;

        Matrix3D(float n00, float n01, float n02,
                 float n10, float n11, float n12,
                 float n20, float n21, float n22) {
            n[0][0] = n00;
            n[0][1] = n01;
            n[0][2] = n02;
            n[1][0] = n10;
            n[1][1] = n11;
            n[1][2] = n12;
            n[2][0] = n20;
            n[2][1] = n21;
            n[2][2] = n22;
        }

        Matrix3D(const Vector3D &a, const Vector3D &b, const Vector3D &c) {
            n[0][0] = a.x;
            n[0][1] = a.y;
            n[0][2] = a.z;
            n[1][0] = b.x;
            n[1][1] = b.y;
            n[1][2] = b.z;
            n[2][0] = c.x;
            n[2][1] = c.y;
            n[2][2] = c.z;
        }

        float &operator()(int i, int j) {
            return n[j][i];
        }

        const float &operator()(int i, int j) const {
            return n[j][i];
        }

        Vector3D &operator[](int j) {
            return (*reinterpret_cast<Vector3D *>(n[j]));
        }

        const Vector3D &operator[](int j) const {
            return (*reinterpret_cast<const Vector3D *>(n[j]));
        }
    };

    Matrix3D operator*(const Matrix3D &A, const Matrix3D &B) {
        return {
                A(0, 0) * B(0, 0) + A(0, 1) * B(1, 0) + A(0, 2) * B(2, 0),
                A(0, 0) * B(0, 1) + A(0, 1) * B(1, 1) + A(0, 2) * B(2, 1),
                A(0, 0) * B(0, 2) + A(0, 1) * B(1, 2) + A(0, 2) * B(2, 2),
                A(1, 0) * B(0, 0) + A(1, 1) * B(1, 0) + A(1, 2) * B(2, 0),
                A(1, 0) * B(0, 1) + A(1, 1) * B(1, 1) + A(1, 2) * B(2, 1),
                A(1, 0) * B(0, 2) + A(1, 1) * B(1, 2) + A(1, 2) * B(2, 2),
                A(2, 0) * B(0, 0) + A(2, 1) * B(1, 0) + A(2, 2) * B(2, 0),
                A(2, 0) * B(0, 1) + A(2, 1) * B(1, 1) + A(2, 2) * B(2, 1),
                A(2, 0) * B(0, 2) + A(2, 1) * B(1, 2) + A(2, 2) * B(2, 2)
        };
    }

    Vector3D operator*(const Matrix3D &M, const Vector3D &v) {
        return {
                M(0, 0) * v.x + M(0, 1) * v.y + M(0, 2) * v.z,
                M(1, 0) * v.x + M(1, 1) * v.y + M(1, 2) * v.z,
                M(2, 0) * v.x + M(2, 1) * v.y + M(2, 2) * v.z,
        };
    }
}


#endif //GAME_ENGINE_MATH_MATRIX3D_H
