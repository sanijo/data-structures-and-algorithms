#include <cstddef>
#include <ios>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>

bool isValid(const char *name)
{
    for(size_t i=0; name[i]!='\0'; ++i)
    {
        if(
           !(name[i]>=65 && name[i]<=90) // uppercase letters
        && !(name[i]>=97 && name[i]<=122) // lowercase letters
        && !(name[i]>=48 && name[i]<=57)) // numbers
        {
            return false;
        }
    }
    return true;
}

int main (int argc, char *argv[])
{
    char name[]="Mirja!na";
    std::cout << std::boolalpha;
    std::cout << "variable name:" << name << " is valid: " 
              << isValid(name) << std::endl;

    return 0;
}
