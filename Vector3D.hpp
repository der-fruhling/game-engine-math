#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

struct Vector3D {
    float x, y, z;

    Vector3D() = default;

    Vector3D(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    float& operator [](int i) {
        return ((&x)[i]);
    }
};

#endif