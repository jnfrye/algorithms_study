#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

#include "algorithm/vector/sort.hpp"
#include "algorithm/vector/search.hpp"
#include "algorithm/matrix/matrix.hpp"


int main() {

    Matrix A = {{1, 2},
                {3, 4}};
    PrintMatrix(A);
    std::cout << std::endl;

    Matrix B = {{5, 6},
                {7, 8}};
    PrintMatrix(B);
    std::cout << std::endl;

    Matrix C = MatrixMultiplyBF(A, B);

    PrintMatrix(C);

    return 0;
}
