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
             //qDebug() << "Error: connection with database fail";
          }
          else
          {
             //qDebug() << "Database: connection ok";
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
    QSqlQuery query("SELECT * FROM scientist");
    int idName7 = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");

    while(query.next())
    {
        int Ids = query.value(idName7).toInt();
        string firstName = query.value(idName).toString().toStdString();
        string lastName = query.value(idname1).toString().toStdString();
        char sex = query.value(idname2).toString().toStdString()[0];
        string nationality = query.value(idname3).toString().toStdString();
        int birthYear = query.value(idname4).toInt();
        int deathYear = query.value(idname5).toInt();
        int awardYear = query.value(idname6).toInt();

        Scientist s(Ids, firstName, lastName, sex, nationality,birthYear,deathYear, awardYear);
        returnScientist.push_back(s);
    }
    return returnScientist;
}

vector<Computer> DataLayer::readAllFromDataComputerBase()
{
    Computer s;
    vector<Computer> displayComputer;
    QSqlQuery query("SELECT * FROM computer");
    int idName = query.record().indexOf("ID");
    int idName1 = query.record().indexOf("name");
    int idName2 = query.record().indexOf("type");
    int idName3 = query.record().indexOf("yearBuilt");
    int idName4 = query.record().indexOf("wasbuilt");

    while(query.next())
    {
        int ids = query.value(idName).toInt();
        string name = query.value(idName1).toString().toStdString();
        string type = query.value(idName2).toString().toStdString();
        int yearbuilt = query.value(idName3).toInt();
        bool wasbuilt = query.value(idName4).toBool();

        Computer s(ids, name, type, yearbuilt, wasbuilt);
        displayComputer.push_back(s);
    }
    return displayComputer;
}

vector<searching> DataLayer::searchForScientistFromSearchingDatabse(string x)
{/*
    vector<searching> joinQueryscientist;
    QString qName = QString::fromStdString(x);
    QSqlQuery query;
    query.prepare("SELECT scientist.firstname, scientist.lastname, computer.name, computer.type, computer.yearbuilt FROM Connect JOIN computer ON Connect.Computer_ID =  computer.ID "
                   "JOIN scientist ON Connect.scientist_ID = scientist.ID"
                   "WHERE scientist.firstname = (:x) COLLATE NOCASE");
    query.addBindValue(qName);
    query.exec();
    int idName = query.record().indexOf("firstname");
    int idName2 = query.record().indexOf("lastname");
    int idName3 = query.record().indexOf("name");
    int idName4 = query.record().indexOf("type");
    int idName5 = query.record().indexOf("yearbuilt");
    while(query.next())
    {
        string firstname = query.value(idName).toString().toStdString();
        string lastname = query.value(idName2).toString().toStdString();
        string compname = query.value(idName3).toString().toStdString();
        string comptype = query.value(idName4).toString().toStdString();
        int yearbuilt = query.value(idName5).toInt();

        searching s(firstname, lastname, compname, comptype, yearbuilt);
        joinQueryscientist.push_back(s);

    }
    return joinQueryscientist;
    */

    //CORRECT
    vector<searching> joinQueryComputer;
    QSqlQuery myQuery;
    QString qName = QString::fromStdString(x);
    myQuery.prepare("SELECT scientist.firstname, scientist.lastname, computer.name, computer.type, computer.yearbuilt FROM Connect JOIN computer ON Connect.Computer_ID =  computer.ID  JOIN scientist ON Connect.scientist_ID = scientist.ID WHERE scientist.firstname = (:x) COLLATE NOCASE");
    myQuery.addBindValue(qName);
    myQuery.exec();
    int idName = myQuery.record().indexOf("firstname");
    int idName2 = myQuery.record().indexOf("lastname");
    int idName3 = myQuery.record().indexOf("name");
    int idName4 = myQuery.record().indexOf("type");
    int idName5 = myQuery.record().indexOf("yearbuilt");

    while(myQuery.next())
    {
        string firstname = myQuery.value(idName).toString().toStdString();
        string lastname = myQuery.value(idName2).toString().toStdString();
        string compname = myQuery.value(idName3).toString().toStdString();
        string comptype = myQuery.value(idName4).toString().toStdString();
        int yearbuilt = myQuery.value(idName5).toInt();

        searching s(firstname, lastname, compname, comptype, yearbuilt);
        joinQueryComputer.push_back(s);
    }
    return joinQueryComputer;


}

