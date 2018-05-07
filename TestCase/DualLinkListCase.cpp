#include "DualLinkListCase.h"

#include "List/DualLinkList.h"
#include <iostream>

using namespace std;
using namespace NPLib;

class DLLTest : public Object
{
public:
    DLLTest() : i(0)
    {
        cout << "DLLTest(0)" << endl;
//        throw 0;
    }

    DLLTest(int i)
    {
        this->i = i;
        cout << "DLLTest(" << i << ")" << endl;
    }

    DLLTest(const DLLTest& obj)
    {
        i = obj.i;
        cout << "DLLTest(const DLLTest& obj) i = " << i << endl;
    }

    ~DLLTest()
    {
        cout << "~DLLTest()" << endl;
    }

    int i;
};

ostream& operator <<(ostream& os, const DLLTest& t)
{
    return os << t.i;
}

void DualLinkListCase()
{
    DualLinkList<DLLTest> l;

    for (int i=0; i<8; i++) {
//        l.append(i);
        l.insert(0, i);
    }

    for (int i=0; i<l.length(); i++) {
        cout << l.get(i) << endl;
    }

    l.remove(1);

////    l.clear();
    for (int i=0; i<l.length(); i++) {
        cout << l.get(i) << endl;
    }

//    for (l.move(0, 2); !l.end(); l.next()) {
//        cout << l.current() << endl;
//    }

    for (l.move(l.length()-1, 2); !l.end(); l.pre())
    {
        cout << l.current() << endl;
    }

    DualLinkList<int> ll;

    for (int i=0; i<8; i++) {
        ll.append(i);
        ll.append(5);
    }

    cout << "------------befor:" << endl;
    for (int i=0; i<ll.length(); i++) {
        cout << ll.get(i) << endl;
    }

    for (ll.move(ll.length()-1); !ll.end();)
    {
        if (ll.current() == 5) {
            ll.remove(ll.find(5));
        } else {
            ll.pre();
        }
    }

    cout << "-----------after:" << endl;
    for (int i=0; i<ll.length(); i++) {
        cout << ll.get(i) << endl;
    }
}
