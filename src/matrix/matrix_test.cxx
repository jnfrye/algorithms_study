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
    Matrix random_matrix4;

protected:
    virtual void SetUp() {
        std::srand((unsigned int)std::time(nullptr)); // Seed the RNG

        int rows1 = RandomInteger(1, 32);
        int rows2 = RandomInteger(1, 32);
        int rows3 = RandomInteger(1, 32);
        int cols3 = RandomInteger(1, 32);
        int rows4 = RandomInteger(2, 32);
        int cols4 = RandomInteger(2, 32);

        random_matrix1 = Matrix(rows1, Row(rows2));
        random_matrix2a = Matrix(rows2, Row(rows3));
        random_matrix2b = Matrix(rows2, Row(rows3));
        random_matrix3 = Matrix(rows3, Row(cols3));
        random_matrix4 = Matrix(rows4, Row(cols4));

        RandomlyFillMatrix(random_matrix1, -12, 12);
        RandomlyFillMatrix(random_matrix2a, -12, 12);
        RandomlyFillMatrix(random_matrix2b, -12, 12);
        RandomlyFillMatrix(random_matrix3, -12, 12);
        RandomlyFillMatrix(random_matrix4, -12, 12);
    }
};

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

/** Splitting then unsplitting a matrix should yield original matrix.
 */
TEST_F(RandomizedMatrixTest, SplittingIsInverseOfUnsplittingMatrix) {
    auto result_matrix = UnsplitMatrix(SplitMatrix(random_matrix4));

    EXPECT_EQ(result_matrix, random_matrix4)
        << "Splitting then unsplitting a matrix should yield original matrix.";
}

/** Basic test of matrix multiplication.
 */
TEST_F(GeneralMatrixTest, MatrixMultiplicationOnBasicMatrices) {
    auto BF_result_matrix = MatrixMultiplyBF(matrix1, matrix2);
    auto DAC_result_matrix = MatrixMultiplyDAC(matrix1, matrix2);
    auto Str_result_matrix = MatrixMultiplyStrassen(matrix1, matrix2);

    Matrix expected_result = {
        {131},
        {40}};

    EXPECT_EQ(BF_result_matrix, expected_result)
        << "Matrix multiplication failed basic test!";
    EXPECT_EQ(DAC_result_matrix, expected_result)
        << "Matrix multiplication failed basic test!";
    EXPECT_EQ(Str_result_matrix, expected_result)
        << "Matrix multiplication failed basic test!";
}

/** Matrix multiplication should be left-distributive over addition.
 */
TEST_F(RandomizedMatrixTest, MatrixMultiplicationLeftDistributive) {
    std::string error_message = "Matrix multiplication should be left-"
        "distributive over addition.";

    auto BF_result_left_side = MatrixMultiplyBF(
        random_matrix1, MatrixAdd(random_matrix2a, random_matrix2b));
    auto BF_result_right_side = MatrixAdd(
        MatrixMultiplyBF(random_matrix1, random_matrix2a),
        MatrixMultiplyBF(random_matrix1, random_matrix2b));

    auto DAC_result_left_side = MatrixMultiplyDAC(
        random_matrix1, MatrixAdd(random_matrix2a, random_matrix2b));
    auto DAC_result_right_side = MatrixAdd(
        MatrixMultiplyDAC(random_matrix1, random_matrix2a),
        MatrixMultiplyDAC(random_matrix1, random_matrix2b));

    auto Str_result_left_side = MatrixMultiplyStrassen(
        random_matrix1, MatrixAdd(random_matrix2a, random_matrix2b));
    auto Str_result_right_side = MatrixAdd(
        MatrixMultiplyStrassen(random_matrix1, random_matrix2a),
        MatrixMultiplyStrassen(random_matrix1, random_matrix2b));

    EXPECT_EQ(BF_result_left_side, BF_result_right_side) << error_message;
    EXPECT_EQ(DAC_result_left_side, DAC_result_right_side) << error_message;
    EXPECT_EQ(Str_result_left_side, Str_result_right_side) << error_message;
}

/** Matrix multiplication should be right-distributive over addition.
 */
TEST_F(RandomizedMatrixTest, MatrixMultiplicationRightDistributive) {
    std::string error_message = "Matrix multiplication should be right-"
        "distributive over addition.";

    auto BF_result_left_side = MatrixMultiplyBF(
        MatrixAdd(random_matrix2a, random_matrix2b), random_matrix3);
    auto BF_result_right_side = MatrixAdd(
        MatrixMultiplyBF(random_matrix2a, random_matrix3),
        MatrixMultiplyBF(random_matrix2b, random_matrix3));

    auto DAC_result_left_side = MatrixMultiplyDAC(
        MatrixAdd(random_matrix2a, random_matrix2b), random_matrix3);
    auto DAC_result_right_side = MatrixAdd(
        MatrixMultiplyDAC(random_matrix2a, random_matrix3),
        MatrixMultiplyDAC(random_matrix2b, random_matrix3));

    auto Str_result_left_side = MatrixMultiplyStrassen(
        MatrixAdd(random_matrix2a, random_matrix2b), random_matrix3);
    auto Str_result_right_side = MatrixAdd(
        MatrixMultiplyStrassen(random_matrix2a, random_matrix3),
        MatrixMultiplyStrassen(random_matrix2b, random_matrix3));

    EXPECT_EQ(BF_result_left_side, BF_result_right_side) << error_message;
    EXPECT_EQ(DAC_result_left_side, DAC_result_right_side) << error_message;
    EXPECT_EQ(Str_result_left_side, Str_result_right_side) << error_message;
}

/** Matrix multiplication should be associative
 */
TEST_F(RandomizedMatrixTest, MatrixMultiplicationIsAssociative) {
    std::string error_message = "Matrix multiplication should be associative!";

    auto BF_left_side = MatrixMultiplyBF(
        random_matrix1,
        MatrixMultiplyBF(random_matrix2a, random_matrix3));
    auto BF_right_side = MatrixMultiplyBF(
        MatrixMultiplyBF(random_matrix1, random_matrix2a),
        random_matrix3);

    auto DAC_left_side = MatrixMultiplyDAC(
        random_matrix1,
        MatrixMultiplyDAC(random_matrix2a, random_matrix3));
    auto DAC_right_side = MatrixMultiplyDAC(
        MatrixMultiplyDAC(random_matrix1, random_matrix2a),
        random_matrix3);

    auto Str_left_side = MatrixMultiplyStrassen(
        random_matrix1,
        MatrixMultiplyStrassen(random_matrix2a, random_matrix3));
    auto Str_right_side = MatrixMultiplyStrassen(
        MatrixMultiplyStrassen(random_matrix1, random_matrix2a),
        random_matrix3);

    EXPECT_EQ(BF_left_side, BF_right_side) << error_message;
    EXPECT_EQ(DAC_left_side, DAC_right_side) << error_message;
    EXPECT_EQ(Str_left_side, Str_right_side) << error_message;
}
