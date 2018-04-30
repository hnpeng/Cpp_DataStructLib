#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "Object/Object.h"

#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))

namespace NPLib {


class Exception : public Object
{
public:
    Exception(const char* message);
    Exception(const char* file, const int line);
    Exception(const char* message, const char* file, const int line);

    Exception(const Exception& obj);
    Exception& operator =(const Exception& rhs);

    char* message() const;
    char* location() const;

    virtual ~Exception() = 0;

protected:
    void init(const char* message, const char* file, int line);

    char* m_message;
    char* m_location;
};

class ArithmeticException : public Exception
{
public:
    ArithmeticException() :
        Exception(nullptr) { }
    ArithmeticException(const char* file, int line) :
        Exception(file, line) { }
    ArithmeticException(const char* message) :
        Exception(message) { }
    ArithmeticException(const char* message, const char* file, int line) :
        Exception(message, file, line) { }

    ArithmeticException(const ArithmeticException& obj) :
        Exception(obj) { }

    ArithmeticException& operator =(const ArithmeticException& rhs)
    {
        Exception::operator =(rhs);

        return *this;
    }
};

class NullPointerException : public Exception
{
public:
    NullPointerException() :
        Exception(nullptr) { }
    NullPointerException(const char* file, int line) :
        Exception(file, line) { }
    NullPointerException(const char* message) :
        Exception(message) { }
    NullPointerException(const char* message, const char* file, int line) :
        Exception(message, file, line) { }

    NullPointerException(const NullPointerException& obj) :
        Exception(obj) { }

    NullPointerException& operator =(const NullPointerException& rhs)
    {
        Exception::operator =(rhs);

        return *this;
    }
};

class IndexOutOfBoundsException : public Exception
{
public:
    IndexOutOfBoundsException() :
        Exception(nullptr) { }
    IndexOutOfBoundsException(const char* file, int line) :
        Exception(file, line) { }
    IndexOutOfBoundsException(const char* message) :
        Exception(message) { }
    IndexOutOfBoundsException(const char* message, const char* file, int line) :
        Exception(message, file, line) { }

    IndexOutOfBoundsException(const IndexOutOfBoundsException& obj) :
        Exception(obj) { }

    IndexOutOfBoundsException& operator =(const IndexOutOfBoundsException& rhs)
    {
        Exception::operator =(rhs);

        return *this;
    }
};

class NoEnoughMemoryException : public Exception
{
public:
    NoEnoughMemoryException() :
        Exception(nullptr) { }
    NoEnoughMemoryException(const char* file, int line) :
        Exception(file, line) { }
    NoEnoughMemoryException(const char* message) :
        Exception(message) { }
    NoEnoughMemoryException(const char* message, const char* file, int line) :
        Exception(message, file, line) { }

    NoEnoughMemoryException(const NoEnoughMemoryException& obj) :
        Exception(obj) { }

    NoEnoughMemoryException& operator =(const NoEnoughMemoryException& rhs)
    {
        Exception::operator =(rhs);

        return *this;
    }
};

class InvalidParameterException : public Exception
{
public:
    InvalidParameterException() :
        Exception(nullptr) { }
    InvalidParameterException(const char* file, int line) :
        Exception(file, line) { }
    InvalidParameterException(const char* message) :
        Exception(message) { }
    InvalidParameterException(const char* message, const char* file, int line) :
        Exception(message, file, line) { }

    InvalidParameterException(const InvalidParameterException& obj) :
        Exception(obj) { }

    InvalidParameterException& operator =(const InvalidParameterException& rhs)
    {
        Exception::operator =(rhs);

        return *this;
    }
};

class InvalidOperationExcpetion : public Exception
{
public:
    InvalidOperationExcpetion() :
        Exception(nullptr) { }
    InvalidOperationExcpetion(const char* file, int line) :
        Exception(file, line) { }
    InvalidOperationExcpetion(const char* message) :
        Exception(message) { }
    InvalidOperationExcpetion(const char* message, const char* file, int line) :
        Exception(message, file, line) { }

    InvalidOperationExcpetion(const InvalidOperationExcpetion& obj) :
        Exception(obj) { }

    InvalidOperationExcpetion& operator =(const InvalidOperationExcpetion& rhs)
    {
        Exception::operator =(rhs);

        return *this;
    }
};

}

#endif
