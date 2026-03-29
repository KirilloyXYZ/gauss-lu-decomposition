#ifndef GENERATORS_H
#define GENERATORS_H

#include <vector>

std::vector<std::vector<double>> generateRandomMatrix(int n, unsigned int seed); // Создаёт случайную матрицу для временных экспериментов.

std::vector<double> generateRandomVector(int n, unsigned int seed); // Создаёт случайную правую часть.

std::vector<std::vector<double>> generateHilbertMatrix(int n); // Строит матрицу Гильберта для эксперимента на точность.

std::vector<double> multiplyMatrixVector(const std::vector<std::vector<double>>& A, const std::vector<double>& x); // Нужна для вычисления b = Hx в эксперименте с матрицей Гильберта.
    
std::vector<double> createOnesVector(int n); // Создаёт тот самый точный вектор решения из единиц.

#endif