vector<searching> DataLayer::searchForComputerFromSearchingDatabase(string x)
{
    vector<searching> joinQueryComputer;
    QSqlQuery myQuery;
    QString qName = QString::fromStdString(x);
    myQuery.prepare("SELECT scientist.firstname, scientist.lastname, computer.name, computer.type, computer.yearbuilt FROM Connect JOIN computer ON Connect.Computer_ID =  computer.ID JOIN scientist ON Connect.scientist_ID = scientist.ID WHERE computer.name = (:x) COLLATE NOCASE");
    myQuery.addBindValue(qName);
    myQuery.exec();
    int idName = myQuery.record().indexOf("firstname");
    int idName2 = myQuery.record().indexOf("lastname");
    int idName3 = myQuery.record().indexOf("name");
    int idName4 = myQuery.record().indexOf("type");
    int idName5 = myQuery.record().indexOf("yearbuilt");

    while(myQuery.next())
    {
        string firstname = myQuery.value(idName).toString().toStdString();
        string lastname = myQuery.value(idName2).toString().toStdString();
        string compname = myQuery.value(idName3).toString().toStdString();
        string comptype = myQuery.value(idName4).toString().toStdString();
        int yearbuilt = myQuery.value(idName5).toInt();

        searching s(firstname, lastname, compname, comptype, yearbuilt);
        joinQueryComputer.push_back(s);
    }
    return joinQueryComputer;
}

bool DataLayer::deleteFunction(int x)
{
    bool deleteF;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT firstname FROM scientist WHERE ID = (:x)");
    myQuery.addBindValue(x);

    if (myQuery.exec())
    {
        if (myQuery.next())
        {
            myQuery.prepare("DELETE FROM scientist WHERE ID = (:x)");
            myQuery.addBindValue(x);
            myQuery.exec();
            deleteF = true;
        }
    }
    else
    {
          deleteF = false;
    }
    return deleteF;
}

bool DataLayer::deleteFunctionComputer(int x)
{
    bool bla;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT name FROM computer WHERE ID = (:x)");
    myQuery.addBindValue(x);

    if (myQuery.exec())
    {
        if (myQuery.next())
        {
            myQuery.prepare("DELETE FROM computer WHERE ID = (:x)");
            myQuery.addBindValue(x);
            myQuery.exec();
            bla = true;
        }
    }
    else
    {
          bla = false;
    }
    return bla;
}

bool DataLayer::deleteConnectionFunctionScientist(int x)
{
    bool deleteF;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT * FROM connect WHERE scientist_ID = (:x)");
    myQuery.addBindValue(x);
    if(myQuery.exec())
    {
        if(myQuery.next())
        {
            myQuery.prepare("DELETE FROM connect WHERE scientist_ID = (:x)");
            myQuery.addBindValue(x);
            myQuery.exec();
            deleteF = true;
        }
    }
    else
    {
        deleteF = false;
    }
    return deleteF;
}

bool DataLayer::deleteConnectionFunctionComputer(int x)
{
    bool deleteF;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT * FROM connect WHERE scientist_ID = (:x)");
    myQuery.addBindValue(x);
    if(myQuery.exec())
    {
        if(myQuery.next())
        {
            myQuery.prepare("DELETE FROM scientist WHERE scientist_ID = (:x)");
            myQuery.addBindValue(x);
            myQuery.exec();
            deleteF = true;
        }
    }
    else
    {
        deleteF = false;
    }
    return deleteF;
}

