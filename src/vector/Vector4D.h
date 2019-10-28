// TODO Make this better

#ifndef VECTOR4D_H
#define VECTOR4D_H

struct Vector4D {
    float x, y, z, w;

    float operator[](int t) {
        return ((&x)[t]);
    }
};

#endif
