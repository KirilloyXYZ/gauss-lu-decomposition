#include "gauss.h"
#include <cmath>

std::vector<double> solveGaussNoPivot(std::vector<std::vector<double>> A, std::vector<double> b)
{
    int n = A.size();
    std::vector<double> x(n);

    for (int k = 0; k < n - 1; k++) // по столбцам 
    {
        for (int i = k + 1; i < n; i++) // по строкам 
        {
            double factor = A[i][k] / A[k][k];

            for (int j = k; j < n; j++)
            {
                A[i][j] -= factor * A[k][j];
            }

            b[i] -= factor * b[k];
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        double sum = 0.0;

        for (int j = i + 1; j < n; j++)
        {
            sum += A[i][j] * x[j];
        }

        x[i] = (b[i] - sum) / A[i][i];
    }

    return x;
}

std::vector<double> solveGaussPartialPivot(std::vector<std::vector<double>> A, std::vector<double> b)
{
    int n = A.size();
    std::vector<double> x(n);

    for (int k = 0; k < n - 1; k++)
    {
        int maxRow = k;
        double maxValue = std::abs(A[k][k]);

        for (int i = k + 1; i < n; i++)
        {
            if (std::abs(A[i][k]) > maxValue)
            {
                maxValue = std::abs(A[i][k]);
                maxRow = i;
            }
        }

        if (maxRow != k)
        {
            A[k].swap(A[maxRow]);

            double temp = b[k];
            b[k] = b[maxRow];
            b[maxRow] = temp;
        }

        for (int i = k + 1; i < n; i++)
        {
            double factor = A[i][k] / A[k][k];

            for (int j = k; j < n; j++)
            {
                A[i][j] -= factor * A[k][j];
            }

            b[i] -= factor * b[k];
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        double sum = 0.0;

        for (int j = i + 1; j < n; j++)
        {
            sum += A[i][j] * x[j];
        }

        x[i] = (b[i] - sum) / A[i][i];
    }

    return x;
}