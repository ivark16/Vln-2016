#ifndef SCIENTISLISTFROMSQL_H
#define SCIENTISLISTFROMSQL_H
#include <QtSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <vector>
#include <scientist.h>


class DataLayer
{

    vector<Scientist> _dataFromDatabase;
    QSqlDatabase m_db;
public:
    DataLayer(const QString &path);
    ~DataLayer();
    void readAllFromDataBase() const;
    vector<Scientist> searchForName(string name);

};

#endif // SCIENTISLISTFROMSQL_H
