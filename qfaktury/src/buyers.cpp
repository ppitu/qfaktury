#include "buyers.h"
#include "ui_buyers.h"
#include "idatalayer.h"
#include "validations.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMovie>
#include <QRegExp>

#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/** Constructor
 */

Buyers::Buyers(QWidget *parent, int mode, IDataLayer *dl) : QDialog(parent), ui(new Ui::Buyers) {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  workingMode = mode;
  dataLayer = dl;
  ui->setupUi(this);
  init();
}

/** init()
 */

void Buyers::init() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  allNames = dataLayer->buyersGetFirmList();

  // connects
  connect(ui->okButton, SIGNAL(clicked()), this, SLOT(okClick()));
  connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(close()));
  connect(ui->typeCombo, SIGNAL(currentIndexChanged(int)), this,
          SLOT(requiredTic(int)));
}


const QString Buyers::getRetBuyer() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;
  return ret;
}

// --------- SLOTS START --
/** Slot - ok & save
 */

void Buyers::okClick() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  QStringList list = QStringList()
                     << ui->nameEdit->text() << ui->typeCombo->currentText()
                     << ui->placeEdit->text() << ui->addressEdit->text()
                     << ui->telefonEdit->text() << ui->nipEdit->text()
                     << ui->codeEdit->text() << ui->accountEdit->text()
                     << ui->emailEdit->text() << ui->wwwEdit->text();

  if (workingMode == 1) {

    if (updateData()) {

      foreach (QString listEl, list) { ret += isEmpty(listEl) + "|"; }

      accept();
    }

  } else {

    if (insertData()) {

      foreach (QString listEl, list) { ret += isEmpty(listEl) + "|"; }

      accept();
    }
  }
}

void Buyers::requiredTic(int type) {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  if (type == 2)
    ui->textLabel2_2->setText(QString("NIP:"));
  else
    ui->textLabel2_2->setText(QString("NIP*:"));

  this->update();
}

// --------- SLOTS END --

//***** DATA access START ****
// load data modification mode

void Buyers::selectData(QString name, int type) {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  setWindowTitle(QString("Edytuj kontrahenta"));
  getData(dataLayer->buyersSelectData(name, type));
  ui->typeCombo->setCurrentIndex(type);
  ui->typeCombo->setEnabled(false);

  if (ui->typeCombo->currentIndex() == 2) {
    ui->textLabel2_2->setText(QString("NIP:"));
  } else {
    ui->textLabel2_2->setText(QString("NIP*:"));
  }

  this->update();
}

// new customer insert data
bool Buyers::insertData() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  bool result = false;
  BuyerData buyerData;

  if ((sett().value("validation").toBool() && validate()) ||
      sett().value("validation").toBool() == false) {

    setData(buyerData);
    result = dataLayer->buyersInsertData(buyerData, ui->typeCombo->currentIndex());
  }

  return result;
}

// update existing
bool Buyers::updateData() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  bool result = false;
  BuyerData buyerData;

  if ((sett().value("validation").toBool() && validateUpdated()) ||
      sett().value("validation").toBool() == false) {

    setData(buyerData);

    result = dataLayer->buyersUpdateData(buyerData, ui->typeCombo->currentIndex(),
                                         ui->nameEdit->text());
  }

  if (ui->typeCombo->currentIndex() == 2) {
    ui->textLabel2_2->setText(QString("NIP:"));
  } else {
    ui->textLabel2_2->setText(QString("NIP*:"));
  }

  this->update();

  return result;
}
//***** DATA access END ****

//********************** VALIDATION START ************************

/** Validate form
 *  Don't save when no
 *  "name", "city", "street", "tic"
 */

/** validate()
 */

