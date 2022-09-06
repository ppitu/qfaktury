#include "product_model.h"


ProductModel::ProductModel(QObject *parent) :
    QAbstractTableModel(parent),
    database_(DatabaseManager::instance()),
    products_(database_.product_dao_.products())
{

}

QModelIndex ProductModel::addProduct(const Product &product)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    Product newProduct(product);
    database_.product_dao_.addProduct(newProduct);
    products_.push_back(newProduct);
    endInsertRows();

    return index(rowIndex, 0);
}

int ProductModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return products_.size();
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

    Product product = products_.at(index.row());

    switch (role) {
    case Roles::ID_ROLE:
        return QVariant::fromValue(product);
    case Qt::DisplayRole:
        switch (index.column()) {
        case ColumnName::ID: return product.getId();
        case ColumnName::IDENT: return product.getIdent();
        case ColumnName::NAME: return product.getName();
        case ColumnName::CODE: return product.getCode();
        case ColumnName::PKWIU: return product.getPkwiu();
        case ColumnName::QUALITY: return product.getQuality();
        case ColumnName::DESCRIPTION: return product.getDescription();
        case ColumnName::NET: return product.getPrice().getNet();
        case ColumnName::GROSS: return product.getPrice().getGross();
        case ColumnName::VAT: return product.getPrice().getVat();
        case ColumnName::METRIC: return product.getMetric();
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

    auto product = qvariant_cast<Product>(value);

    database_.product_dao_.updateProduct(product);
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
        const Product& product = products_.at(row + countLeft);
        database_.product_dao_.removeProduct(product.getId());
    }

    products_.erase(products_.begin() + row, products_.begin() + row + count);

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
