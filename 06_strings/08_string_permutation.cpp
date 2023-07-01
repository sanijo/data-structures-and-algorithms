#include <iostream>

// permutation finding using recursion
// time complexity: O(n!)
void permutation(char* str, int k) {
    static int A[10] = {0}; // stores the index of the character in str
    static char res[10];  // stores the result
    // final result is stored in res when the string is exhausted and it is
    // printed
    if (str[k] == '\0') {
        res[k] = '\0';
        // print contents of res    
        for (const auto &v: res) {
           std::cout << v;
        }
        std::cout << std::endl;
    } else {
        for (size_t i = 0; str[i] != '\0'; ++i) {
            if (A[i] == 0) { 
                // if the character is not used store the character in res
                res[k] = str[i];
                A[i] = 1; // mark the character as used
                permutation(str, k + 1); 
                A[i] = 0; // unmark the character as used
            }
        }
    }
}

int main (int argc, char *argv[]) {
    char str[] = "mnkl";
    permutation(str, 0);

    return 0;
}
