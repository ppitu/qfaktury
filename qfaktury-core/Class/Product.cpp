#include "Product.h"

Product::Product() :
    mLastId(0),
    mName(""),
    mCode(""),
    mPkwiu(""),
    mDescription(""),
    mIdent(""),
    mQuality(""),
    mMetric(""),
    mPrice(0, 0)
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

const QString &Product::description() const
{
    return mDescription;
}

void Product::setDescription(const QString &newDescription)
{
    mDescription = newDescription;
}

const QString &Product::ident() const
{
    return mIdent;
}

void Product::setIdent(const QString &newIdent)
{
    mIdent = newIdent;
}

const QString &Product::quality() const
{
    return mQuality;
}

void Product::setQuality(const QString &newQuality)
{
    mQuality = newQuality;
}

const QString &Product::metric() const
{
    return mMetric;
}

void Product::setMetric(const QString &newMetric)
{
    mMetric = newMetric;
}

const PriceType &Product::price() const
{
    return mPrice;
}

void Product::setPrice(const PriceType &newPrice)
{
    mPrice = newPrice;
}

Product::Product(int id, int lastId, const QString &ident, const QString &name, const QString &code, const QString &pkwiu, const QString &description, const QString &quality, const QString &metric, const PriceType& price) :
    mId(id),
    mLastId(lastId),
    mIdent(ident),
    mName(name),
    mCode(code),
    mPkwiu(pkwiu),
    mDescription(description),
    mQuality(quality),
    mMetric(metric),
    mPrice(price)
{}
