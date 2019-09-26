//
// Created by liamcoal on 9/25/19.
//

#include <gtest/gtest.h>
#include "../src/matrix/Matrix3D.h"

TEST(Matrix3D, Vector3DAccess) {
    Matrix3D m3d;
    m3d[1][1] = 5.f;
    ASSERT_FLOAT_EQ(m3d[1][1], 5.f);
}

TEST(Matrix3D, ParenthesesAccess) {
    Matrix3D m3d;
    m3d(1, 1) = 5.f;
    ASSERT_FLOAT_EQ(m3d(1, 1), 5.f);
}

TEST(Matrix3D, MultiplyByMatrix3D) {

    Matrix3D A(1, 2, 3, 4, 5, 6, 7, 8, 9);
    Matrix3D B(1, 2, 3, 3, 2, 1, 1, 3, 2);
    Matrix3D r = A * B;

    ASSERT_FLOAT_EQ(r(0, 0), 30);
    ASSERT_FLOAT_EQ(r(0, 1), 36);
    ASSERT_FLOAT_EQ(r(0, 2), 42);
    ASSERT_FLOAT_EQ(r(1, 0), 18);
    ASSERT_FLOAT_EQ(r(1, 1), 24);
    ASSERT_FLOAT_EQ(r(1, 2), 30);
    ASSERT_FLOAT_EQ(r(2, 0), 27);
    ASSERT_FLOAT_EQ(r(2, 1), 33);
    ASSERT_FLOAT_EQ(r(2, 2), 39);
}

TEST(Matrix3D, MultiplyByVector3D) {
    Matrix3D M(1, 2, 3, 4, 5, 6, 7, 8, 9);
    Vector3D v(10, 11, 12);
    Vector3D r = M * v;

    ASSERT_FLOAT_EQ(r.x, 138);
    ASSERT_FLOAT_EQ(r.y, 171);
    ASSERT_FLOAT_EQ(r.z, 204);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}