#include "CircleListCase.h"

#include "List/CircleList.h"
#include <iostream>

using namespace std;
using namespace NPLib;

void josephus(int n, int s, int m)
{
    CircleList<int> l;

    for (int i = 1; i <= n; i++) {
        l.append(i);
    }

    l.move(s - 1, m - 1);

    while (l.length() > 0) {
        l.next();

        cout << l.current() << endl;

        l.remove(l.find(l.current()));
    }
}

void CircleListCase()
{
    josephus(41, 1, 3);
}