bool Buyers::validate() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  if (Validations::instance()->isEmptyField(ui->nameEdit->text(),
                                            ui->textLabel1->text()))
    return false;
  if (Validations::instance()->isEmptyField(ui->placeEdit->text(),
                                            ui->textLabel3->text()))
    return false;

  if (!Validations::instance()->isEmptyField(ui->codeEdit->text(),
                                             ui->textLabel4->text())) {
    if (!Validations::instance()->validateZip(ui->codeEdit->text()))
      return false;
  } else {
    return false;
  }

  if (Validations::instance()->isEmptyField(ui->addressEdit->text(),
                                            ui->textLabel2->text()))
    return false;

  if (ui->typeCombo->currentIndex() == 2) {

    ui->textLabel2_2->setText(QString("NIP:"));
    this->update();

    if (!ui->nipEdit->text().isEmpty()) {

      if (!Validations::instance()->validateNIP(ui->nipEdit->text()))
        return false;
      if (!Validations::instance()->checkSumNIP(ui->nipEdit->text()))
        return false;
    }

  } else {

    ui->textLabel2_2->setText(QString("NIP*:"));
    this->update();

    if (!Validations::instance()->isEmptyField(ui->nipEdit->text(),
                                               ui->textLabel2_2->text())) {

      if (!Validations::instance()->validateNIP(ui->nipEdit->text()))
        return false;
      if (!Validations::instance()->checkSumNIP(ui->nipEdit->text()))
        return false;

    } else {

      return false;
    }
  }

  if (!ui->accountEdit->text().isEmpty()) {
    if (!Validations::instance()->validateAccount(ui->accountEdit->text()))
      return false;
    if (!Validations::instance()->checkSumAccount(ui->accountEdit->text()))
      return false;
  }

  if (!ui->telefonEdit->text().isEmpty()) {
    if (!Validations::instance()->validateTel(ui->telefonEdit->text()))
      return false;
  }

  if (!ui->emailEdit->text().isEmpty()) {
    if (!Validations::instance()->validateEmail(ui->emailEdit->text()))
      return false;
  }

  if (!ui->wwwEdit->text().isEmpty()) {
    if (!Validations::instance()->validateWebsite(ui->wwwEdit->text()))
      return false;
  }

  if (allNames.indexOf(QRegExp(ui->nameEdit->text(), Qt::CaseSensitive,
                               QRegExp::FixedString).cap()) != -1) {
    QMessageBox::critical(0, "QFaktury",
                          QString("Kontrahent nie moze zostać dodany, ponieważ "
                                 "istnieje już kontrahent o tej nazwie."));
    return false;
  }

  return true;
}

bool Buyers::validateUpdated() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  if (Validations::instance()->isEmptyField(ui->nameEdit->text(),
                                            ui->textLabel1->text()))
    return false;
  if (Validations::instance()->isEmptyField(ui->placeEdit->text(),
                                            ui->textLabel3->text()))
    return false;

  if (!Validations::instance()->isEmptyField(ui->codeEdit->text(),
                                             ui->textLabel4->text())) {
    if (!Validations::instance()->validateZip(ui->codeEdit->text()))
      return false;
  } else {
    return false;
  }

  if (Validations::instance()->isEmptyField(ui->addressEdit->text(),
                                            ui->textLabel2->text()))
    return false;

  if (!Validations::instance()->isEmptyField(ui->nipEdit->text(),
                                             ui->textLabel2_2->text())) {
    if (!Validations::instance()->validateNIP(ui->nipEdit->text()))
      return false;
    if (!Validations::instance()->checkSumNIP(ui->nipEdit->text()))
      return false;
  } else {
    return false;
  }

  if (!ui->accountEdit->text().isEmpty()) {
    if (!Validations::instance()->validateAccount(ui->accountEdit->text()))
      return false;
    if (!Validations::instance()->checkSumAccount(ui->accountEdit->text()))
      return false;
  }

  if (!ui->telefonEdit->text().isEmpty()) {
    if (!Validations::instance()->validateTel(ui->telefonEdit->text()))
      return false;
  }

  if (!ui->emailEdit->text().isEmpty()) {
    if (!Validations::instance()->validateEmail(ui->emailEdit->text()))
      return false;
  }

  if (!ui->wwwEdit->text().isEmpty()) {
    if (!Validations::instance()->validateWebsite(ui->wwwEdit->text()))
      return false;
  }

  return true;
}

//********************** VALIDATION  END ************************

//********************** DATA METHODS START *********************
/** Loads data from labels into Data object
 */

void Buyers::setData(BuyerData &buyerData) {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  buyerData.name = ui->nameEdit->text();
  buyerData.place = ui->placeEdit->text();
  buyerData.code = ui->codeEdit->text();
  buyerData.address = ui->addressEdit->text();
  buyerData.tic = ui->nipEdit->text();
  buyerData.account = ui->accountEdit->text();
  buyerData.phone = ui->telefonEdit->text();
  buyerData.email = ui->emailEdit->text();
  buyerData.www = ui->wwwEdit->text();
}

