#ifndef MONEY_H
#define MONEY_H

#include <cstdint>

#include <QString>

class Money final
{
public:
  Money();
  explicit Money(int money, int precision);
  explicit Money(float money, int precision);
  explicit Money(double money, int precision);
  explicit Money(const QString& money, int precision);

  const QString toString() const;

private:
  void checkPrecision();
  void validate(const QString& money);

  int32_t money_;
  int precision_;
};

#endif // MONEY_H
