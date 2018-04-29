#ifndef OBJECT_H
#define OBJECT_H

#include <cstdlib>

namespace NPLib {

class Object
{
public:
    void* operator new(size_t size);
    void* operator new[](size_t size);
    void operator delete(void* p);
    void operator delete[](void* p);

    virtual ~Object() = 0;
};

}

#endif