/** Load details
 */

void Buyers::getData(BuyerData buyerData) {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  ui->nameEdit->setText(buyerData.name);
  ui->placeEdit->setText(buyerData.place);
  ui->codeEdit->setText(buyerData.code);
  ui->addressEdit->setText(buyerData.address);
  ui->nipEdit->setText(buyerData.tic);
  ui->accountEdit->setText(buyerData.account);
  ui->telefonEdit->setText(buyerData.phone);
  ui->emailEdit->setText(buyerData.email);
  ui->wwwEdit->setText(buyerData.www);
}

// executes shell script for preparation before connection to GUS
bool Buyers::checkGusPath() {
  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  const char *homedir;

  if ((homedir = getenv("HOME")) == NULL) {
    homedir = getpwuid(getuid())->pw_dir;
  }

  const char *addGusPath1 =
      "sh /usr/share/qfaktury/src/GusApi/php-dependencies.sh \"";
  const char *br = "\"";

  char *RutaFinal1 =
      new char[strlen(addGusPath1) + strlen(homedir) + strlen(br) + 1];
  strcpy(RutaFinal1, addGusPath1);
  strcat(RutaFinal1, homedir);
  strcat(RutaFinal1, br);

  if (system(RutaFinal1) == 0)
    return true;

  return false;
}

// connects to GUS data thanks to PHP scripts, that saves result into json file
bool Buyers::connectGUS() {
  if (QFile(sett().getGUSDir() + "/result.json").exists())
    QFile::resize(sett().getGUSDir() + "/result.json", 0);

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  const char *firstPart =
      "php -f /usr/share/qfaktury/src/GusApi/getFromNip.php ";
  const char *secondPart =
      ui->nipEdit->text().remove(QChar('-')).toStdString().c_str();

  char *RutaFinal = new char[strlen(firstPart) + strlen(secondPart) + 1];
  strcpy(RutaFinal, firstPart);
  strcat(RutaFinal, secondPart);

  if (system(RutaFinal) == 0)
    return true;

  return false;
}

// container function for various raport types from GUS
void Buyers::RaportTypesContainer(QStringList &listJsonNodes,
                                  QJsonObject &item) {

  qDebug() << QString("QJsonObject[dane] of value ") << listJsonNodes.at(0)
           << QString(": ") << item[listJsonNodes.at(0)];
  QJsonValue name = item[listJsonNodes.at(0)];
  QString reformed = QString();

  Q_FOREACH (QString ref, name.toString().toLower().split(" ")) {
    if (ref.length() > 1) {
      ref[0] = ref.at(0).toTitleCase();
      reformed += " " + ref;
    } else
      reformed += " " + ref;
  }

  ui->nameEdit->setText(reformed.trimmed());

  /* in case of array get array and convert into string*/
  qDebug() << QString("QJsonObject[dane] of value ") << listJsonNodes.at(1)
           << QString(": ") << item[listJsonNodes.at(1)];
  QJsonValue city = item[listJsonNodes.at(1)];
  ui->placeEdit->setText(city.toString().trimmed());

  qDebug() << QString("QJsonObject[dane] of value ") << listJsonNodes.at(2)
           << QString(" and ") << listJsonNodes.at(3) << QString(": ")
           << item[listJsonNodes.at(2)];
  QJsonValue address = item[listJsonNodes.at(2)];
  QJsonValue companyNumber = item[listJsonNodes.at(3)];
  ui->addressEdit->setText(address.toString().trimmed() + " " +
                       companyNumber.toString().trimmed());

  qDebug() << QString("QJsonObject[dane] of value ") << listJsonNodes.at(4)
           << QString(": ") << item[listJsonNodes.at(4)];
  QJsonValue postalCode = item[listJsonNodes.at(4)];
  ui->codeEdit->setText(postalCode.toString().insert(2, '-').trimmed());

  qDebug() << QString("QJsonObject[dane] of value ") << listJsonNodes.at(5)
           << QString(": ") << item[listJsonNodes.at(5)];
  QJsonValue tel = item[listJsonNodes.at(5)];
  ui->telefonEdit->setText("+48" + tel.toString().trimmed());

  qDebug() << QString("QJsonObject[dane] of value ") << listJsonNodes.at(6)
           << QString(": ") << item[listJsonNodes.at(6)];
  QJsonValue email = item[listJsonNodes.at(6)];
  ui->emailEdit->setText(email.toString().toLower().trimmed());

  qDebug() << QString("QJsonObject[dane] of value ") << listJsonNodes.at(7)
           << QString(": ") << item[listJsonNodes.at(7)];
  QJsonValue site = item[listJsonNodes.at(7)];
  ui->wwwEdit->setText(site.toString().toLower().trimmed());
}

