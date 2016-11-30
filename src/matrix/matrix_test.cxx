/** Unit tests for `matrix.cpp`
 */

#include "gtest/gtest.h"

#include "algorithm/matrix/matrix.hpp"
#include "algorithm/random.hpp"


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

/** General test fixture for basic matrix functions.
 */
class RandomizedMatrixTest: public ::testing::Test {
public:
    Matrix random_matrix1;
    Matrix random_matrix2a;
    Matrix random_matrix2b;
    Matrix random_matrix3;

protected:
    virtual void SetUp() {
        std::srand((unsigned int)std::time(nullptr)); // Seed the RNG

        int rows1 = RandomInterval(1, 12);
        int rows2 = RandomInterval(1, 12);
        int rows3 = RandomInterval(1, 12);
        int cols3 = RandomInterval(1, 12);

        random_matrix1 = Matrix(rows1, std::vector<int>(rows2));
        random_matrix2a = Matrix(rows2, std::vector<int>(rows3));
        random_matrix2b = Matrix(rows2, std::vector<int>(rows3));
        random_matrix3 = Matrix(rows3, std::vector<int>(cols3));

        RandomlyFillMatrix(random_matrix1, -12, 12);
        RandomlyFillMatrix(random_matrix2a, -12, 12);
        RandomlyFillMatrix(random_matrix2b, -12, 12);
        RandomlyFillMatrix(random_matrix3, -12, 12);
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

TEST_F(RandomizedMatrixTest, MatrixMultiplicationLeftDistributive) {
    std::string error_message = "Matrix multiplication should be left-"
        "distributive.";

    auto result_left_side = MatrixMultiplyBF(
        random_matrix1, MatrixAdd(random_matrix2a, random_matrix2b));
    auto result_right_side = MatrixAdd(
        MatrixMultiplyBF(random_matrix1, random_matrix2a),
        MatrixMultiplyBF(random_matrix1, random_matrix2b));

    EXPECT_EQ(result_left_side, result_right_side) << error_message;
}

/** Matrix multiplication should be associative
 */
TEST_F(RandomizedMatrixTest, MatrixMultiplicationIsAssociative) {
    std::string error_message = "Matrix multiplication should be associative!";

    auto left_side = MatrixMultiplyBF(
        random_matrix1,
        MatrixMultiplyBF(random_matrix2a, random_matrix3));
    auto right_side = MatrixMultiplyBF(
        MatrixMultiplyBF(random_matrix1, random_matrix2a),
        random_matrix3);

    EXPECT_EQ(left_side, right_side) << error_message;
}
