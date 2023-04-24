#include<iostream>

using std::cout;
using std::endl;


int fn(int n)
{
    if (n>0)
    {
        return fn(n-1)+n;
    }
    return 0;
}

// Instead of static variable x can be defined as global:
// int x{0};
int fn_static(int n)
{
    static int x{0};
    if (n>0)
    {
        x++;
        return fn_static(n-1)+x;
    }
    return 0;
}

int main (int argc, char *argv[])
{
    int i{0};
    i = fn(5);
    cout << i << endl;
    i = fn_static(5); // 25
    cout << i << endl;
    i = fn_static(5); // now 50 is expected because x variable is static
    cout << i << endl;

    return 0;
}
