#include "Exception.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace NPLib;

Exception::Exception(const char *message)
{
    init(message, nullptr, 0);
}

Exception::Exception(const char *file, const int line)
{
    init(nullptr, file, line);
}

Exception::Exception(const char *message, const char *file, const int line)
{
    init(message, file, line);
}

void Exception::init(const char *message, const char *file, int line)
{
    m_message = message ? strdup(message) : NULL;

    if (file != nullptr) {
        char sline[16];
        sprintf(sline, "%d", line);
        m_location = reinterpret_cast<char*>(malloc(strlen(file) + strlen(sline) + 2));
        strcpy(m_location, file);
        strcat(m_location, ":");
        strcat(m_location, sline);
    } else {
        m_location = nullptr;
    }
}

Exception::Exception(const Exception &obj)
{
    m_message = strdup(obj.m_message);
    m_location = strdup(obj.m_location);
}

Exception &Exception::operator =(const Exception &rhs)
{
    if (this != & rhs) {
        free(m_message);
        free(m_location);
        m_message = strdup(rhs.m_message);
        m_location = strdup(rhs.m_location);
    }

    return *this;
}

char *Exception::message() const
{
    return m_message;
}

char *Exception::location() const
{
    return m_location;
}

Exception::~Exception()
{
    free(m_message);
    free(m_location);
}
