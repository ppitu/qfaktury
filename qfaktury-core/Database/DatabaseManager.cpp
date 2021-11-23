#include "DatabaseManager.h"

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

    mDatabase->close();
}

DatabaseManager::DatabaseManager(const QString &path) :
    mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
    mProductDao(*mDatabase)
{

    mDatabase->setDatabaseName(path);
    bool openStatus = mDatabase->open();

    qDebug() << "Database connection: " << (openStatus ? "OK" : "Error");

    mProductDao.init();
}
