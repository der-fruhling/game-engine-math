#ifndef TRANSFORM4D_H
#define TRANSFORM4D_H


#include "../game_engine_math_decls.h"
#include "Matrix4D.h"
#include "../vector/Vector3D.h"
#include "../point/Point3D.h"

namespace game_engine_math {
    struct Transform4D : Matrix4D {
        Transform4D() = default;
        Transform4D(float n00, float n01, float n02, float n03,
                    float n10, float n11, float n12, float n13,
                    float n20, float n21, float n22, float n23) : Matrix4D()
        {
            n[0][0] = n00; n[0][1] = n10; n[0][2] = n20;
            n[1][0] = n01; n[1][1] = n11; n[1][2] = n21;
            n[2][0] = n02; n[2][1] = n12; n[2][2] = n22;
            n[3][0] = n03; n[3][1] = n13; n[3][2] = n23;
    
            n[0][3] = n[1][3] = n[2][3] = 0.0f;
            n[3][3] = 1.0f;
        }

        Transform4D(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Point3D&  p);

        Vector3D& operator[](int j) {
            return *reinterpret_cast<Vector3D*>(n[j]);
        }

        const Vector3D& operator[](int j) const {
            return *reinterpret_cast<const Vector3D*>(n[j]);
        }

        void SetTranslation(const Point3D& p);
    };
    
    Transform4D Inverse(const Transform4D& H);

    Transform4D operator*(const Transform4D& A, const Transform4D& B);

    Vector3D operator*(const Transform4D& H, const Vector3D& v) {
        return {
            H(0,0) * v.x + H(0,1) * v.y + H(0,2) * v.z,
            H(1,0) * v.x + H(1,1) * v.y + H(1,2) * v.z,
            H(2,0) * v.x + H(2,1) * v.y + H(2,2) * v.z
        };
    }

    Point3D operator*(const Transform4D& H, const Point3D& v) {
        return {
            H(0,0) * v.x + H(0,1) * v.y + H(0,2) * v.z + H(0,3),
            H(1,0) * v.x + H(1,1) * v.y + H(1,2) * v.z + H(1,3),
            H(2,0) * v.x + H(2,1) * v.y + H(2,2) * v.z + H(2,3)
        };
    }
}

#endif
