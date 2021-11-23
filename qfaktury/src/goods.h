#include "detector.h"
#if _pragma_once_support
#pragma once
#endif
#ifndef GOODS_H
#define GOODS_H

#include "productdata.h"
#include "ui_goods.h"

class IDataLayer;

// class for saving good or service data with GUI
class Product : public QDialog, public Ui::Goods {

  Q_OBJECT

public:
  Product(QWidget *parent, int mode, IDataLayer *dl);
  void selectData(QString idx, int type); // called from MainWindow
  const QString getRetGoods();

public slots:

  void okClick();

private:
  IDataLayer *dataLayer;
  QString ret;
  QStringList net;
  int workMode; // Working mode - 0 = new; 1 = edit

  void init();
  void getData(ProductData prodData);
  void setData(ProductData &prodData);
  bool updateData();
  bool insertData();
  QString isEmpty(QString in);
};
#endif
