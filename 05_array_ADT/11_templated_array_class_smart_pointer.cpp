#include <cstddef>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <random>
#include <type_traits>
#include <vector>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::vector;

bool debug=true;

template<typename T>
class Array
{
private:
    std::unique_ptr<T[]> A;
    size_t size{0};
    size_t length{0};

    void swap(T &l, T &r);
    void resize(size_t newSize);

public:
    static_assert(
        std::is_arithmetic<T>::value, "Only numeric types are supported");

    Array<T>(){}

    Array<T>(size_t size):
        size(size),
        length(0)
    {
        A = std::make_unique<T[]>(size);
    }

    Array<T>(size_t size, size_t length):
        size(size),
        length(length)
    {
        if (length>size)
        {
            throw std::invalid_argument("Length cannot be greater than size");
        }
        A = std::make_unique<T[]>(size);
    }

    Array<T>(std::initializer_list<T> values):
        size(values.size()),
        length(values.size())
    {
        A = std::make_unique<T[]>(size);
        size_t i=0;
        for(const T& value: values)
        {
            A[i++]=value;
        }
    }

    Array<T>(const Array<T>& obj):
        size(obj.size),
        length(obj.length)
    {
        A = std::make_unique<T[]>(size);
        for(size_t i=0; i<length; ++i)
        {
            A[i]=obj.A[i];
        }
    }

    Array<T>(Array<T>&& obj) noexcept = default;

    Array<T>& operator=(Array<T>&& obj) noexcept = default;

    Array<T>& operator=(const Array<T>& obj)
    {
        if(this != &obj)
        {
            size=obj.size;
            length=obj.length;
            A = std::make_unique<T[]>(size);
            for(size_t i=0; i<length; ++i)
            {
                A[i]=obj.A[i];
            }
        }
        return *this;
    }

    T& operator[](size_t index)
    {
        if(index<length)
        {
            return A[index];
        }
        throw std::out_of_range("Index is out of bounds");
    }

    const T& operator[](size_t index) const
    {
        if(index<length)
        {
            return A[index];
        }
        throw std::out_of_range("Index is out of bounds");
    }

