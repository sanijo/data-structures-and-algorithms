#include<iostream>

using std::cout;
using std::endl;

struct Rectangle
{
    int l;
    int b;
    char x;
};

int main()
{
    struct Rectangle r1={1,5};

    cout << sizeof(r1) << endl;
    cout << r1.l << endl;
    cout << r1.b << endl;
    cout << r1.x << endl;

    r1.l = 2;
    r1.b = 3;
    r1.x = 'd';
    cout << r1.l << endl;
    cout << r1.b << endl;
    cout << r1.x << endl;
    
    return 0;
}
