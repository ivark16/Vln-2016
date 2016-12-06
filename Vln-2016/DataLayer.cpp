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

vector<Scientist> DataLayer::readAllFromScientistsDataBase()
{

    Scientist s;
    vector<Scientist> returnScientist;
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
        string firstName = query.value(idName).toString().toStdString();
        string lastName = query.value(idname1).toString().toStdString();
        char sex = query.value(idname2).toString().toStdString()[0];
        string nationality = query.value(idname3).toString().toStdString();
        int birthYear = query.value(idname4).toInt();
        int deathYear = query.value(idname5).toInt();
        int awardYear = query.value(idname6).toInt();
        Scientist s(firstName, lastName, nationality, sex, birthYear, deathYear, awardYear);
        cout << s.getFirstName();
        _scientists.push_back(s);
    }
    return _scientists;
}

vector<Computer> DataLayer::readAllFromDataComputerBase()
{
    Computer s;
    QSqlQuery query("SELECT * FROM computer");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");

    while(query.next())
    {
        string name = query.value(idName).toString().toStdString();
        string type = query.value(idName1).toString().toStdString();
        int yearbuilt = query.value(idName2).toInt();
        bool wasbuilt = query.value(idName3).toBool();
        Computer s(name, type, yearbuilt, wasbuilt);
        _computer.push_back(s);
    }
    return _computer;
}

vector<searching> DataLayer::readAllDataFromSearchingDatabse()
{
    searching s;
    QSqlQuery query("SELECT scientist.firstname, scientist.lastname, computer.name, computer.yearbuilt FROM Connect "
                    "JOIN computer ON Connect.Computer_ID =  computer.IDJOIN scientist ON Connect.scientist_ID = scientist.ID;");
    int idName = query.record().indexOf("firstname");
    int idName2 = query.record().indexOf("lastname");
    int idName3 = query.record().indexOf("name");
    int idName4 = query.record().indexOf("yearbuilt");
    while(query.next())
    {
        string firstname = query.value(idName).toString().toStdString();
        string lastname = query.value(idName2).toString().toStdString();
        string compname = query.value(idName3).toString().toStdString();
        int yearbuilt = query.value(idName4).toInt();
        searching s(firstname, lastname, compname, yearbuilt);
        _searching.push_back(s);

    }
    cout << "helloo" << endl;
    return _searching;
}

void DataLayer::searchForNameFromDatabase(string name)
{
    vector<Scientist> scientists;
    QSqlQuery query;
    QString qName = QString::fromStdString(name);
    query.prepare("SELECT * FROM scientist WHERE firstname= (:x) OR lastname = (:y)");
    query.addBindValue(qName);
    query.addBindValue(qName);
    query.exec();
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");
    while(query.next())
    {
        string firstName = query.value(idName).toString().toStdString();
        string lastName = query.value(idname1).toString().toStdString();
        char sex = query.value(idname2).toString().toStdString()[0];
        string nationality = query.value(idname3).toString().toStdString();
        int birthYear = query.value(idname4).toInt();
        int deathYear = query.value(idname5).toInt();
        int awardYear = query.value(idname6).toInt();
        cout << firstName;
        Scientist s(firstName, lastName, nationality, sex, birthYear, deathYear, awardYear);
        scientists.push_back(s);

        _scientists = scientists;
    }
}

