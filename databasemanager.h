#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

class DatabaseManager {
public:
    DatabaseManager(const QString &path);
    bool open();
    void close();
    QSqlDatabase getDatabase() const;

private:
    QSqlDatabase db;
    QString dbPath;
};

#endif // DATABASEMANAGER_H
