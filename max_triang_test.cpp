//
// Created by jellybe on 11.10.2021.
//

#include <gtest/gtest.h>
extern "C" {
#include "./max_triang.h"
}

TEST(MTR_TEST, VALCHECK) {
    const int n = 10;
    float X[n] = {1, 5, 8, 7, 4, 5, 6, 3, 4, 2};
    float Y[n] = {8, 5, 6, 9, 8, 7, 4, 5, 2, 1};
    int ans[3] = {2, 0, 9};
    const float **pX = arr_to_parr(X, n), **pY = arr_to_parr(Y, n);
    const int **pans = max_triang(pX, pY, n);
    EXPECT_TRUE(pans != nullptr);
    for (int i = 0; i < 3; i++) EXPECT_EQ(ans[i], pans[i][0]);
    free(pX); free(pY); freep((void**)pans, 3);
}

TEST(MTR_TEST, BADSTATE_CHECK) {
    const int n = 2;
    float X[n] = {2, 4};
    float Y[n] = {3, 5};
    const float **pX = arr_to_parr(X, n), **pY = arr_to_parr(Y, n);
    const int **pans = max_triang(pX, pY, n);
    EXPECT_TRUE(pans == nullptr);
    free(pX); free(pY);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
