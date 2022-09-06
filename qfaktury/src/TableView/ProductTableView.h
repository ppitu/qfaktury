#ifndef PRODUCTTABLEVIEW_H
#define PRODUCTTABLEVIEW_H

#include <QWidget>

namespace Ui {
class ProductTableView;
}

class ProductModel;
class QItemSelectionModel;

class ProductTableView : public QWidget
{
    Q_OBJECT

public:
    explicit ProductTableView(QWidget *parent = nullptr);
    ~ProductTableView();

    void setModel(ProductModel* model);
    void setProductSeelctionModel(QItemSelectionModel* productSelectionModel);

public slots:
    void addProduct();
    void editProduct();
    void removeProduct();

private:
    Ui::ProductTableView *ui;

    ProductModel* productModel_;
    QItemSelectionModel* productSelectionModel_;
};

#endif // PRODUCTTABLEVIEW_H
