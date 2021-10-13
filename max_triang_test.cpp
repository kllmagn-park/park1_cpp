//
// Created by jellybe on 11.10.2021.
//

#include <gtest/gtest.h>
extern "C" {
#include "max_triang.h"
}

TEST(MTR_TEST, VALCHECK) {
    const int n = 10;
    float X[n] = {1, 5, 8, 7, 4, 5, 6, 3, 4, 2};
    float Y[n] = {8, 5, 6, 9, 8, 7, 4, 5, 2, 1};
    int ans[3] = {2, 4, 9};
    float **pX = arr_to_parr(X, n), **pY = arr_to_parr(Y, n);
    int **pans = max_triang(pX, pY, n);
    EXPECT_TRUE(pans != nullptr);
    free(pans);
    for (int i = 0; i < 3; i++) {
        pans = max_triang(pX, pY, n);
        EXPECT_EQ(ans[i], pans[i][0]);
        free(pans);
    }
    free(pX); free(pY);
}

TEST(MTR_TEST, BADSTATE_CHECK)
{
    const int n = 2;
    float X[n] = {2, 4};
    float Y[n] = {3, 5};
    float **pX = arr_to_parr(X, n), **pY = arr_to_parr(Y, n);
    int **pans = max_triang(pX, pY, n);
    EXPECT_TRUE( pans == nullptr);
    free(pans); free(pX); free(pY);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}