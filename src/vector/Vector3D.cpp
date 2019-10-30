//
// Created by liam on 10/29/19.
//

#include "Vector3D.h"
#include "../matrix/Transform4D.h"

namespace game_engine_math {
    Vector3D operator*(const Vector3D &n, const Transform4D &H) {
        return {
                n.x * H(0, 0) + n.y * H(1, 0) + n.z * H(2, 0),
                n.x * H(0, 1) + n.y * H(1, 1) + n.z * H(2, 1),
                n.x * H(0, 2) + n.y * H(1, 2) + n.z * H(2, 2)
        };
    }
}