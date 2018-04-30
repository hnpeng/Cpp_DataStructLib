#include "DynamicListCase.h"

#include <iostream>
#include "List/DynamicList.h"

using namespace std;
using namespace NPLib;

void DynamicListCase()
{
    DynamicList<int> l(10);

    for (int i=0; i<10; i++) {
//        l.insert(0, i);
        l.append(i);
    }

    cout << "l.length = " << l.length() << endl;
    cout << "l.capacity = " << l.capacity() << endl;

    l.resize(5);

    cout << "l.length = " << l.length() << endl;
    cout << "l.capacity = " << l.capacity() << endl;

    for (int i=0; i < l.length(); i++) {
        cout << l[i] << endl;
    }

    while (l.length() > 0) {
        int temp;
        l.remove(0, temp);

        cout << "remove: " << temp << endl;
    }
}
