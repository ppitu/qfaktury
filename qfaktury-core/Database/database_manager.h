#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <memory>

#include <QString>

#include <QtSql/QSqlDatabase>

#include "DatabaseClass/product_dao.h"

class QSqlQuery;

const QString DATABASE_NAME = "qfaktury.db";

class DatabaseManager {
public:
  static void debugQuery(const QSqlQuery &query);

  static DatabaseManager &instance();
  ~DatabaseManager();

protected:
  DatabaseManager(const QString &path = DATABASE_NAME);

private:
  QSqlDatabase database_;

public:
  const ProductDao product_dao_;
};

#endif // DATABASEMANAGER_H
