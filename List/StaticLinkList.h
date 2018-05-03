#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H

#include "LinkList.h"

namespace NPLib {

template <typename T, int N>
class StaticLinkList : public LinkList<T>
{
    typedef typename LinkList<T>::Node Node;

    struct SNode : public Node
    {
        void* operator new(size_t, void* loc) throw()
        {
            return loc;
        }

//        void operator delete(void*) throw()
//        {
//        }
    };

public:
    StaticLinkList()
    {
        for (int i=0; i<N-1; i++) {
            m_usedLink[i] = i + 1;
        }

        m_usedLink[N-1] = -1;

        m_unusedListHead = 0;
    }

    SNode* create()
    {
        SNode* ret = NULL;

        if (m_unusedListHead != -1) {
            ret = reinterpret_cast<SNode*>(m_space) + m_unusedListHead;
            ret = new(ret) SNode();

            m_unusedListHead = m_usedLink[m_unusedListHead];
        }

        return ret;
    }

    void destroy(Node* pn)
    {
        for (int i=0; i<N; i++) {
            SNode* toDel = reinterpret_cast<SNode*>(m_space) + i;

            if (toDel == pn) {
                toDel->~SNode();
                m_usedLink[i] = m_unusedListHead;
                m_unusedListHead = i;

                break;
            }
        }
    }

    int capacity() const
    {
        return N;
    }

    ~StaticLinkList()
    {
        this->clear();
    }

private:
    char m_space[sizeof(SNode) * N];
    int m_usedLink[N];
    int m_unusedListHead;
};

}

#endif // STATICLINKLIST_H
