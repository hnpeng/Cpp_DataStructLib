#ifndef POINTER_H
#define POINTER_H

#include "Object/Object.h"

namespace NPLib {

template <typename T>
class Pointer : public Object
{
public:
    Pointer(T* pointer = NULL) : m_pointer(pointer) { }

    T* operator ->()
    {
        return m_pointer;
    }

    const T* operator ->() const
    {
        return m_pointer;
    }

    T& operator *()
    {
        return *m_pointer;
    }

    const T& operator *() const
    {
        return *m_pointer;
    }

    T* get() const
    {
        return m_pointer;
    }

    bool isNull() const
    {
        return (m_pointer == NULL);
    }

protected:
    T* m_pointer;
};

}

#endif // POINTER_H
