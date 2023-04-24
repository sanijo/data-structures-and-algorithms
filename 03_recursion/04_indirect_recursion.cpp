#include<iostream>

using std::cout;
using std::endl;

template<typename T>
void fn_A(T);
template<typename T>
void fn_B(T);

template<typename T>
void fn_A(T n)
{
    if (n>0)
    {
        cout << n << endl;
        fn_B(n-1);
    }
}

template<typename T>
void fn_B(T n)
{
    if (n>0)
    {
        cout << n << endl;
        fn_A(n/2);
    }
}

int main (int argc, char *argv[])
{
    fn_A<float>(20.0);
    
    return 0;
}
