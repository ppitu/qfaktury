#ifndef PRODUCT_H
#define PRODUCT_H

#include "qfaktury-core_global.h"

#include <QMetaType>
#include <QString>

class Product
{
public:
    Product();
    //Product(QString c1, QString c2, QString c3);
    Product(int id, int vat, int lastId, const QString &name, const QString &code, const QString &pkwiu, const QString &currency, const QString &description, const QString &type, double quantity, double discount, double price, double net, double gross);

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
    const QString &currency() const;
    void setCurrency(const QString &newCurrency);
    const QString &description() const;
    void setDescription(const QString &newDescription);
    const QString &type() const;
    void setType(const QString &newType);
    double quantity() const;
    void setQuantity(double newQuantity);
    double discount() const;
    void setDiscount(double newDiscount);
    double price() const;
    void setPrice(double newPrice);
    double net() const;
    void setNet(double newNet);
    double gross() const;
    void setGross(double newGross);

private:
    int mId;
    int mVat;
    int mLastId;
    QString mName;
    QString mCode;
    QString mPkwiu;
    QString mCurrency;
    QString mDescription;
    QString mType;
    double mQuantity;
    double mDiscount;
    double mPrice;
    double mNet;
    double mGross;

};

Q_DECLARE_METATYPE(Product);

#endif // PRODUCT_H
