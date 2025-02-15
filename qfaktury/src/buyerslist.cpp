
#include "buyerslist.h"
#include "settings.h"

#include <QTextStream>

/** Constructor
 */
BuyersList::BuyersList(QWidget *parent) : QDialog(parent) {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  setupUi(this);
  init();
}

/** Init
 */

void BuyersList::init() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  companiesList.clear();
  officesList.clear();
  personsList.clear();

  // read data
  readBuyer();

  // load data
  QString customer;
  listBox1->clear();

  foreach (customer, companiesList)
    listBox1->addItem(customer.split("|")[0]);

  // connects
  connect(okBtn, SIGNAL(clicked()), this, SLOT(doAccept()));
  connect(cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
  connect(comboBox1, SIGNAL(activated(int)), this, SLOT(comboBox1Changed()));
  connect(listBox1, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(doAccept()));
  connect(listBox1, &QListWidget::itemSelectionChanged,
          [this]() { updateDetails(listBox1->currentItem()); });
  connect(listBox1, SIGNAL(itemClicked(QListWidgetItem *)), this,
          SLOT(updateDetails(QListWidgetItem *)));
}

const QString BuyersList::getRetBuyerList() {
  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;
  return ret;
}

// *************************** SLOTS START *************************************

/** Slot
 *  Connected to accept signal
 */

void BuyersList::doAccept() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  if (!listBox1->selectedItems().isEmpty()) {

    ret = detailsToString();
    accept();

  } else {

    QMessageBox::information(this, "QFaktury", QString("Wskaż kontrahenta."),
                             QMessageBox::Ok);
  }
}

/** Slot
 *  comboBox1 changed
 */

void BuyersList::comboBox1Changed() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  listBox1->clear();
  clearDetails();
  QString customer;

  switch (comboBox1->currentIndex()) {
  case 0:

    foreach (customer, companiesList)
      listBox1->addItem(customer.split("|")[0]);
    break;

  case 1:

    foreach (customer, officesList)
      listBox1->addItem(customer.split("|")[0]);
    break;

  default:

    foreach (customer, personsList)
      listBox1->addItem(customer.split("|")[0]);
    break;
  }
}

/** Slot
 *  Update details when user selected
 */

void BuyersList::updateDetails(QListWidgetItem *item) {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  QStringList custDetails = QStringList();
  QString customer = QString();

  switch (comboBox1->currentIndex()) {
  case 0:

    foreach (customer, companiesList) {
      custDetails = customer.split("|");
      if (item->text().compare(custDetails[0]) == 0) {
        displayDetails(custDetails);
      }
    }
    break;

  case 1:

    foreach (customer, officesList) {
      custDetails = customer.split("|");
      if (item->text().compare(custDetails[0]) == 0) {
        displayDetails(custDetails);
      }
    }
    break;

  default:

    foreach (customer, personsList) {
      custDetails = customer.split("|");
      if (item->text().compare(custDetails[0]) == 0) {
        displayDetails(custDetails);
      }
    }
    break;
  }
}

// *************************** SLOTS END *************************************

/** Load selected customer data
 */
void BuyersList::readBuyer() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  QDomDocument doc(sett().getCustomersDocName());
  QDomElement root;
  QDomElement office;
  QDomElement company;
  QDomElement natur_person;

  QFile file(sett().getCustomersXml());

  if (!file.open(QIODevice::ReadOnly)) {

    QFileInfo check_file(file.fileName());

    if (check_file.exists() && check_file.isFile()) {

      QFile(file.fileName())
          .setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);

    } else {

      QDir mainPath(file.fileName());

      mainPath.mkpath(file.fileName());

      readBuyer();
    }

  } else {

    QTextStream stream(&file);

    if (!doc.setContent(stream.readAll())) {

      root = doc.createElement(sett().getCustomersDocName());
      doc.appendChild(root);
      office = doc.createElement(sett().getOfficeName());
      root.appendChild(office);
      company = doc.createElement(sett().getCompanyName());
      root.appendChild(company);
      natur_person = doc.createElement(sett().getNaturalPerson());
      root.appendChild(natur_person);

      QString xml = doc.toString();

      file.close();
      file.open(QIODevice::WriteOnly);
      QTextStream ts(&file);
      /* ToDo: Uniniętw */
      //ts.setCodec(QTextCodec::codecForName(sett().getCodecName()));
      ts << xml;
      file.close();

      readBuyer();

    } else {

      root = doc.documentElement();
      office = root.firstChild().toElement();
      company = root.childNodes().at(1).toElement();
      natur_person = root.childNodes().at(2).toElement();
    }

    for (QDomNode n = company.firstChild(); !n.isNull(); n = n.nextSibling()) {

      companiesList.append(xmlDataToString(n));
    }

    for (QDomNode n = office.firstChild(); !n.isNull(); n = n.nextSibling()) {

      officesList.append(xmlDataToString(n));
    }

    for (QDomNode n = natur_person.firstChild(); !n.isNull();
         n = n.nextSibling()) {

      personsList.append(xmlDataToString(n));
    }
  }

  file.close();
}

