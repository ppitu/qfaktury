#include "ProductTableView.h"
#include "ui_ProductTableView.h"

#include "Model/ProductModel.h"
#include "src/Dialog/ProductDialog.h"

ProductTableView::ProductTableView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductTableView),
    mProductModel(nullptr),
    mProductSelectionModel(nullptr)
{
    ui->setupUi(this);
}

ProductTableView::~ProductTableView()
{
    delete ui;
}

void ProductTableView::setModel(ProductModel *model)
{
    mProductModel = model;
    ui->tableProduct->setModel(mProductModel);
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
        QModelIndex createdIndex = mProductModel->addProduct(product);
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

    auto product = qvariant_cast<Product>(mProductModel->data(currentProductIndex, ProductModel::Roles::ID_ROLE));

    auto *dialog = new ProductDialog(product, this);

    auto dialogCode = dialog->exec();

    if(dialogCode == QDialog::Accepted)
    {
        mProductModel->setData(currentProductIndex, QVariant::fromValue(product), ProductModel::Roles::ID_ROLE);
    }

    delete dialog;
}

void ProductTableView::removeProduct()
{
    if(ui->tableProduct->selectionModel()->selectedIndexes().isEmpty())
    {
        return;
    }

    int row = ui->tableProduct->selectionModel()->currentIndex().row();
    mProductModel->removeRow(row);
}
