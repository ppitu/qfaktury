#include "EmailException.h"

EmailException::EmailException()
{

}

const char *EmailException::what() const throw()
{
       return "Invalid e-mail";
}
