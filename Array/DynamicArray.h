#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "Array.h"

namespace NPLib {

template <typename T>
class DynamicArray : public Array<T>
{
public:
    DynamicArray(int length = 0)
    {
        init(new T[length], length);
    }

    DynamicArray(const DynamicArray& obj)
    {
        init(copy(obj.m_array, obj.m_length, obj.m_length), obj.m_length);
    }

    DynamicArray& operator =(const DynamicArray& rhs)
    {
        if (this != &rhs) {
            update(copy(rhs.m_array, rhs.m_length, rhs.m_length), rhs.m_length);
        }

        return *this;
    }

    void resize(int length)
    {
        if (length == m_length)
            return;

        if (length >= 0) {
            update(copy(this->m_array, m_length, length), length);
        } else {
            THROW_EXCEPTION(InvalidParameterException, "Invalid parameter \"length\" ...");
        }
    }

    int length() const
    {
        return m_length;
    }

    ~DynamicArray()
    {
        delete[] this->m_array;
    }

private:
    void init(T* newArr, int newLen)
    {
        if (newArr != NULL) {
            this->m_array = newArr;
            this->m_length = newLen;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicArry ...");
        }
    }

    T* copy(T* srcArr, int len, int newLen)
    {
        T* array = new T[newLen];

        if (array != NULL) {
            int length = len < newLen ? len : newLen;

            for (int i=0; i<length; i++) {
                array[i] = srcArr[i];
            }
        }

        return array;
    }

    void update(T* newArr, int newLen)
    {
        if (newArr != NULL) {
            T* temp = this->m_array;

            this->m_array = newArr;
            this->m_length = newLen;

            delete[] temp;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to copy array ...");
        }
    }

private:
    int m_length;
};

}

#endif // DYNAMICARRAY_H
