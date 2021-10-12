//
// Created by jellybe on 11.10.2021.
//

#include <gtest/gtest.h>
extern "C" {
#include "max_triang.h"
}

TEST(MTR_TEST, Assert_47) {
    const int n = 10;
    float X[n] = {1, 5, 8, 7, 4, 5, 6, 3, 4, 2};
    float Y[n] = {8, 5, 6, 9, 8, 7, 4, 5, 2, 1};
    EXPECT_EQ(max_triang(X, Y, n), 47);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}