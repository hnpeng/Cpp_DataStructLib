#include "LinkListCase.h"

#include "List/LinkList.h"
#include <iostream>

using namespace std;
using namespace NPLib;

class LLTest : public Object
{
public:
    LLTest() : i(0)
    {
        cout << "LLTest(0)" << endl;
//        throw 0;
    }

    LLTest(int i)
    {
        this->i = i;
        cout << "LLTest(" << i << ")" << endl;
    }

    LLTest(const LLTest& obj)
    {
        i = obj.i;
        cout << "LLTest(const LLTest& obj) i = " << i << endl;
    }

    ~LLTest()
    {
        cout << "~LLTest()" << endl;
    }

    int i;
};

ostream& operator <<(ostream& os, const LLTest& t)
{
    return os << t.i;
}

void LinkListCase()
{
    LinkList<LLTest> l;

    for (int i=0; i<8; i++) {
        l.append(i);
    }

    for (int i=0; i<l.length(); i++) {
        cout << l.get(i) << endl;
    }

    LLTest toRemove;
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
