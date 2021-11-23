/*
 * ConvertAmount.cpp
 *
 *  Created on: Mar 16, 2009
 *      Author: tpielech
 */

#include "convertamount.h"
#include "settings.h"

ConvertAmount::ConvertAmount() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;
  // TODO Auto-generated constructor stub
}

ConvertAmount::~ConvertAmount() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;
  // TODO Auto-generated destructor stub
}

QString &ConvertAmount::descAmount(QString &countMoney, QString partMoney,
                                   QString ifOne, QString ifMore,
                                   QString ifBetween) {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  while (partMoney.length() < 3)
    partMoney = QString("0") + partMoney;

  switch (partMoney.left(1).toInt()) {
  case 1:
    countMoney += QString(" ") + hundsList()[0];
    break;
  case 2:
    countMoney += QString(" ") + hundsList()[1];
    break;
  case 3:
    countMoney += QString(" ") + hundsList()[2];
    break;
  case 4:
    countMoney += QString(" ") + hundsList()[3];
    break;
  case 5:
    countMoney += QString(" ") + hundsList()[4];
    break;
  case 6:
    countMoney += QString(" ") + hundsList()[5];
    break;
  case 7:
    countMoney += QString(" ") + hundsList()[6];
    break;
  case 8:
    countMoney += QString(" ") + hundsList()[7];
    break;
  case 9:
    countMoney += QString(" ") + hundsList()[8];
    break;
  case 0:
    countMoney += QString("");
    break;
  }

  if (partMoney.mid(1, 1).toInt() == 1) {

    switch (partMoney.right(1).toInt()) {
    case 1:
      countMoney += QString(" ") + endsTensList()[0];
      break;
    case 2:
      countMoney += QString(" ") + endsTensList()[1];
      break;
    case 3:
      countMoney += QString(" ") + endsTensList()[2];
      break;
    case 4:
      countMoney += QString(" ") + endsTensList()[3];
      break;
    case 5:
      countMoney += QString(" ") + endsTensList()[4];
      break;
    case 6:
      countMoney += QString(" ") + endsTensList()[5];
      break;
    case 7:
      countMoney += QString(" ") + endsTensList()[6];
      break;
    case 8:
      countMoney += QString(" ") + endsTensList()[7];
      break;
    case 9:
      countMoney += QString(" ") + endsTensList()[8];
      break;
    case 0:
      countMoney += QString(" ") + endsTensList()[9];
      break;
    }

  } else {
    switch (partMoney.mid(1, 1).toInt()) {
    case 2:
      countMoney += QString(" ") + endsHundList()[0];
      break;
    case 3:
      countMoney += QString(" ") + endsHundList()[1];
      break;
    case 4:
      countMoney += QString(" ") + endsHundList()[2];
      break;
    case 5:
      countMoney += QString(" ") + endsHundList()[3];
      break;
    case 6:
      countMoney += QString(" ") + endsHundList()[4];
      break;
    case 7:
      countMoney += QString(" ") + endsHundList()[5];
      break;
    case 8:
      countMoney += QString(" ") + endsHundList()[6];
      break;
    case 9:
      countMoney += QString(" ") + endsHundList()[7];
      break;
    case 0:
      countMoney += QString("");
      break;
    }

    switch (partMoney.right(1).toInt()) {
    case 1:
      countMoney += QString(" ") + simpleNumbList()[0];
      break;
    case 2:
      countMoney += QString(" ") + simpleNumbList()[1];
      break;
    case 3:
      countMoney += QString(" ") + simpleNumbList()[2];
      break;
    case 4:
      countMoney += QString(" ") + simpleNumbList()[3];
      break;
    case 5:
      countMoney += QString(" ") + simpleNumbList()[4];
      break;
    case 6:
      countMoney += QString(" ") + simpleNumbList()[5];
      break;
    case 7:
      countMoney += QString(" ") + simpleNumbList()[6];
      break;
    case 8:
      countMoney += QString(" ") + simpleNumbList()[7];
      break;
    case 9:
      countMoney += QString(" ") + simpleNumbList()[8];
      break;
    case 0:
      countMoney += QString("");
      break;
    }
  }

  if (!ifOne.isEmpty() && !ifOne.isNull()) {
    if (partMoney.toInt() > 9) {

      countMoney += ifMore;
      qDebug() << "partMoney.toInt() > 9: " << partMoney.toInt();

    } else if ((partMoney.toInt() < 10) && (partMoney.toInt() > 0)) {

      if ((partMoney.toInt() > 1) && (partMoney.toInt() < 5))
        countMoney += ifBetween;
      else if (partMoney.toInt() > 4)
        countMoney += ifMore;
      else
        countMoney += ifOne;
      qDebug() << "partMoney.toInt() >= 1: " << partMoney.toInt();
    }
  }

  return countMoney;
}

