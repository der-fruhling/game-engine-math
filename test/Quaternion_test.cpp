#include "../src/vector/Quaternion.h"
#include <gtest/gtest.h>

using namespace game_engine_math;

#define ASSERT_QUATERNION_EQ(a, b) { \
    Quaternion q1_macro = a; \
    Quaternion q2_macro = b; \
    ASSERT_FLOAT_EQ(q1_macro.x, q2_macro.x); \
    ASSERT_FLOAT_EQ(q1_macro.y, q2_macro.y); \
    ASSERT_FLOAT_EQ(q1_macro.z, q2_macro.z); \
    ASSERT_FLOAT_EQ(q1_macro.w, q2_macro.w); \
}

TEST(Quaternion, MultiplyScalar) {
    Quaternion q1 = {1, 2, 3, 4},
               r  = {2, 4, 6, 8};
    float t = 2;
    ASSERT_QUATERNION_EQ(q1*t, r);
}

TEST(Quaternion, MultiplyQuaternions) {
    Quaternion q1 = {1,  2,  3,  4},
               q2 = {5,  6,  7,  8},
               r  = {24, 48, 48, -6};
    ASSERT_QUATERNION_EQ(q1*q2, r);
}

TEST(Quaternion, AddQuaternions) {
    Quaternion q1 = {1,  2,  3,  4},
               q2 = {5,  6,  7,  8},
               r  = {6,  8, 10, 12};
    ASSERT_QUATERNION_EQ(q1+q2, r);
}

TEST(Quaternion, DistributiveLaw) {
    Quaternion q1 = {1,  2,  3,  4},
               q2 = {5,  6,  7,  8},
               q3 = {9, 10, 11, 12};
    float t = 13,
          s = 14;
    ASSERT_QUATERNION_EQ((q1 + q2) * t, q1*t + q2*t);
    ASSERT_QUATERNION_EQ(q1*(s+t), q1*s + q1*t);
    ASSERT_QUATERNION_EQ(q1 * (q2 + q3), q1*q2 + q1*q3);
    ASSERT_QUATERNION_EQ((q1 + q2) * q3, q1*q3 + q2*q3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
