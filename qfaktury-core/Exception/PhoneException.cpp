#include "PhoneException.h"

PhoneException::PhoneException()
{
    
}

const char *PhoneException::what() const throw()
{
    return "Invalid phone number";
}
