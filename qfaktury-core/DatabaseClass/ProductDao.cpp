#include "ProductDao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "Database/DatabaseManager.h"

#include "Class/Product.h"

ProductDao::ProductDao(QSqlDatabase& database) :
    mDatabase(database)
{

}

void ProductDao::init() const
{
    if(!mDatabase.tables().contains("product"))
    {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE product (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(50), code VARCHAR(20), pkwiu VARCHAR(20),"
                   "currency VARCHAR(20), description VARCHAR(100), quantity REAL, discount REAL, price REAL, net REAL, gross REAL)");
    }
}

void ProductDao::addProduct(Product &product) const
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO product (name, code, pkwiu, currency, description, quantity, discount, price, net, gross) VALUES"
                  "(:name, :code, :pkwiu, :currency, :description, :quantity, :discount, :price, :net, :gross)");
    query.bindValue(":name", product.name());
    query.bindValue(":code", product.code());
    query.bindValue(":pkwiu", product.pkwiu());
    query.bindValue(":currency", product.currency());
    query.bindValue(":description", product.description());
    query.bindValue(":quantity", product.quantity());
    query.bindValue(":discount", product.discount());
    query.bindValue(":price", product.price());
    query.bindValue(":net", product.net());
    query.bindValue(":gross", product.gross());
    query.exec();
    product.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
}

void ProductDao::updateProduct(const Product &product) const
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE product SET name = (:name), code = (:code), pkwiu = (:pkwiu), currency = (:currency),"
                  "description = (:description), quantity = (:quantity), discount = (:discount), price = (:price),"
                  "net = (:net), gross = (:gross) WHERE id = (:id)");
    query.bindValue(":id", product.id());
    query.bindValue(":name", product.name());
    query.bindValue(":code", product.code());
    query.bindValue(":pkwiu", product.pkwiu());
    query.bindValue(":currency", product.currency());
    query.bindValue(":description", product.description());
    query.bindValue(":quantity", product.quantity());
    query.bindValue(":discount", product.discount());
    query.bindValue(":price", product.price());
    query.bindValue(":net", product.net());
    query.bindValue(":gross", product.gross());
    query.exec();
    DatabaseManager::debugQuery(query);
}

void ProductDao::removeProduct(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM person WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    DatabaseManager::debugQuery(query);
}

std::unique_ptr<std::vector<std::unique_ptr<Product> > > ProductDao::products() const
{
    QSqlQuery query("SELECT * FROM product", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);

    std::unique_ptr<std::vector<std::unique_ptr<Product>>> list (new std::vector<std::unique_ptr<Product>>());

    while(query.next())
    {
        std::unique_ptr<Product> product(new Product());
        product->setId(query.value("id").toInt());
        product->setName(query.value("name").toString());
        product->setCode(query.value("code").toString());
        product->setPkwiu(query.value("pkwiu").toString());
        product->setCurrency(query.value("description").toString());
        product->setDescription(query.value("description").toString());
        product->setQuantity(query.value("quantity").toDouble());
        product->setDiscount(query.value("discount").toDouble());
        product->setPrice(query.value("price").toDouble());
        product->setNet(query.value("net").toDouble());
        product->setGross(query.value("gross").toDouble());
        list->push_back(std::move(product));
    }

    return list;
}
