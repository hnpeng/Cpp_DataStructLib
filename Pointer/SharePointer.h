#ifndef SHAREPOINTER_H
#define SHAREPOINTER_H

#include "Pointer.h"
#include "Exception/Exception.h"

namespace NPLib {

template <typename T>
class SharePointer : public Pointer<T>
{
public:
    SharePointer(T* p = NULL) : Pointer<T>(p), m_ref(NULL)
    {
        if (p != NULL) {
            m_ref = reinterpret_cast<int*>(malloc(sizeof(int)));

            if (m_ref != NULL) {
                *m_ref = 1;
            } else {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create SharePoint ...");
            }
        }
    }

    SharePointer(const SharePointer& obj)
    {
        this->m_pointer = obj.m_pointer;
        m_ref = obj.m_ref;

        if (m_ref != NULL) {
            (*m_ref)++;
        }
    }

    SharePointer& operator =(const SharePointer& rhs)
    {
        if (this != &rhs) {
            clear();
            this->m_pointer = rhs.m_pointer;
            m_ref = rhs.m_ref;

            if (m_ref != NULL) {
                (*m_ref)++;
            }
        }

        return *this;
    }

    void clear()
    {
        T* toDel = this->m_pointer;
        int* ref = m_ref;

        this->m_pointer = NULL;
        this->m_ref = NULL;

        if (ref != NULL) {
            (*ref)--;

            if (*ref == 0) {
                free(ref);
                delete toDel;
            }

        }
    }

    ~SharePointer()
    {
        clear();
    }

private:
    int* m_ref;
};

template <typename T>
bool operator ==(const SharePointer<T>& lhs, const SharePointer<T>& rhs)
{
    return lhs.get() == rhs.get();
}

template <typename T>
bool operator !=(const SharePointer<T>& lhs, const SharePointer<T>& rhs)
{
    return !(lhs == rhs);
}

}

#endif // SHAREPOINTER_H
