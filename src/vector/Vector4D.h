// TODO Make this better

#ifndef VECTOR4D_H
#define VECTOR4D_H


#include "../game_engine_math_decls.h"

namespace game_engine_math {
    struct Vector4D {
        float x, y, z, w;

        float &operator[](int t) {
            return ((&x)[t]);
        }
    };
}

#endif
