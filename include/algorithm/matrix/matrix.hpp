/** Basic matrix operations.
 */

#ifndef ALGORITHMS_STUDY_CPP_MATRIX_HPP
#define ALGORITHMS_STUDY_CPP_MATRIX_HPP

#include <vector>

typedef std::vector<int> Row;
typedef std::vector<Row> Matrix;

/**
 *
 */
Matrix Multiply(Matrix A, Matrix B);

#endif //ALGORITHMS_STUDY_CPP_MATRIX_HPP
