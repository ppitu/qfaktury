#ifndef NIPEXCEPTION_H
#define NIPEXCEPTION_H

#include <exception>

class NIPException : public std::exception
{
public:
    NIPException();

    const char* what() const throw();
};

#endif // NIPEXCEPTION_H
