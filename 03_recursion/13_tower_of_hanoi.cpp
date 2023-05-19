#include<iostream>

using std::cout;
using std::endl;

void  TOH(int n, int A, int B, int C)
{
    if (n>0)
    {
        TOH(n-1, A, C, B);
        cout << "(" << A << "," << C << ")" << endl;
        TOH(n-1, B, A, C);
    }
}

int main (int argc, char *argv[])
{
    TOH(4, 1, 2, 3);
    
    return 0;
}
