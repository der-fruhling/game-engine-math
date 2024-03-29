#include "../src/vector/Vector3D.h"
#include <gtest/gtest.h>

using namespace game_engine_math;

#define ASSERT_VECTOR3D_EQ(vec, exx, exy, exz) \
do { \
    Vector3D res = vec; \
    ASSERT_FLOAT_EQ(res.x, exx); \
    ASSERT_FLOAT_EQ(res.y, exy); \
    ASSERT_FLOAT_EQ(res.z, exz); \
} while(0)

#define ASSERT_VECTOR3D_D_EQ(vec1, vec2) ASSERT_VECTOR3D_EQ(vec1, vec2.x, vec2.y, vec2.z)

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

TEST(Vector3D, VectorMultiplication) {
    Vector3D a(1.f, 2.f, 3.f);
    Vector3D b(4.f, 5.f, 6.f);
    Vector3D r = a * b;
    ASSERT_VECTOR3D_EQ(r, 4.f, 10.f, 18.f);
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

TEST(Vector3D, DotProductOrthogonal) {
    Vector3D v1(0, 1, 0);
    Vector3D v2(1, 0, 0);
    ASSERT_FLOAT_EQ(DotProduct(v1, v2), 0.f);
    ASSERT_FLOAT_EQ(DotProduct(v2, v1), 0.f);
}

TEST(Vector3D, DotProductParallel) {
    Vector3D v1(3, 0, 0);
    Vector3D v2(-5, 0, 0);
    /**
     * this is fine because they return floats
     */
    ASSERT_FLOAT_EQ(DotProduct(v1, v1), 9.f);
    ASSERT_FLOAT_EQ(DotProduct(v2, v2), 25.f);
    ASSERT_FLOAT_EQ(DotProduct(v1, v2), -15.f);
}

TEST(Vector3D, CrossProduct) {
    Vector3D v1(3, 4, 5);
    Vector3D v2(2, 1, 7);
    Vector3D result = CrossProduct(v1, v2);
    ASSERT_VECTOR3D_EQ(result, 23, -11, -5);
}

TEST(Vector3D, CrossProductParallel) {
    Vector3D v1(3, 0, 0);
    Vector3D v2(-5, 0, 0);
    ASSERT_VECTOR3D_EQ(CrossProduct(v1, v1), 0, 0, 0);
    ASSERT_VECTOR3D_EQ(CrossProduct(v2, v2), 0, 0, 0);
    ASSERT_VECTOR3D_EQ(CrossProduct(v1, v2), 0, 0, 0);
}

TEST(Vector3D, CrossProductAntiCommutativity) {
    Vector3D a(1, 2, 3);
    Vector3D b(4, 5, 6);
    ASSERT_VECTOR3D_D_EQ(CrossProduct(a, b), CrossProduct(-b, a));
}

TEST(Vector3D, CrossProductDistributiveLaw) { // it's the law
    Vector3D a(1, 2, 3);
    Vector3D b(4, 5, 6);
    Vector3D c(7, 8, 9);

    Vector3D r1 = CrossProduct(a, b + c),
             r2 = CrossProduct(a, b) + CrossProduct(a, c);

    ASSERT_VECTOR3D_D_EQ(r1, r2);
}

TEST(Vector3D, CrossProductScalarFactorization) {
    Vector3D a(1, 2, 3);
    Vector3D b(4, 5, 6);
    float t = 7.f;

    Vector3D r1 = CrossProduct(a * t, b),
            r2 = CrossProduct(a, b * t),
            r3 = CrossProduct(a, b) * t;

    ASSERT_VECTOR3D_D_EQ(r1, r2);
    ASSERT_VECTOR3D_D_EQ(r2, r3);
}

TEST(Vector3D, TripleProduct) {
    Vector3D a(1, 2, 3);
    Vector3D b(4, 5, 6);
    Vector3D c(7, 8, 9);

    Vector3D r1 = CrossProduct(a, CrossProduct(b, c)),
             r2 = b * DotProduct(a, c) - c * DotProduct(a, b);

    ASSERT_VECTOR3D_D_EQ(r1, r2);
}

TEST(Vector3D, ProjectReject) {
    Vector3D a(0, 1, 0);
    Vector3D b(1, 1, 0);
    Vector3D p = Project(a, b);
    ASSERT_VECTOR3D_EQ(p, .5f, .5f, 0.f);
    Vector3D r = Reject(a, b);
    ASSERT_VECTOR3D_EQ(r, -.5f, .5f, 0.f);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
