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

Matrix MatrixTranspose(const Matrix &A) {
    int num_rows = A.size();
    int num_cols = A[0].size();

    Matrix A_transpose(num_cols, Row(num_rows));
    for (int row = 0; row < num_rows; ++row)
        for (int col = 0; col < num_cols; ++col)
            A_transpose[col][row] = A[row][col];

    return A_transpose;
}

std::vector<std::vector<Matrix>> SplitMatrix(const Matrix &A) {
    if (A.size() < 2 || A[0].size() < 2)
        throw std::runtime_error("Too few rows or columns to split matrix!");

    int num_rows = A.size();
    int num_cols = A[0].size();

    std::vector<std::vector<Matrix>> split_matrix(2, std::vector<Matrix>(2));

    int middle_row = static_cast<int>(std::floor(num_rows/2.));
    int middle_col = static_cast<int>(std::floor(num_cols/2.));

    Row row_dims = {middle_row, num_rows - middle_row};
    Row col_dims = {middle_col, num_cols - middle_col};

    for (int row = 0; row < 2; ++row)
        for (int col = 0; col < 2; ++col){
            split_matrix[row][col] = Matrix(row_dims[row], Row(col_dims[col]));

            for (int subrow = 0; subrow < row_dims[row]; ++subrow)
                for (int subcol = 0; subcol < col_dims[col]; ++subcol)
                    split_matrix[row][col][subrow][subcol] = A
                        [subrow + row * row_dims[0]]
                        [subcol + col * col_dims[0]];

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
    for (int row = 0; row < num_rows; ++row) {
        int subrow_offset = std::accumulate(
            row_dims.begin(), row_dims.begin() + row, 0);
        for (int col = 0; col < num_cols; ++col) {
            int subcol_offset = std::accumulate(
                col_dims.begin(), col_dims.begin() + col, 0);

            for (int subrow = 0; subrow < row_dims[row]; ++subrow)
                for (int subcol = 0; subcol < col_dims[col]; ++subcol) {
                    unsplit_matrix
                        [subrow + subrow_offset]
                        [subcol + subcol_offset]
                        = split_matrix[row][col][subrow][subcol];
                }
        }
    }
    return unsplit_matrix;
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

Matrix MatrixMultiplyDAC(const Matrix &left, const Matrix &right) {
    int num_rows = left.size();
    int num_cols = right[0].size();

    Matrix product(num_rows, Row(num_cols));

    if (num_rows == 1 || num_cols == 1) {
        product = MatrixMultiplyBF(left, right);
    }
    else {
        auto split_product = SplitMatrix(product);
        auto split_left = SplitMatrix(left);
        auto split_right = SplitMatrix(right);

        for (int row = 0; row < 2; ++row)
            for (int col = 0; col < 2; ++col)
                split_product[row][col] =
                    MatrixAdd(
                        MatrixMultiplyDAC(
                            split_left[row][0], split_right[0][col]),
                        MatrixMultiplyDAC(
                            split_left[row][1], split_right[1][col]));

        product = UnsplitMatrix(split_product);
    }
    return product;
}
