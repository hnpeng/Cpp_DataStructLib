#include "Object.h"

#include <cstdlib>

using namespace NPLib;

void *Object::operator new(size_t size)
{
    return malloc(size);
}

void *Object::operator new[](size_t size)
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

Object::~Object()
{

}
