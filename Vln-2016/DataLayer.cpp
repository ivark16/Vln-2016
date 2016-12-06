#include "DataLayer.h"
#include <iostream>
#include <vector>


DataLayer::DataLayer()
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
    QSqlQuery query("SELECT * FROM scientist");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");
    while(query.next())
    {
        QString firstName = query.value(idName).toString();
        QString lastName = query.value(idname1).toString();
        QString gender = query.value(idname2).toString();
        QString nationality = query.value(idname3).toString();
        QString YOB = query.value(idname4).toString();
        QString YOD = query.value(idname5).toString();
        QString YOA = query.value(idname6).toString();

        qDebug() << firstName << lastName << gender << nationality << YOB << YOD << YOA;
    }
}





