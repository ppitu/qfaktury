#include "ProductTableView.h"
#include "ui_ProductTableView.h"

#include "Model/product_model.h"
#include "src/Dialog/ProductDialog.h"

ProductTableView::ProductTableView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductTableView),
    productModel_(nullptr),
    productSelectionModel_(nullptr)
{
    ui->setupUi(this);
}

ProductTableView::~ProductTableView()
{
    delete ui;
}

void ProductTableView::setModel(ProductModel *model)
{
    productModel_ = model;
    ui->tableProduct->setModel(productModel_);
}

void ProductTableView::setProductSeelctionModel(QItemSelectionModel *productSelectionModel)
{

}

void ProductTableView::addProduct()
{
    Product product;

    auto* dialog = new ProductDialog(product);

    auto dialogCode = dialog->exec();

    if(dialogCode == QDialog::Accepted)
    {
        QModelIndex createdIndex = productModel_->addProduct(product);
        ui->tableProduct->setCurrentIndex(createdIndex);
    }

    delete dialog;
}

void ProductTableView::editProduct()
{
    if(ui->tableProduct->selectionModel()->selectedIndexes().isEmpty())
    {
        return;
    }

    QModelIndex currentProductIndex = ui->tableProduct->selectionModel()->selectedIndexes().first();

    auto product = qvariant_cast<Product>(productModel_->data(currentProductIndex, ProductModel::Roles::ID_ROLE));

    auto dialog =  ProductDialog(product, this);

    auto dialogCode = dialog.exec();

    qDebug() << "Product update price gross" << product.getPrice().getGross();
    qDebug() << "Product update price net" << product.getPrice().getNet();

    if(dialogCode == QDialog::Accepted)
    {
        productModel_->setData(currentProductIndex, QVariant::fromValue(product), ProductModel::Roles::ID_ROLE);
    }

}

void ProductTableView::removeProduct()
{
    if(ui->tableProduct->selectionModel()->selectedIndexes().isEmpty())
    {
        return;
    }

    int row = ui->tableProduct->selectionModel()->currentIndex().row();
    productModel_->removeRow(row);
}
