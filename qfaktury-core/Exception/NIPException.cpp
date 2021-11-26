#include "NIPException.h"

NIPException::NIPException()
{

}

const char *NIPException::what() const throw()
{
   return "Invalid NIP";
}
