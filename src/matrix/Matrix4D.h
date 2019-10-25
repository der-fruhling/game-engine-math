// TODO Make this better

#ifndef MATRIX4D_H
#define MATRIX4D_H

#include "../vector/Vector4D.h"

struct Matrix4D {
    Vector4D n[4];

    float operator[](int x) {
        return n[x];
    }

    float operator()(int x, int y) {
        return n[y][x];
    }
}
