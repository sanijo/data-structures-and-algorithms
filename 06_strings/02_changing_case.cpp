#include <cstddef>
#include <iostream>
#include <ostream>

int main (int argc, char *argv[])
{
    char name[100];
    std::cout << "Enter your name (char version): ";
    std::cin >> name;
    std::cout << "Entered name is " << name << "\n";

    char choice;
    bool isValidChoice=false;
    while(!isValidChoice)
    {
        std::cout << "Convert to uppercase or lowercase (enter U/L): ";
        std::cin >> choice;
        switch(choice)
        {
            case 'L':
                {
                    for(size_t i=0; name[i]!='\0'; ++i)
                    {
                        if(name[i]>=65 && name[i]<=90)
                        {
                            name[i]+=32; //if char is uppercase
                        }
                    }
                    isValidChoice=true;
                    break;
                }
            case 'U':
                {
                    for(size_t i=0; name[i]!='\0'; ++i)
                    {
                        if(name[i]>=97 && name[i]<=122)
                        {
                            name[i]-=32; //if char is lowercase
                        }
                    }
                    isValidChoice=true;
                    break;
                }
            default:
                {
                    std::cout << "Invalid choice" << std::endl;
                    break;
                }
        }
    }
    std::cout << "Choice is to change all char to " << choice << "\n";
    std::cout << "Modified name is " << name << "\n";

    return 0;
}
