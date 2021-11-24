#ifndef PRODUCTMODEL_H
#define PRODUCTMODEL_H

#include <QAbstractTableModel>
#include <QHash>
#include <vector>
#include <memory>

#include "Class/Product.h"
#include "Database/DatabaseManager.h"

#include "qfaktury-core_global.h"

class QFAKTURYCORE_EXPORT ProductModel : public QAbstractTableModel
{
    Q_OBJECT
public:

    enum Roles {
        ID_ROLE = Qt::UserRole + 1,
        IDENT_ROLE,
        NAME_ROLE,
        CODE_ROLE,
        PKWIU_ROLE,
        QUALITY_ROLE,
        DESCRIPTION_ROLE,
        NET_ROLE,
        GROSS_ROLE,
        VAT_ROLE,
        METRIC_ROLE
    };

    enum ColumnName {
        ID = 0,
        IDENT,
        NAME,
        CODE,
        PKWIU,
        QUALITY,
        DESCRIPTION,
        NET,
        GROSS,
        VAT,
        METRIC
    };

    explicit ProductModel(QObject *parent = nullptr);

    QModelIndex addProduct(const Product& product);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    bool removeRows(int row, int count, const QModelIndex &parent) override;
    QHash<int, QByteArray> roleNames() const override;

private:
    bool isIndexValid(const QModelIndex& index) const;

private:
    DatabaseManager& mDb;
    std::unique_ptr<std::vector<std::unique_ptr<Product>>> mProducts;
};

#endif // PRODUCTMODEL_H
