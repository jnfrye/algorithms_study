/** Unit tests for `matrix.cpp`
 */

#include "gtest/gtest.h"

#include "algorithm/matrix/matrix.hpp"


/** General test fixture for basic matrix functions.
 */
class GeneralMatrixTest: public ::testing::Test {
public:
    Matrix singleton;
    Matrix matrix1;
    Matrix matrix2;

protected:
    virtual void SetUp() {
        singleton = {{5}};
        matrix1 = {
            {8, -3, 6},
            {0, -4, 4}};
        matrix2 = {
            {10},
            {-3},
            {7}};
    }
};

/** Basic test of matrix multiplication.
 */
TEST_F(GeneralMatrixTest, MatrixMultiplicationOnBasicMatrices) {
    auto result_matrix = MatrixMultiplyBF(matrix1, matrix2);

    Matrix expected_result = {
        {131},
        {40}};

    EXPECT_EQ(result_matrix, expected_result)
        << "Matrix multiplication failed basic test!";

}


