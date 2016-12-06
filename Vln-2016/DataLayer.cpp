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

vector<Scientist> DataLayer::readAllFromDataBase()
{
    vector<Scientist> returnScientist;
    Scientist s;
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
        s.firstName = query.value(idName).toString().toStdString();
        s.lastName = query.value(idname1).toString().toStdString();
        s.sex = query.value(idname2).toString().toStdString()[0];
        s.nationality = query.value(idname3).toString().toStdString();
        s.birthYear = query.value(idname4).toInt();
        s.deathYear = query.value(idname5).toInt();
        s.awardYear = query.value(idname6).toInt();

        returnScientist.push_back(s);

    }
    return returnScientist;
}
