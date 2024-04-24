#include <iostream>

const int MAX_SIZE = 1000;

int sumOfZPattern(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int sum = 0;

    // Traverse the top row of the Z
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            sum += matrix[i][j];
        }
        std::cout << "Partial Sum: " << sum << "\n";
    }

    // Traverse the diagonal of the Z
    for (int i = 1; i < n - 1; ++i) {
        for (int j = n - i - 1; j < n - i + 1; ++j) {
            sum += matrix[i][j];
        }
        std::cout << "Partial Sum: " << sum << "\n";
    }

    // Traverse the bottom row of the Z
    for (int i = n - 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += matrix[i][j];
        }
        std::cout << "Partial Sum: " << sum << "\n";
    }

    return sum;
}

int main() {
    int n;
    std::cin >> n;

    int matrix[MAX_SIZE][MAX_SIZE];

    // Input matrix elements
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int result = sumOfZPattern(matrix, n);
    std::cout << "Final Sum: " << result << "\n";

    return 0;
}
