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
        returnScientist.push_back(s);
    }
    return returnScientist;
}


bool DataLayer::deleteFunction(string x)
{
    QSqlQuery myQuery;
    QString qName = QString::fromStdString(x);
    myQuery.prepare(("SELECT firstname FROM scientist WHERE firstname = (:x)"));
    myQuery.addBindValue(qName);
    if (myQuery.exec())
    {
        if (myQuery.next())
        {
            myQuery.prepare("DELETE FROM scientist WHERE firstname = (:x)");
            myQuery.addBindValue(qName);
            myQuery.exec();
            return true;
        }
    }
    else
    {
          return false;
    }
}

bool DataLayer::addFunction(string name1, string name2, char gender1, string nation, int yob, int yod, int yoa)
{
    QSqlQuery query;
    QString qName1 = QString::fromStdString(name1);
    QString qName2 = QString::fromStdString(name2);
    //QString qGender = QString::fromStdString(gender1)[0];
    QString qNat = QString::fromStdString(nation);

    query.prepare("INSERT INTO scientist (firstname, lastname, gender, nationality, YOB, YOD, YOA) VALUES (:name1, :name2, :gender1, :nation, :yob, :yod, :yoa)");
    query.addBindValue(qName1);
    query.addBindValue(qName2);
    //query.addBindValue(qGender);
    query.addBindValue(qNat);
    query.addBindValue(yob);
    query.addBindValue(yod);
    query.addBindValue(yoa);


    if (query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
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

int DataLayer::getSizeOfScientists()
{
    return _scientists.size();
}

char DataLayer::getGenderAt(int i)
{
    return _scientists[i].getGender();
}

vector<Scientist> DataLayer::readInAlphabeticalOrder()
{
    vector<Scientist> returnScientist;
    //qDebug() << "Persons in Database: ";
    QSqlQuery query("SELECT * FROM scientist s ORDER BY s.firstname, s.lastname ASC");
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
        cout << s.getFirstName() << " ";
        returnScientist.push_back(s);
    }
    return returnScientist;
}

