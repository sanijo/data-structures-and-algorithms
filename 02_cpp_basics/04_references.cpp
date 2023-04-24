#include<iostream>

using std::cout;
using std::endl;

int main (int argc, char *argv[])
{
    int a{6};
    int &r = a;

    cout << "a: " << a << "\n";
    cout << "r: " << r << "\n";

    int b{4};
    r=b;
    
    cout << "a: " << a << "\n";
    cout << "b: " << a << "\n";
    cout << "r: " << r << endl;

    return 0;
}
