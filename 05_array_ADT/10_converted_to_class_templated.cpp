#include <iostream>
#include <stdexcept>
#include <string>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <random>
#include <type_traits>

using std::cout;
using std::endl;
using std::string;

template<typename T>
class Array
{
private:
    T *A;
    size_t size;
    size_t length;

    void swap(T &l, T &r);

public:
    Array():
        size(10),
        length(0)
    {
        A = new T [size];
        for(size_t i=0; i<length; i++)
        {
            A[i] = 0;
        }
    }

    Array(size_t size):
        size(size),
        length(0)
    {
        A = new T [size];
        for(size_t i=0; i<length; i++)
        {
            A[i] = 0;
        }
    }

    Array(size_t size, size_t length):
        size(size),
        length(length)
    {
        if (length>size)
        {
            throw std::invalid_argument("Length cannot be greater than size");
        }
        A = new T [size];
        for(size_t i=0; i<length; i++)
        {
            A[i] = 0;
        }
    }

    ~Array()
    {
        delete [] A;
    }

    void fillArrayWithRandomNumber(T minRange, T maxRange, bool sorted=true);
    void display(string message);
    void append(T x);
    void insert(size_t index, T x);
    T remove(size_t index);
    size_t linearSearch(T key, bool moveToHead=true);
    size_t binarySearch(T key);
    T get(size_t index);
    void set(size_t index, T value);
    T max();
    T min();
    T sum();
    float avg();
    void reverse();
    void shiftRight();
    void shiftRightRotation();
    void shiftLeft();
    void shiftLeftRotation();
    void insertSort(T number);
    bool isSorted();
    void reArrange();
    Array* merge(const Array &arr);
    Array* arrayUnion(const Array &arr);
    Array* arrayIntersection(const Array &arr);
    Array* arrayDifference(const Array &arr);

};

template<typename T>
void Array<T>::fillArrayWithRandomNumber(T minRange, T maxRange, bool sorted)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis_int(minRange, maxRange);
    std::uniform_real_distribution<> dis_float(minRange, maxRange);
    
    for(size_t i=0; i<length; i++)
    {
        if constexpr (std::is_integral<T>::value)
        {
            A[i] = dis_int(gen);
        }
        else if constexpr (std::is_floating_point<T>::value)
        {
            A[i] = dis_float(gen);
        }
    }
    if(sorted)
    {
        std::sort(A, A+length);
    }
}

template<typename T>
void Array<T>::display(const string message)
{
    cout << message << "\n";
    for(size_t i{0}; i<length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

template<typename T>
void Array<T>::append(T x)
{
    if (length<size)
        A[length++] = x;
}

template<typename T>
void Array<T>::insert(size_t index, T x)
{
    if (index>=0 && index<=length)
    {
        for(size_t i=length; i>index; i--)
        {
            A[i] = A[i-1];
        }
        A[index] = x;
        length++;
    }
}

template<typename T>
T Array<T>::remove(size_t index)
{
    if (index>=0 && index<=length)
    {
        T removed_value = A[index];
        for(size_t i=index; i<length-1; i++)
        {
            A[i] = A[i+1];
        }
        length--;
        return removed_value;
    }
    return 0;
}

template<typename T>
void Array<T>::swap(T &l, T &r)
{
    T tmp=l;
    l=r;
    r=tmp;
}

template<typename T>
size_t Array<T>::linearSearch(T key, bool moveToHead)
{
    for(size_t i{0}; i<length; i++)
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
                return static_cast<T>(i)-1;
            }
        }
    }
    return std::numeric_limits<size_t>::max();
}

