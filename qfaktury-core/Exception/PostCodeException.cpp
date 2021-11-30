#include "PostCodeException.h"

PostCodeException::PostCodeException()
{

}

const char *PostCodeException::what() const noexcept
{
    return "Invalid post code";
}
