#include<iostream>
#include<string>
#include<cassert>

using std::cout;
using std::endl;
using std::cin;
using std::string;

struct Array
{
    int *A;
    int size;
    int length;
};

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

int main (int argc, char *argv[])
{
    Array arr;

    cout << "Input array size: \n";
    cin >> arr.size;
    arr.A = new int [arr.size];
    arr.length = 0;

    int n;
    cout << "How many numbers: \n";
    cin >> n;

    cout << "Enter all numbers: \n";
    for (int i=0; i<n; i++)
        cin >> arr.A[i];
    arr.length = n;

//    display(arr, "Initial array modification");
////    append(arr, 9);
////    display(arr, "Append function modification");
//    insert(arr,2,69);
//    display(arr, "Insert function modification");
//    cout << remove(arr,2) << "\n";
//    display(arr, "Remove function modification");
//    int number{0};
//    cout << "Enter element you want to search: \n";
//    cin >> number;
//    cout << "Binary serch index: " << binarySearch(arr,number) << "\n";
//    assert(binarySearch(arr, number) == 2);
//    cout << "Linear serch index: " << linearSearch(arr,number) << "\n";
//    display(arr, "Linear search function modification");

    // Get/set/max/min/sum/avg
//    set(arr,0,3);
//    display(arr, "set(arr,0,3) array modification");
//    cout << "get(arr,2): " << get(arr,2) << "\n";
//    cout << "min(arr): " << min(arr) << "\n";
//    cout << "max(arr): " << max(arr) << "\n";
//    cout << "sum(arr): " << sum(arr) << "\n";
//    cout << "avg(arr): " << avg(arr) << "\n";

    // Shifting
//    shiftLeft(arr);
//    display(arr, "shiftLeft(arr) array modification");
//    shiftLeftRotation(arr);
//    display(arr, "shiftLeftRotation(arr) array modification");
//    shiftRight(arr);
//    display(arr, "shiftRight(arr) array modification");
//    shiftRightRotation(arr);
//    display(arr, "shiftRightRotation(arr) array modification");

    // Check if sorted
    Array arrSorted;

    arrSorted.size = 10;
    arrSorted.A = new int [arrSorted.size];
    arrSorted.length = 6;
    for (int i=0; i<arrSorted.length; i++)
        arrSorted.A[i] = i;

    display(arrSorted, "Initial arrSorted");
    insertSort(arrSorted,3);
    display(arrSorted, "insertSort(arrSorted,3)");
    cout << "isSorted(arr): " << isSorted(arr) << "\n";
    cout << "isSorted(arrSorted): " << isSorted(arrSorted) << "\n";
    
    // Move negative to left and positive numbers to the right side
    display(arr, "Initial arr");
    reArrange(arr);
    display(arr, "arr reArrange(arr)");

    delete [] arr.A;
    delete [] arrSorted.A;

    return 0;
}
