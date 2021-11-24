#ifndef PRODUCT_H
#define PRODUCT_H

#include "qfaktury-core_global.h"

#include <QMetaType>
#include <QString>

class Product
{
public:
    Product();
    Product(int id, int vat, int lastId, const QString &ident, const QString &name, const QString &code, const QString &pkwiu, const QString &description, const QString &quality, const QString &metric, double net, double gross);

    int id() const;
    void setId(int newId);
    int vat() const;
    void setVat(int newVat);
    int lastId() const;
    void setLastId(int newLastId);
    const QString &name() const;
    void setName(const QString &newName);
    const QString &code() const;
    void setCode(const QString &newCode);
    const QString &pkwiu() const;
    void setPkwiu(const QString &newPkwiu);
    const QString &description() const;
    void setDescription(const QString &newDescription);
    double net() const;
    void setNet(double newNet);
    double gross() const;
    void setGross(double newGross);
    const QString &ident() const;
    void setIdent(const QString &newIdent);
    const QString &quality() const;
    void setQuality(const QString &newQuality);

    const QString &metric() const;
    void setMetric(const QString &newMetric);

private:
    int mId;
    int mVat;
    int mLastId;
    QString mIdent;
    QString mName;
    QString mCode;
    QString mPkwiu;
    QString mDescription;
    QString mQuality;
    QString mMetric;
    double mNet;
    double mGross;
};

Q_DECLARE_METATYPE(Product);

#endif // PRODUCT_H
