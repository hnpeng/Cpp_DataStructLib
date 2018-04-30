#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include "SeqList.h"

namespace NPLib {

template <typename T>
class DynamicList : public SeqList<T>
{
public:
    DynamicList(int capacity)
    {
        this->m_array = new T[capacity];

        if (this->m_array != nullptr) {
            m_capacity = capacity;
            this->m_length = 0;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create the object ...");
        }
    }

    ~DynamicList()
    {
        delete[] this->m_array;
    }

    int capacity() const
    {
        return m_capacity;
    }

    void resize(int capacity)
    {
        if (capacity == m_capacity)
            return;

        if (capacity >= 0) {
            T* array = new T[capacity];

            if (array != nullptr) {
                int length = capacity < this->m_length ? capacity : this->m_length;

                for (int i=0; i < length; i++) {
                    array[i] = this->m_array[i];
                }

                T* temp = this->m_array;
                this->m_array = array;
                this->m_length = length;
                m_capacity = capacity;

                delete[] temp;
            } else {
                THROW_EXCEPTION(NoEnoughMemoryException, "No enough memory for the capacity ...");
            }
        } else {
            THROW_EXCEPTION(InvalidParameterException, "Invalid parameter capacity ...");
        }
    }

private:
    int m_capacity;
};

}

#endif // DYNAMICLIST_H
