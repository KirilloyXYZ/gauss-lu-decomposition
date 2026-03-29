#include "experiments.h"
#include "benchmark.h"
#include "gauss.h"
#include "lu.h"
#include "generators.h"
#include "metrics.h"
#include <iostream>
#include <iomanip>
#include <ctime>

void runSingleSystemBenchmark()
{
    int sizes[4] = {100, 200, 500, 1000};

    std::cout << "Experiment 1: single system benchmark" << std::endl;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "n\tGaussNoPivot\tGaussPartialPivot\tLUDecomposition\tLUSolve" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        int n = sizes[i];

        std::vector<std::vector<double>> A = generateRandomMatrix(n, 1000 + n);
        std::vector<double> b = generateRandomVector(n, 2000 + n);

        double gaussNoPivotTime = measureGaussNoPivotTime(A, b);
        double gaussPartialPivotTime = measureGaussPartialPivotTime(A, b);
        double luDecompositionTime = measureLUDecompositionTime(A);

        LUDecomposition lu = decomposeLU(A);
        double luSolveTime = measureLUSolveTime(lu.L, lu.U, b);

        std::cout << n << "\t"
                  << gaussNoPivotTime << "\t"
                  << gaussPartialPivotTime << "\t"
                  << luDecompositionTime << "\t"
                  << luSolveTime << std::endl;
    }

    std::cout << std::endl;
}

void runMultipleRightHandSidesBenchmark()
{
    int ks[3] = {1, 10, 100};
    int n = 500;

    std::vector<std::vector<double>> A = generateRandomMatrix(n, 5000);

    std::cout << "Experiment 2: multiple right-hand sides" << std::endl;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "k\tGaussPartialPivotTotal\tLUTotal" << std::endl;

    for (int i = 0; i < 3; i++)
    {
        int k = ks[i];
        std::vector<std::vector<double>> rightParts(k);

        for (int j = 0; j < k; j++)
        {
            rightParts[j] = generateRandomVector(n, 6000 + j);
        }

        clock_t gaussStart = clock();

        for (int j = 0; j < k; j++)
        {
            solveGaussPartialPivot(A, rightParts[j]);
        }

        clock_t gaussEnd = clock();
        double gaussDuration = (double)(gaussEnd - gaussStart) / CLOCKS_PER_SEC;

        clock_t luStart = clock();

        LUDecomposition lu = decomposeLU(A);

        for (int j = 0; j < k; j++)
        {
            backwardSubstitution(lu.U, forwardSubstitution(lu.L, rightParts[j]));
        }

        clock_t luEnd = clock();
        double luDuration = (double)(luEnd - luStart) / CLOCKS_PER_SEC;

        std::cout << k << "\t"
                  << gaussDuration << "\t"
                  << luDuration << std::endl;
    }

    std::cout << std::endl;
}

void runHilbertAccuracyBenchmark()
{
    int sizes[3] = {5, 10, 15};

    std::cout << "Experiment 3: Hilbert matrix accuracy" << std::endl;
    std::cout << std::scientific << std::setprecision(6);

    for (int i = 0; i < 3; i++)
    {
        int n = sizes[i];

        std::vector<std::vector<double>> H = generateHilbertMatrix(n);
        std::vector<double> exactX = createOnesVector(n);
        std::vector<double> b = multiplyMatrixVector(H, exactX);

        std::vector<double> xGaussNoPivot = solveGaussNoPivot(H, b);
        std::vector<double> xGaussPartialPivot = solveGaussPartialPivot(H, b);

        LUDecomposition lu = decomposeLU(H);
        std::vector<double> y = forwardSubstitution(lu.L, b);
        std::vector<double> xLU = backwardSubstitution(lu.U, y);

        double gaussNoPivotError = computeRelativeError(xGaussNoPivot, exactX);
        double gaussNoPivotResidual = computeResidual(H, xGaussNoPivot, b);

        double gaussPartialPivotError = computeRelativeError(xGaussPartialPivot, exactX);
        double gaussPartialPivotResidual = computeResidual(H, xGaussPartialPivot, b);

        double luError = computeRelativeError(xLU, exactX);
        double luResidual = computeResidual(H, xLU, b);

        std::cout << "n = " << n << std::endl;
        std::cout << "Method\t\t\tRelativeError\t\tResidual" << std::endl;
        std::cout << "GaussNoPivot\t\t" << gaussNoPivotError << "\t" << gaussNoPivotResidual << std::endl;
        std::cout << "GaussPartialPivot\t" << gaussPartialPivotError << "\t" << gaussPartialPivotResidual << std::endl;
        std::cout << "LU\t\t\t" << luError << "\t" << luResidual << std::endl;
        std::cout << std::endl;
    }
}