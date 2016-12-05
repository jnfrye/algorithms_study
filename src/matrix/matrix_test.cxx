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
    Matrix matrix3;

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
        matrix3 = {
            {8, -3, 6},
            {2, 1, 1},
            {-5, 0, 9},
            {0, -4, 4}};
    }
};

/** Randomized test fixture for basic matrix functions.
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
    auto BF_result_matrix = MatrixMultiplyBF(matrix1, matrix2);
    auto DAC_result_matrix = MatrixMultiplyDAC(matrix1, matrix2);

    Matrix expected_result = {
        {131},
        {40}};

    EXPECT_EQ(BF_result_matrix, expected_result)
        << "Matrix multiplication failed basic test!";
    EXPECT_EQ(DAC_result_matrix, expected_result)
        << "Matrix multiplication failed basic test!";
}

/** Basic test of matrix splitting.
 */
TEST_F(GeneralMatrixTest, SplitMatrixOnBasicMatrix) {
    auto results = SplitMatrix(matrix3);

    std::vector<std::vector<Matrix>> expected_result(2, std::vector<Matrix>(2));

    expected_result[0][0] = {
        {8},
        {2}};
    expected_result[0][1] = {
        {-3, 6},
        {1, 1}};
    expected_result[1][0] = {
        {-5},
        {0}};
    expected_result[1][1] = {
        {0, 9},
        {-4, 4}};

    EXPECT_EQ(results, expected_result)
        << "Matrix splitting failed basic test!";

}

/** Matrix multiplication should be left-distributive over addition.
 */
TEST_F(RandomizedMatrixTest, MatrixMultiplicationLeftDistributive) {
    std::string error_message = "Matrix multiplication should be left-"
        "distributive over addition.";

    auto result_left_side = MatrixMultiplyBF(
        random_matrix1, MatrixAdd(random_matrix2a, random_matrix2b));
    auto result_right_side = MatrixAdd(
        MatrixMultiplyBF(random_matrix1, random_matrix2a),
        MatrixMultiplyBF(random_matrix1, random_matrix2b));

    EXPECT_EQ(result_left_side, result_right_side) << error_message;
}

/** Matrix multiplication should be right-distributive over addition.
 */
TEST_F(RandomizedMatrixTest, MatrixMultiplicationRightDistributive) {
    std::string error_message = "Matrix multiplication should be right-"
        "distributive over addition.";

    auto result_left_side = MatrixMultiplyBF(
        MatrixAdd(random_matrix2a, random_matrix2b), random_matrix3);
    auto result_right_side = MatrixAdd(
        MatrixMultiplyBF(random_matrix2a, random_matrix3),
        MatrixMultiplyBF(random_matrix2b, random_matrix3));

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

/** Splitting then unsplitting a matrix should yield original matrix.
 */
TEST_F(RandomizedMatrixTest, SplittingIsInverseOfUnsplittingMatrix) {
    auto result_matrix = UnsplitMatrix(SplitMatrix(random_matrix1));

    EXPECT_EQ(result_matrix, random_matrix1)
        << "Splitting then unsplitting a matrix should yield original matrix.";
}
