#include "DynamicArrayCase.h"

#include "Array/DynamicArray.h"
#include <iostream>

using namespace std;
using namespace NPLib;

class DATest
{
public:
    DATest() : i(0)
    {
        cout << "DATest(0)" << endl;
    }

    DATest(int i)
    {
        this->i = i;
        cout << "DATest(" << i << ")" << endl;
    }

    DATest(const DATest& obj)
    {
        i = obj.i;
        cout << "DATest(const DATest& obj) i = " << i << endl;
    }

    int i;
};

ostream& operator <<(ostream& os, const DATest& t)
{
    return os << t.i;
}

void DynamicArrayCase()
{
    DynamicArray<DATest> a(8);

    for (int i=0; i<8; i++) {
        a[i] = i;
    }

    a.resize(10);

    for (int i=0; i<a.length(); i++) {
        cout << a[i] << endl;
    }

    DynamicArray<DATest> aa(0);

    aa = a;

    for (int i=0; i<aa.length(); i++) {
        cout << aa[i] << endl;
    }
}
