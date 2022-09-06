#ifndef MONEYTEST_H
#define MONEYTEST_H

#include <QTest>

class MoneyTest : public QObject
{
  Q_OBJECT
public:
  MoneyTest();

private slots:
  void construct_from_int_test();
};

#endif // MONEYTEST_H
