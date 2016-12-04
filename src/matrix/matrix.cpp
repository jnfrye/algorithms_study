#include "algorithm/matrix/matrix.hpp"

#include <stdexcept>
#include <iostream>
#include <cmath>
#include <numeric>


void PrintMatrix(const Matrix &A) {
    for (int row = 0; row < A.size(); ++row) {
        for (int col = 0; col < A[0].size(); ++col)
            std::cout << A[row][col] << "\t";
        std::cout << std::endl;
    }
}

Matrix MatrixScalarMultiply(const int scalar, const Matrix &A) {
    Matrix C(A);    // copy matrix A
    for (int row = 0; row < C.size(); ++row)
        for (int col = 0; col < C[0].size(); ++col)
            C[row][col] *= scalar;

    return C;
}

Matrix MatrixAdd(const Matrix &A, const Matrix &B) {
    // Pre-conditions
    if (A.size() != B.size() || A[0].size() != B[0].size())
        throw std::runtime_error("Cannot add matrices of different sizes!");

    // Iniitialize matrix full of zeros
    Matrix C(A.size(), std::vector<int>(B[0].size(), 0));
    for (int row = 0; row < A.size(); ++row)
        for (int col = 0; col < A[0].size(); ++col)
            C[row][col] = A[row][col] + B[row][col];

    return C;
}

Matrix MatrixSubtract(const Matrix &A, const Matrix &B) {
    return MatrixAdd(A, MatrixScalarMultiply(-1, B));
}

Matrix MatrixMultiplyBF(const Matrix &A, const Matrix &B) {
    // Pre-conditions
    if (A.size() == 0 || B.size() == 0)
        throw std::runtime_error("Cannot multiply empty matrices!");
    if (A[0].size() != B.size())
        throw std::runtime_error("Left matrix must have number of columns "
            "equal to number of rows in right matrix!");

    // Initialize matrix full of zeros
    Matrix C(A.size(), std::vector<int>(B[0].size(), 0));
    for (int row = 0; row < A.size(); ++row)
        for (int col = 0; col < B[0].size(); ++col)
            for (int k = 0; k < B.size(); ++k)
                C[row][col] += A[row][k] * B[k][col];

    // Post-conditions
    if (C.size() != A.size())
        throw std::runtime_error("Result matrix has incorrect number of rows!");
    if (C[0].size() != B[0].size())
        throw std::runtime_error("Result matrix has incorrect number of cols!");

    return C;
}

std::vector<std::vector<Matrix>> SplitMatrix(const Matrix &A) {

    std::vector<std::vector<Matrix>> split_matrix(2, std::vector<Matrix>(2));

    int num_rows = A.size();
    int num_cols = A[0].size();

    int middle_row = static_cast<int>(
        std::floor(num_rows/2.));
    int middle_col = static_cast<int>(
        std::floor(num_cols/2.));

    Row row_dims = {middle_row, num_rows - middle_row};
    Row col_dims = {middle_col, num_cols - middle_col};

    for (int row = 0; row < 2; ++row)
        for (int col = 0; col < 2; ++col){
            Matrix temp(row_dims[row], Row(col_dims[col]));

            for (int subrow = 0; subrow < row_dims[row]; ++subrow)
                for (int subcol = 0; subcol < col_dims[col]; ++subcol)
                    temp[subrow][subcol] = A
                        [subrow + row * row_dims[0]]
                        [subcol + col * col_dims[0]];

            split_matrix[row][col] = temp;
        }
    return split_matrix;
}

Matrix UnsplitMatrix(const std::vector<std::vector<Matrix>> &split_matrix) {
    int num_rows = split_matrix.size();
    int num_cols = split_matrix[0].size();

    Row row_dims(num_rows);
    int num_subrows = 0;
    for (int row = 0; row < num_rows; ++row) {
        row_dims[row] = split_matrix[row][0].size();
        num_subrows += row_dims[row];
    }
    Row col_dims(num_cols);
    int num_subcols = 0;
    for (int col = 0; col < num_cols; ++col) {
        col_dims[col] = split_matrix[0][col][0].size();
        num_subcols += col_dims[col];
    }
    // Fun with indices!
    Matrix unsplit_matrix(num_subrows, Row(num_subcols));
    for (int row = 0; row < num_rows; ++row)
        for (int col = 0; col < num_cols; ++col){
            Matrix temp(split_matrix[row][col]);

            for (int subrow = 0; subrow < row_dims[row]; ++subrow)
                for (int subcol = 0; subcol < col_dims[col]; ++subcol)
                     unsplit_matrix
                         [subrow + std::accumulate(
                            row_dims.begin(), row_dims.begin() + row, 0)]
                         [subcol + std::accumulate(
                            col_dims.begin(), col_dims.begin() + col, 0)]
                                = temp[subrow][subcol];
        }
    return unsplit_matrix;
}

