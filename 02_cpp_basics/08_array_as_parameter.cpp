#include <cstddef>
#include<iostream>

using std::cout;
using std::endl;

template<typename T>
void print_array(T, T); 

template<typename T>
T* create_array(size_t); 

template<typename T>
void print_array(T a[], T n) // int* a can be used but int a[] is array specific
{
//    for(size_t i=0; i<n; i++)
    for (auto el: a) {
    
    }
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

template<typename T>
T* create_array(size_t n)
{
    T *p{new T [n]};

    // initialize
    for(size_t i=0; i<n; i++)
    {
        p[i] = static_cast<T>(0);
    }
    
    return p;
}


int main()
{
    float A[] = {1.1, 2.2, 3.3, 4.1};
    print_array<float>(A, 4);

    auto *p = create_array<float>(3);

    print_array<float>(p, 5);

    p[0] = 1.1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;

    print_array<float>(p, 5);

    delete [] p;
    
    return 0;
}
