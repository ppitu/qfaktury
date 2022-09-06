#ifndef PRODUCT_H
#define PRODUCT_H

#include "qfaktury-core_global.h"

#include <QMetaType>
#include <QString>

#include "TypeClass/Price.h"

class Product
{
public:
    Product();
    Product(int id, int lastId, const QString &ident, const QString &name, const QString &code, const QString &pkwiu, const QString &description, const QString &quality, const QString &metric, const Price& price);

    int getId() const;
    void setId(int newId);
    int getLastId() const;
    void setLastId(int newLastId);
    const QString &getName() const;
    const QString &getCode() const;
    const QString &getPkwiu() const;
    const QString &getDescription() const;
    const QString &getIdent() const;
    const QString &getQuality() const;
    const QString &getMetric() const;
    const Price &getPrice() const;

private:
    int id_;
    int lastId_;
    QString ident_;
    QString name_;
    QString code_;
    QString pkwiu_;
    QString description_;
    QString quality_;
    QString metric_;
    Price price_;
};

Q_DECLARE_METATYPE(Product);

#endif // PRODUCT_H
