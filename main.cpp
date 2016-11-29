#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

#include "algorithm/vector/sort.hpp"
#include "algorithm/vector/search.hpp"
#include "algorithm/matrix/matrix.hpp"
#include "algorithm/random.hpp"


int main() {

    Matrix A = Matrix(2, std::vector<int>(2, 0));
    RandomlyFillMatrix(A, -5, 5);
    PrintMatrix(A);
    std::cout << std::endl;

    Matrix B = Matrix(2, std::vector<int>(2, 0));
    RandomlyFillMatrix(B, -5, 5);
    PrintMatrix(B);
    std::cout << std::endl;

    Matrix C = MatrixMultiplyBF(A, B);

    PrintMatrix(C);

    for (int i = 0; i < 20; ++i)
        std::cout << RandomInterval(0, 15) << ' ';

    return 0;
}
