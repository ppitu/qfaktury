#ifndef MONEYEXCEPTION_H
#define MONEYEXCEPTION_H

#include <exception>

namespace exception
{

class MoneyException : public std::exception
{
public:
  MoneyException();

  const char* what() const noexcept;
};

}

#endif // MONEYEXCEPTION_H
