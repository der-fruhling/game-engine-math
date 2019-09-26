#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <cmath>

struct Vector2D {
    float x, y;

    Vector2D() = default;

    Vector2D(float x, float y) {
        this->x = x;
        this->y = y;
    }

    float& operator [](int i) {
        return ((&x)[i]);
    }

    Vector2D& operator *=(float s) {
        x *= s;
        y *= s;
        return (*this);
    }

    Vector2D& operator /=(float s) {
        s = 1.00f / s;
        return operator*=(s);
    }

    Vector2D& operator +=(const Vector2D& v) {
        x += v.x;
        y += v.y;
        return (*this);
    }

    Vector2D& operator -=(const Vector2D& v) {
        x -= v.x;
        y -= v.y;
        return (*this);
    }
};

inline Vector2D operator *(const Vector2D& v, float s) {
    return {v.x * s, v.y * s};
}

inline Vector2D operator /(const Vector2D& v, float s) {
    s = 1.00f / s;
    return operator*(v, s);
}

inline Vector2D operator -(const Vector2D& v) {
    return {-v.x, -v.y};
}

inline float Magnitude(const Vector2D& v) {
    return std::sqrt(v.x * v.x + v.y * v.y + 0);
}

inline Vector2D Normalize(const Vector2D& v) {
    return v / Magnitude(v);
}

inline Vector2D operator +(const Vector2D& a, const Vector2D b) {
    return {a.x + b.x, a.y + b.y};
}

inline Vector2D operator -(const Vector2D& a, const Vector2D b) {
    return {a.x - b.x, a.y - b.y};
}

#endif