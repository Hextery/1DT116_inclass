#include <iostream>
#include <vector>
#include <utility>
#include <cmath>  // Added math header

int main() {
    const int n = 50000000;
    std::vector<std::pair<int, bool>> myVector;
    
    // Resize and initialize vector
    myVector.resize(n);
    for (int i = 1; i <= n; ++i) {
        myVector[i-1] = {i, true};
    }

    // Use integer square root method
    for (int k = 2; k * k <= n; k++) {
        if (myVector[k-1].second) {
            // Mark multiples as non-prime
            for (int i = k * k; i <= n; i += k) {
                myVector[i - 1].second = false;
            }
        }
    }

    // Count primes
    int count = 0;
    for (const auto& pair : myVector) {
        if (pair.second) { 
            count++;
        }
    }
    
    std::cout << "Amount of primes: " << count << std::endl;

    return 0;
}
