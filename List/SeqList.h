#ifndef SEQLIST_H
#define SEQLIST_H

#include "List.h"
#include "Exception/Exception.h"

namespace NPLib {

template <typename T>
class SeqList : public List<T>
{
public:
    bool insert(int pos, const T& element)
    {
        bool ret = pos >= 0 && capacity() > m_length;

        if (ret) {
            int i;

            for (i=m_length; i>pos; i--) {
                m_array[i] = m_array[i-1];
            }

            m_array[i] = element;
            m_length++;
        }

        return ret;
    }

    bool append(const T& element)
    {
        return insert(m_length, element);
    }

    bool remove(int pos)
    {
        int ret = 0 <= pos && pos < m_length;

        if (ret) {
            for (int i=pos; i < m_length-1; i++) {
                m_array[i] = m_array[i+1];
            }

            m_length--;
        }

        return ret;
    }

    bool get(int pos, T& element) const
    {
        bool ret = 0 <= pos && pos < m_length;

        if (ret) {
            element = m_array[pos];
        }

        return ret;
    }

    bool set(int pos, const T& element)
    {
        bool ret = 0 <= pos && pos < m_length;

        if (ret) {
            m_array[pos] = element;
        }

        return ret;
    }

    int find(const T& element) const
    {
        int ret = -1;

        for (int i=0; i < m_length; i++) {
            if (m_array[i] == element) {
                ret = i;
                break;
            }
        }

        return ret;
    }

    void clear()
    {
        m_length = 0;
    }

    int length() const
    {
        return m_length;
    }

    T& operator [](int pos)
    {
        if (0 <= pos && pos < m_length) {
            return m_array[pos];
        } else {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Invalide pos of the array ...");
        }
    }

    T operator [](int pos) const
    {
        return const_cast<SeqList<T>&>(*this)[pos];
    }

    virtual int capacity() const = 0;

protected:
    T* m_array;
    int m_length;
};

}

#endif // SEQLIST_H
