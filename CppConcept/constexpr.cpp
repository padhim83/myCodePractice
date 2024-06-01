#include <iostream>

// Function to compute the factorial of a number at compile time using constexpr
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

// Trigger a static_assert with the constexpr value as part of the message
static_assert(factorial(5) == 120, "Factorial of 5 is not 120");

int main() {
    constexpr int size = 10;
    constexpr double pi = 3.14159;

    // Compute factorial of 5 at compile time
    constexpr int result = factorial(5);

    // Output the result
    std::cout << "Factorial of 5 is: " << result << std::endl;

    return 0;
}
