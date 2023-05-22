#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>

int main (int argc, char *argv[])
{
    char name1 []="Some Name";
    std::cout << "name1 " << name1 << std::endl;

    char name2[100];
    std::cout << "Enter your name (char version): ";
    std::cin >> name2;

    std::cout << "Entered name is " << name2 << std::endl;

    size_t i=0;
    while(name2[i] != '\0')
    {
        i++;
    }
    std::cout << "Length of name2 is " << i << std::endl;

    std::cout << "Enter your name (string version): ";
    // Ignore remaining characters in the buffer
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cin.ignore(i+1, '\n'); 
    std::string stringName;
    std::getline(std::cin,stringName);
    std::cout << "Entered name is " << stringName << std::endl;

    return 0;
}
