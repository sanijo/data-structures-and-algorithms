#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>

int main (int argc, char *argv[])
{
    char expression[11]={'T','h','e',' ',' ','e','n','d','\0'};
    size_t vowels=0;
    size_t consonents=0;

    for(size_t i=0; expression[i]!='\0'; ++i)
    {
        if(
          expression[i]=='a'||expression[i]=='e'|| 
          expression[i]=='i'|| expression[i]=='o' || 
          expression[i]=='u' || expression[i]=='A'|| 
          expression[i]=='E' || expression[i]=='I'|| 
          expression[i]=='O' || expression[i]=='U')
        {
            vowels++;
        }
        else if(
                (expression[i]>=65 && expression[i]<=90) 
             || (expression[i]>=97 && expression[i]<122))
        {
            consonents++;
        }
    }
    std::cout << "vowels = " << vowels
              << "\n" << "consonent = " << consonents << std::endl;

    // Words count
    size_t space=0;
    for(size_t i=0; expression[i]!='\0'; ++i)
    {
        // Checking if it is a space and not white space
        if(expression[i]==' ' && expression[i-1] != ' ')
        {
            space++;
        }
    }
    std::cout << "Number of words is = " << space+1 << std::endl;

    return 0;
}
