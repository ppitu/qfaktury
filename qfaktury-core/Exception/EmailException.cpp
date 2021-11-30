#include "EmailException.h"

EmailException::EmailException()
{

}

const char *EmailException::what() const noexcept
{
       return "Invalid e-mail";
}
