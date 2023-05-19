#include <cstdlib>
#include<iostream>
#include<string>
#include<cassert>
#include<ctime>
#include<algorithm>

using std::cout;
using std::endl;
using std::string;

struct Array
{
    int *A;
    int size;
    int length;
};

void fillArrayWithRandomNumber(Array &arr, int minRange, int maxRange, bool sorted=true)
{
    for(int i=0; i<arr.length; i++)
    {
        arr.A[i]=minRange+rand()%(maxRange-minRange+1);
    }
    if(sorted)
    {
        std::sort(arr.A, arr.A+arr.length);
    }
}

void display(Array arr, const string message)
{
    cout << message << "\n";
    for(int i{0}; i<arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

void append(Array &arr, int x)
{
    if (arr.length<arr.size)
        arr.A[arr.length++] = x;
}

void insert(Array &arr, int index, int x)
{
    if (index>=0 && index<=arr.length)
    {
        for(int i=arr.length; i>index; i--)
        {
            arr.A[i] = arr.A[i-1];
        }
        arr.A[index] = x;
        arr.length++;
    }
}

int remove(Array &arr, int index)
{
    if (index>=0 && index<=arr.length)
    {
        int removed_value = arr.A[index];
        for(int i=index; i<arr.length-1; i++)
        {
            arr.A[i] = arr.A[i+1];
        }
        arr.length--;
        return removed_value;
    }
    return 0;
}

void swap(int &l, int &r)
{
    int tmp=l;
    l=r;
    r=tmp;
}

int linearSearch(Array &arr, int key, bool moveToHead=true)
{
    for(int i{0}; i<arr.length; i++)
    {
        if(key==arr.A[i])
        {
            if(moveToHead)
            {
                swap(arr.A[i], arr.A[0]);
                return 0;
            } 
            else
            {
                swap(arr.A[i], arr.A[i-1]);
                return static_cast<int>(i)-1;
            }
        }
    }
    return -1;
}

int binarySearch(Array &arr, int key)
{
    int l{0};
    int h{arr.length-1};

    while (l<=h)
    {
        int mid = l+(h-l)/2;
        if(key==arr.A[mid])
        {
            return mid;
        }
        else if(key<arr.A[mid])
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

int get(const Array &arr, int index)
{
    if(index>=0 && index<arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

void set(Array &arr, int index, int value)
{
    if(index>=0 && index<arr.length)
    {
        arr.A[index] = value;
    }
}

int max(const Array &arr)
{
    int max=arr.A[0];
    for(int i{0}; i<arr.length; i++)
    {
        if(arr.A[i]>max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

int min(const Array &arr)
{
    int min=arr.A[0];
    for(int i{0}; i<arr.length; i++)
    {
        if(arr.A[i]<min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

int sum(const Array &arr)
{
    int sum=0;
    for(int i{0}; i<arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

float avg(const Array &arr)
{
    return static_cast<float>(sum(arr))/arr.length;
}

void reverse(Array &arr)
{
    int start = 0;
    int end = arr.length-1;
    
    while(start < end)
    {
        swap(arr.A[start], arr.A[end]);
        start++;
        end--;
    }
}

void shiftRight(Array &arr)
{
    for(int i=arr.length-1; i>0; i--)
    {
        arr.A[i] = arr.A[i-1];
    }
    arr.A[0] = 0;
}

void shiftRightRotation(Array &arr)
{
    auto tmp = arr.A[arr.length-1];
    for(int i=arr.length-1; i>0; i--)
    {
        arr.A[i] = arr.A[i-1];
    }
    arr.A[0] = tmp;
}

void shiftLeft(Array &arr)
{
    for(int i=1; i<arr.length; i++)
    {
        arr.A[i-1] = arr.A[i];
    }
    arr.A[arr.length-1] = 0;
}

void shiftLeftRotation(Array &arr)
{
    auto tmp = arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        arr.A[i-1] = arr.A[i];
    }
    arr.A[arr.length-1] = tmp;
}

void insertSort(Array &arr, int number)
{
    if(arr.length==arr.size)
    {
        return;
    }
    int i = arr.length-1;
    while(i>=0 && arr.A[i]>number)
    {
        arr.A[i+1]=arr.A[i];
        i--;
    }
    arr.A[i+1] = number;
    arr.length++;
}

bool isSorted(Array arr)
{
    for(int i=0; i<arr.length-1; i++)
    {
        if(arr.A[i]>arr.A[i+1])
        {
            return false;
        }
    }
    return true;
}

void reArrange(Array &arr)
{
    int i=0;
    int j=arr.length-1;

    do
    {
        while(arr.A[i]<0)
        {
            i++;
        }
        while(arr.A[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr.A[i],arr.A[j]);
        }
    } while(i<j);
}

void merge(const Array &arrA, const Array &arrB, Array &arrC)
{
    int i=0;
    int j=0;
    int k=0;

    while(i<arrA.length && j<arrB.length)
    {
        if(arrA.A[i]<arrB.A[j])
        {
            arrC.A[k++]=arrA.A[i++];
        }
        else
        {
            arrC.A[k++]=arrB.A[j++];
        }
    }
    for(; i<arrA.length; i++)
    {
        arrC.A[k++]=arrA.A[i];
    }
    for(; j<arrB.length; j++)
    {
        arrC.A[k++]=arrB.A[j];
    }
}


int main (int argc, char *argv[])
{
    Array arrA;
    Array arrB;
    Array arrC;

    arrA.size = 10;
    arrB.size = 10;
    arrC.size = arrA.size+arrB.size;

    arrA.A = new int [arrA.size];
    arrB.A = new int [arrB.size];
    arrC.A = new int [arrC.size];

    arrA.length = 4;
    arrB.length = 5;
    arrC.length = arrA.length+arrB.length;

    int minRange = 0;
    int maxRange = 10;

    srand(time(0)); // seed with current time

    fillArrayWithRandomNumber(arrA, minRange, maxRange);
    fillArrayWithRandomNumber(arrB, minRange, maxRange);

    display(arrA, "arrA");
    display(arrB, "arrB");
    display(arrC, "arrC");

    merge(arrA, arrB, arrC);
    display(arrC, "arrC");

    delete [] arrA.A;
    delete [] arrB.A;
    delete [] arrC.A;

    return 0;
}
