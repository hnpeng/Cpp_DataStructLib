#ifndef LINKLIST_H
#define LINKLIST_H

#include "List.h"
#include "Exception/Exception.h"

namespace NPLib {

template <typename T>
class LinkList : public List<T>
{
public:
    LinkList()
    {
        m_header.next = NULL;
        m_length = 0;
        m_step = 1;
        m_current = NULL;
    }

    bool insert(int pos, const T& element)
    {
        bool ret = 0 <= pos && pos <= m_length;

        if (ret) {
            Node* newNode = create();

            if (newNode != NULL) {
                Node* current = position(pos);

                newNode->element = element;
                newNode->next = current->next;
                current->next = newNode;

                m_length++;
            } else {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create Node ...");
            }

        }

        return ret;
    }

    bool append(const T& element)
    {
        return insert(m_length, element);
    }

    bool remove(int pos, T& element)
    {
        bool ret = 0 <= pos && pos < m_length;

        if (ret) {
            Node* current = position(pos);
            Node* toDel = current->next;

            if (m_current == toDel) {
                m_current = toDel->next;
            }

            current->next = toDel->next;
            element = toDel->element;
            m_length--;

            destroy(toDel);
        }

        return ret;
    }

    bool get(int pos, T& element) const
    {
        bool ret = 0 <= pos && pos < m_length;

        if (ret) {
            element = position(pos)->next->element;
        }

        return ret;
    }

    T get(int pos) const
    {
        T ret;

        if (get(pos, ret)) {
            return ret;
        } else {
            THROW_EXCEPTION(InvalidParameterException, "Invalid parameter pos ...");
        }
    }

    bool set(int pos, const T& element)
    {
        bool ret = 0 <= pos && pos < m_length;

        if (ret) {
            position(pos)->next->element = element;
        }

        return ret;
    }

    int find(const T& element) const
    {
        int ret = -1;
        int i = 0;
        Node* current = m_header.next;

        while (current != NULL) {
            if (current->element == element) {
                ret = i;
                break;
            } else {
                i++;
                current = current->next;
            }
        }

        return ret;
    }

    void clear()
    {
        while (m_header.next != NULL) {
            Node* toDel = m_header.next;

            m_header.next = toDel->next;
            m_length--;
            destroy(toDel);
        }
    }

    int length() const
    {
        return m_length;
    }

    bool move(int pos, int step = 1)
    {
        bool ret = 0 <= pos && pos < m_length;

        ret = ret && step > 0;

        if (ret) {
            m_step = step;
            m_current = position(pos)->next;
        }

        return ret;
    }

    bool next()
    {
        int i;

        for (i=0; i<m_step && m_current != NULL; i++) {
            m_current = m_current->next;
        }

        return i == m_step;
    }

    bool end()
    {
        return m_current == NULL;
    }

    T current()
    {
        if (!end()) {
            return m_current->element;
        } else {
            THROW_EXCEPTION(InvalidOperationExcpetion, "No value at current position ...");
        }
    }

    ~LinkList()
    {
        clear();
    }

protected:
    struct Node : public Object
    {
        T element;
        Node* next;
    };

    virtual Node* create()
    {
        return new Node;
    }

    virtual void destroy(Node* pn)
    {
        delete pn;
    }

private:
    Node* position(int pos) const
    {
        Node* ret = reinterpret_cast<Node*>(&m_header);

        for (int i=0; i<pos; i++) {
            ret = ret->next;
        }

        return ret;
    }

private:

    mutable struct : public Object
    {
        char preserve[sizeof(T)];
        Node* next;
    } m_header;
    int m_length;
    int m_step;
    Node* m_current;
};

}

#endif // LINKLIST_H
