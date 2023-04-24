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
    int a{10};
    cout << a << endl;
    int *p;
    p = &a;
    cout << &p << endl; //adress of pointer variable
    cout << p << endl; // value inside p variable (adress of a)
    cout << &a << endl; // adress of a
    cout << *p << endl; // value inside adress of a

    int A[5] = {1,1,2,3,4};
    int *pA{A}; // or int *pA; pA = A[0];
    cout << pA << endl; // value inside pA variable (adress of A[0])

    for (size_t i=0; i<5; i++)
    {
        cout << *(pA+i) << " ";
    }
    cout << endl;

    for (size_t i=0; i<5; i++)
    {
        cout << pA[i] << " ";
    }
    cout << endl;

    // pointer to heap
    int *pH{new int [5]}; //or int *pH; p = new int [5];

    pH[0] = 1;
    pH[1] = 6;
    pH[2] = 2;
    pH[3] = 4;
    pH[4] = 3;

    for (size_t i=0; i<5; i++)
    {
        cout << *(pH+i) << " ";
    }
    cout << endl;

    for (size_t i=0; i<5; i++)
    {
        cout << pH[i] << " ";
    }
    cout << endl;

    cout << sizeof(pH) << endl;

    delete [] pH; // [] not necessary if not array
    
    return 0;
}
