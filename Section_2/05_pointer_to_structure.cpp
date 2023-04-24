#include<iostream>

using std::cout;
using std::endl;

struct Rectangle
{
    int l;
    int b;
    char x;
};

int main()
{
    Rectangle r{1,2,'x'};
    Rectangle *p{&r};

    cout << "r.l:" << r.l << " r.b:" << r.b << " r.x:" << r.x << endl;

    (*p).l = 3;
    (*p).b = 5;
    (*p).x = 'm';

    cout << "r.l:" << r.l << " r.b:" << r.b << " r.x:" << r.x << endl;

    p->l = 7;
    p->b = 8;
    p->x = 'u';

    cout << "r.l:" << r.l << " r.b:" << r.b << " r.x:" << r.x << endl;

    // in heap
    Rectangle *pH(new Rectangle {6,9,'b'});

    cout << "pH->l:" << pH->l << " pH->b:" << pH->b << " pH->x:" << pH->x << endl;

    pH->l = 7;
    pH->b = 8;
    pH->x = 'u';

    cout << "pH->l:" << pH->l << " pH->b:" << pH->b << " pH->x:" << pH->x << endl;

    delete pH;
    
    return 0;
}
