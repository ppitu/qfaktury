
#include "ProductDialog.h"
#include "ui_ProductDialog.h"

#include "src/idatalayer.h"
#include "src/settings.h"
#include "src/validations.h"

#include "TypeClass/Price.h"

ProductDialog::ProductDialog(Product& product, QWidget *parent) :
                                                                  QDialog(parent),
                                                                  ui(new Ui::ProductDialog),
                                                                  product_(product)
{
  ui->setupUi(this);

  connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &ProductDialog::accept);
  connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &ProductDialog::reject);
  connect(ui->dsNet, &QDoubleSpinBox::editingFinished, this, &ProductDialog::calculateGross);
  connect(ui->cbVat, &QComboBox::currentIndexChanged, this, &ProductDialog::calculateGross);

  ui->elIdent->setText(product_.getIdent());
  ui->elName->setText(product_.getName());
  ui->elCode->setText(product_.getCode());
  ui->elDescription->setText(product_.getDescription());
  ui->elMetric->setText(product_.getMetric());
  ui->elQuality->setText(product_.getQuality());
  ui->elPKWIU->setText(product_.getPkwiu());
  ui->dsNet->setValue(product_.getPrice().getNet());
  ui->dsGross->setValue(product_.getPrice().getGross());
}

ProductDialog::~ProductDialog()
{
  delete ui;
}

void ProductDialog::accept()
{
  Product product(product_.getId(), product_.getLastId(), ui->elIdent->text(), ui->elName->text(), ui->elCode->text(), ui->elPKWIU->text(),
                  ui->elDescription->text(), ui->elQuality->text(), ui->elMetric->text(), {ui->dsNet->value(), ui->cbVat->currentText().toInt()});

  product_ = product;

  QDialog::accept();
}

void ProductDialog::reject()
{
  QDialog::reject();
}

void ProductDialog::calculateGross()
{
  Price price(ui->dsNet->value(), ui->cbVat->currentText().toInt());
  ui->dsGross->setValue(price.getGross());
  qDebug() << "Dziala: " << price.getGross();
}
