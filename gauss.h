#ifndef GAUSS_H
#define GAUSS_H

#include <vector>

std::vector<double> solveGaussNoPivot(std::vector<std::vector<double>> A, std::vector<double> b); // Решает систему линейных уравнений методом Гаусса без выбора ведущего элемента

std::vector<double> solveGaussPartialPivot(std::vector<std::vector<double>> A, std::vector<double> b); // Решает СЛАУ методом Гаусса с выбором главного элемента по столбцу.
    

#endif