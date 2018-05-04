#ifndef CIRCLELIST_H
#define CIRCLELIST_H

#include "LinkList.h"

namespace NPLib {

template <typename T>
class CircleList : public LinkList<T>
{
    typedef typename LinkList<T>::Node Node;

public:
    bool insert(int pos, const T& element)
    {
        bool ret = true;

        pos = pos % (this->m_length + 1);

        ret = LinkList<T>::insert(pos, element);

        if (ret && pos == 0) {
            last_to_first();
        }

        return ret;
    }

    bool append(const T& element)
    {
        return insert(this->m_length, element);
    }

    bool remove(int pos)
    {
        bool ret = true;

        pos = mod(pos);

        if (pos == 0) {
            if (this->m_header.next != NULL) {
                Node* toDel = this->m_header.next;

                this->m_header.next = toDel->next;
                this->m_length--;
                last_to_first();

                if (this->m_current == toDel) {
                    this->m_current = toDel->next;
                }

                if (this->m_length == 0) {
                    this->m_header.next = NULL;
                    this->m_current = NULL;
                }

                this->destroy(toDel);
            } else {
                ret = false;
            }
        } else {
            ret = LinkList<T>::remove(pos);
        }

        return ret;
    }

    bool get(int pos, T& element) const
    {
        return LinkList<T>::get(mod(pos), element);
    }

    T get(int pos) const
    {
        return LinkList<T>::get(mod(pos));
    }

    bool set(int pos, const T& element)
    {
        return LinkList<T>::set(mod(pos), element);
    }

    int find(const T& element) const
    {
        return LinkList<T>::find(element);
    }

    void clear()
    {
        while (this->m_length > 1) {
            remove(1);
        }

        remove(0);
    }

    bool move(int pos, int step)
    {
        return LinkList<T>::move(mod(pos), step);
    }

    bool end()
    {
        return this->m_length == 0 || this->m_current == NULL;
    }

    ~CircleList()
    {
        clear();
    }

private:
    Node* last()
    {
        return this->position(this->m_length-1)->next;
    }

    void last_to_first()
    {
        Node* la = last();

        if (la != NULL) {
            la->next = this->m_header.next;
        }
    }

    int mod(int i) const
    {
        return this->m_length == 0 ? 0 : i % this->m_length;
    }
};

}

#endif // CIRCLELIST_H
