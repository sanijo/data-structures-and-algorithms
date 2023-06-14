#include <iostream>

int main (int argc, char *argv[]) {
    // Find duplicates in a string using bitwise operations
    char expression[] = "interesting";

    // 1. Create a variable to store the presence of each letter. 
    // int of 32 bits is used to store the presence of 26 letters. 
    // All bits are assigned to 0 by default. 0000
    int H = 0;
    // print the size of H in bits
    std::cout << "Size of H in bits: " << sizeof(H) * 8 << std::endl;

    // 2. Iterate over the string
    for (size_t i = 0; expression[i] != '\0'; ++i) {
        // 3. Create a variable that will set the bit corresponding to each 
        // letter. In bits it looks similar to this: 0001
        int x = 1;
        // 4. Shift 1 to the left by the position of each letter.
        // Example: if the letter is 'c', then the position is 2 and if shifted
        // by 2, then the bit will look like this: 0100.
        x = x << (expression[i] - 97);
        // 5. Check if the bitwise AND of H and x is 0 (masking)
        //    If it is 0, then the letter is not present in the string
        //    If it is not 0, then the letter is present in the string
        if ((H & x) > 0) {
            std::cout << expression[i] << " is duplicated" << std::endl;
        } else {
            // 6. If the letter is not present in the string, then
            //    set the bit corresponding to the letter to 1.
            //    Example: if the letter is 'c', then H | x will look like this:
            //    0000 | 0100 = 0100
            H = H | x;
        }
    }
    std::cout << std::endl;
    
    // Same as above but for both upper and lower case letters
    char expression2[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    long int H2 = 0;
    std::cout << "Size of H2 in bits: " << sizeof(H2) * 8 << std::endl;
    for (size_t i = 0; expression2[i] != '\0'; ++i) {
        long int x = 1;
        if (expression2[i] >= 65 && expression2[i] <= 90) {
            x = x << (expression2[i] - 65); // uppercase
        } else if (expression2[i] >= 97 && expression2[i] <= 122) {
            x = x << (expression2[i] - 71); // lowercase 71 = 97 - 26
        }
        if ((H2 & x) > 0) {
                std::cout << expression2[i] << " is duplicated" << std::endl;
        } else {
            H2 = H2 | x; // set the bit to 1 by performing merging
        }
    }

    // print H2 in binary:
    std::cout << "H2 in binary: ";
    for (int i = sizeof(H2) * 8 - 1; i >= 0; --i) {
        std::cout << ((H2 >> i) & 1);
    }
    std::cout << std::endl;

    return 0;
}
