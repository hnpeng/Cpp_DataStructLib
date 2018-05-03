#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include "Pointer.h"

namespace NPLib {

template <typename T>
class SmartPointer : public Pointer<T>
{
public:
    SmartPointer(T* p =  nullptr) : Pointer<T>(p) { }

    ~SmartPointer()
    {
        delete this->m_pointer;
    }

    SmartPointer(const SmartPointer& obj)
    {
        this->m_pointer = obj.m_pointer;
        const_cast<SmartPointer&>(obj).m_pointer = nullptr;
    }

    SmartPointer& operator =(const SmartPointer& rhs)
    {
        if (this != &rhs) {
            T* temp =  this->m_pointer;

            this->m_pointer = rhs.m_pointer;
            const_cast<SmartPointer&>(rhs).m_pointer = nullptr;

            delete temp;
        }

        return *this;
    }

};

}


#endif
