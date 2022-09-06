#include "database_manager.h"

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

void DatabaseManager::debugQuery(const QSqlQuery &query)
{
  if(query.lastError().type() == QSqlError::ErrorType::NoError) {
    qDebug() << "Query Ok: " << query.lastQuery();
  } else {
    qWarning() << "Query KO: " << query.lastError().type();
    qWarning() << "Query text: " << query.lastQuery();
  }
}

DatabaseManager &DatabaseManager::instance()
{

  static DatabaseManager singleton;
  return singleton;
}

DatabaseManager::~DatabaseManager()
{

  database_.close();
}

DatabaseManager::DatabaseManager(const QString &path) :
                                                        database_(QSqlDatabase::addDatabase("QSQLITE")),
                                                        product_dao_(database_)
{

  database_.setDatabaseName(path);
  bool openStatus = database_.open();

  qDebug() << "Database connection: " << (openStatus ? "OK" : "Error");

  product_dao_.init();
}