bool DataLayer::addFunction(Scientist newScientist)
{
    QSqlQuery query;
    QString qName1 = QString::fromStdString(newScientist.getFirstName());
    QString qName2 = QString::fromStdString(newScientist.getLastName());
    QString qGender = QChar(newScientist.getGender());
    QString qNat = QString::fromStdString(newScientist.getNationality());

    query.prepare("INSERT INTO scientist (firstname, lastname, gender, nationality, YOB, YOD, YOA) VALUES (:name1, :name2, :gender1, :nation, :yob, :yod, :yoa)");
    query.addBindValue(qName1);
    query.addBindValue(qName2);
    query.addBindValue(qGender);
    query.addBindValue(qNat);
    query.addBindValue(newScientist.getBirthYear());
    query.addBindValue(newScientist.getDeathYear());
    query.addBindValue(newScientist.getAwardYear());


    if (query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}


vector<Scientist> DataLayer::searchForNameFromDatabase(string name)
{
    vector<Scientist> scientists;
    QSqlQuery query;
    QString qName = QString::fromStdString(name);
    query.prepare("SELECT * FROM scientist WHERE firstname LIKE (:name) OR lastname LIKE (:name) COLLATE NOCASE");
    query.addBindValue("%" + qName + "%");
    query.addBindValue("%" + qName + "%");
    query.exec();
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");
    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string firstName = query.value(idName).toString().toStdString();
        string lastName = query.value(idname1).toString().toStdString();
        char sex = query.value(idname2).toString().toStdString()[0];
        string nationality = query.value(idname3).toString().toStdString();
        int birthYear = query.value(idname4).toInt();
        int deathYear = query.value(idname5).toInt();
        int awardYear = query.value(idname6).toInt();
        Scientist s(id, firstName, lastName, sex, nationality,birthYear,deathYear, awardYear);
        scientists.push_back(s);
    }
    return scientists;
}

int DataLayer::getSizeOfScientists()
{
    return _scientists.size();
}

int DataLayer::getSizeOfComputer()
{
    return _computer.size();
}

char DataLayer::getGenderAt(int i)
{
    return _scientists[i].getGender();
}

int DataLayer::getBirthYearAt(int i)
{
    return _scientists[i].getBirthYear();
}

int DataLayer::getDeathYearAt(int i)
{
    return _scientists[i].getDeathYear();
}
int DataLayer::getAwardYearAt(int i)

{
    return _scientists[i].getAwardYear();
}

vector<Scientist> DataLayer::readInAlphabeticalOrder()
{
    vector<Scientist> returnScientist;
    QSqlQuery query("SELECT * FROM scientist s ORDER BY s.firstname, s.lastname ASC");
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");

    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string firstName = query.value(idName).toString().toStdString();
        string lastName = query.value(idname1).toString().toStdString();
        char sex = query.value(idname2).toString().toStdString()[0];
        string nationality = query.value(idname3).toString().toStdString();
        int birthYear = query.value(idname4).toInt();
        int deathYear = query.value(idname5).toInt();
        int awardYear = query.value(idname6).toInt();
        Scientist s(id, firstName, lastName, sex, nationality,birthYear,deathYear, awardYear);
        returnScientist.push_back(s);
    }
    return returnScientist;
}

vector<Scientist> DataLayer::readInReverseAlphabeticalOrder()
{
    vector<Scientist> returnScientist;
    QSqlQuery query("SELECT * FROM scientist s ORDER BY s.firstname DESC");
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");

    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string firstName = query.value(idName).toString().toStdString();
        string lastName = query.value(idname1).toString().toStdString();
        char sex = query.value(idname2).toString().toStdString()[0];
        string nationality = query.value(idname3).toString().toStdString();
        int birthYear = query.value(idname4).toInt();
        int deathYear = query.value(idname5).toInt();
        int awardYear = query.value(idname6).toInt();
        Scientist s(id, firstName, lastName, sex, nationality,birthYear,deathYear, awardYear);
        returnScientist.push_back(s);
    }
    return returnScientist;
}

