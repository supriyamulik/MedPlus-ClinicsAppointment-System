#include "databasemanager.h"

DatabaseManager::DatabaseManager(const QString &path)
    : dbPath(path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
}

bool DatabaseManager::open()
{
    if (!db.open()) {
        qDebug() << "Database error:" << db.lastError().text();
        return false;
    }
    qDebug() << "✅ Connected to database!";
    return true;
}

void DatabaseManager::close()
{
    if (db.isOpen()) {
        db.close();
    }
}

QSqlDatabase DatabaseManager::getDatabase() const
{
    return db;
}
