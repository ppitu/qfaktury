#ifndef PRODUCTDIALOG_H
#define PRODUCTDIALOG_H

#include <QDialog>

#include "Class/Product.h"

// TODO
// Dodać walidacje to pól

namespace Ui {
    class ProductDialog;
}

class ProductDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ProductDialog(Product& product, QWidget *parent = nullptr);
    ~ProductDialog();
    //void selectData(QString idx, int type); // called from MainWindow
    //const QString getRetGoods();

private slots:
    void accept();
    void reject();

    //void okClick();

private:
    Ui::ProductDialog *ui;
    Product& mProduct;
    /*IDataLayer *dataLayer;
  QString ret;
  QStringList net;
  int workMode; // Working mode - 0 = new; 1 = edit

  void init();
  void getData(ProductData prodData);
  void setData(ProductData &prodData);
  bool updateData();
  bool insertData();
  QString isEmpty(QString in);*/
};

#endif //PRODUCTDIALOG_H
