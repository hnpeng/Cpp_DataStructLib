#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include "Object/Object.h"

namespace NPLib {

template <typename T>
class SmartPointer : public Object
{
public:
    SmartPointer(T* p =  nullptr)
    {
        m_pointer = p;
    }

    ~SmartPointer()
    {
        delete m_pointer;
    }

    SmartPointer(const SmartPointer& obj)
    {
        m_pointer = obj.m_pointer;
        const_cast<SmartPointer&>(obj).m_pointer = nullptr;
    }

    SmartPointer& operator =(const SmartPointer& rhs)
    {
        if (this != &rhs) {
            delete m_pointer;
            m_pointer = rhs.m_pointer;
            const_cast<SmartPointer&>(rhs).m_pointer = nullptr;
        }

        return *this;
    }

    T* operator ->() const
    {
        return m_pointer;
    }

    T& operator *() const
    {
        return *m_pointer;
    }

    bool isNull() const
    {
        return m_pointer == nullptr;
    }

    T* getPointer() const
    {
        return m_pointer;
    }

private:
    T* m_pointer;
};

}


#endif