template<typename T>
size_t Array<T>::binarySearch(T key)
{
    size_t l{0};
    size_t h{length-1};

    while (l<=h)
    {
        size_t mid = l+(h-l)/2;
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
    return std::numeric_limits<size_t>::max();
}

template<typename T>
T Array<T>::get(const size_t index)
{
    if(index>=0 && index<length)
    {
        return A[index];
    }
    throw std::out_of_range("Index out of bounds");
}

template<typename T>
void Array<T>::set(size_t index, T value)
{
    if(index>=0 && index<length)
    {
        A[index] = value;
    }
}

template<typename T>
T Array<T>::max()
{
    T max=A[0];
    for(size_t i{0}; i<length; i++)
    {
        if(A[i]>max)
        {
            max = A[i];
        }
    }
    return max;
}

template<typename T>
T Array<T>::min()
{
    T min=A[0];
    for(size_t i{0}; i<length; i++)
    {
        if(A[i]<min)
        {
            min = A[i];
        }
    }
    return min;
}

template<typename T>
T Array<T>::sum()
{
    T sum=0;
    for(size_t i{0}; i<length; i++)
    {
        sum += A[i];
    }
    return sum;
}

template<typename T>
float Array<T>::avg()
{
    return static_cast<float>(sum())/length;
}

template<typename T>
void Array<T>::reverse()
{
    size_t start = 0;
    size_t end = length-1;
    
    while(start < end)
    {
        swap(A[start], A[end]);
        start++;
        end--;
    }
}

template<typename T>
void Array<T>::shiftRight()
{
    for(size_t i=length-1; i>0; i--)
    {
        A[i] = A[i-1];
    }
    A[0] = 0;
}

template<typename T>
void Array<T>::shiftRightRotation()
{
    auto tmp = A[length-1];
    for(size_t i=length-1; i>0; i--)
    {
        A[i] = A[i-1];
    }
    A[0] = tmp;
}

template<typename T>
void Array<T>::shiftLeft()
{
    for(size_t i=1; i<length; i++)
    {
        A[i-1] = A[i];
    }
    A[length-1] = 0;
}

template<typename T>
void Array<T>::shiftLeftRotation()
{
    auto tmp = A[0];
    for(size_t i=1; i<length; i++)
    {
        A[i-1] = A[i];
    }
    A[length-1] = tmp;
}

template<typename T>
void Array<T>::insertSort(T number)
{
    if(length==size)
    {
        return;
    }
    size_t i = length-1;
    while(i>=0 && A[i]>number)
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1] = number;
    length++;
}

template<typename T>
bool Array<T>::isSorted()
{
    for(size_t i=0; i<length-1; i++)
    {
        if(A[i]>A[i+1])
        {
            return false;
        }
    }
    return true;
}

template<typename T>
void Array<T>::reArrange()
{
    size_t i=0;
    size_t j=length-1;

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

template<typename T>
Array<T>* Array<T>::merge(const Array &arr)
{
    Array<T> *arrMerged = new Array<T>(size+arr.size);

    size_t i=0;
    size_t j=0;
    size_t k=0;

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

template<typename T>
Array<T>* Array<T>::arrayUnion(const Array &arr)
{
    Array<T> *arrMerged = new Array<T>(size+arr.size);

    size_t i=0;
    size_t j=0;
    size_t k=0;

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

template<typename T>
Array<T>* Array<T>::arrayIntersection(const Array &arr)
{
    Array<T> *arrMerged = new Array<T>(size+arr.size);

    size_t i=0;
    size_t j=0;
    size_t k=0;

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

template<typename T>
Array<T>* Array<T>::arrayDifference(const Array &arr)
{
    Array<T> *arrMerged = new Array<T>(size+arr.size);

    size_t i=0;
    size_t j=0;
    size_t k=0;

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
    Array<float> A(10,5);
    Array<float> B(10,4);

    A.display("Array A");
    B.display("Array B");

    float minRange = 0.0;
    float maxRange = 10.0;

    A.fillArrayWithRandomNumber(minRange, maxRange);
    B.fillArrayWithRandomNumber(minRange, maxRange);

    A.display("Array A");
    B.display("Array B");

    Array<float> *C = new Array<float>;

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
