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

/** Multiply two matrices using the brute force algorithm.
 *
 * Worst-case performance is Theta(n^3)
 *
 * @param A Left-hand matrix
 * @param B Right-hand matrix
 * @return  Result matrix.
 */
Matrix MatrixMultiplyBF(const Matrix A, const Matrix B);

#endif //ALGORITHMS_STUDY_CPP_MATRIX_HPP
