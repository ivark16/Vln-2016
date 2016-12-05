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

       if (!m_db.open())
       {
          qDebug() << "Error: connection with database fail";
       }
       else
       {
          qDebug() << "Database: connection ok";
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
    QSqlQuery query("SELECT * FROM Scientists");
    int idName = query.record().indexOf("name");
    while(query.next())
    {
        QString name = query.value(idName).toString();
        qDebug() << "=====" << name;
        cout << "HaLLOOO" << endl;
    }
}





