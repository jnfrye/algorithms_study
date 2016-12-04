/** Basic matrix operations.
 */

#ifndef ALGORITHMS_STUDY_CPP_MATRIX_HPP
#define ALGORITHMS_STUDY_CPP_MATRIX_HPP

#include <vector>


typedef std::vector<int> Row;
typedef std::vector<Row> Matrix;

/** Display matrix in a nice format.
 */
void PrintMatrix(const Matrix &A);

/** Multiply a matrix by a scalar.
 *
 * @param scalar    Scalar to multiply matrix by.
 * @param A         Matrix to get multiplied by scalar.
 * @return          Result of scalar multiplied by matrix.
 */
Matrix MatrixScalarMultiply(const int scalar, const Matrix &A);

/** Add two matrices.
 *
 * @param A Left-hand matrix
 * @param B Right-hand matrix
 * @return  Result matrix.
 */
Matrix MatrixAdd(const Matrix &A, const Matrix &B);

/** Subtract one matrix from another (A - B).
 *
 * The second argument is subtracted from the first (A - B).
 *
 * @param A     Matrix to be subtracted from.
 * @param B     Matrix to be subtracted.
 * @return      Result of subtraction.
 */
Matrix MatrixSubtract(const Matrix &A, const Matrix &B);

/** Split matrix into quadrants (returns a matrix of matrices).
 *
 * @param A Matrix to be split
 * @return  Matrix of matrices.
 */
std::vector<std::vector<Matrix>> SplitMatrix(const Matrix &A);

/** Unsplit a matrix of matrices (returns a matrix of values).
 *
 * @param split_matrix  Matrix to be unsplit.
 * @return              Unsplit matrix.
 */
Matrix UnsplitMatrix(const std::vector<std::vector<Matrix>> &split_matrix);

/** Multiply two matrices using the brute force algorithm.
 *
 * Worst-case performance is Theta(n^3)
 *
 * @param A Left-hand matrix
 * @param B Right-hand matrix
 * @return  Result matrix.
 */
Matrix MatrixMultiplyBF(const Matrix &A, const Matrix &B);

/** Multiply two matrices using the recursive divide-and-conquer algorithm.
 *
 * Worst-case performance is Theta(n^3).
 *
 * @param left  Left-hand matrix
 * @param right Right-hand matrix
 * @return      Result matrix.
 */
Matrix MatrixMultiplyDAC(const Matrix &left, const Matrix &right);

#endif //ALGORITHMS_STUDY_CPP_MATRIX_HPP
