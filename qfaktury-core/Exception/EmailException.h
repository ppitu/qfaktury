#ifndef EMAILEXCEPTION_H
#define EMAILEXCEPTION_H

#include <exception>

class EmailException : public std::exception
{
public:
    EmailException();

    const char* what() const noexcept;
};

#endif // EMAILEXCEPTION_H
