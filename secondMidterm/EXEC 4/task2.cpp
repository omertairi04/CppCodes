#include <iostream>
#include <cstring>

int main() {
    const int MAX_LENGTH = 80;

    char str1[MAX_LENGTH + 1];
    char str2[MAX_LENGTH + 1];

    // Read two strings of the same length
    std::cin >> str1 >> str2;

    int length = strlen(str1);

    char result[MAX_LENGTH + 1];

    // Compare strings and build the result string
    for (int i = 0; i < length; ++i) {
        if (str1[i] == str2[i]) {
            result[i] = '*';
        } else {
            int count = 1;
            for (int j = i + 1; j < length; ++j) {
                if (str1[i] == str1[j]) {
                    count++;
                }
            }

            if (count > 9) {
                result[i] = 'X';
            } else {
                result[i] = '0' + count;
            }
        }
    }

    result[length] = '\0';  // Null-terminate the result string

    // Output the result string
    std::cout << result << std::endl;

    return 0;
}
