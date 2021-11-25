#include "productdata.h"
#include "settings.h"

#include <QTextStream>

ProductData::ProductData()
{
    id = 0;
    name = "";
    code = "";
    pkwiu = "";
    quantity = 0;
    quanType = "";
    discount = 0;
    price = 0;
    nett = 0;
    vat = 0;
    gross = 0;
    curr = "";
    requiredAmount = 0;
    givedOutAmount = 0;
}

ProductData::ProductData(QString c1, QString c2, QString c3)
{
    code = c1;
    if (code == "")
        code = "-";
    curr = c2;
    if (curr == "")
        curr = "-";
    pkwiu = c3;
    if (pkwiu == "")
        pkwiu = "-";
}

ProductData::ProductData(int inId, QString inName, QString inCode, QString inPkwiu, double inQuantity, QString inQuanType, double inDiscount, double inPrice, double inNett, int inVat, double inGross, QString inCurr, int reqAmount, int givAmount)
{
    id = inId;
    name = inName;
    code = inCode;
    pkwiu = inPkwiu;
    quantity = inQuantity;
    quanType = inQuanType;
    discount = inDiscount;
    price = inPrice;
    nett = inNett;
    vat = inVat;
    gross = inGross;
    curr = inCurr;
    requiredAmount = reqAmount;
    givedOutAmount = givAmount;
}

int ProductData::getId() const
{
    return id;
}

QString ProductData::getName() const
{
    return name;
}

QString ProductData::getCode() const
{
    return code;
}

QString ProductData::getPkwiu() const
{
    return pkwiu;
}

double ProductData::getQuantity() const
{
    return quantity;
}

QString ProductData::getQuantityType() const
{
    return quanType;
}

double ProductData::getDiscount() const
{
    return discount;
}

double ProductData::getPrice() const
{
    return price;
}

double ProductData::getNett() const
{
    return nett;
}

int ProductData::getVat() const
{
    return vat;
}

double ProductData::getGross() const
{
    return gross;
}

QString ProductData::getCurr() const
{
    return curr;
}

void ProductData::setId(QString inId)
{
    id = inId.toInt();
}

void ProductData::setName(QString inName)
{
    name = inName;
}

void ProductData::setCode(QString inCode)
{
    code = inCode;
}

void ProductData::setPkwiu(QString inPkwiu)
{
    pkwiu = inPkwiu;
}

void ProductData::setQuantity(QString quan)
{
    quantity = quan.toInt();
}

void ProductData::setQuanType(QString qType)
{
    quanType = qType;
}

void ProductData::setDiscount(QString disc)
{
    discount = disc.toInt();
}

void ProductData::setPrice(QString prc)
{
    price = sett().stringToDouble(prc);
}

void ProductData::setNett(QString net)
{
    nett = sett().stringToDouble(net);
}

void ProductData::setVat(QString vt)
{
    vat = vt.toInt();
}

void ProductData::setGross(QString gr)
{
    double decimalPointsGross = gr.right(2).toInt() * 0.01;
    gross = sett().stringToDouble(gr);
    gross += decimalPointsGross;
}

void ProductData::setCurr(QString cr)
{
    curr = cr;
}

void ProductData::setRequiredAmount(QString reqAmount)
{
    requiredAmount = reqAmount.toInt();
}

void ProductData::setGivedOutAmount(QString givAmount)
{
    givedOutAmount = givAmount.toInt();
}

QString ProductData::toString()
{
    QString str;
    QTextStream ret(&str);
    ret << "id: " << id << "\n"
        << "name: " << name << "\n"
        << "code: " << code << "\n"
        << "pkwiu: " << pkwiu << "\n"
        << "quantity: " << quantity << "\n"
        << "quanType: " << quanType << "\n"
        << "discount: " << discount << "\n"
        << "price: " << price << "\n"
        << "nett: " << nett << "\n"
        << "vat: " << vat << "\n"
        << "gross: " << gross << "\n"
        << "curr: " << curr << "\n"
        << "requiredAmount: " << requiredAmount << "\n"
        << "givedOutAmount: " << givedOutAmount;
    return "ProductData: [" + str + "]";
}