vector<Scientist> DataLayer::readInOldestOrder()
{
    vector<Scientist> returnScientist;
    QSqlQuery query("SELECT * FROM scientist s ORDER BY s.YOB, s.YOD ASC");
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");

    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string firstName = query.value(idName).toString().toStdString();
        string lastName = query.value(idname1).toString().toStdString();
        char sex = query.value(idname2).toString().toStdString()[0];
        string nationality = query.value(idname3).toString().toStdString();
        int birthYear = query.value(idname4).toInt();
        int deathYear = query.value(idname5).toInt();
        int awardYear = query.value(idname6).toInt();
        Scientist s(id, firstName, lastName, sex, nationality,birthYear,deathYear, awardYear);
        returnScientist.push_back(s);
    }
    return returnScientist;
}

vector<Scientist> DataLayer::readInYoungestOrder()
{
    vector<Scientist> returnScientist;
    QSqlQuery query("SELECT * FROM scientist s ORDER BY s.YOB DESC");
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");

    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string firstName = query.value(idName).toString().toStdString();
        string lastName = query.value(idname1).toString().toStdString();
        char sex = query.value(idname2).toString().toStdString()[0];
        string nationality = query.value(idname3).toString().toStdString();
        int birthYear = query.value(idname4).toInt();
        int deathYear = query.value(idname5).toInt();
        int awardYear = query.value(idname6).toInt();

        Scientist s(id, firstName, lastName, sex, nationality,birthYear,deathYear, awardYear);
        returnScientist.push_back(s);
    }
    return returnScientist;
}

vector<Scientist> DataLayer::searchForTuringAwardWinners(int x)
{
    vector<Scientist> scientists;
    QSqlQuery query;
    query.prepare("SELECT * FROM scientist WHERE YOA = (:x)");
    query.addBindValue(x);
    query.exec();
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");
    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string firstName = query.value(idName).toString().toStdString();
        string lastName = query.value(idname1).toString().toStdString();
        char sex = query.value(idname2).toString().toStdString()[0];
        string nationality = query.value(idname3).toString().toStdString();
        int birthYear = query.value(idname4).toInt();
        int deathYear = query.value(idname5).toInt();
        int awardYear = query.value(idname6).toInt();
        Scientist s(id, firstName, lastName, sex, nationality,birthYear,deathYear, awardYear);
        scientists.push_back(s);
    }
    return scientists;
}

vector<Scientist> DataLayer::searchForYearOfBirth(int x)
{
    vector<Scientist> scientists;
    QSqlQuery query;
    query.prepare("SELECT * FROM scientist WHERE YOB = (:x)");
    query.addBindValue(x);
    query.exec();
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");
    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string firstName = query.value(idName).toString().toStdString();
        string lastName = query.value(idname1).toString().toStdString();
        char sex = query.value(idname2).toString().toStdString()[0];
        string nationality = query.value(idname3).toString().toStdString();
        int birthYear = query.value(idname4).toInt();
        int deathYear = query.value(idname5).toInt();
        int awardYear = query.value(idname6).toInt();
        Scientist s(id, firstName, lastName, sex, nationality,birthYear,deathYear, awardYear);
        scientists.push_back(s);
    }
    return scientists;
}

vector<Scientist> DataLayer::searchRangeForYearOfBirth(int x, int y)
{
    vector<Scientist> scientists;
    QSqlQuery query;
    query.prepare("SELECT * FROM scientist s WHERE s.YOB BETWEEN (:x) AND (:y)");
    query.addBindValue(x);
    query.addBindValue(y);
    query.exec();
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");
    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string firstName = query.value(idName).toString().toStdString();
        string lastName = query.value(idname1).toString().toStdString();
        char sex = query.value(idname2).toString().toStdString()[0];
        string nationality = query.value(idname3).toString().toStdString();
        int birthYear = query.value(idname4).toInt();
        int deathYear = query.value(idname5).toInt();
        int awardYear = query.value(idname6).toInt();
        Scientist s(id, firstName, lastName, sex, nationality,birthYear,deathYear, awardYear);
        scientists.push_back(s);
    }
    return scientists;
}

vector<Computer> DataLayer::readInAlphabeticalOrderComputer()
{
    vector<Computer> returnComputer;
    QSqlQuery query("SELECT * FROM computer s ORDER BY s.name ASC");
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");

    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string name = query.value(idName).toString().toStdString();
        string type = query.value(idName1).toString().toStdString();
        int yearbuilt = query.value(idName2).toInt();
        bool wasbuilt = query.value(idName3).toBool();
        Computer s(id, name, type, yearbuilt, wasbuilt);
        returnComputer.push_back(s);
    }
    return returnComputer;
}