// sets data into QLineEdits from JSON file, which has informations about last
// buyer taken from GUS
void Buyers::setDataFromGUS() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  QFile file;
  file.setFileName(QDir::homePath() +
                   "/.local/share/data/elinux/gus/result.json");
  file.open(QIODevice::ReadOnly | QIODevice::Text);
  QString val = file.readAll();
  file.close();

  QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
  QJsonObject sett2 = d.object();
  QJsonValue value = sett2.value(QString("dane"));
  QJsonObject item = value.toObject();

  QStringList depNodes = QStringList() << "praw_nazwa"
                                       << "praw_adSiedzMiejscowosc_Nazwa"
                                       << "praw_adSiedzUlica_Nazwa"
                                       << "praw_adSiedzNumerNieruchomosci"
                                       << "praw_adSiedzKodPocztowy"
                                       << "praw_numerTelefonu"
                                       << "praw_adresEmail"
                                       << "praw_adresStronyinternetowej";

  QStringList persNodes = QStringList() << "fiz_nazwa"
                                        << "fiz_adSiedzMiejscowosc_Nazwa"
                                        << "fiz_adSiedzUlica_Nazwa"
                                        << "fiz_adSiedzNumerNieruchomosci"
                                        << "fiz_adSiedzKodPocztowy"
                                        << "fiz_numerTelefonu"
                                        << "fiz_adresEmail"
                                        << "fiz_adresStronyinternetowej";

  if (item["praw_nazwa"].isString()) {

    RaportTypesContainer(depNodes, item);

  } else if (item["fiz_nazwa"].isString()) {

    RaportTypesContainer(persNodes, item);

  } else {

    QMessageBox::warning(this, "Informacje z GUS",
                         "Nie było możliwe pobranie danych z Głównego Urzędu "
                         "Statystycznego. Sprawdź, czy podany numer NIP jest "
                         "poprawny.");
  }
}

// creates file in json format for php composer, because copying from app path
// changes permission of place to root
void Buyers::createComposerJson(QString path, QString filename) {

  QJsonObject recordObject;
  recordObject.insert("name", QJsonValue::fromVariant("gusapi/gusapi"));
  recordObject.insert("description",
                      QJsonValue::fromVariant("Gus Api Library for PHP"));
  recordObject.insert("type", QJsonValue::fromVariant("library"));
  recordObject.insert("license", QJsonValue::fromVariant("LGPL-2.1"));

  QJsonArray keywordsArray;
  keywordsArray.push_back("nip");
  keywordsArray.push_back("regon");
  keywordsArray.push_back("krs");
  keywordsArray.push_back("api");
  keywordsArray.push_back("soap");
  keywordsArray.push_back("library");
  keywordsArray.push_back("GUS");
  keywordsArray.push_back("CEGID");
  recordObject.insert("keywords", keywordsArray);

  QJsonArray authorsArray;
  QJsonObject recordObject2;
  recordObject2.insert("name", "Janusz Żukowicz");
  recordObject2.insert("email", "john_zuk@wp.pl");
  authorsArray.push_back(recordObject2);
  recordObject.insert("authors", authorsArray);

  QJsonObject recordObject3;
  recordObject3.insert("php", ">=5.4");
  recordObject.insert("require", recordObject3);

  QJsonObject recordObject4;
  recordObject4.insert("phpunit/phpunit", "4.6.6");
  recordObject.insert("require-dev", recordObject4);

  QJsonObject gusapi;
  gusapi.insert("GusApi\\", "/usr/share/qfaktury/src/GusApi/src/GusApi/");
  QJsonObject psr;
  psr.insert("psr-4", gusapi);

  recordObject.insert("autoload", psr);

  QJsonDocument doc(recordObject);
  //  qDebug() << doc.toJson();

  QFile composerFile(path + "/" + filename);
  composerFile.open(QFile::WriteOnly);
  composerFile.write(doc.toJson());
}

