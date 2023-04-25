#include<iostream>

using std::cout;
using std::endl;


inline constexpr int sum(int n)
{
    return (n==0) ? 0 : sum(n-1)+n;
}

int main (int argc, char *argv[])
{
    float result{0};
    result = sum(5); 
    cout << "Result: "<< result << endl;
    
    return 0;
}