vector<Computer> DataLayer::readInReverseAlphabeticalOrderComputer()
{
    vector<Computer> returnComputer;
    QSqlQuery query("SELECT * FROM computer s ORDER BY s.name DESC");
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");

    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string name = query.value(idName).toString().toStdString();
        string type = query.value(idName1).toString().toStdString();
        int yearbuilt = query.value(idName2).toInt();
        bool wasbuilt = query.value(idName3).toBool();
        Computer s(id, name, type, yearbuilt, wasbuilt);
        returnComputer.push_back(s);
    }
    return returnComputer;
}

vector<Computer> DataLayer::readInOldestOrderComputer()
{
    vector<Computer> returnComputer;
    QSqlQuery query("SELECT * FROM computer s ORDER BY s.yearBuilt ASC");
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");

    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string name = query.value(idName).toString().toStdString();
        string type = query.value(idName1).toString().toStdString();
        int yearbuilt = query.value(idName2).toInt();
        bool wasbuilt = query.value(idName3).toBool();

        Computer s(id, name, type, yearbuilt, wasbuilt);
        returnComputer.push_back(s);
    }
    return returnComputer;
}

vector<Computer> DataLayer::readInYoungestOrderComputer()
{
    vector<Computer> returnComputer;
    QSqlQuery query("SELECT * FROM computer s ORDER BY s.yearBuilt DESC");
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");

    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string name = query.value(idName).toString().toStdString();
        string type = query.value(idName1).toString().toStdString();
        int yearbuilt = query.value(idName2).toInt();
        bool wasbuilt = query.value(idName3).toBool();

        Computer s(id, name, type, yearbuilt, wasbuilt);
        returnComputer.push_back(s);
    }
    return returnComputer;
}

