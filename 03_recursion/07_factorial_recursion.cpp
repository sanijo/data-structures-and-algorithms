#include<iostream>

using std::cout;
using std::endl;


inline constexpr int factorial(int n)
{
    return (n==0) ? 1 : factorial(n-1)*n;
}

int main (int argc, char *argv[])
{
    float result{0};
    result = factorial(5); 
    cout << "Result: "<< result << endl;
    
    return 0;
}
