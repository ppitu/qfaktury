#ifndef POSTCODEEXCEPTION_H
#define POSTCODEEXCEPTION_H

#include <exception>

class PostCodeException : public std::exception
{
public:
    PostCodeException();

    const char* what() const throw();
};

#endif // POSTCODEEXCEPTION_H
