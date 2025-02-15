#ifndef PRODUCTDIALOG_H
#define PRODUCTDIALOG_H

#include <QDialog>

#include "Class/product.h"

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

private slots:
    void accept();
    void reject();

    void calculateGross();

private:
    Ui::ProductDialog *ui;
    Product& product_;
};

#endif //PRODUCTDIALOG_H
