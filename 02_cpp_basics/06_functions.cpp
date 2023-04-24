#include<iostream>
#include<chrono>

using std::cout;
using std::endl;


template<typename T>
inline constexpr T sum(T a, T b)
{
    return a+b;
}

int main (int argc, char *argv[])
{
    float a{1.13};
    float b{6.13};

    // Start timer
    auto start = std::chrono::high_resolution_clock::now();

    cout << "Sum of " << a << " and " << b << ": " << sum(a,b) << "\n";

    // End timer
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration
    auto duration = 
        std::chrono::duration_cast<std::chrono::microseconds>(end-start);

    cout << "Duration: " << duration.count() << " microseconds" << endl;
    
    return 0;
}
