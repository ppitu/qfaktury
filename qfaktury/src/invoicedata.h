/*
 * InvoiceData.h
 *
 *  Created on: Mar 12, 2009
 *      Author: moux
 */
#include "detector.h"
#if _pragma_once_support
#pragma once
#endif
#ifndef INVOICEDATA_H
#define INVOICEDATA_H

#include "custompaymdata.h"
#include "productdata.h"
#include "documentdata.h"

// class for holding data about invoices. One instance -> one invoice.
class InvoiceData : public DocumentData {

public:
    InvoiceData(){}
    virtual ~InvoiceData(){}

  QString getCustomer() { return customer; }
  QString customer; // buyer
  QMap<int, ProductData> products;
  QDate liabDate;
  QDate sellingDate;
  QDate productDate;
  QDate endTransDate;
  QDate duplDate;
  QString invNr;
  QString origInvNr;
  QString paymentType;
  QString currencyType;
  QString reason;
  QString additText;
  QString payment1;
  QDate date1;
  double amount1;

  QString payment2;
  QDate date2;
  double amount2;

  QString type;
  QString id; // in case of xml, here goes filename
  bool ifpVAT;
  bool ifInvForDelNote;

  QString custStreet;
  QString custTic;
  QString custCity;
  QString custName;
  QString sellerAddress;
  QString sellerName;
  QString sellerTic;
  QString sellerCity;

  int currencyTypeId;
  int discount;
  CustomPaymData custPaym;
  QDate issueDate;
  int invoiceType; // 1 - FVAT, 2 - FPro, 3 - corr, 4 - FBrutto

  QString jpkFieldText;

  /**
   *  Return invoice type
   */

  QString getInvoiceTypeAndSaveNr(int invoiceType) {
    QString ret = "FVAT";

    switch (invoiceType) {
    case 1:
      ret = QString("FVAT");
      break;
    case 2:
      ret = QString("FPro");
      break;
    case 3:
      ret = QString("korekta");
      break;
    case 4:
      ret = QString("FBrutto");
      break;
    case 5:
      ret = QString("kbrutto");
      break;
    case 6:
      ret = QString("rachunek");
      break;
    case 7:
      ret = QString("duplikat");
      break;
    case 8:
      ret = QString("RR");
      break;
    case 9:
      ret = QString("FVAT");
      break;
    case 10:
      ret = QString("RW");
      break;
    default:
      ret = QString("FVAT");
      break;
    }

    return ret;
  }

  int getInvoiceNameReturnType(QString invoiceType) {

    if (invoiceType == QString("FVAT")) return 1;
    else if (invoiceType == QString("FPro")) return 2;
    else if (invoiceType == QString("korekta")) return 3;
    else if (invoiceType == QString("FBrutto")) return 4;
    else if (invoiceType == QString("kbrutto")) return 5;
    else if (invoiceType == QString("rachunek")) return 6;
    else if (invoiceType == QString("duplikat")) return 7;
    else if (invoiceType == QString("RR")) return 8;
    else if (invoiceType == QString("FVAT")) return 9;
    else if (invoiceType == QString("RW")) return 10;
    else return 1;

    return 1;

}

};

#endif