Matrix MatrixMultiplyDACOld(
        const Matrix &left, const Matrix &right,
        const int left_row_begin, const int left_row_end,
        const int left_col_begin, const int left_col_end,
        const int right_row_begin, const int right_row_end,
        const int right_col_begin, const int right_col_end) {
    // The result matrix must have the same number of rows as the left side
    // matrix and the same number of columns as the right side matrix.
    int num_rows = left_row_end - left_row_begin;
    int num_cols = right_col_end - right_col_begin;
    Matrix C(num_rows, std::vector<int>(num_cols, 0));

    if (num_rows == 1 && num_cols == 1) {
        C[0][0] =
            left[left_row_begin][left_col_begin] *
            right[right_row_begin][right_col_begin];

        std::cout << "got here 1" << std::endl;
    }
    else {
        // Calculate the partitions
        int left_row_middle = static_cast<int>(
            std::floor((left_row_begin + left_row_end)/2.));
        int left_col_middle = static_cast<int>(
            std::floor((left_col_begin + left_col_end)/2.));
        int right_row_middle = static_cast<int>(
            std::floor((right_row_begin + right_row_end)/2.));
        int right_col_middle = static_cast<int>(
            std::floor((right_col_begin + right_col_end)/2.));

        std::cout << "got here 2" << std::endl;
        // FIXME There must be a better way to do this
        // FIXME maybe I could put all of the partition locations into a matrix
        Matrix C_up_left = MatrixAdd(
                MatrixMultiplyDACOld(left, right,
                                     left_row_begin, left_row_middle,    // L11
                                     left_col_begin, left_col_middle,
                                     right_row_begin, right_row_middle,  // R11
                                     right_col_begin, right_col_middle),
            MatrixMultiplyDACOld(left, right,
                                 left_row_begin, left_row_middle,    // L12
                                 left_col_middle, left_col_end,
                                 right_row_middle, right_row_end,    // R21
                                 right_col_begin, right_col_middle));
        Matrix C_up_right = MatrixAdd(
                MatrixMultiplyDACOld(left, right,
                                     left_row_begin, left_row_middle,    // L11
                                     left_col_begin, left_col_middle,
                                     right_row_begin, right_row_middle,  // R12
                                     right_col_middle, right_col_end),
            MatrixMultiplyDACOld(left, right,
                                 left_row_begin, left_row_middle,    // L12
                                 left_col_middle, left_col_end,
                                 right_row_middle, right_row_end,    // R22
                                 right_col_middle, right_col_end));
        Matrix C_lo_left = MatrixAdd(
                MatrixMultiplyDACOld(left, right,
                                     left_row_middle, left_row_end,      // L21
                                     left_col_begin, left_col_middle,
                                     right_row_begin, right_row_middle,  // R11
                                     right_col_begin, right_col_middle),
            MatrixMultiplyDACOld(left, right,
                                 left_row_middle, left_row_end,      // L22
                                 left_col_middle, left_col_end,
                                 right_row_middle, right_row_end,    // R21
                                 right_col_begin, right_col_middle));
        Matrix C_lo_right = MatrixAdd(
                MatrixMultiplyDACOld(left, right,
                                     left_row_middle, left_row_end,      // L21
                                     left_col_begin, left_col_middle,
                                     right_row_begin, right_row_middle,  // R12
                                     right_col_middle, right_col_end),
            MatrixMultiplyDACOld(left, right,
                                 left_row_middle, left_row_end,      // L22
                                 left_col_middle, left_col_end,
                                 right_row_middle, right_row_end,    // R22
                                 right_col_middle, right_col_end));


        std::cout << "got here 3" << std::endl;
        // Fill C with the results
        for (int row = 0; row < num_rows; ++row) {
            std::cout << "got here 4" << std::endl;
            for (int col = 0; col < num_cols; ++col) {
                std::cout << "got here 5" << std::endl;
                if (row + left_row_begin < left_row_middle) {
                    if (col + right_col_begin < right_col_middle) {
                        C[row][col] = C_up_left[row][col];
                    }
                    else {
                        C[row][col] = C_up_right[row - left_row_middle][col];
                    }
                }
                else {
                    if (col + right_col_begin < right_col_middle) {
                        C[row][col] = C_lo_left[row][col - right_col_middle];
                    }
                    else {
                        C[row][col] = C_lo_right[row - left_row_middle][col - right_col_middle];
                    }
                }
            }
        }
        std::cout << "got here 6" << std::endl;

    }
    return C;
}
