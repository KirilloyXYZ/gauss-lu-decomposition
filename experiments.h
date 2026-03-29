#ifndef EXPERIMENTS_H
#define EXPERIMENTS_H

// Запускает эксперимент сравнения времени решения одной системы
// для n = 100, 200, 500, 1000.
void runSingleSystemBenchmark();

// Запускает эксперимент для одной матрицы и нескольких правых частей
// для k = 1, 10, 100.
void runMultipleRightHandSidesBenchmark();

// Запускает эксперимент точности на матрице Гильберта
// для n = 5, 10, 15.
void runHilbertAccuracyBenchmark();

#endif