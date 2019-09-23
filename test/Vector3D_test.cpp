#include "../Vector3D.hpp"
#include <gtest/gtest.h>

TEST(Vector3D_test, TryVector3D) {
    Vector3D a(1.5f, 3.7f, 32.25f);
    ASSERT_EQ(1.5f, a.x);
    ASSERT_EQ(3.7f, a.y);
    ASSERT_EQ(32.25f, a.z);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
