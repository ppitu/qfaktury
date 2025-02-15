
#include "detector.h"
#ifndef BUYERS_H
#define BUYERS_H

//#include "ui_buyers.h"

#include <QStringList>
#include <QDialog>

class IDataLayer;
class BuyerData;
class QJsonValue;

namespace Ui {
    class Buyers;
}

// class for setting your data as company with GUI
class Buyers : public QDialog/*, public Ui::Buyers*/
{

  Q_OBJECT

public:
  Buyers(QWidget *parent, int mode, IDataLayer *dl);
  void selectData(QString name,
                  int type); // 0 - company, 1 - department, 2 - natural person
  bool insertData();
  bool updateData();
  const QString getRetBuyer(); // gets variable in string format, that holds
                               // information for table rows (for example: "id |
                               // name | tic" etc)

public slots:

  void okClick();
  void requiredTic(int);

private slots:
  void on_gusBtn_clicked();

private:
  Ui::Buyers *ui;
  QStringList allNames;
  QString ret;
  IDataLayer *dataLayer;
  int workingMode; // 0 = new

  QString isEmpty(QString in);
  void init();
  void getData(BuyerData buyerData);
  void setData(BuyerData &buyerData);
  bool validate();
  bool validateUpdated();
  bool connectGUS();
  bool checkGusPath();
  void setDataFromGUS();
  void RaportTypesContainer(QStringList&, QJsonObject&);
  void createComposerJson(QString,QString);

};
#endif
