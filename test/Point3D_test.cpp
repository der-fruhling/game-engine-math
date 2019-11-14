#include <gtest/gtest.h>
#include "../src/point/Point3D.h"

using namespace game_engine_math;

TEST(Point3D, DistPointLine) {
    Point3D q (0, 10, 0), p (0, 0, 0);
    Vector3D v (5, 0, 0);
    float f = DistPointLine(q, p, v);
    ASSERT_FLOAT_EQ(f, 10.f);
}

TEST(Point3D, DistLineLine) {
    Point3D p1 (0, 0, 0), p2 (1, 0, 0);
    Vector3D v1 (1, 1, 0), v2 (1, 1, 0);
    float f = DistLineLine(p1, v1, p2, v2);
    ASSERT_FLOAT_EQ(f, std::sin(M_PI/4));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