bool DataLayer::addFunctionComputer(Computer newComputer)
{
    QSqlQuery query;
    QString qName1 = QString::fromStdString(newComputer.getComputerName());
    QString qType1 = QString::fromStdString(newComputer.getComputerType());
    query.prepare("INSERT INTO computer (name, type, yearBuilt, wasbuilt) VALUES (:name1, :type1, :yob, :wasbuilt1)");
    query.addBindValue(qName1);
    query.addBindValue(qType1);
    query.addBindValue(newComputer.getYearOfBuild());
    query.addBindValue(newComputer.getWasBuilt());

    if (query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DataLayer::addFunctionConnect(connection newConnection)
{
    QSqlQuery query;
    query.prepare("INSERT INTO connect (Scientist_ID, Computer_ID) VALUES (:scientistId, :computerId)");
    query.addBindValue(newConnection.getScientistId());
    query.addBindValue(newConnection.getComputersId());

    if (query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<Computer> DataLayer::checkInComputer(string x)
{
    vector<Computer> myVector;
    QSqlQuery query;
    QString qName = QString::fromStdString(x);

    query.prepare("SELECT * FROM computer c WHERE c.name LIKE (:x) COLLATE NOCASE");
    query.addBindValue("%" + qName + "%");
    query.exec();
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");

    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string name = query.value(idName).toString().toStdString();
        string type = query.value(idName1).toString().toStdString();
        int yearbuilt = query.value(idName2).toInt();
        bool wasbuilt = query.value(idName3).toBool();
        Computer s(id, name, type, yearbuilt, wasbuilt);
        myVector.push_back(s);
    }
    return myVector;
}

// This function searches the database for a type of computer matching the given string.  It returns all matching comptuers.
vector<Computer> DataLayer::checkInComputerType(string x)
{
    vector<Computer> myVector;
    QSqlQuery query;
    QString qName = QString::fromStdString(x);

    query.prepare("SELECT * FROM computer c WHERE c.type LIKE (:x) COLLATE NOCASE");
    query.addBindValue("%" + qName + "%");
    query.exec();
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");

    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string name = query.value(idName).toString().toStdString();
        string type = query.value(idName1).toString().toStdString();
        int yearbuilt = query.value(idName2).toInt();
        bool wasbuilt = query.value(idName3).toBool();
        Computer s(id, name, type, yearbuilt, wasbuilt);
        myVector.push_back(s);
    }
    return myVector;
}

bool DataLayer::checkIfExists(string x)
{
    bool exists = false;

    QSqlQuery checkQuery;
    QString qName = QString::fromStdString(x);
    checkQuery.prepare("SELECT firstname FROM scientist WHERE firstname = (:x) COLLATE NOCASE");
    checkQuery.addBindValue(qName);

    if (checkQuery.exec())
    {
        if(checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        exists = false;
    }

    return exists;
}

bool DataLayer::checkIfComputerExists(string x)
{
    bool exists = false;

    QSqlQuery checkQuery;
    QString qName = QString::fromStdString(x);
    checkQuery.prepare("SELECT name FROM scientist WHERE name = (:x) COLLATE NOCASE");
    checkQuery.addBindValue(qName);

    if (checkQuery.exec())
    {
        if(checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        exists = false;
    }

    return exists;
}

vector<Computer> DataLayer::checkInComputerYear(int x, int y)
{
    vector<Computer> myVector;
    QSqlQuery query;

    query.prepare("SELECT * FROM computer c WHERE c.yearBuilt BETWEEN (:x) AND (:y)");
    query.addBindValue(x);
    query.addBindValue(y);
    query.exec();
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");
    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string name = query.value(idName).toString().toStdString();
        string type = query.value(idName1).toString().toStdString();
        int yearbuilt = query.value(idName2).toInt();
        bool wasbuilt = query.value(idName3).toBool();
        Computer s(id, name, type, yearbuilt, wasbuilt);
        myVector.push_back(s);
    }
    return myVector;
}

vector<Computer> DataLayer::checkInComputerSingleYear(int x)
{
    vector<Computer> myVector;
    QSqlQuery query;

    query.prepare("SELECT * FROM computer c WHERE c.yearBuilt = (:x)");
    query.addBindValue(x);
    query.exec();
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");
    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string name = query.value(idName).toString().toStdString();
        string type = query.value(idName1).toString().toStdString();
        int yearbuilt = query.value(idName2).toInt();
        bool wasbuilt = query.value(idName3).toBool();
        Computer s(id, name, type, yearbuilt, wasbuilt);
        myVector.push_back(s);
    }
    return myVector;
}

vector<Computer> DataLayer::ComputerWasBuilt()
{
    vector<Computer> myVector;
    QSqlQuery query;

    query.prepare("Select * From computer c WHERE c.wasbuilt = 1");
    query.exec();
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");
    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string name = query.value(idName).toString().toStdString();
        string type = query.value(idName1).toString().toStdString();
        int yearbuilt = query.value(idName2).toInt();
        bool wasbuilt = query.value(idName3).toBool();
        Computer s(id, name, type, yearbuilt, wasbuilt);
        myVector.push_back(s);
    }
    return myVector;
}

vector<Computer> DataLayer::ComputerWasNotBuilt()
{
    vector<Computer> myVector;
    QSqlQuery query;

    query.prepare("Select * From computer c WHERE c.wasbuilt = 0");
    query.exec();
    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");
    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string name = query.value(idName).toString().toStdString();
        string type = query.value(idName1).toString().toStdString();
        int yearbuilt = query.value(idName2).toInt();
        bool wasbuilt = query.value(idName3).toBool();
        Computer s(id, name, type, yearbuilt, wasbuilt);
        cout << name << " ";
        myVector.push_back(s);
    }
    return myVector;
}

bool DataLayer::updateFirstName(string x, int y)
{
    bool check;
    QSqlQuery query;
    QString qName = QString::fromStdString(x);

    query.prepare("UPDATE scientist SET firstname = (:x) WHERE ID = (:y)");
    query.addBindValue(qName);
    query.addBindValue(y);

    if(query.exec())
    {
        if (query.next())
        {
            check = true;
        }
    }
    else
    {
        check = false;
    }
    return check;
}












