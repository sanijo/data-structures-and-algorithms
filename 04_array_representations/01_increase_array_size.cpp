#include<iostream>

using std::cout;
using std::endl;

int main (int argc, char *argv[])
{
    int np = 5;
    int *p = new int [np];

    for (int i{0}; i<np; i++)
    {
        p[i] = i;
    }

    for (int i{0}; i<np; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    int nq = 10;
    int *q = new int [nq];

    // Copy values from p to q
    for (int i{0}; i<np; i++)
    {
        q[i] = p[i];
    }

    delete [] p; // dealocate memory
    p = q; // take the pointer pointing to the memory of q
    q = nullptr; //set q pointer to nullptr
                 
    for (int i{0}; i<nq; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    delete [] p;
    
    return 0;
}
