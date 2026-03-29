#ifndef METRICS_H
#define METRICS_H

#include <vector>

double vectorNorm(const std::vector<double>& v); // Считает норму вектора.

double computeResidual(const std::vector<std::vector<double>>& A, const std::vector<double>& x, const std::vector<double>& b); // Считает невязку ||Ax - b||.

double computeRelativeError(const std::vector<double>& approxX, const std::vector<double>& exactX); // Считает относительную погрешность


#endif