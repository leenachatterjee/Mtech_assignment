#include <iostream>
#include <vector>
#include <algorithm>

int Difference(const std::vector<int>& arr) {
    if (arr.size() < 2) {
        return 0;
    }

    // Sort the array in ascending order
    std::vector<int> Arr = arr;
    std::sort(Arr.begin(), Arr.end());

    // Calculate the largest difference between subsequent entries
    int maxDiff = 0;
    for (size_t i = 1; i < Arr.size(); ++i) {
        int diff = Arr[i] - Arr[i - 1];
        if (diff > maxDiff) {
            maxDiff = diff;
        }
    }

    return maxDiff;
}

int main() {
    std::vector<int> A = {17, 3, 14, 2, 11, 7, 5 };

    std::cout << "Enter the Array [A] = [";
    for (size_t i = 0; i < A.size(); ++i) {
        std::cout << A[i];
        if (i < A.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]." << std::endl;

    int maxDifference = Difference(A);

    std::cout << "Sorted Array is: [";
    std::sort(A.begin(), A.end());
    for (size_t i = 0; i < A.size(); ++i) {
        std::cout << A[i];
        if (i < A.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]." << std::endl;

    std::cout << "Largest Difference between two subsequent entries is: " << maxDifference << std::endl;

    return 0;
}
