#include <iostream>

int addNumbers(int n) {
    // Base case: If n is 0, the sum is 0
    if (n == 0) {
        return 0;
    } else {
        // Recursive case: Sum of n natural numbers is n + sum of (n-1) natural numbers
        return n + addNumbers(n - 1);
    }
}

int main() {
    int num;

    std::cout << "Enter a positive integer: ";
    std::cin >> num;

    int sum = addNumbers(num);

    printf("Sum of first %d natural numbers = %d\n", num, sum);

    return 0;
}
