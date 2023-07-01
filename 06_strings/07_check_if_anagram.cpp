#include <iostream>

int main (int argc, char *argv[]) {
    // find if two strings are anagrams using hash table
    char str1[] = "decimal";
    char str2[] = "medical";
    size_t H[26] = {0};

    // iterate over str1 and increment the hash table
    for (size_t i = 0; str1[i] != '\0'; ++i) {
        H[str1[i] - 97]++;
    }

    // iterate over str2 and decrement the hash table
    for (size_t i = 0; str2[i] != '\0'; ++i) {
        H[str2[i] - 97]--;
        // stop if the hash table value is less than 0
        if (H[str2[i] - 97] < 0) {
            std::cout << "Not an anagram\n";
            break;
        }
    }

    // check if the hash table is empty
    bool isAnagram = true;
    for (size_t i = 0; i < 26; ++i) {
        if (H[i] != 0) {
            isAnagram = false;
            break;
        }
    }

    if (isAnagram) {
        std::cout << "Anagram\n";
    } else {
        std::cout << "Not an anagram\n";
    }

    // find if two strings are anagrams using bit manipulation (sufficient if
    // there is no repetition of characters) - O(n)
    // XOR all the characters in both strings
    // if the strings are anagrams, the result will be 0
    // if the strings are not anagrams, the result will be non-zero
    // XOR operation explanation:
    // 1 ^ 1 = 0
    // 1 ^ 0 = 1
    // 0 ^ 1 = 1
    // 0 ^ 0 = 0
    // e.g. letter a first appears in str1, so H1 = 0001:
    // 0000 ^ (0001 << 0) = 0001
    // letter a second appears in str1 so H1 = 0001 ^ (0001 << 0) = 0000
    int H1 = 0; 
    for (size_t i = 0; str1[i] != '\0'; ++i) {
        H1 = H1 ^ (1 << (str1[i] - 97));
    }
    for (size_t i = 0; str2[i] != '\0'; ++i) {
        H1 = H1 ^ (1 << (str2[i] - 97));
    }
    if (H1 == 0) {
        printf("Anagram\n");
    } else {
        printf("Not an anagram\n");
    }

    return 0;
}
