#include "metrics.h"
#include <cmath>

double vectorNorm(const std::vector<double>& v)
{
    double sum = 0.0;

    for (int i = 0; i < (int)v.size(); i++)
    {
        sum += v[i] * v[i];
    }

    return std::sqrt(sum);
}

double computeResidual(const std::vector<std::vector<double>>& A, const std::vector<double>& x, const std::vector<double>& b)
{
    std::vector<double> residual(A.size(), 0.0);

    for (int i = 0; i < (int)A.size(); i++)
    {
        double sum = 0.0;

        for (int j = 0; j < (int)x.size(); j++)
        {
            sum += A[i][j] * x[j];
        }

        residual[i] = sum - b[i];
    }

    return vectorNorm(residual);
}

double computeRelativeError(const std::vector<double>& approxX, const std::vector<double>& exactX)
{
    std::vector<double> diff(approxX.size());

    for (int i = 0; i < (int)approxX.size(); i++)
    {
        diff[i] = approxX[i] - exactX[i];
    }

    return vectorNorm(diff) / vectorNorm(exactX);
}