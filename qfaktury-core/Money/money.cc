#include "money.h"

#include <cmath>

#include "Exception/money_exception.h"
#include "qregularexpression.h"

Money::Money() :
                 money_(0),
                 precision_(0)
{
  
}

Money::Money(int money, int precision) :
                                         money_(money),
                                         precision_(precision)
{
  checkPrecision();
}

Money::Money(float money, int precision) : precision_(precision)
{
  checkPrecision();

  money_ = static_cast<int32_t>(money * std::pow(10, precision_));
}

Money::Money(double money, int precision) : precision_(precision)
{
  checkPrecision();

  money_ = static_cast<int32_t>(money * std::pow(10, precision_));
}

Money::Money(const QString &money, int precision) :
                                                    precision_(precision)
{
  checkPrecision();
  validate(money);

  money_ = money.toInt() * static_cast<int32_t>(std::pow(10, precision_));
}

const QString Money::toString() const
{
  if(money_ == 0)
    return "0.00";

  return QString::number(static_cast<int32_t>(money_ / static_cast<int32_t>(std::pow(10, precision_)))) +
         "." + QString::number(static_cast<int32_t>(money_ % precision_));
}

void Money::validate(const QString& money)
{
  QRegularExpression re("/^(0|[1-9]\\d*)(\\.\\d+)?$/");
  QRegularExpressionMatch match = re.match(money);

  if(!match.hasMatch())
  {
    throw exception::MoneyException();
  }
}

void Money::checkPrecision()
{
  if(precision_ < 0 || precision_ > 4)
  {
    throw exception::MoneyException();
  }
}
