#ifndef ARRAY_H
#define ARRAY_H

#include "Object/Object.h"
#include "Exception/Exception.h"

namespace NPLib {

template <typename T>
class Array : public Object
{
public:
    bool set(int pos, const T& element)
    {
        bool ret = 0 <= pos && pos < length();

        if (ret) {
            m_array[pos] = element;
        }

        return ret;
    }

    bool get(int pos, T& element)
    {
        bool ret = 0 <= pos && pos < length();

        if (ret) {
            element = m_array[pos];
        }

        return ret;
    }

    virtual int length() const = 0;

    T& operator [](int pos)
    {
        if (0 <= pos && pos < length()) {
            return m_array[pos];
        } else {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Invalid pos of the array ...");
        }
    }

    T operator [](int pos) const
    {
        return const_cast<Array<T>&>(*this)[pos];
    }

protected:
    T* m_array;
};

}

#endif // ARRAY_H
