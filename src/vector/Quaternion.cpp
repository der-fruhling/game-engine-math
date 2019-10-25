#include "Quaternion.h"
#include <cmath>

namespace game_engine_math {
    Matrix3D Quaternion::GetRotationMatrix() {
        float x2 = x * x,
              y2 = y * y,
              z2 = z * z,
              xy = x * y,
              xz = x * z,
              yz = y * z,
              wx = w * x,
              wy = w * y,
              wz = w * z;

        return {
            1.0f - 2.0f * (y2 + z2), 2.0f * (xy - wz), 2.0f * (xz + wy),
            2.0f * (xy + wz), 1.0f - 2.0f * (x2 + z2), 2.0f * (yz - wx),
            2.0f * (xz - wy), 2.0f * (yz + wx), 1.0f - 2.0f * (x2 + y2)
        };
    }

    void Quaternion::SetRotationMatrix(const Matrix3D& m) {
        float m00 = m(0,0);
        float m11 = m(1,1);
        float m22 = m(2,2);
        float sum = m00 + m11 + m22;

        if(sum > 0.0f) {
            w = sqrt(sum + 1.0f) * 0.5f;
            float f = 0.25f / w;
            x = (m(2,1) - m(1,2)) * f;
            y = (m(0,1) - m(2,0)) * f;
            z = (m(1,0) - m(0,1)) * f;
        } else if((m00 > m11) && (m00 > m22)) {
            x = sqrt(m00 - m11 - m22 + 1.0f) * 0.5f;
            float f = 0.25f / x;
            y = (m(2,1) + m(1,2)) * f;
            z = (m(0,2) + m(2,0)) * f;
            w = (m(2,1) - m(1,2)) * f;
        } else if(m11 > m22) {
            y = sqrt(m11 - m00 - m22 + 1.0f) * 0.5f;
            float f = 0.25f / y;
            x = (m(1,0) + m(0,1)) * f;
            z = (m(2,1) + m(1,2)) * f;
            w = (m(0,2) - m(2,0)) * f;
        } else {
            z = sqrt(m22 - m00 - m11 + 1.0f) * 0.5f;
            float f = 0.25f / z;
            x = (m(0,2) + m(2,0)) * f;
            y = (m(2,1) + m(1,2)) * f;
            w = (m(1,0) - m(0,1)) * f;
        }
    }
}
