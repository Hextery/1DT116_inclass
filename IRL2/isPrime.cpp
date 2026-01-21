#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

int main() {
    const int n = 50000000; // n = max
    std::vector<std::pair<int, bool>> myVector;
    for (int i = 1; i <= n; ++i) {
        myVector.emplace_back(i, true);
    }

    //int k = 2; // b�rjar p� tv�
    for (int k = 2; k < sqrt(n) ; k++)
    {
        if (myVector[k-1].second) {
            // kollar prim
            for (int i = k; i <= n; i += k) {
                myVector[i - 1].second = false;
            }
        }
    }/*
    while (k * k <= n) {
        if (myVector[k - 1].second) {
            // kollar prim
            for (int i = k; i <= n; i += k) {
                myVector[i - 1].second = false;
            }
        }
        k++;
    }*/

    // Skriver ut
    std::cout << "Prime numbers up to " << n << ":" << std::endl;
    int count = 0;
    for (const auto& pair : myVector) {
        if (pair.second) { 
            //std::cout << pair.first << " ";
            count++;
        }
    }
    std::cout << "Amount : " << count << std::endl;

    return 0;
}
