#include<iostream>

using std::cout;
using std::endl;

int main (int argc, char *argv[])
{
    // Define row and column size
    int m{3};
    int n{3};

    // All in stack
    int A[m][n];
    // Fill the array
    for (int i{0}; i<m; i++)
    {
        for (int j{0}; j<n; j++)
        {
            A[i][j] = {i+j};
        }
    }
    // Print the array
    for (int i{0}; i<m; i++)
    {
        for (int j{0}; j<n; j++)
        {
            cout << "A(" << i << "," << j << ")=" << A[i][j] << "\n";
        }
    }
    cout << endl;

    // In stack and in heap
    int *B[m];
    for (int i{0}; i<m; i++)
    {
        B[i] = new int [n];
    }
    // Fill the array
    for (int i{0}; i<m; i++)
    {
        for (int j{0}; j<n; j++)
        {
            B[i][j] = {i+j};
        }
    }
    // Print the array
    for (int i{0}; i<m; i++)
    {
        for (int j{0}; j<n; j++)
        {
            cout << "B(" << i << "," << j << ")=" << B[i][j] << "\n";
        }
    }
    cout << endl;
    // Release memory for B
    for (int i{0}; i<m; i++)
    {
        delete [] B[i];
    }

    // In heap only
    int **C = new int* [m];
    for (int i{0}; i<m; i++)
    {
        C[i] = new int [n];
    }
    // Fill the array
    for (int i{0}; i<m; i++)
    {
        for (int j{0}; j<n; j++)
        {
            C[i][j] = {i+j};
        }
    }
    // Print the array
    for (int i{0}; i<m; i++)
    {
        for (int j{0}; j<n; j++)
        {
            cout << "C(" << i << "," << j << ")=" << C[i][j] << "\n";
        }
    }
    cout << endl;
    // Release memory for C
    for (int i{0}; i<m; i++)
    {
        delete [] C[i];
    }
    delete [] C;

    return 0;
}
