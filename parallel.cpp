#parallel-->
#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

void parallelVectorAddition(std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c) {
    #pragma omp parallel for
    for (int i = 0; i < a.size(); ++i) {
        a[i] = b[i] + c[i];
    }
}

int main() {
    const int size = 1000000; // Adjust the size of vectors as needed
    std::vector<int> vectorA(size), vectorB(size), vectorC(size);

    // Initialize vectors with some values
    for (int i = 0; i < size; ++i) {
        vectorB[i] = i;
        vectorC[i] = i * 2;
    }

    // Measure execution time for parallel vector addition
    double startParallel = omp_get_wtime();
    parallelVectorAddition(vectorA, vectorB, vectorC);
    double endParallel = omp_get_wtime();

    // Output execution time for parallel version
    std::cout << "Parallel Execution Time: " << endParallel - startParallel << " seconds" << std::endl;

    return 0;
}
