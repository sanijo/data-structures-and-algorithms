#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cassert>
#include <ctime>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;

class Array
{
private:
    int *A;
    int size;
    int length;

    void swap(int &l, int &r);

public:
    Array():
        size(10),
        length(0)
    {
        A = new int [size];
        for(int i=0; i<length; i++)
        {
            A[i] = 0;
        }
    }

    Array(int size):
        size(size),
        length(0)
    {
        A = new int [size];
        for(int i=0; i<length; i++)
        {
            A[i] = 0;
        }
    }

    Array(int size, int length):
        size(size),
        length(length)
    {
        if (length>size)
        {
            throw std::invalid_argument("Length cannot be greater than size");
        }
        A = new int [size];
        for(int i=0; i<length; i++)
        {
            A[i] = 0;
        }
    }

    ~Array()
    {
        delete [] A;
    }

    void fillArrayWithRandomNumber(int minRange, int maxRange, bool sorted=true);
    void display(string message);
    void append(int x);
    void insert(int index, int x);
    int remove(int index);
    int linearSearch(int key, bool moveToHead=true);
    int binarySearch(int key);
    int get(int index);
    void set(int index, int value);
    int max();
    int min();
    int sum();
    float avg();
    void reverse();
    void shiftRight();
    void shiftRightRotation();
    void shiftLeft();
    void shiftLeftRotation();
    void insertSort(int number);
    bool isSorted();
    void reArrange();
    Array* merge(const Array &arr);
    Array* arrayUnion(const Array &arr);
    Array* arrayIntersection(const Array &arr);
    Array* arrayDifference(const Array &arr);

};

void Array::fillArrayWithRandomNumber(int minRange, int maxRange, bool sorted)
{
    for(int i=0; i<length; i++)
    {
        A[i]=minRange+rand()%(maxRange-minRange+1);
    }
    if(sorted)
    {
        std::sort(A, A+length);
    }
}

