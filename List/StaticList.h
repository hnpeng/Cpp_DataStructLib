#ifndef STATICLIST_H
#define STATICLIST_H

#include "SeqList.h"

namespace NPLib {

template <typename T, int N>
class StaticList : public SeqList<T>
{
public:
    StaticList()
    {
        this->m_length = 0;
        this->m_array = m_space;
    }

    virtual int capacity() const
    {
        return N;
    }

private:
    T m_space[N];
};

}

#endif // STATICLIST_H
