#include "product.h"

Product::Product() :
    lastId_(0),
    name_(""),
    code_(""),
    pkwiu_(""),
    description_(""),
    ident_(""),
    quality_(""),
    metric_(""),
    price_(0, 0)
{

}

int Product::getId() const
{
    return id_;
}

void Product::setId(int newId)
{
    id_ = newId;
}

int Product::getLastId() const
{
    return lastId_;
}

void Product::setLastId(int newLastId)
{
    lastId_ = newLastId;
}

const QString &Product::getName() const
{
    return name_;
}

const QString &Product::getCode() const
{
    return code_;
}

const QString &Product::getPkwiu() const
{
    return pkwiu_;
}

const QString &Product::getDescription() const
{
    return description_;
}

const QString &Product::getIdent() const
{
    return ident_;
}

const QString &Product::getQuality() const
{
    return quality_;
}

const QString &Product::getMetric() const
{
    return metric_;
}

const Price &Product::getPrice() const
{
    return price_;
}

Product::Product(int id, int lastId, const QString &ident, const QString &name, const QString &code, const QString &pkwiu, const QString &description, const QString &quality, const QString &metric, const Price& price) :
    id_(id),
    lastId_(lastId),
    ident_(ident),
    name_(name),
    code_(code),
    pkwiu_(pkwiu),
    description_(description),
    quality_(quality),
    metric_(metric),
    price_(price)
{}
