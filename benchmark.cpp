#include "benchmark.h"
#include "gauss.h"
#include "lu.h"
#include <ctime>

double measureGaussNoPivotTime(const std::vector<std::vector<double>>& A, const std::vector<double>& b)
{
    clock_t start = clock();

    solveGaussNoPivot(A, b);

    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

double measureGaussPartialPivotTime(const std::vector<std::vector<double>>& A, const std::vector<double>& b)
{
    clock_t start = clock();

    solveGaussPartialPivot(A, b);

    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

double measureLUDecompositionTime(const std::vector<std::vector<double>>& A)
{
    clock_t start = clock();

    decomposeLU(A);

    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

double measureLUSolveTime(const std::vector<std::vector<double>>& L, const std::vector<std::vector<double>>& U, const std::vector<double>& b)
{
    clock_t start = clock();

    backwardSubstitution(U, forwardSubstitution(L, b));

    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}