#include "SmartPointerCase.h"

#include "Pointer/SmartPointer.h"
#include <iostream>

using namespace std;
using namespace NPLib;

class SPTest
{
public:
    SPTest(int i) : i(i)
    {
        cout << "SPTest() " << i << endl;
    }
    ~SPTest()
    {
        cout << "~SPTest() is " << i << endl;
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
    SmartPointer<SPTest> sp1 = new SPTest(5);
//    SmartPointer<SPTest> sp2 = new SPTest(3);
    SmartPointer<SPTest> sp2 = sp1;

//    sp2 = sp1;

    sp2->info();
    cout << sp1.isNull() << endl;
    cout << sp2.isNull() << endl;

    SPTest * t1 = sp2.get();
    t1->info();

    SmartPointer<SPTest>* pSp = new SmartPointer<SPTest>(new SPTest(7));
    delete pSp;
}
