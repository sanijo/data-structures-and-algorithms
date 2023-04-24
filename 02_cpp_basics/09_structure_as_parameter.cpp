#include<iostream>

using std::cout;
using std::endl;

struct Rectangle
{
    int l;
    int b;
};

struct Test
{
    int A[5];
    int n;
};

void area(Rectangle);
void area(Rectangle*);
void areaRef(Rectangle&);
void change_length_pointer(Rectangle*, int);
void change_length_reference(Rectangle&, int);
Rectangle* create_dynamic_rectangle();
void fun(Test t1);

void area(Rectangle r)
{
    cout << "Area by parameter: " << r.l*r.b << endl;
}

void area(Rectangle* r)
{
    cout << "Area by pointer: " << r->l*r->b << endl;
}

void areaRef(Rectangle& r)
{
    cout << "Area by reference: " << r.l*r.b << endl;
}

void change_length_pointer(Rectangle* p, int length)
{
    p->l = length;
}

void change_length_reference(Rectangle& r, int length)
{
    r.l = length;
}

Rectangle* create_dynamic_rectangle()
{
    Rectangle* p(new Rectangle);
    p->l = 1;
    p->b = 1;

    return p;
}

void fun(Test t)
{
    // do something
}

int main()
{
    Rectangle r1{9,5};

    area(r1);
    area(&r1);
    areaRef(r1);

    change_length_pointer(&r1, 20);
    area(&r1);
    change_length_reference(r1, 10);
    areaRef(r1);

    // creating structure in heap memory
    Rectangle* pR{create_dynamic_rectangle()};
    area(pR);

    // Test structure
    Test t1{{1,2,3,4,5}, 5};
    fun(t1); // structure consisting array can be passed by value, copy of array is created
    
    return 0;
}
