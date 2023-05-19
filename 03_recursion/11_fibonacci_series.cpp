#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;


// Example of excessive recursion O(2^n)
//int fibonacci(int n)
//{
//    if (n<=1)
//        return n;
//    return fibonacci(n-2)+fibonacci(n-1);
//}

// With memorization of function calls
int fibonacci(int n)
{
    static vector<int> F (n+1,-1);
    if (n<=1) {
        F.at(n)=n;
        return n;
    }
    else {
        if (F.at(n-2)==-1) {
            F.at(n-2)=fibonacci(n-2);
        }
        if (F.at(n-1)==-1) {
            F.at(n-1)=fibonacci(n-1);
        }
    }
    F.at(n)=F.at(n-2)+F.at(n-1);
    return F.at(n-2)+F.at(n-1);
}

int main (int argc, char *argv[])
{
    auto result = fibonacci(10); 
    cout << "Result: "<< result << endl;
    
    return 0;
}