/** Loads data one string
 */

QString BuyersList::xmlDataToString(QDomNode n) {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  QString text = QString();
  text = n.toElement().attribute("name") + "|";     // 0
  text += n.toElement().attribute("address") + "|"; // 1
  text += n.toElement().attribute("code") + " " +
          n.toElement().attribute("place") + "|";   // 2
  text += n.toElement().attribute("tic") + "|";     // 3
  text += n.toElement().attribute("bank") + "|";    // 4
  text += n.toElement().attribute("account") + "|"; // 5
  text += n.toElement().attribute("swift") + "|";   // 6
  text += n.toElement().attribute("krs") + "|";     // 7
  text += n.toElement().attribute("phone") + "|";   // 8
  text += n.toElement().attribute("fax") + "|";     // 9
  text += n.toElement().attribute("email") + "|";   // 10
  text += n.toElement().attribute("www");           // 11
  return text;
}

/** Loads data to labels
 */

void BuyersList::displayDetails(QStringList custDetails) {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  labelNameE->setText(custDetails[0]);
  labelAddressE->setText(custDetails[1]);
  labelCityE->setText(custDetails[2]);
  labelTicE->setText(custDetails[3]);
  labelAccountE->setText(custDetails[5]);
  labelPhoneE->setText(custDetails[8]);
  labelEmailE->setText(custDetails[10]);
  labelWWWE->setText("<a href=" + custDetails[11] + ">" + custDetails[11] +
                     "</a>");
  labelWWWE->setStyleSheet("color: #1E90FF");
}

/** Clear labels
 */

void BuyersList::clearDetails() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  labelNameE->setText("");
  labelAddressE->setText("");
  labelCityE->setText("");
  labelTicE->setText("");
  labelAccountE->setText("");
  labelPhoneE->setText("");
  labelEmailE->setText("");
  labelWWWE->setText("");
}

/** Labels to string
 */

QString BuyersList::detailsToString() {

  qDebug() << __FILE__ << __LINE__ << __FUNCTION__;

  QString ret = labelNameE->text();

  if (!labelAddressE->text().isEmpty())
    ret += "," + labelAddressE->text();
  else
    ret += ",-";

  if (!labelCityE->text().isEmpty())
    ret += "," + labelCityE->text();
  else
    ret += ",-";

  if (!labelTicE->text().isEmpty())
    ret += "," + QString("NIP: ") + labelTicE->text();
  else
    ret += "," + QString("NIP: ") + "-";

  if (!labelAccountE->text().isEmpty())
    ret += ", " + QString("Konto: ") + labelAccountE->text();
  else
    ret += "," + QString("Konto: ") + "-";

  if (!labelPhoneE->text().isEmpty())
    ret += ", " + QString("Tel: ") + labelPhoneE->text();
  else
    ret += "," + QString("Tel: ") + "-";

  if (!labelEmailE->text().isEmpty())
    ret += ", " + QString("Email: ") + labelEmailE->text();
  else
    ret += "," + QString("Email: ") + "-";

  if (!labelWWWE->text().isEmpty())
    ret += ", " + QString("Strona: ") + labelWWWE->text();
  else
    ret += "," + QString("Strona: ") + "-";

  return ret;
}
