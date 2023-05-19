#include<iostream>

using std::cout;
using std::endl;


template<typename T>
T e(T x, T n)
{
    static T s{static_cast<T>(1)};

    if (n==0)
        return s;
    s=static_cast<T>(1)+x/n*s;
    return e(x, n-1);
}

int main (int argc, char *argv[])
{
    auto result = e<double>(1,10); 
    cout << "Result: "<< result << endl;
    
    return 0;
}
