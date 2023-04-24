#include<iostream>

using std::cout;
using std::endl;


//template<typename T>
//inline constexpr T fn_nested(T n)
//{
//    if (n>100)
//    {
//        return n-static_cast<T>(10);
//    }
//    return fn_nested(fn_nested(n+ static_cast<T>(11)));
//}

template<typename T>
inline constexpr T fn_nested(T n)
{
    auto f = [](T x) -> T { return x - static_cast<T>(10); };
    return (n > 100) ? f(n) : fn_nested(fn_nested(n + static_cast<T>(11)));
}


int main (int argc, char *argv[])
{
    float result{0};
    result = fn_nested<float>(95.3); 
    cout << "Result: "<< result << endl;
    
    return 0;
}
