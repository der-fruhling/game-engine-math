#include "../src/vector/Vector3D.hpp"
#include <gtest/gtest.h>

TEST(Vector3D, TryVector3D) {
    Vector3D a(1.5f, 3.7f, 32.25f);
    ASSERT_EQ(1.5f, a.x);
    ASSERT_EQ(3.7f, a.y);
    ASSERT_EQ(32.25f, a.z);
}

TEST(Vector3D, ScalarMultiplication) {
    Vector3D a(1.f, 1.f, 1.f);
    a *= 2.f;
    ASSERT_FLOAT_EQ(a.x, 2.f);
    ASSERT_FLOAT_EQ(a.y, 2.f);
    ASSERT_FLOAT_EQ(a.z, 2.f);
}

TEST(Vector3D, ScalarDivision) {
    Vector3D a(1.f, 1.f, 1.f);
    a /= 2.f;
    ASSERT_FLOAT_EQ(a.x, .5f);
    ASSERT_FLOAT_EQ(a.y, .5f);
    ASSERT_FLOAT_EQ(a.z, .5f);
}

TEST(Vector3D, VectorAdditionPlusEquals) {
    Vector3D a(1.f, 2.f, 3.f);
    a += a;
    ASSERT_FLOAT_EQ(a.x, 2.f);
    ASSERT_FLOAT_EQ(a.y, 4.f);
    ASSERT_FLOAT_EQ(a.z, 6.f);
    
}

TEST(Vector3D, VectorAddition) {
    Vector3D a(1.f, 2.f, 3.f);
    Vector3D b = a + a;
    ASSERT_FLOAT_EQ(b.x, 2.f);
    ASSERT_FLOAT_EQ(b.y, 4.f);
    ASSERT_FLOAT_EQ(b.z, 6.f);
}

TEST(Vector3D, ScalarMultiplicationStarEquals) {
    Vector3D a(1.f, 2.f, 3.f);
    a *= 2.f;
    ASSERT_FLOAT_EQ(a.x, 2.f);
    ASSERT_FLOAT_EQ(a.y, 4.f);
    ASSERT_FLOAT_EQ(a.z, 6.f);
}

TEST(Vector3D, VectorSubtractionMinusEquals) {
    Vector3D a(2.f, 3.f, 4.f);
    a -= Vector3D(1.f, 1.f, 1.f);
    ASSERT_FLOAT_EQ(a.x, 1.f);
    ASSERT_FLOAT_EQ(a.y, 2.f);
    ASSERT_FLOAT_EQ(a.z, 3.f);
    
}

TEST(Vector3D, VectorSubtraction) {
    Vector3D a(2.f, 3.f, 4.f);
    Vector3D b = a - Vector3D(1.f, 1.f, 1.f);
    ASSERT_FLOAT_EQ(b.x, 1.f);
    ASSERT_FLOAT_EQ(b.y, 2.f);
    ASSERT_FLOAT_EQ(b.z, 3.f);
}

TEST(Vector3D, ScalarDivisionSlashEquals) {
    Vector3D a(2.f, 4.f, 6.f);
    a /= 2.f;
    ASSERT_FLOAT_EQ(a.x, 1.f);
    ASSERT_FLOAT_EQ(a.y, 2.f);
    ASSERT_FLOAT_EQ(a.z, 3.f);
}

TEST(Vector3D, VectorMagnitude) {
    Vector3D a(1.f, 2.f, 3.f);
    float b = Magnitude(a);
    ASSERT_FLOAT_EQ(ceil(b), 4.f);
}

TEST(Vector3D, VectorNormalize) {
    Vector3D a(1.f, 2.f, 3.f);
    Vector3D b = Normalize(a);
    ASSERT_FLOAT_EQ(b.x, 0.26726124f);
    ASSERT_FLOAT_EQ(b.y, 0.53452248f);
    ASSERT_FLOAT_EQ(b.z, 0.80178373f);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