//********************** DATA METHODS END *********************

// helper method which sets "-" in input forms

QString Buyers::isEmpty(QString in) {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  if (in == "")
    return "-";
  return in;
}

// signal for connection to GUS and update data in QLineEdits
void Buyers::on_gusBtn_clicked() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  QLabel *lbl = new QLabel;
  QMovie *movie = new QMovie(lbl);
  movie->setFileName(":/res/icons/waitForResp.gif");
  lbl->setMovie(movie);
  lbl->show();
  movie->start();

  ui->gusLayout->addWidget(lbl);
  QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
  update();



  if (ui->nipEdit->text().isEmpty() || ui->nipEdit->text().isNull())
    QMessageBox::warning(
        this, "NIP",
        "Aby skorzystać z funkcji, powinieneś najpierw podać numer NIP");
  else {

    bool firstRunGUS = false;

    if (!QDir(sett().getGUSDir()).exists()) {
      QDir dir;
      dir.mkpath(sett().getGUSDir());
      firstRunGUS = true;
      QMessageBox::information(
          this, "Przygotowanie",
          "Poczekaj chwilę, aż program pobierze i "
          "przygotuje zależności dla korzystania z danych "
          "GUS po raz pierwszy. Może to potrwać do minuty");
    }

    if (!QFile(QDir::homePath() + "/.local/share/data/elinux/gus/composer.json")
             .exists()) {
      createComposerJson(sett().getGUSDir(), QString("composer.json"));
    }

    if (firstRunGUS) {
      if (QMessageBox::warning(this, "Konfiguracja PHP",
                               QString("Czy chcesz przygotować plik php.ini do "
                                      "korzystania z klienta SOAP, aby łączyć "
                                      "się z Głównym Urzędem Statystycznym? "
                                      "Jeśli tego nie zrobisz, powinieneś "
                                      "znaleźć plik php.ini, znaleźć wiersz "
                                       ";extension=soap.so i usunąć średnik. ")) == 0) {
          /* ToDo: Sprawdzić */
                               //QString("Tak"), QString("Nie"), 0, 0, 1) == 0) {

          if (DISTRO_FEDORA) system("beesu -l /usr/share/qfaktury/src/GusApi/soap-php.sh");
          else system("gksudo sh /usr/share/qfaktury/src/GusApi/soap-php.sh");
      }
    }


    if (!QDir(sett().getGUSDir() + "/vendor").exists() ||
        QDir(sett().getGUSDir() + "/vendor").isEmpty())

      if (!checkGusPath()) {
          if (DISTRO_FEDORA) {
              QMessageBox::warning(this, "I etap",
                                   "Program nie mógł przygotować się do skorzystania "
                                   "z danych Głównego Urzędu Statystycznego. "
                                   "Prawdopdobnie nie masz zainstalowanej paczki "
                                   "beesu, podałeś złe hasło autoryzacyjne lub "
                                   "odmówiłeś podania hasła dla konfiguracji PHP");
          } else {
              QMessageBox::warning(this, "I etap",
                                   "Program nie mógł przygotować się do skorzystania "
                                   "z danych Głównego Urzędu Statystycznego. "
                                   "Prawdopdobnie nie masz zainstalowanej paczki "
                                   "gksu, podałeś złe hasło autoryzacyjne lub "
                                   "odmówiłeś podania hasła dla konfiguracji PHP");
          }

      }

    if (connectGUS()) {
      setDataFromGUS();
    } else {
      QMessageBox::warning(this, "II etap",
                           "Program nie mógł pobrać danych z Głównego "
                           "Urzędu Statystycznego. Prawdopdobnie nie masz "
                           "zainstalowanej paczki php lub brakuje plików w "
                           "ścieżce /usr/share/qfaktury/src/GusApi");
    }

    movie->stop();
    movie->deleteLater();
    lbl->deleteLater();
  }

  setCursor(QCursor(Qt::ArrowCursor));
}
