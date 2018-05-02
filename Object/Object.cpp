#include "Object.h"

#include <cstdlib>

using namespace NPLib;

void *Object::operator new(size_t size) throw()
{
    return malloc(size);
}

void *Object::operator new[](size_t size) throw()
{
    return malloc(size);
}

void Object::operator delete(void *p)
{
    free(p);
}

void Object::operator delete[](void *p)
{
    free(p);
}

bool Object::operator ==(const Object &obj)
{
    return (this == &obj);
}

//bool Object::operator !=(const Object &obj) const
//{
//    return (this != &obj);
//}

Object::~Object()
{

}
