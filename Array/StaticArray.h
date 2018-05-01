#ifndef STATICARRAY_H
#define STATICARRAY_H

#include "Array.h"

namespace NPLib {

template <typename T, int N>
class StaticArray : public Array<T>
{
public:
    StaticArray()
    {
        this->m_array = m_space;
    }

    StaticArray(const StaticArray& obj)
    {
        this->m_array = m_space;

        for (int i=0; i<N; i++) {
            this->m_array[i] = obj.m_array[i];
        }
    }

    StaticArray& operator =(const StaticArray& rhs)
    {
        if (this != & rhs)
        {
            for (int i=0; i<N; i++) {
                this->m_array[i] = rhs.m_array[i];
            }
        }

        return *this;
    }

    int length() const
    {
        return N;
    }

private:
    T m_space[N];
};

}

#endif // STATICARRAY_H
