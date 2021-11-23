#include "Product.h"

Product::Product() :
    mVat(0),
    mLastId(0),
    mName(""),
    mCode(""),
    mPkwiu(""),
    mCurrency(""),
    mDescription(""),
    mType(""),
    mQuantity(0),
    mDiscount(0),
    mPrice(0),
    mNet(0),
    mGross(0)
{

}

int Product::id() const
{
    return mId;
}

void Product::setId(int newId)
{
    mId = newId;
}

int Product::vat() const
{
    return mVat;
}

void Product::setVat(int newVat)
{
    mVat = newVat;
}

int Product::lastId() const
{
    return mLastId;
}

void Product::setLastId(int newLastId)
{
    mLastId = newLastId;
}

const QString &Product::name() const
{
    return mName;
}

void Product::setName(const QString &newName)
{
    mName = newName;
}

const QString &Product::code() const
{
    return mCode;
}

void Product::setCode(const QString &newCode)
{
    mCode = newCode;
}

const QString &Product::pkwiu() const
{
    return mPkwiu;
}

void Product::setPkwiu(const QString &newPkwiu)
{
    mPkwiu = newPkwiu;
}

const QString &Product::currency() const
{
    return mCurrency;
}

void Product::setCurrency(const QString &newCurrency)
{
    mCurrency = newCurrency;
}

const QString &Product::description() const
{
    return mDescription;
}

void Product::setDescription(const QString &newDescription)
{
    mDescription = newDescription;
}

const QString &Product::type() const
{
    return mType;
}

void Product::setType(const QString &newType)
{
    mType = newType;
}

double Product::quantity() const
{
    return mQuantity;
}

void Product::setQuantity(double newQuantity)
{
    mQuantity = newQuantity;
}

double Product::discount() const
{
    return mDiscount;
}

void Product::setDiscount(double newDiscount)
{
    mDiscount = newDiscount;
}

double Product::price() const
{
    return mPrice;
}

void Product::setPrice(double newPrice)
{
    mPrice = newPrice;
}

double Product::net() const
{
    return mNet;
}

void Product::setNet(double newNet)
{
    mNet = newNet;
}

double Product::gross() const
{
    return mGross;
}

void Product::setGross(double newGross)
{
    mGross = newGross;
}

Product::Product(int id, int vat, int lastId, const QString &name, const QString &code, const QString &pkwiu, const QString &currency, const QString &description, const QString &type, double quantity, double discount, double price, double net, double gross) : mId(id),
    mVat(vat),
    mLastId(lastId),
    mName(name),
    mCode(code),
    mPkwiu(pkwiu),
    mCurrency(currency),
    mDescription(description),
    mType(type),
    mQuantity(quantity),
    mDiscount(discount),
    mPrice(price),
    mNet(net),
    mGross(gross)
{}
