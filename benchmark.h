#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <vector>

// Измеряет время решения системы методом Гаусса без выбора ведущего элемента.
// На вход получает матрицу A и вектор правой части b.
// Возвращает время выполнения в секундах.
double measureGaussNoPivotTime(const std::vector<std::vector<double>>& A, const std::vector<double>& b);

// Измеряет время решения системы методом Гаусса с выбором главного элемента по столбцу.
// На вход получает матрицу A и вектор правой части b.
// Возвращает время выполнения в секундах.
double measureGaussPartialPivotTime(const std::vector<std::vector<double>>& A, const std::vector<double>& b);

// Измеряет время выполнения LU-разложения матрицы A.
// На вход получает матрицу A.
// Возвращает время выполнения в секундах.
double measureLUDecompositionTime(const std::vector<std::vector<double>>& A);

// Измеряет время решения системы через уже готовые матрицы L и U.
// На вход получает матрицы L, U и вектор правой части b.
// Возвращает время выполнения в секундах.
double measureLUSolveTime(const std::vector<std::vector<double>>& L, const std::vector<std::vector<double>>& U, const std::vector<double>& b);

#endif