#include "StaticArrayCase.h"

#include "Array/StaticArray.h"
#include <iostream>

using namespace std;
using namespace NPLib;

class SATest
{
public:
    SATest() : i(0)
    {
        cout << "SATest(0)" << endl;
    }

    SATest(int i)
    {
        this->i = i;
        cout << "SATest(" << i << ")" << endl;
    }

    SATest(const SATest& obj)
    {
        i = obj.i;
        cout << "SATest(const SATest& obj) i = " << i << endl;
    }

    int i;
};

ostream& operator <<(ostream& os, const SATest& t)
{
    return os << t.i;
}

void StaticArrayCase()
{
    StaticArray<SATest, 5> a;

    for (int i=0; i<5; i++) {
        a[i] = i;
    }

    StaticArray<SATest, 5> aa = a;
    cout << "aa[1] = " << aa[1] << endl;
    a[1] = 11;

    for (int i=0; i<aa.length(); i++) {
        cout << aa[i].i << endl;
    }
}
