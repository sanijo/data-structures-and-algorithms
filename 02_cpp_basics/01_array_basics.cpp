#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int A[5];
    A[0] = 12;
    A[1] = 13;
    A[2] = 14;

    cout<< sizeof(A) << endl;
    cout<< A[2] << endl;
    cout<< A[4] << endl;
    //C style
    printf("%d\n",A[2]);

    int n;
    cout<< "Enter Size: ";
    cin >> n;
    int B[n];
    B[0] = 2;
    for (auto& element: B)
    {
        cout<< element << " "; 
    }
    cout<< endl;
    
    return 0;
}
