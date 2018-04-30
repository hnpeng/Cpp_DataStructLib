#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "TestCase/SmartPointerCase.h"
#include "TestCase/ExceptionCase.h"
#include "TestCase/ObjectCase.h"
#include "TestCase/StaticListCase.h"
#include "TestCase/DynamicListCase.h"

using namespace std;
//using namespace NPLib;

int main()
{
//    SmartPointerCase();
//    ExceptionCase();
//    ObjectCase();
//    StaticListCase();
    DynamicListCase();

    cout << "Hello World!" << endl;
    return 0;
}
