#ifndef LU_H
#define LU_H

#include <vector>

struct LUDecomposition 
{
    std::vector<std::vector<double>> L;
    std::vector<std::vector<double>> U;
};

LUDecomposition decomposeLU(const std::vector<std::vector<double>>& A); // Выполняет LU-разложение матрицы A и возвращает две матрицы: L и U

std::vector<double> forwardSubstitution(const std::vector<std::vector<double>>& L, const std::vector<double>& b); // Решает нижнетреугольную систему Ly = b.

std::vector<double> backwardSubstitution(const std::vector<std::vector<double>>& U, const std::vector<double>& y); // Решает верхнетреугольную систему Ux = y.


#endif