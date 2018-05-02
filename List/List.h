#ifndef LIST_H
#define LIST_H

#include "Object/Object.h"

namespace NPLib {

template <typename T>
class List : public Object
{
public:
    List() { }
    virtual bool insert(int pos, const T& element) = 0;
    virtual bool append(const T& element) = 0;
    virtual bool remove(int pos, T& element) = 0;
    virtual bool get(int pos, T& element) const = 0;
    virtual bool set(int pos, const T& element) = 0;
    virtual int find(const T& element) const = 0;
    virtual void clear() = 0;
    virtual int length() const = 0;

private:
    List(const List&);
    List& operator =(const List&);
};

}

#endif
