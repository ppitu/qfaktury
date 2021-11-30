#ifndef NIPEXCEPTION_H
#define NIPEXCEPTION_H

#include <exception>

class NIPException : public std::exception
{
public:
    NIPException();

    const char* what() const noexcept;
};

#endif // NIPEXCEPTION_H
