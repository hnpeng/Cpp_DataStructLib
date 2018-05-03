#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "TestCase/SmartPointerCase.h"
#include "TestCase/ExceptionCase.h"
#include "TestCase/ObjectCase.h"
#include "TestCase/StaticListCase.h"
#include "TestCase/DynamicListCase.h"
#include "TestCase/StaticArrayCase.h"
#include "TestCase/DynamicArrayCase.h"
#include "TestCase/LinkListCase.h"
#include "TestCase/StaticLinkListCase.h"

using namespace std;
//using namespace NPLib;

int main()
{
//    SmartPointerCase();
//    ExceptionCase();
//    ObjectCase();
//    StaticListCase();
//    DynamicListCase();
//    StaticArrayCase();
//    DynamicArrayCase();
//    LinkListCase();
    StaticLinkListCase();

    cout << "Hello World!" << endl;
    return 0;
}
