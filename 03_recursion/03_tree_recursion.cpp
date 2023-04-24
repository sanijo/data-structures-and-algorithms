#include<iostream>

using std::cout;
using std::endl;

// Tree recursion
void fn_tree(int n)
{
    if (n>0)
    {
        cout << n << endl;
        fn_tree(n-1);
        fn_tree(n-1);
    }
}

int main (int argc, char *argv[])
{
    fn_tree(3); 
    cout << endl;
    
    return 0;
}
