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
        query.exec("CREATE TABLE product (id INTEGER PRIMARY KEY AUTOINCREMENT, ident VARCHAR(50) NOT NULL UNIQUE, name VARCHAR(50), code VARCHAR(20), pkwiu VARCHAR(20),"
                   "quality VARCHAR(30), description VARCHAR(100), net REAL, gross REAL, vat INTEGER, metric VARCHAR(30))");
    }
}

void ProductDao::addProduct(Product &product) const
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO product (ident, name, code, pkwiu, quality, description, net, gross, vat, metric) VALUES"
                  "(:ident, :name, :code, :pkwiu, :quality, :description, :net, :gross, :vat, :metric)");
    query.bindValue(":ident", product.ident());
    query.bindValue(":name", product.name());
    query.bindValue(":code", product.code());
    query.bindValue(":pkwiu", product.pkwiu());
    query.bindValue(":quality", product.quality());
    query.bindValue(":description", product.description());
    query.bindValue(":net", product.price().getNet());
    query.bindValue(":gross", product.price().getGross());
    query.bindValue(":vat", product.price().getVat());
    query.bindValue(":metric", product.metric());
    query.exec();
    product.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
}

void ProductDao::updateProduct(const Product &product) const
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE product SET ident = (:ident), name = (:name), code = (:code), pkwiu = (:pkwiu), quality = (:quality),"
                  "description = (:description), net = (:net), gross = (:gross), vat = (:vat), metric = (:metric) WHERE id = (:id)");
    query.bindValue(":ident", product.ident());
    query.bindValue(":id", product.id());
    query.bindValue(":name", product.name());
    query.bindValue(":code", product.code());
    query.bindValue(":pkwiu", product.pkwiu());
    query.bindValue(":quality", product.quality());
    query.bindValue(":description", product.description());
    query.bindValue(":net", product.price().getNet());
    query.bindValue(":gross", product.price().getGross());
    query.bindValue(":vat", product.price().getVat());
    query.bindValue(":metric", product.metric());
    query.exec();
    DatabaseManager::debugQuery(query);
}

void ProductDao::removeProduct(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM product WHERE id = (:id)");
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
        product->setIdent(query.value("ident").toString());
        product->setName(query.value("name").toString());
        product->setCode(query.value("code").toString());
        product->setPkwiu(query.value("pkwiu").toString());
        product->setQuality(query.value("quality").toString());
        product->setDescription(query.value("description").toString());
        PriceType price(query.value("net").toDouble(), query.value("vat").toInt());
        product->setPrice(price);
        product->setMetric(query.value("metric").toString());
        list->push_back(std::move(product));
    }

    return list;
}

ProductDao::~ProductDao()
{
    
}
