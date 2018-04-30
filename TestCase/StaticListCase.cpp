#include "StaticListCase.h"

#include "List/StaticList.h"
#include <iostream>

using namespace NPLib;
using namespace std;

class SLTest
{
public:
    SLTest() : i(0)
    {
        cout << "SLTest(0)" << endl;
    }

    SLTest(int i)
    {
        this->i = i;
        cout << "SLTest(" << i << ")" << endl;
    }

    SLTest(const SLTest& obj)
    {
        i = obj.i;
        cout << "SLTest(const SLTest& obj) i = " << i << endl;
    }

    int i;
};

ostream& operator <<(ostream& os, const SLTest& t)
{
    return os << t.i;
}

void StaticListCase()
{
    StaticList<SLTest, 5> l;

    for (int i=0; i<5; i++) {
//        l.insert(0, i);
        l.append(SLTest(i));
    }

    l[1] = 11;
//    const StaticList<SLTest, 5> li = l;

//    cout << "li[1] = " << li[1] << endl;

    for (int i=0; i<l.length(); i++) {
        cout << i << " = " << l[i] << endl;
    }

    try {
        cout << l[5] << endl;
    } catch (const Exception& e) {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    while (l.length() > 0) {
        SLTest temp(0);
        if (l.remove(0, temp)) {
            cout << temp << endl;
        }
    }

    cout << "l.lenght = " << l.length() << endl;
    cout << "l.capacity = " << l.capacity() << endl;
}
