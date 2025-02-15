#if _pragma_once_support
#pragma once
#endif
#ifndef WAREHOUSEDATA_H
#define WAREHOUSEDATA_H

#include "productdata.h"
#include "documentdata.h"

// class for holding informations about warehouse documents. One instance -> one
// document
class WarehouseData : public DocumentData {

public:
  QString getCustomer() { return customer; }
  QString customer; // buyer
  QMap<int, ProductData> products;
  QDate liabDate;
  QDate sellingDate;
  QDate productDate;
  QDate endTransDate;
  QDate duplDate;
  QString sellerAddress;
  QString invNr;
  QString paymentType;
  QString additText;

  QString type;
  QString id;           // in case of xml, here goes filename
  bool ifInvForDelNote; // for delivery note (WZ)

  QString custStreet;
  QString custTic;
  QString custCity;
  QString custName;
  QDate issueDate;
  int invoiceType; // 9 - WZ, 10 - RW

  // *START* for good issue note (RW)
  QString goodFromPlace;
  QString goodToPlace;
  QString departmentCost;
  QDate goodFromDate;
  QDate goodToDate;
  // *END*

  /**
   *  Return invoice type
   */

  QString getInvoiceTypeAndSaveNr(int invoiceType) {
    QString ret = "WZ";

    switch (invoiceType) {
    case 9:
      ret = QString("WZ");
      break;
    case 10:
      ret = QString("RW");
      break;
    default:
      ret = QString("WZ");
      break;
    }

    return ret;
  }
};

#endif
