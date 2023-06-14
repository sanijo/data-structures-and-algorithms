#include <cstddef>
#include <iostream>

int main (int argc, char *argv[]) {

    // Find duplicates in a string using for loops
    // Time complexity: O(n^2)
    // Space complexity: O(1)
    // Note: This method modifies the original string
    //      by replacing the duplicates with -1
    //      so that they are not counted again
    //      when the outer loop encounters them
    //      in the inner loop

    std::cout << "Find duplicates in a string using for loops" << std::endl;
    char A[] = "dupllicatessu";
    // Print the string
    std::cout << "Original string: " << A << std::endl;
    for (size_t i = 0; A[i] != '\0'; ++i) {
        size_t count = 1;
        if (A[i] != -1) {
            for (size_t j = i + 1; A[j] != '\0'; ++j) {
                if (A[i] == A[j]) {
                    count++;
                    A[j] = -1;
                }
            }
            if (count > 1) {
                std::cout << A[i] << " is duplicated " 
                    << count << " times" << std::endl;
            }
        }
    }
    // Print modified string
    std::cout << "Modified string: " << A << std::endl;
    std::cout << std::endl;

    // Find duplicates in a string using hash table
    // ASCII value of 'a' is 97 while that of 'z' is 122. Also ASCII value of 
    // 'A' is 65 while that of 'Z' is 90 therefore we can use 
    // an array of size 26 to store the count of each character.
    // Short description of the algorithm:
    //     1. Create a hash table of size 26 and initialize all elements to 0
    //     2. Iterate through the string and increment the count of each
    //     character in the hash table
    //     3. Iterate through the hash table and print the characters that
    //     have a count greater than 1
    // Time complexity: O(n)
    // Space complexity: O(n)
    // Note: This method does not modify the original string
    
    std::cout << "Find duplicates in a string using hash table" << std::endl;
    char B[] = "dupllicatessu";
    // Print the string
    std::cout << "Original string: " << B << std::endl;
    // Create a hash table 
    int H[26] = {0};
    for (size_t i = 0; B[i] != '\0'; ++i) {
        H[B[i] - 97]++; 
    }
    for (size_t i = 0; i < 26; ++i) {
        if (H[i] > 1) {
            std::cout << static_cast<char>(i + 97) << " is duplicated " 
                << H[i] << " times" << std::endl;
        }
    }
    std::cout << std::endl;

    //  Same as above but for uppercase letters
    char C[] = "DUPLLICATESSU";
    // Print the string
    std::cout << "Original string: " << C << std::endl;
    // Create a hash table
    int I[26] = {0};
    for (size_t i = 0; C[i] != '\0'; ++i) {
        I[C[i] - 65]++;
    }
    for (size_t i = 0; i < 26; ++i) {
        if (I[i] > 1) {
            std::cout << static_cast<char>(i + 65) << " is duplicated " 
                << I[i] << " times" << std::endl;
        }
    }
    std::cout << std::endl;

    // Combined for uppercase and lowercase letters
    char D[] = "DUPLLICATESSUdupllicatessu";
    // Print the string
    std::cout << "Original string: " << D << std::endl;
    // Create a hash table
    int J[52] = {0};
    for (size_t i = 0; D[i] != '\0'; ++i) {
        if (D[i] >= 65 && D[i] <= 90) {
            J[D[i] - 65]++;
        } else if (D[i] >= 97 && D[i] <= 122) {
            J[D[i] - 71]++; // 71 because 97 - 26 = 71 (lowercase in hash table
                            // is stored from index 26 to 51)
        }
    }
    for (size_t i = 0; i < 52; ++i) {
        if (J[i] > 1) {
            if (i < 26) {
                std::cout << static_cast<char>(i + 65) << " is duplicated " 
                    << J[i] << " times" << std::endl;
            } else {
                std::cout << static_cast<char>(i + 71) << " is duplicated " 
                    << J[i] << " times" << std::endl;
            }
        }
    }

    return 0;
}
