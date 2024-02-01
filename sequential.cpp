#sequential-->
#include <iostream>
#include <vector>
#include <chrono>

void sequentialVectorAddition(std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c) {
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

    // Measure execution time for sequential vector addition
    auto startSequential = std::chrono::high_resolution_clock::now();
    sequentialVectorAddition(vectorA, vectorB, vectorC);
    auto endSequential = std::chrono::high_resolution_clock::now();

    // Output execution time for sequential version
    std::cout << "Sequential Execution Time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endSequential - startSequential).count()
              << " milliseconds" << std::endl;

    return 0;
}
