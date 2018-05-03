#include "SharePointerCase.h"

#include "Pointer/SharePointer.h"
#include <iostream>

using namespace std;
using namespace NPLib;

class SharePTest : public Object
{
public:
    SharePTest() : i(0)
    {
        cout << "SharePTest(0)" << endl;
//        throw 0;
    }

    SharePTest(int i)
    {
        this->i = i;
        cout << "SharePTest(" << i << ")" << endl;
    }

    SharePTest(const SharePTest& obj)
    {
        i = obj.i;
        cout << "SharePTest(const SharePTest& obj) i = " << i << endl;
    }

    ~SharePTest()
    {
        cout << "~SharePTest()" << endl;
    }

    int i;
};

ostream& operator <<(ostream& os, const SharePTest& t)
{
    return os << t.i;
}

void SharePointerCase()
{
    const SharePointer<SharePTest> psp1 = new SharePTest(5);
    SharePointer<SharePTest> psp2;
    SharePointer<SharePTest> psp3 = psp1;

    psp2 = psp1;

//    psp1->i = 100;
    (*psp2).i = 100;


    cout << *psp1 << endl;
    cout << *psp2 << endl;
    cout << *psp3 << endl;

    cout << (psp3 == psp2) << endl;

    psp3.clear();
}