const QStringList ConvertAmount::hundsList() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  QStringList hundredsPL = QStringList();
  hundredsPL << QString("sto") << QString("dwieście")
             << QString("trzysta") << QString("czterysta")
             << QString("pięćset") << QString("sześćset")
             << QString("siedemset") << QString("osiemset")
             << QString("dziewięćset");

  return hundredsPL;
}

const QStringList ConvertAmount::endsHundList() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  QStringList hundEndsPL = QStringList();
  hundEndsPL << QString("dwadzieścia") << QString("trzydzieści")
             << QString("czterdzieści")
             << QString("pięćdziesiąt")
             << QString("sześćdziesiąt")
             << QString("siedemdziesiąt")
             << QString("osiemdziesiąt")
             << QString("dziewięćdziesiąt");

  return hundEndsPL;
}

const QStringList ConvertAmount::endsTensList() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  QStringList tenEndsPL = QStringList();
  tenEndsPL << QString("jedenaście") << QString("dwanaście")
            << QString("trzynaście") << QString("czternaście")
            << QString("piętnaście") << QString("szesnaście")
            << QString("siedemnaście") << QString("osiemnaście")
            << QString("dziewiętnaście") << QString("dziesięć");

  return tenEndsPL;
}

const QStringList ConvertAmount::simpleNumbList() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  QStringList nineNumbs = QStringList();
  nineNumbs << QString("jeden") << QString("dwa")
            << QString("trzy") << QString("cztery")
            << QString("pięć") << QString("sześć")
            << QString("siedem") << QString("osiem")
            << QString("dziewięć");

  return nineNumbs;
}

QString ConvertAmount::convertPL(QString input, QString currency) {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  QString in = input.remove(sett().getTPointStr());
  qDebug() << "in: " << in;

  QString tmp = in.remove(in.indexOf(sett().getDecimalPointStr()), 3);
  qDebug() << "temp: " << tmp;

  QString hundreds = tmp.right(3);
  QString thousands = QString();
  QString millions = QString();
  QString billions = QString();

  switch (tmp.length()) {
  case 4:

    thousands = tmp.left(1);
    millions = QString("");
    billions = QString("");
    break;

  case 5:

    thousands = tmp.left(2);
    millions = QString("");
    billions = QString("");
    break;

  case 6:

    thousands = tmp.left(3);
    millions = QString("");
    billions = QString("");
    break;

  case 7:

    millions = tmp.left(1);
    thousands = tmp.mid(1, 3);
    billions = QString("");
    break;

  case 8:

    millions = tmp.left(2);
    thousands = tmp.mid(2, 3);
    billions = QString("");
    break;

  case 9:

    millions = tmp.left(3);
    thousands = tmp.mid(3, 3);
    billions = QString("");
    break;

  case 10:

    billions = tmp.left(1);
    millions = tmp.mid(1, 3);
    thousands = tmp.mid(4, 3);
    break;

  case 11:

    billions = tmp.left(2);
    millions = tmp.mid(2, 3);
    thousands = tmp.mid(5, 3);
    break;

  case 12:

    billions = tmp.left(3);
    millions = tmp.mid(3, 3);
    thousands = tmp.mid(6, 3);
    break;

  default:

    thousands = QString("");
    millions = QString("");
    billions = QString("");
    break;
  }

  qDebug() << "billions' value: " << billions;
  qDebug() << "millions' value: " << millions;
  qDebug() << "thousands' value: " << thousands;

  QString out = QString();

  descAmount(out, billions, QString(" miliard"),
             QString(" miliardów"), QString(" miliardy"));
  descAmount(out, millions, QString(" milion"),
             QString(" milionów"), QString(" miliony"));
  descAmount(out, thousands, QString(" tysiąc"),
             QString(" tysięcy"), QString(" tysiące"));
  descAmount(out, hundreds);

  in = input;
  QString change = in.remove(0, in.indexOf(sett().getDecimalPointStr()) + 1);

  return out + QString(" ") + change + QString("/100 ") +
         currency;
}
