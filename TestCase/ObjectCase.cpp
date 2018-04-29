#include "ObjectCase.h"

#include "Object/Object.h"
#include <iostream>

using namespace std;
using namespace NPLib;

class ObjTest : public Object
{
public:
    int i;
};

void ObjectCase()
{
    ObjTest* t = new ObjTest;
    ObjTest* ta = new ObjTest[5];

    cout << "t = " << t << endl;
    cout << "ta = " << ta << endl;

    delete t;
    delete[] ta;

}
