#include "ProductModel.h"


ProductModel::ProductModel(QObject *parent) :
    QAbstractTableModel(parent),
    mDb(DatabaseManager::instance()),
    mProducts(mDb.mProductDao.products())
{

}

QModelIndex ProductModel::addProduct(const Product &product)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    std::unique_ptr<Product> newProduct(new Product(product));
    mDb.mProductDao.addProduct(*newProduct);
    mProducts->push_back(std::move(newProduct));
    endInsertRows();

    return index(rowIndex, 0);
}

int ProductModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mProducts->size();
}

int ProductModel::columnCount(const QModelIndex &parent) const
{
    return 11;
}

QVariant ProductModel::data(const QModelIndex &index, int role) const
{
    if(!isIndexValid(index))
    {
        return {};
    }

    Product& product = *mProducts->at(index.row());

    switch (role) {
    case Roles::ID_ROLE:
        return QVariant::fromValue(product);
    case Qt::DisplayRole:
        switch (index.column()) {
        case ColumnName::ID: return product.id();
        case ColumnName::IDENT: return product.ident();
        case ColumnName::NAME: return product.name();
        case ColumnName::CODE: return product.code();
        case ColumnName::PKWIU: return product.pkwiu();
        case ColumnName::QUALITY: return product.quality();
        case ColumnName::DESCRIPTION: return product.description();
        case ColumnName::NET: return product.price().getNet();
        case ColumnName::GROSS: return product.price().getGross();
        case ColumnName::VAT: return product.price().getVat();
        case ColumnName::METRIC: return product.metric();
        }
    default:
        return {};
    }

}

bool ProductModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!isIndexValid(index) || role != Roles::ID_ROLE)
    {
        return false;
    }

    auto productTemp = qvariant_cast<Product>(value);

    Product& product = *mProducts->at(index.row());
    product.setIdent(productTemp.ident());
    product.setName(productTemp.name());
    product.setCode(productTemp.code());
    product.setPkwiu(productTemp.pkwiu());
    product.setQuality(productTemp.quality());
    product.setDescription(productTemp.description());
    product.setPrice(productTemp.price());
    product.setMetric(productTemp.metric());
    mDb.mProductDao.updateProduct(product);
    emit dataChanged(index, index);

    return true;
}

bool ProductModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(row < 0 || row >= rowCount() || count < 0 || (row + count) > rowCount())
    {
        return false;
    }

    beginRemoveRows(parent, row, row + count - 1);
    int countLeft = count;

    while (countLeft--) {
        const Product& product = *mProducts->at(row + countLeft);
        mDb.mProductDao.removeProduct(product.id());
    }

    endRemoveRows();

    return true;
}

QHash<int, QByteArray> ProductModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::ID_ROLE] = "id";
    return roles;
}

bool ProductModel::isIndexValid(const QModelIndex &index) const
{
    return index.isValid() && index.row() < rowCount();
}
