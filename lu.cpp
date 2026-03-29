#include "lu.h"

LUDecomposition decomposeLU(const std::vector<std::vector<double>>& A)
{
    int n = A.size();

    LUDecomposition result;
    result.L = std::vector<std::vector<double>>(n, std::vector<double>(n, 0.0));
    result.U = std::vector<std::vector<double>>(n, std::vector<double>(n, 0.0));

    for (int i = 0; i < n; i++)
    {
        for (int k = i; k < n; k++)
        {
            double sum = 0.0;

            for (int j = 0; j < i; j++)
            {
                sum += result.L[i][j] * result.U[j][k];
            }

            result.U[i][k] = A[i][k] - sum;
        }

        result.L[i][i] = 1.0;

        for (int k = i + 1; k < n; k++)
        {
            double sum = 0.0;

            for (int j = 0; j < i; j++)
            {
                sum += result.L[k][j] * result.U[j][i];
            }

            result.L[k][i] = (A[k][i] - sum) / result.U[i][i];
        }
    }

    return result;
}

std::vector<double> forwardSubstitution(const std::vector<std::vector<double>>& L, const std::vector<double>& b)
{
    int n = L.size();
    std::vector<double> y(n);

    for (int i = 0; i < n; i++)
    {
        double sum = 0.0;

        for (int j = 0; j < i; j++)
        {
            sum += L[i][j] * y[j];
        }

        y[i] = (b[i] - sum) / L[i][i];
    }

    return y;
}

std::vector<double> backwardSubstitution(const std::vector<std::vector<double>>& U, const std::vector<double>& y)
{
    int n = U.size();
    std::vector<double> x(n);

    for (int i = n - 1; i >= 0; i--)
    {
        double sum = 0.0;

        for (int j = i + 1; j < n; j++)
        {
            sum += U[i][j] * x[j];
        }

        x[i] = (y[i] - sum) / U[i][i];
    }

    return x;
}