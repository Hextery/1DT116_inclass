#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>
#include <chrono>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <Numbers of threads>" << std::endl;
        return 1;
    }
    const int threads = std::atoi(argv[1]);
    const int n = 50000000;
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    int sqrt_n = std::sqrt(n);
    omp_set_num_threads(threads);
    auto start_time = std::chrono::high_resolution_clock::now();
    #pragma omp parallel for schedule(dynamic)
    for (int k = 2; k <= sqrt_n ; k++) {
            // Mark multiples of k starting from k*k
            for (int i = k; i <= n; i += k) {
                isPrime[i] = false;
            }
        
    }

    // Count primes
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    std::cout << "Prime numbers up to " << n << ": " << count << std::endl;
    std::cout << "Time: "<< duration.count() << "Seconds" << std::endl;

    return 0;
}
