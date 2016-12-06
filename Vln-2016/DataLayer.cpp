#include "DataLayer.h"
#include <iostream>
#include <vector>
//#include <sqlite3.h>
//#include <sql.h>


DataLayer::DataLayer(const QString &path)
{
    QSqlDatabase m_db;

       m_db = QSqlDatabase::addDatabase("QSQLITE");
       m_db.setDatabaseName("Scientists.sqlite");

       if (m_db.isOpen())
       {
           qDebug() << "Database: connection ok";
       }
       else
       {
           qDebug() << "Error: connection with database fail";
       }
}

DataLayer::~DataLayer()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

void DataLayer::readAllFromDataBase() const
{
    qDebug() << "Persons in Database: ";
    QSqlQuery query;
    query.exec("SELECT * FROM Scientists");
    //cout << idName;
    while(query.next())
    {
        cout << "test";
        int idName = query.value(0).toInt();
        QString name = query.value(1).toString();
        qDebug() << idName << name;
        cout << "HaLLOOO"<< endl;
    }
}





