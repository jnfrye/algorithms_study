#include "algorithm/matrix/matrix.hpp"

#include <stdexcept>
#include <iostream>


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
