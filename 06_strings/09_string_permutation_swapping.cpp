#include <iostream>

// permutation finding using swapping

// swap the characters at index i and j
void swap(char* str, int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void permutation(char* str, int l) {
    // final result is stored in str when the string is exhausted and it is
    // printed
    if (str[l] == '\0') {
        // print contents of str    
        for (size_t i = 0; str[i] != '\0'; ++i) {
            std::cout << str[i];
        }
        std::cout << std::endl;
    } else {
        for (size_t i = l; str[i] != '\0'; ++i) {
            swap(str, l, i);
            permutation(str, l + 1); 
            swap(str, l, i);
        }
    }
}

int main (int argc, char *argv[]) {
    char str[] = "mnkl";
    permutation(str, 0);

    return 0;
}
