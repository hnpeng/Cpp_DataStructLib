#ifndef OBJECT_H
#define OBJECT_H

#include <cstdlib>

namespace NPLib {

class Object
{
public:
    void* operator new(size_t size) throw();
    void* operator new[](size_t size) throw();
    void operator delete(void* p);
    void operator delete[](void* p);

    bool operator ==(const Object& obj);
//    virtual bool operator !=(const Object& obj) const;

    virtual ~Object() = 0;
};

}

#endif
