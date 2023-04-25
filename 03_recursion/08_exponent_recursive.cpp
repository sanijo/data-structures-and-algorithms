#include<iostream>

using std::cout;
using std::endl;


inline constexpr int pow(int m, int n)
{
    return (n==0) ? 1 : pow(m,n-1)*m;
}

int main (int argc, char *argv[])
{
    float result{0};
    result = pow(2,4); 
    cout << "Result: "<< result << endl;
    
    return 0;
}
