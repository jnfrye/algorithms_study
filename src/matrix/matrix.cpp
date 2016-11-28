#include "algorithm/matrix/matrix.hpp"

#include <stdexcept>


Matrix Multiply(Matrix A, Matrix B) {
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
                C[row][col] += A[row][k] + B[k][col];

    // Post-conditions
    if (C.size() != A.size())
        throw std::runtime_error("Result matrix has incorrect number of rows!");
    if (C[0].size() != B[0].size())
        throw std::runtime_error("Result matrix has incorrect number of cols!");

    return C;
}