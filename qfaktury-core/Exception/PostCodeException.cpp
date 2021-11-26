#include "PostCodeException.h"

PostCodeException::PostCodeException()
{

}

const char *PostCodeException::what() const throw()
{
    return "Invalid post code";
}
