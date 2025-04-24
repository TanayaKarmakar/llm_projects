
#include <iostream>
#include <chrono>
#include <iomanip>

double calculate(long long iterations, double param1, double param2) {
    double result = 1.0;
    for (long long i = 1; i <= iterations; ++i) {
        double j = i * param1 - param2;
        result -= (1.0 / j);
        j = i * param1 + param2;
        result += (1.0 / j);
    }
    return result;
}

int main() {
    // Start time measurement
    auto start = std::chrono::high_resolution_clock::now();

    double result = calculate(100000000LL, 4.0, 1.0) * 4;

    // End time measurement
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate execution time in seconds
    std::chrono::duration<double> execution_time = end - start;
    
    // Output result and execution time
    std::cout << "Result: " << std::fixed << std::setprecision(12) << result << "\n";
    std::cout << "Execution Time: " << std::fixed << std::setprecision(6) << execution_time.count() << " seconds\n";

    return 0;
}
