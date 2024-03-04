#include <iostream>

int countElementsLessThanX(int x) {
    // Using the formula S_n = n^2
    // Find the largest n such that n^2 <= x
    int n = 1;
    while ((long long)n * n <= x) {
        n++;
    }

    // Number of elements less than x is n - 1
    return n - 1;
}

int main() {
    int x;

    std::cout << "Enter the value of x: ";
    std::cin >> x;

    int count = countElementsLessThanX(x);

    std::cout << x << " is greater than " << count << " elements in the prefix sum." << std::endl;

    return 0;
}
