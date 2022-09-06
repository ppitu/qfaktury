#include "product_dao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "Database/database_manager.h"

#include "Class/product.h"

ProductDao::ProductDao(QSqlDatabase& database) :
                                                 database_(database)
{

}

void ProductDao::init() const
{
  if(!database_.tables().contains("product"))
  {
    QSqlQuery query(database_);
    query.exec("CREATE TABLE product (id INTEGER PRIMARY KEY AUTOINCREMENT, ident VARCHAR(50) NOT NULL UNIQUE, name VARCHAR(50), code VARCHAR(20), pkwiu VARCHAR(20),"
        "quality VARCHAR(30), description VARCHAR(100), net REAL, gross REAL, vat INTEGER, metric VARCHAR(30))");
  }
}

void ProductDao::addProduct(Product &product) const
{
  QSqlQuery query(database_);
  query.prepare("INSERT INTO product (ident, name, code, pkwiu, quality, description, net, gross, vat, metric) VALUES"
      "(:ident, :name, :code, :pkwiu, :quality, :description, :net, :gross, :vat, :metric)");
  query.bindValue(":ident", product.getIdent());
  query.bindValue(":name", product.getName());
  query.bindValue(":code", product.getCode());
  query.bindValue(":pkwiu", product.getPkwiu());
  query.bindValue(":quality", product.getQuality());
  query.bindValue(":description", product.getDescription());
  query.bindValue(":net", product.getPrice().getNet());
  query.bindValue(":gross", product.getPrice().getGross());
  query.bindValue(":vat", product.getPrice().getVat());
  query.bindValue(":metric", product.getMetric());
  query.exec();
  product.setId(query.lastInsertId().toInt());
  DatabaseManager::debugQuery(query);
}

void ProductDao::updateProduct(const Product &product) const
{
  QSqlQuery query(database_);
  query.prepare("UPDATE product SET ident = (:ident), name = (:name), code = (:code), pkwiu = (:pkwiu), quality = (:quality),"
      "description = (:description), net = (:net), gross = (:gross), vat = (:vat), metric = (:metric) WHERE id = (:id)");
  query.bindValue(":ident", product.getIdent());
  query.bindValue(":id", product.getId());
  query.bindValue(":name", product.getName());
  query.bindValue(":code", product.getCode());
  query.bindValue(":pkwiu", product.getPkwiu());
  query.bindValue(":quality", product.getQuality());
  query.bindValue(":description", product.getDescription());
  query.bindValue(":net", product.getPrice().getNet());
  query.bindValue(":gross", product.getPrice().getGross());
  query.bindValue(":vat", product.getPrice().getVat());
  query.bindValue(":metric", product.getMetric());
  query.exec();
  DatabaseManager::debugQuery(query);
}

void ProductDao::removeProduct(int id) const
{
  QSqlQuery query(database_);
  query.prepare("DELETE FROM product WHERE id = (:id)");
  query.bindValue(":id", id);
  query.exec();
  DatabaseManager::debugQuery(query);
}

std::vector<Product> ProductDao::products() const
{
  QSqlQuery query("SELECT * FROM product", database_);
  query.exec();
  DatabaseManager::debugQuery(query);

  std::vector<Product> products;

  while(query.next())
  {
    products.emplace_back(Product{query.value("id").toInt(), -1, query.value("ident").toString(), query.value("name").toString(),
                           query.value("code").toString(), query.value("pkwiu").toString(), query.value("description").toString()
                           , query.value("quality").toString(), query.value("metric").toString(), Price{query.value("net").toDouble(), query.value("vat").toInt()}});
  }

  return products;
}

ProductDao::~ProductDao()
{

}
