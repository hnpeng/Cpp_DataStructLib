#include "StaticLinkListCase.h"

#include "List/StaticLinkList.h"
#include <iostream>

using namespace std;
using namespace NPLib;

class SLLTest : public Object
{
public:
    SLLTest() : i(0)
    {
        cout << "SLLTest(0)" << endl;
//        throw 0;
    }

    SLLTest(int i)
    {
        this->i = i;
        cout << "SLLTest(" << i << ")" << endl;
    }

    SLLTest(const SLLTest& obj)
    {
        i = obj.i;
        cout << "SLLTest(const SLLTest& obj) i = " << i << endl;
    }

    ~SLLTest()
    {
//        cout << "~SLLTest()" << endl;
    }

    int i;
};

ostream& operator <<(ostream& os, const SLLTest& t)
{
    return os << t.i;
}

void StaticLinkListCase()
{
    StaticLinkList<SLLTest, 8> l;

    for (int i=0; i<8; i++) {
        l.append(i);
    }

    for (int i=0; i<l.length(); i++) {
        cout << l.get(i) << endl;
    }

    SLLTest toRemove;
    l.remove(1, toRemove);
    cout << "remove = " << toRemove << endl;

//    l.clear();
    for (int i=0; i<l.length(); i++) {
        cout << l.get(i) << endl;
    }

    for (l.move(0, 2); !l.end(); l.next()) {
        cout << l.current() << endl;
    }
}

//void StaticLinkListCase()
//{
//    StaticLinkList<int, 8> l;

////    l.append(5);

//    for (int i=0; i<8; i++) {
//        l.append(i);
//    }

//    l.clear();

//    for (int i=0; i<8; i++) {
//        l.append(i * i);
//    }

////    int temp;
////    l.remove(0, temp);
////    cout << "remove = " << temp << endl;

//    for (int i=0; i<l.length(); i++) {
//        cout << l.get(i) << endl;
//    }

//    try {
//        l.append(11);
//    } catch (const Exception& e) {
//        cout << e.message() << endl;
//        cout << e.location() << endl;
//    }
//}
