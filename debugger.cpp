#include <iostream>
#include <vector>

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int x = 5;
    int y = 3;
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    int fact = factorial(x);

    int sum = 0;
    for (int num : numbers) {
        sum += num * y;
    }

    std::cout << "Factorial of " << x << " is " << fact << std::endl;
    std::cout << "Sum of numbers * " << y << " is " << sum << std::endl;

    return 0;
}
