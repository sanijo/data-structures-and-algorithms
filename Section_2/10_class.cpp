#include<iostream>

using std::cout;
using std::endl;

template<typename T>
class Rectangle
{
    T length;
    T breadth;
public:
    Rectangle()
    :
    length(1),
    breadth(1)
    {}

    Rectangle
    (
    T l,
    T b
    ):
    length(l),
    breadth(b)
    {}

    inline T area();

    inline T perimeter();

    inline void set_length(T l)
    {
        length=l;
    }

    inline void set_breadth(T b)
    {
        breadth=b;
    }

    inline T get_length()
    {
        return length;
    }

    inline T get_breadth()
    {
        return breadth;
    }

    ~Rectangle(){};

};

template<typename T>
T Rectangle<T>::area()
{
    return length*breadth;
}

template<typename T>
T Rectangle<T>::perimeter()
{
    return 2*(length*breadth);
}


int main()
{
    Rectangle<float>* p{new Rectangle<float>(2.2,2.0)};

    cout<< "Length:" << p->get_length() 
        << " Breadth:" << p->get_breadth() 
        << " Perimeter:" << p->area()
        << " Area:" << p->perimeter()
        << endl;

    p->set_length(8.0);
    p->set_breadth(23.1);

    cout<< "Length:" << p->get_length() 
        << " Breadth:" << p->get_breadth() 
        << " Perimeter:" << p->area()
        << " Area:" << p->perimeter()
        << endl;

    delete p;
    
    return 0;
}