    bool operator==(const Array<T>& obj) const
    {
        if(length != obj.length)
        {
            return false;
        }
        for(size_t i=0; i<length; ++i)
        {
            if(A[i] != obj.A[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Array<T>& obj) const
    {
        return !(*this == obj);
    }

    bool operator<(const Array<T>& obj) const
    {
        for(size_t i=0; i<length && i<obj.length; ++i)
        {
            if(A[i]<obj.A[i])
            {
                return true;
            }
            if(A[i]>obj.A[i])
            {
                return false;
            }
        }
        return length<obj.length;
    }

    bool operator>(const Array<T>& obj) const
    {
        return !(*this<=obj);
    }

    bool operator<=(const Array<T>& obj) const
    {
        return (*this<obj) || (*this==obj);
    }

    bool operator>=(const Array<T>& obj) const
    {
        return !(*this<obj);
    }

    Array<T> operator+(const Array<T>& obj) const
    {
        if(length != obj.length)
        {
            throw std::runtime_error(
                "Arrays must have the same length for addition");
        }
        Array<T> result(size,length);
        for(size_t i=0; i<length; ++i)
        {
            result.A[i] = A[i]+obj.A[i];
        }
        return result;
    }

    Array<T>& operator+=(const Array<T>& obj)
    {
        return *this = *this+obj;
    }

    Array<T> operator-(const Array<T>& obj) const
    {
        if(length != obj.length)
        {
            throw std::runtime_error(
                "Arrays must have the same length for subtraction");
        }
        Array<T> result(size,length);
        for(size_t i=0; i<length; ++i)
        {
            result.A[i] = A[i]-obj.A[i];
        }
        return result;
    }

    Array<T>& operator-=(const Array<T>& obj)
    {
        return *this = *this-obj;
    }

    Array<T> operator*(const Array<T>& obj) const
    {
        if(length != obj.length)
        {
            throw std::runtime_error(
                "Arrays must have the same length for multiplication");
        }
        Array<T> result(size,length);
        for(size_t i=0; i<length; ++i)
        {
            result[i] = A[i]*obj.A[i];
        }
        return result;
    }

    Array<T>& operator*=(const Array<T>& obj)
    {
        return *this = *this*obj;
    }

    Array<T> operator/(const Array<T>& obj) const
    {
        if(length != obj.length)
        {
            throw std::runtime_error(
                "Arrays must have the same length for division");
        }
        Array<T> result(size,length);
        for(size_t i=0; i<length; ++i)
        {
            if(obj.A[i]==0)
            {
                throw std::invalid_argument(
                    "Division by zero detected in array division");
            }
            result.A[i] = A[i]/obj.A[i];
        }
        return result;
    }

    Array<T>& operator/=(const Array<T>& obj)
    {
        return *this = *this/obj;
    }

    ~Array<T>() noexcept = default;

    void fillArrayWithRandomNumber(
        const T minRange, const T maxRange, bool sorted=true);
    void display(const string message) const;
    void append(const T x);
    void insert(const size_t index, const T x);
    T remove(const size_t index);
    size_t linearSearch(const T key, bool moveToHead=true);
    size_t binarySearch(const T key);
    T get(const size_t index) const;
    void set(const size_t index, const T value);
    T max() const;
    T min() const;
    T sum() const;
    float avg() const;
    void reverse();
    void shiftRight();
    void shiftRightRotation();
    void shiftLeft();
    void shiftLeftRotation();
    void insertSort(const T number);
    bool isSorted() const;
    void reArrange();
    std::unique_ptr<Array<T>> merge(const Array &arr) const;
    std::unique_ptr<Array<T>> arrayUnion(const Array &arr) const;
    std::unique_ptr<Array<T>> arrayIntersection(const Array &arr) const;
    std::unique_ptr<Array<T>> arrayDifference(const Array &arr) const;
};

template<typename T>
void Array<T>::fillArrayWithRandomNumber(const T minRange, const T maxRange, bool sorted)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis_int(minRange, maxRange);
    std::uniform_real_distribution<> dis_float(minRange, maxRange);
    
    for(size_t i=0; i<length; ++i)
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
        std::sort(A.get(), A.get()+length);
    }
}

template<typename T>
void Array<T>::display(const string message) const
{
    cout << message << "\n";
    for(size_t i{0}; i<length; ++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

template<typename T>
void Array<T>::append(const T x)
{
    if (length<size)
        A[length++] = x;
}

template<typename T>
void Array<T>::insert(const size_t index, const T x)
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
T Array<T>::remove(const size_t index)
{
    if (index>=0 && index<=length)
    {
        T removed_value = A[index];
        for(size_t i=index; i<length-1; ++i)
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
void Array<T>::resize(size_t newSize)
{
    std::unique_ptr<T[]> B = std::make_unique<int[]>(newSize);
    for(size_t i=0; i<length; ++i)
    {
        B[i]=A[i];
    }
    A=std::move(B);
    size=newSize;
}

template<typename T>
size_t Array<T>::linearSearch(const T key, bool moveToHead)
{
    for(size_t i{0}; i<length; ++i)
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
size_t Array<T>::binarySearch(const T key)
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
T Array<T>::get(const size_t index) const
{
    if(index>=0 && index<length)
    {
        return A[index];
    }
    throw std::out_of_range("Index out of bounds");
}

template<typename T>
void Array<T>::set(const size_t index, const T value)
{
    if(index>=0 && index<length)
    {
        A[index] = value;
    }
}

template<typename T>
T Array<T>::max() const
{
    T max=A[0];
    for(size_t i{0}; i<length; ++i)
    {
        if(A[i]>max)
        {
            max = A[i];
        }
    }
    return max;
}

template<typename T>
T Array<T>::min() const
{
    T min=A[0];
    for(size_t i{0}; i<length; ++i)
    {
        if(A[i]<min)
        {
            min = A[i];
        }
    }
    return min;
}

template<typename T>
T Array<T>::sum() const
{
    T sum=0;
    for(size_t i{0}; i<length; ++i)
    {
        sum += A[i];
    }
    return sum;
}

template<typename T>
float Array<T>::avg() const
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
    for(size_t i=1; i<length; ++i)
    {
        A[i-1] = A[i];
    }
    A[length-1] = 0;
}

template<typename T>
void Array<T>::shiftLeftRotation()
{
    auto tmp = A[0];
    for(size_t i=1; i<length; ++i)
    {
        A[i-1] = A[i];
    }
    A[length-1] = tmp;
}

template<typename T>
void Array<T>::insertSort(const T number)
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
bool Array<T>::isSorted() const
{
    for(size_t i=0; i<length-1; ++i)
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
std::unique_ptr<Array<T>> Array<T>::merge(const Array &arr) const
{
    auto arrMerged = std::make_unique<Array<T>>(size+arr.size);

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
    for(; i<length; ++i)
    {
        arrMerged->A[k++]=A[i];
    }
    for(; j<arr.length; ++j)
    {
        arrMerged->A[k++]=arr.A[j];
    }
    arrMerged->length=length+arr.length;

    return arrMerged;
}

template<typename T>
std::unique_ptr<Array<T>> Array<T>::arrayUnion(const Array &arr) const
{
    auto arrUnion = std::make_unique<Array<T>>(size+arr.size);

    size_t i=0;
    size_t j=0;
    size_t k=0;

    while(i<length && j<arr.length)
    {
        if(A[i]<arr.A[j])
        {
            arrUnion->A[k++]=A[i++];
        }
        else if(arr.A[j]<A[i])
        {
            arrUnion->A[k++]=arr.A[j++];
        }
        else
        {
            arrUnion->A[k++]=A[i++];
            j++;
        }
    }
    // Copy remaining elements if any
    while(i<length)
    {
        arrUnion->A[k++]=A[i++];
    }
    while(j<arr.length)
    {
        arrUnion->A[k++]=arr.A[j++];
    }
    arrUnion->length=k;

    return arrUnion;
}

template<typename T>
std::unique_ptr<Array<T>> Array<T>::arrayIntersection(const Array &arr) const
{
    auto arrIntersect = std::make_unique<Array<T>>(size+arr.size);

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
            arrIntersect->A[k++]=A[i++];
            j++;
        }
    }
    arrIntersect->length=k;

    return arrIntersect;
}

template<typename T>
std::unique_ptr<Array<T>> Array<T>::arrayDifference(const Array &arr) const
{
    auto arrDiff = std::make_unique<Array<T>>(size+arr.size);

    size_t i=0;
    size_t j=0;
    size_t k=0;

    while(i<length && j<arr.length)
    {
        if(A[i]<arr.A[j])
        {
            arrDiff->A[k++]=A[i++];
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
        arrDiff->A[k++]=A[i++];
    }
    arrDiff->length=k;

    return arrDiff;
}


int main (int argc, char *argv[])
{
    Array<float> A(10,4);
    Array<float> B(10,4);

    A.display("Array A");
    B.display("Array B");

    float minRange = 0.0;
    float maxRange = 10.0;

    A.fillArrayWithRandomNumber(minRange, maxRange);
    B.fillArrayWithRandomNumber(minRange, maxRange);

    A.display("Array A");
    B.display("Array B");

    std::unique_ptr<Array<float>> C;

    C = A.merge(B);
    C->display("Array C merge");

    C = A.arrayIntersection(B);
    C->display("Array C intersection");

    C = A.arrayUnion(B);
    C->display("Array C union");

    C = A.arrayDifference(B);
    C->display("Array C difference");

    cout << (*C)[1] << endl;
    auto isEqual = (A==*C);
    A.display("Array A");
    C->display("Array C");
    cout << std::boolalpha;
    cout << "Is A equal C: " << isEqual << endl;

    A.display("Array A");
    B.display("Array B");
    auto D = A-B;
    D.display("Array D");
    A *= B;
    A.display("Array A");
    cout << A.sum() << endl;

    // Testing move constructor and assignment operator
    vector<Array<float>> v;
    v.push_back(Array<float>{1,2,3});
    v.push_back(Array<float>{4,5,6});
    v.insert(v.begin()+2,Array<float>{7,8,9}); // insert at index 2
    
    size_t i{0};
    for(const auto& array: v)
    {
        array.display("Element "+std::to_string(i));
        ++i;
    }

    // Check const
    Array<float> x{1,2,3};
    const Array<float> y{7,8,9};
    C = x.merge(y);
    C->display("Merged x and y");
    C->set(0, 1.1);
    C->display("C->set(0,1.1)");

    return 0;
}
