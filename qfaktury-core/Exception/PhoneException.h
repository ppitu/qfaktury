#ifndef PHONEEXCEPTION_H
#define PHONEEXCEPTION_H

#include <exception>

class PhoneException : public std::exception
{
public:
    PhoneException();

    const char* what() const throw();
};

#endif // PHONEEXCEPTION_H
