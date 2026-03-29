#include "experiments.h"

int main()
{
    runSingleSystemBenchmark();
    runMultipleRightHandSidesBenchmark();
    runHilbertAccuracyBenchmark();

    return 0;
}