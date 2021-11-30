#include "PhoneException.h"

PhoneException::PhoneException()
{
    
}

const char *PhoneException::what() const noexcept
{
    return "Invalid phone number";
}
