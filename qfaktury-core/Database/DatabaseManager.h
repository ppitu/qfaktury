#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <memory>

#include "DatabaseClass/ProductDao.h"

class QSqlDatabase;
class QSqlQuery;

const QString DATABASE_NAME = "qfaktury.db";

class DatabaseManager
{
public:
    static void debugQuery(const QSqlQuery& query);

    static DatabaseManager& instance();
    ~DatabaseManager();

protected:
    DatabaseManager(const QString& path = DATABASE_NAME);

private:
    std::unique_ptr<QSqlDatabase> mDatabase;

public:
    const ProductDao mProductDao;
};

#endif // DATABASEMANAGER_H
