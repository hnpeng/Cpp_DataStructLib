#include "SmartPointerCase.h"

#include "SmartPointer/SmartPointer.h"
#include <iostream>

using namespace std;
using namespace NPLib;

class Test
{
public:
    Test(int i) : i(i)
    {
        cout << "Test()" << endl;
    }
    ~Test()
    {
        cout << "~Test() is " << i << endl;
    }
    void info()
    {
        cout << "i = " << i << endl;
        cout << "i am test" << endl;
    }

    int i;
};

void SmartPointerCase()
{
    SmartPointer<Test> sp1 = new Test(5);
    SmartPointer<Test> sp2 = new Test(3);

    sp2 = sp1;

    sp2->info();
    cout << sp1.isNull() << endl;
    cout << sp2.isNull() << endl;

    Test * t1 = sp2.getPointer();
    t1->info();
}
