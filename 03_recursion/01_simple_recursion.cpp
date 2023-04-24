#include<iostream>

using std::cout;
using std::endl;

// Tail recursion
void fn_tail(int n)
{
    if (n>0)
    {
        cout << n << endl;
        fn_tail(n-1);
    }
}

// Head recursion
void fn_head(int n)
{
    if (n>0)
    {
        fn_head(n-1);
        cout << n << endl;
    }
}

int main (int argc, char *argv[])
{
    fn_tail(3); 
    cout << endl;
    fn_head(3);
    
    return 0;
}
