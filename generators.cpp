#include "generators.h"
#include <cstdlib>

std::vector<std::vector<double>> generateRandomMatrix(int n, unsigned int seed)
{
    std::srand(seed);
    std::vector<std::vector<double>> matrix(n, std::vector<double>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = -1.0 + 2.0 * std::rand() / RAND_MAX;
        }
    }

    return matrix;
}

std::vector<double> generateRandomVector(int n, unsigned int seed)
{
    std::srand(seed);
    std::vector<double> vec(n);

    for (int i = 0; i < n; i++)
    {
        vec[i] = -1.0 + 2.0 * std::rand() / RAND_MAX;
    }

    return vec;
}

std::vector<std::vector<double>> generateHilbertMatrix(int n)
{
    std::vector<std::vector<double>> matrix(n, std::vector<double>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 1.0 / (i + j + 1);
        }
    }

    return matrix;
}

std::vector<double> multiplyMatrixVector(const std::vector<std::vector<double>>& A, const std::vector<double>& x)
{
    int n = A.size();
    std::vector<double> result(n, 0.0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (int)x.size(); j++)
        {
            result[i] += A[i][j] * x[j];
        }
    }

    return result;
}

std::vector<double> createOnesVector(int n)
{
    std::vector<double> vec(n, 1.0);
    return vec;
}