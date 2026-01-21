#include <iostream>
#include <vector>
#include <cmath>

int main() {
    const int n = 50000000;
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int k = 2; k * k <= n; k++) {
        if (isPrime[k]) {
            // Mark multiples of k starting from k*k
            for (int i = k * k; i <= n; i += k) {
                isPrime[i] = false;
            }
        }
    }

    // Count primes
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }

    std::cout << "Prime numbers up to " << n << ": " << count << std::endl;

    return 0;
}
