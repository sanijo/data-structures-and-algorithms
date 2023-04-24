#include<iostream>

using std::cout;
using std::endl;


template<typename T>
void swap(T, T); // by value

template<typename T>
void swap(T*, T*); // by adress (pointer)

template<typename  T>
void swap_ref(T&, T&); // by refference (alias)

template<typename T>
void swap(T a, T b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void swap(T* a, T* b)
{
    T tmp;
    tmp = *a; // dereference pointer a
    *a = *b;
    *b = tmp;
}

template<typename T>
void swap_ref(T& a, T& b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int x(5);
    int y(6);

    cout << "x:" << x << " y:" << y << endl;

    swap<int>(x, y);
    cout << "x:" << x << " y:" << y << endl;

    swap<int>(&x, &y); // may be inline function. Use reference for cheap f-ns
    cout << "x:" << x << " y:" << y << endl;

    swap_ref(x, y);
    cout << "x:" << x << " y:" << y << endl;
    
    return 0;
}
