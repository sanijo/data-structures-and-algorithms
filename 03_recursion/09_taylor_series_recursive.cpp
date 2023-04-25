#include<iostream>

using std::cout;
using std::endl;


double e(int x, int n)
{
    static double p{1};
    static double f{1};
    double r;

    if (n==0)
        return 1;
    r=e(x,n-1);
    p=p*x;
    f=f*n;
    return r+p/f;
}

int main (int argc, char *argv[])
{
    float result{0};
    result = e(1,10); 
    cout << "Result: "<< result << endl;
    
    return 0;
}
