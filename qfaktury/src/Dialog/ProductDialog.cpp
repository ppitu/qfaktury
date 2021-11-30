
#include "ProductDialog.h"
#include "ui_ProductDialog.h"

#include "src/idatalayer.h"
#include "src/settings.h"
#include "src/validations.h"

#include "TypeClass/Price.h"

ProductDialog::ProductDialog(Product& product, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProductDialog),
    mProduct(product)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &ProductDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &ProductDialog::reject);
    connect(ui->dsNet, &QDoubleSpinBox::editingFinished, this, &ProductDialog::calculateGross);
    connect(ui->cbVat, &QComboBox::currentIndexChanged, this, &ProductDialog::calculateGross);

    ui->elIdent->setText(mProduct.ident());
    ui->elName->setText(mProduct.name());
    ui->elCode->setText(mProduct.code());
    ui->elDescription->setText(mProduct.description());
    ui->elMetric->setText(mProduct.metric());
    ui->elQuality->setText(mProduct.quality());
    ui->elPKWIU->setText(mProduct.pkwiu());
    ui->dsNet->setValue(mProduct.price().getNet());
    ui->dsGross->setValue(mProduct.price().getGross());
}

ProductDialog::~ProductDialog()
{
    delete ui;
}

void ProductDialog::accept()
{
    mProduct.setIdent(ui->elIdent->text());
    mProduct.setName(ui->elName->text());
    mProduct.setCode(ui->elCode->text());
    mProduct.setDescription(ui->elDescription->text());
    mProduct.setPkwiu(ui->elPKWIU->text());
    Price price(ui->dsNet->value(), ui->cbVat->currentText().toInt());
    mProduct.setPrice(price);
    mProduct.setMetric(ui->elMetric->text());
    mProduct.setQuality(ui->elQuality->text());

    QDialog::accept();
}

void ProductDialog::reject()
{
    QDialog::reject();
}

void ProductDialog::calculateGross()
{
    price.changeNet(ui->dsNet->value());
    price.chbageVat(ui->cbVat->currentText().toInt());
    ui->dsGross->setValue(price.getGross());
    qDebug() << "Dziala: " << price.getGross();
}
