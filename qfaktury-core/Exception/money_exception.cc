#include "money_exception.h"

using namespace exception;

MoneyException::MoneyException()
{

}

const char *MoneyException::what() const noexcept
{
  return "Invalid money format";
}