void Array::display(const string message)
{
    cout << message << "\n";
    for(int i{0}; i<length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Array::append(int x)
{
    if (length<size)
        A[length++] = x;
}

void Array::insert(int index, int x)
{
    if (index>=0 && index<=length)
    {
        for(int i=length; i>index; i--)
        {
            A[i] = A[i-1];
        }
        A[index] = x;
        length++;
    }
}

int Array::remove(int index)
{
    if (index>=0 && index<=length)
    {
        int removed_value = A[index];
        for(int i=index; i<length-1; i++)
        {
            A[i] = A[i+1];
        }
        length--;
        return removed_value;
    }
    return 0;
}

void Array::swap(int &l, int &r)
{
    int tmp=l;
    l=r;
    r=tmp;
}

int Array::linearSearch(int key, bool moveToHead)
{
    for(int i{0}; i<length; i++)
    {
        if(key==A[i])
        {
            if(moveToHead)
            {
                swap(A[i], A[0]);
                return 0;
            } 
            else
            {
                swap(A[i], A[i-1]);
                return static_cast<int>(i)-1;
            }
        }
    }
    return -1;
}

int Array::binarySearch(int key)
{
    int l{0};
    int h{length-1};

    while (l<=h)
    {
        int mid = l+(h-l)/2;
        if(key==A[mid])
        {
            return mid;
        }
        else if(key<A[mid])
        {
            h=mid-1;
        }
        else 
        {
            l=mid+1;
        }
    }

    return -1;
}

int Array::get(const int index)
{
    if(index>=0 && index<length)
    {
        return A[index];
    }
    return -1;
}

void Array::set(int index, int value)
{
    if(index>=0 && index<length)
    {
        A[index] = value;
    }
}

int Array::max()
{
    int max=A[0];
    for(int i{0}; i<length; i++)
    {
        if(A[i]>max)
        {
            max = A[i];
        }
    }
    return max;
}

int Array::min()
{
    int min=A[0];
    for(int i{0}; i<length; i++)
    {
        if(A[i]<min)
        {
            min = A[i];
        }
    }
    return min;
}

int Array::sum()
{
    int sum=0;
    for(int i{0}; i<length; i++)
    {
        sum += A[i];
    }
    return sum;
}

float Array::avg()
{
    return static_cast<float>(sum())/length;
}

void Array::reverse()
{
    int start = 0;
    int end = length-1;
    
    while(start < end)
    {
        swap(A[start], A[end]);
        start++;
        end--;
    }
}

void Array::shiftRight()
{
    for(int i=length-1; i>0; i--)
    {
        A[i] = A[i-1];
    }
    A[0] = 0;
}

void Array::shiftRightRotation()
{
    auto tmp = A[length-1];
    for(int i=length-1; i>0; i--)
    {
        A[i] = A[i-1];
    }
    A[0] = tmp;
}

void Array::shiftLeft()
{
    for(int i=1; i<length; i++)
    {
        A[i-1] = A[i];
    }
    A[length-1] = 0;
}

void Array::shiftLeftRotation()
{
    auto tmp = A[0];
    for(int i=1; i<length; i++)
    {
        A[i-1] = A[i];
    }
    A[length-1] = tmp;
}

void Array::insertSort(int number)
{
    if(length==size)
    {
        return;
    }
    int i = length-1;
    while(i>=0 && A[i]>number)
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1] = number;
    length++;
}

bool Array::isSorted()
{
    for(int i=0; i<length-1; i++)
    {
        if(A[i]>A[i+1])
        {
            return false;
        }
    }
    return true;
}

void Array::reArrange()
{
    int i=0;
    int j=length-1;

    do
    {
        while(A[i]<0)
        {
            i++;
        }
        while(A[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            swap(A[i],A[j]);
        }
    } while(i<j);
}

Array* Array::merge(const Array &arr)
{
    Array *arrMerged = new Array(size+arr.size);

    int i=0;
    int j=0;
    int k=0;

    while(i<length && j<arr.length)
    {
        if(A[i]<arr.A[j])
        {
            arrMerged->A[k++]=A[i++];
        }
        else
        {
            arrMerged->A[k++]=arr.A[j++];
        }
    }
    for(; i<length; i++)
    {
        arrMerged->A[k++]=A[i];
    }
    for(; j<arr.length; j++)
    {
        arrMerged->A[k++]=arr.A[j];
    }
    arrMerged->length=length+arr.length;

    return arrMerged;
}

Array* Array::arrayUnion(const Array &arr)
{
    Array *arrMerged = new Array(size+arr.size);

    int i=0;
    int j=0;
    int k=0;

    while(i<length && j<arr.length)
    {
        if(A[i]<arr.A[j])
        {
            arrMerged->A[k++]=A[i++];
        }
        else if(arr.A[j]<A[i])
        {
            arrMerged->A[k++]=arr.A[j++];
        }
        else
        {
            arrMerged->A[k++]=A[i++];
            j++;
        }
    }
    // Copy remaining elements if any
    while(i<length)
    {
        arrMerged->A[k++]=A[i++];
    }
    while(j<arr.length)
    {
        arrMerged->A[k++]=arr.A[j++];
    }
    arrMerged->length=k;

    return arrMerged;
}

Array* Array::arrayIntersection(const Array &arr)
{
    Array *arrMerged = new Array(size+arr.size);

    int i=0;
    int j=0;
    int k=0;

    while(i<length && j<arr.length)
    {
        if(A[i]<arr.A[j])
        {
            i++;
        }
        else if(arr.A[j]<A[i])
        {
            j++;
        }
        else
        {
            arrMerged->A[k++]=A[i++];
            j++;
        }
    }
    arrMerged->length=k;

    return arrMerged;
}

Array* Array::arrayDifference(const Array &arr)
{
    Array *arrMerged = new Array(size+arr.size);

    int i=0;
    int j=0;
    int k=0;

    while(i<length && j<arr.length)
    {
        if(A[i]<arr.A[j])
        {
            arrMerged->A[k++]=A[i++];
        }
        else if(arr.A[j]<A[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    // Copy remaining elements if any
    while(i<length)
    {
        arrMerged->A[k++]=A[i++];
    }
    arrMerged->length=k;

    return arrMerged;
}


int main (int argc, char *argv[])
{
    Array A(10,5);
    Array B(10,4);

    A.display("Array A");
    B.display("Array B");

    int minRange = 0;
    int maxRange = 10;
    srand(time(0)); // seed with current time

    A.fillArrayWithRandomNumber(minRange, maxRange);
    B.fillArrayWithRandomNumber(minRange, maxRange);

    A.display("Array A");
    B.display("Array B");

    Array *C = new Array;

    C = A.merge(B);
    C->display("Array C merge");

    C = A.arrayIntersection(B);
    C->display("Array C intersection");

    C = A.arrayUnion(B);
    C->display("Array C union");

    C = A.arrayDifference(B);
    C->display("Array C difference");

    delete C;

    return 0;
}
