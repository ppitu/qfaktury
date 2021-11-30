#include "NIPException.h"

NIPException::NIPException()
{

}

const char *NIPException::what() const noexcept
{
   return "Invalid NIP";
}
