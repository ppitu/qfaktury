#include "money_test.h"

#include "Money/money.h"

MoneyTest::MoneyTest()
{

}

void MoneyTest::construct_from_int_test()
{
  {
    Money money(10000, 2);

    QCOMPARE(money.toString(), "100.0");
  }
}
