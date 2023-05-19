#include<iostream>

using std::cout;
using std::endl;


inline constexpr int nCr(int n, int r)
{
    return (n==r || r==0) ? 1 : nCr(n-1, r-1)+nCr(n-1, r);
}

int main (int argc, char *argv[])
{
    float result{0};
    result = nCr(5,2); 
    cout << "Result: "<< result << endl;
    
    return 0;
}
