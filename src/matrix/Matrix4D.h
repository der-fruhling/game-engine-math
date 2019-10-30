// TODO Make this better

#ifndef MATRIX4D_H
#define MATRIX4D_H

#include "../game_engine_math_decls.h"
#include "../vector/Vector4D.h"

namespace game_engine_math {
    struct Matrix4D {
        float n[4][4];

        Vector4D& operator[](int x) {
            return *reinterpret_cast<Vector4D *>(n[x]);
        }

        const Vector4D& operator[](int x) const {
            return *reinterpret_cast<const Vector4D *>(n[x]);
        }

        float& operator()(int x, int y) {
            return n[y][x];
        }

        const float& operator()(int x, int y) const {
            return n[y][x];
        }
    };
}

#endif
