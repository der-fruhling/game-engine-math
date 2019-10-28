#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3D.h"
#include "../matrix/Matrix3D.h"
#include <cmath>

namespace game_engine_math {
    struct Quaternion;

    inline Quaternion operator/(const Quaternion& q, float f);

    struct Quaternion {
        float x, y, z, w;

        Quaternion() = default;

        Quaternion(float a, float b, float c, float s) {
            x = a; y = b; z = c;
            w = s;
        }

        Quaternion(const Vector3D &v, float s) {
            x = v.x; y = v.y; z = v.z;
            w = s;
        }

        const Vector3D& GetVectorPart() const {
            static const Vector3D& v = {x, y, z};
            return v;
        }

        Matrix3D GetRotationMatrix();
        void SetRotationMatrix(const Matrix3D &m);

        inline Quaternion conjugate() {
            return {-x, -y, -z, w};
        }

        inline Quaternion operator*(float f) {
            return {x*f, y*f, z*f, w*f};
        }

        inline Quaternion inverse() {
            return conjugate() / square();
        }

        inline Quaternion normalize() {
            return *this / magnitude();
        }

        inline float square() {
            return Square(GetVectorPart()) + w * w;
        }

        inline float magnitude() {
            return std::sqrt(square());
        }
    };

    Quaternion operator*(const Quaternion& q1, const Quaternion& q2) {
        return {
            q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
            q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x,
            q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w,
            q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z
        };
    }

    Vector3D Transform(const Vector3D& v, const Quaternion& q) {
        const Vector3D& b = q.GetVectorPart();
        float b2 = b.x * b.x + b.y * b.y + b.z * b.z;
        return v * (q.w * q.w - b2) + b * (DotProduct(v, b) * 2.0f) + CrossProduct(b, v) * (q.w * 2.0f);
    }

    inline Quaternion operator+(const Quaternion& q1, const Quaternion& q2) {
        return {q1.x+q2.x, q1.y+q2.y, q1.z+q2.z, q1.w+q2.w};
    }

    inline bool operator==(const Quaternion& q1, const Quaternion& q2) {
        return q1.x >= q2.x-0.125f &&
               q1.x <= q2.x+0.125f &&
               q1.y >= q2.y-0.125f &&
               q1.y <= q2.y+0.125f &&
               q1.z >= q2.z-0.125f &&
               q1.z <= q2.z+0.125f &&
               q1.w >= q2.w-0.125f &&
               q1.w <= q2.w+0.125f ;
    }

    inline Quaternion operator/(const Quaternion& q, float f) {
        return {q.x/f, q.y/f, q.z/f, q.w/f};
    }
}

#endif
