/** Basic matrix operations.
 */

#ifndef ALGORITHMS_STUDY_CPP_MATRIX_HPP
#define ALGORITHMS_STUDY_CPP_MATRIX_HPP

#include <vector>

typedef std::vector<int> Row;
typedef std::vector<Row> Matrix;

/** Display matrix in a nice format.
 */
void PrintMatrix(const Matrix A)

/**
 *
 */
Matrix Multiply(const Matrix A, const Matrix B);

#endif //ALGORITHMS_STUDY_CPP_MATRIX_HPP