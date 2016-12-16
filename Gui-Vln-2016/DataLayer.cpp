#include "DataLayer.h"
#include <iostream>
#include <vector>

//A default constructor for the data layer.
DataLayer::DataLayer()
{
    QSqlDatabase m_db;

       m_db = QSqlDatabase::addDatabase("QSQLITE");
       m_db.setDatabaseName("Scientists.sqlite");
       if (!m_db.open())
       {
               qDebug("AÆSJBFPIASHBFÐOAJSD");
       }
       else
       {
    }
}

//A defult constructor that accesses the database.
DataLayer::~DataLayer()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

//Returns all scientists in the database.
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

    //This loop is intended to extract data from the database.
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

//Returns all scientists in the dtabase in order of ID.
vector<Scientist> DataLayer::readAllFromScientistDataBaseById(int x)
{
    Scientist s;
    vector<Scientist> returnScientist;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT * FROM scientist WHERE scientist.ID = (:x)");
    myQuery.addBindValue(x);
    myQuery.exec();

    int idName7 = myQuery.record().indexOf("ID");
    int idName = myQuery.record().indexOf("firstname");
    int idname1 = myQuery.record().indexOf("lastname");
    int idname2 = myQuery.record().indexOf("gender");
    int idname3 = myQuery.record().indexOf("nationality");
    int idname4 = myQuery.record().indexOf("YOB");
    int idname5 = myQuery.record().indexOf("YOD");
    int idname6 = myQuery.record().indexOf("YOA");

    //This loop is intended to extract data from the database.
    while(myQuery.next())
    {
        int Ids = myQuery.value(idName7).toInt();
        string firstName = myQuery.value(idName).toString().toStdString();
        string lastName = myQuery.value(idname1).toString().toStdString();
        char sex = myQuery.value(idname2).toString().toStdString()[0];
        string nationality = myQuery.value(idname3).toString().toStdString();
        int birthYear = myQuery.value(idname4).toInt();
        int deathYear = myQuery.value(idname5).toInt();
        int awardYear = myQuery.value(idname6).toInt();

        Scientist s(Ids, firstName, lastName, sex, nationality,birthYear,deathYear, awardYear);
        returnScientist.push_back(s);
    }
    return returnScientist;
}

//Returns all computers in the database.
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

    //This loop is intended to extract data from the database
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

//Returns all computers in the dtabase in order of ID
vector<Computer> DataLayer::readAllFromDataComputerBaseById(int x)
{
    Computer s;
    vector<Computer> displayComputer;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT * FROM computer WHERE computer.ID = (:x)");
    myQuery.addBindValue(x);
    myQuery.exec();

    int idName = myQuery.record().indexOf("ID");
    int idName1 = myQuery.record().indexOf("name");
    int idName2 = myQuery.record().indexOf("type");
    int idName3 = myQuery.record().indexOf("yearBuilt");
    int idName4 = myQuery.record().indexOf("wasbuilt");

    //This loop is intended to extract data from the database.
    while(myQuery.next())
    {
        int ids = myQuery.value(idName).toInt();
        string name = myQuery.value(idName1).toString().toStdString();
        string type = myQuery.value(idName2).toString().toStdString();
        int yearbuilt = myQuery.value(idName3).toInt();
        bool wasbuilt = myQuery.value(idName4).toBool();

        Computer s(ids, name, type, yearbuilt, wasbuilt);
        displayComputer.push_back(s);
    }
    return displayComputer;
}

//Returns all connections in the database.
vector<connection> DataLayer::readAllFromDataConnectionBase()
{
    connection s;
    vector<connection> displayConnection;
    QSqlQuery query("SELECT * FROM connection");

    int idName1 = query.record().indexOf("scientistId");
    int idName2 = query.record().indexOf("computersId");

    //This loop is intended to extract data from the database.
    while(query.next())
    {
        //int ids = query.value(idName).toInt();
        int scientistId = query.value(idName1).toInt();
        int computersId = query.value(idName2).toInt();

        connection s(scientistId, computersId);
        displayConnection.push_back(s);
    }
    return displayConnection;
}

//This function lets you search the joined table for a scientist.  it returns all entries in the join table that match.
vector<searching> DataLayer::searchForScientistFromSearchingDatabse(string x)
{
    vector<searching> joinQueryComputer;
    QSqlQuery myQuery;
    QString qName = QString::fromStdString(x);
    myQuery.prepare("SELECT connect.scientist_ID, connect.computer_ID, scientist.firstname, scientist.lastname, computer.name, computer.type, computer.yearbuilt FROM Connect JOIN computer ON Connect.Computer_ID =  computer.ID  JOIN scientist ON Connect.scientist_ID = scientist.ID WHERE scientist.firstname LIKE (:x) OR scientist.lastname LIKE (:x) COLLATE NOCASE");
    myQuery.addBindValue("%" + qName + "%");
    myQuery.addBindValue("%" + qName + "%");
    myQuery.exec();

    int idNamesScientistID = myQuery.record().indexOf("scientist_ID");
    int idNamesComputerID = myQuery.record().indexOf("computer_ID");
    int idName = myQuery.record().indexOf("firstname");
    int idName2 = myQuery.record().indexOf("lastname");
    int idName3 = myQuery.record().indexOf("name");
    int idName4 = myQuery.record().indexOf("type");
    int idName5 = myQuery.record().indexOf("yearbuilt");

    //This loop is intended to extract data from the database.
    while(myQuery.next())
    {
        int IdScientist = myQuery.value(idNamesScientistID).toInt();
        int IdComputer = myQuery.value(idNamesComputerID).toInt();
        string firstname = myQuery.value(idName).toString().toStdString();
        string lastname = myQuery.value(idName2).toString().toStdString();
        string compname = myQuery.value(idName3).toString().toStdString();
        string comptype = myQuery.value(idName4).toString().toStdString();
        int yearbuilt = myQuery.value(idName5).toInt();

        searching s(IdScientist, IdComputer,firstname, lastname, compname, comptype, yearbuilt);
        joinQueryComputer.push_back(s);
    }
    return joinQueryComputer;
}

//This function lets you search the joined table of computers and scientists.  It takes a computer name and searches for it, returning all relevant entries in the table.
vector<searching> DataLayer::searchForComputerFromSearchingDatabase(string x)
{
    vector<searching> joinQueryComputer;
    QSqlQuery myQuery;
    QString qName = QString::fromStdString(x);
    myQuery.prepare("SELECT connect.scientist_ID, connect.computer_ID, scientist.firstname, scientist.lastname, computer.name, computer.type, computer.yearbuilt FROM Connect JOIN computer ON Connect.Computer_ID =  computer.ID JOIN scientist ON Connect.scientist_ID = scientist.ID WHERE computer.name LIKE (:x) OR computer.type LIKE (:x) OR computer.yearBuilt LIKE (:x) COLLATE NOCASE");
    myQuery.addBindValue("%" + qName + "%");
    myQuery.addBindValue("%" + qName + "%");
    myQuery.addBindValue("%" + qName + "%");
    myQuery.exec();

    int idNamesScientistID = myQuery.record().indexOf("scientist_ID");
    int idNamesComputerID = myQuery.record().indexOf("computer_ID");
    int idName = myQuery.record().indexOf("firstname");
    int idName2 = myQuery.record().indexOf("lastname");
    int idName3 = myQuery.record().indexOf("name");
    int idName4 = myQuery.record().indexOf("type");
    int idName5 = myQuery.record().indexOf("yearbuilt");

    //This loop is intended to extract data from the database.
    while(myQuery.next())
    {
        int IdScientist = myQuery.value(idNamesScientistID).toInt();
        int IdComputer = myQuery.value(idNamesComputerID).toInt();
        string firstname = myQuery.value(idName).toString().toStdString();
        string lastname = myQuery.value(idName2).toString().toStdString();
        string compname = myQuery.value(idName3).toString().toStdString();
        string comptype = myQuery.value(idName4).toString().toStdString();
        int yearbuilt = myQuery.value(idName5).toInt();

        searching s(IdScientist, IdComputer,firstname, lastname, compname, comptype, yearbuilt);
        joinQueryComputer.push_back(s);
    }
    return joinQueryComputer;
}

//This function displays a list of connections between scientists and computers (in the order they are in stored in our database, which is an order by their ID).
vector<searching> DataLayer::displayAllfromSearching()
{
    vector<searching> joinQueryComputer;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT connect.scientist_ID, connect.computer_ID, scientist.firstname, scientist.lastname, computer.name, computer.type, computer.yearbuilt FROM Connect JOIN computer ON Connect.Computer_ID =  computer.ID JOIN scientist ON Connect.scientist_ID = scientist.ID");
    myQuery.exec();

    int idNamesScientistID = myQuery.record().indexOf("scientist_ID");
    int idNamesComputerID = myQuery.record().indexOf("computer_ID");
    int idName = myQuery.record().indexOf("firstname");
    int idName2 = myQuery.record().indexOf("lastname");
    int idName3 = myQuery.record().indexOf("name");
    int idName4 = myQuery.record().indexOf("type");
    int idName5 = myQuery.record().indexOf("yearbuilt");

    //This loop is intended to extract data from the database.
    while(myQuery.next())
    {
        int IdScientist = myQuery.value(idNamesScientistID).toInt();
        int IdComputer = myQuery.value(idNamesComputerID).toInt();
        string firstname = myQuery.value(idName).toString().toStdString();
        string lastname = myQuery.value(idName2).toString().toStdString();
        string compname = myQuery.value(idName3).toString().toStdString();
        string comptype = myQuery.value(idName4).toString().toStdString();
        int yearbuilt = myQuery.value(idName5).toInt();

        searching s(IdScientist, IdComputer,firstname, lastname, compname, comptype, yearbuilt);
        joinQueryComputer.push_back(s);
    }
    return joinQueryComputer;
}

//This function displays a list of connections between scientists and computers (in an ascending order by their first name).
vector<searching> DataLayer::displayFirstNamefromSearchingAscendingOrder()
{
    vector<searching> joinQueryComputer;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT connect.scientist_ID, connect.computer_ID, scientist.firstname, scientist.lastname, computer.name, computer.type, computer.yearbuilt FROM Connect JOIN computer ON Connect.Computer_ID =  computer.ID JOIN scientist ON Connect.scientist_ID = scientist.ID ORDER BY scientist.firstname ASC;");
    myQuery.exec();

    int idNamesScientistID = myQuery.record().indexOf("scientist_ID");
    int idNamesComputerID = myQuery.record().indexOf("computer_ID");
    int idName = myQuery.record().indexOf("firstname");
    int idName2 = myQuery.record().indexOf("lastname");
    int idName3 = myQuery.record().indexOf("name");
    int idName4 = myQuery.record().indexOf("type");
    int idName5 = myQuery.record().indexOf("yearbuilt");

    //This loop is intended to extract data from the database.
    while(myQuery.next())
    {
        int IdScientist = myQuery.value(idNamesScientistID).toInt();
        int IdComputer = myQuery.value(idNamesComputerID).toInt();
        string firstname = myQuery.value(idName).toString().toStdString();
        string lastname = myQuery.value(idName2).toString().toStdString();
        string compname = myQuery.value(idName3).toString().toStdString();
        string comptype = myQuery.value(idName4).toString().toStdString();
        int yearbuilt = myQuery.value(idName5).toInt();

        searching s(IdScientist, IdComputer,firstname, lastname, compname, comptype, yearbuilt);
        joinQueryComputer.push_back(s);
    }
    return joinQueryComputer;
}

//This function displays a list of connections between scientists and computers (in an descending order by their first name).
vector<searching> DataLayer::displayFirstNamefromSearchingDescendingOrder()
{
    vector<searching> joinQueryComputer;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT connect.scientist_ID, connect.computer_ID, scientist.firstname, scientist.lastname, computer.name, computer.type, computer.yearbuilt FROM Connect JOIN computer ON Connect.Computer_ID =  computer.ID JOIN scientist ON Connect.scientist_ID = scientist.ID ORDER BY scientist.firstname DESC;");
    myQuery.exec();

    int idNamesScientistID = myQuery.record().indexOf("scientist_ID");
    int idNamesComputerID = myQuery.record().indexOf("computer_ID");
    int idName = myQuery.record().indexOf("firstname");
    int idName2 = myQuery.record().indexOf("lastname");
    int idName3 = myQuery.record().indexOf("name");
    int idName4 = myQuery.record().indexOf("type");
    int idName5 = myQuery.record().indexOf("yearbuilt");

    //This loop is intended to extract data from the database.
    while(myQuery.next())
    {
        int IdScientist = myQuery.value(idNamesScientistID).toInt();
        int IdComputer = myQuery.value(idNamesComputerID).toInt();
        string firstname = myQuery.value(idName).toString().toStdString();
        string lastname = myQuery.value(idName2).toString().toStdString();
        string compname = myQuery.value(idName3).toString().toStdString();
        string comptype = myQuery.value(idName4).toString().toStdString();
        int yearbuilt = myQuery.value(idName5).toInt();

        searching s(IdScientist, IdComputer,firstname, lastname, compname, comptype, yearbuilt);
        joinQueryComputer.push_back(s);
    }
    return joinQueryComputer;
}

//This function displays a list of connections between scientists and computers (in an ascending order by their last name).
vector<searching> DataLayer::displayLastNamefromSearchingAscendingOrder()
{
    vector<searching> joinQueryComputer;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT connect.scientist_ID, connect.computer_ID, scientist.firstname, scientist.lastname, computer.name, computer.type, computer.yearbuilt FROM Connect JOIN computer ON Connect.Computer_ID =  computer.ID JOIN scientist ON Connect.scientist_ID = scientist.ID ORDER BY scientist.lastname ASC;");
    myQuery.exec();

    int idNamesScientistID = myQuery.record().indexOf("scientist_ID");
    int idNamesComputerID = myQuery.record().indexOf("computer_ID");
    int idName = myQuery.record().indexOf("firstname");
    int idName2 = myQuery.record().indexOf("lastname");
    int idName3 = myQuery.record().indexOf("name");
    int idName4 = myQuery.record().indexOf("type");
    int idName5 = myQuery.record().indexOf("yearbuilt");

    //This loop is intended to extract data from the database.
    while(myQuery.next())
    {
        int IdScientist = myQuery.value(idNamesScientistID).toInt();
        int IdComputer = myQuery.value(idNamesComputerID).toInt();
        string firstname = myQuery.value(idName).toString().toStdString();
        string lastname = myQuery.value(idName2).toString().toStdString();
        string compname = myQuery.value(idName3).toString().toStdString();
        string comptype = myQuery.value(idName4).toString().toStdString();
        int yearbuilt = myQuery.value(idName5).toInt();

        searching s(IdScientist, IdComputer,firstname, lastname, compname, comptype, yearbuilt);
        joinQueryComputer.push_back(s);
    }
    return joinQueryComputer;
}

//This function displays a list of connections between scientists and computers (in an descending order by their last name).
vector<searching> DataLayer::displayLastNamefromSearchingDescendingOrder()
{
    vector<searching> joinQueryComputer;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT connect.scientist_ID, connect.computer_ID, scientist.firstname, scientist.lastname, computer.name, computer.type, computer.yearbuilt FROM Connect JOIN computer ON Connect.Computer_ID =  computer.ID JOIN scientist ON Connect.scientist_ID = scientist.ID ORDER BY scientist.lastname DESC;");
    myQuery.exec();

    int idNamesScientistID = myQuery.record().indexOf("scientist_ID");
    int idNamesComputerID = myQuery.record().indexOf("computer_ID");
    int idName = myQuery.record().indexOf("firstname");
    int idName2 = myQuery.record().indexOf("lastname");
    int idName3 = myQuery.record().indexOf("name");
    int idName4 = myQuery.record().indexOf("type");
    int idName5 = myQuery.record().indexOf("yearbuilt");

    //This loop is intended to extract data from the database.
    while(myQuery.next())
    {
        int IdScientist = myQuery.value(idNamesScientistID).toInt();
        int IdComputer = myQuery.value(idNamesComputerID).toInt();
        string firstname = myQuery.value(idName).toString().toStdString();
        string lastname = myQuery.value(idName2).toString().toStdString();
        string compname = myQuery.value(idName3).toString().toStdString();
        string comptype = myQuery.value(idName4).toString().toStdString();
        int yearbuilt = myQuery.value(idName5).toInt();

        searching s(IdScientist, IdComputer,firstname, lastname, compname, comptype, yearbuilt);
        joinQueryComputer.push_back(s);
    }
    return joinQueryComputer;
}

//This function displays a list of connections between a scientists and a computer (in an ascending order by the computers name).
vector<searching> DataLayer::displayComputerNamefromSearchingAscendingOrder()
{
    vector<searching> joinQueryComputer;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT connect.scientist_ID, connect.computer_ID, scientist.firstname, scientist.lastname, computer.name, computer.type, computer.yearbuilt FROM Connect JOIN computer ON Connect.Computer_ID =  computer.ID JOIN scientist ON Connect.scientist_ID = scientist.ID ORDER BY computer.name ASC;");
    myQuery.exec();

    int idNamesScientistID = myQuery.record().indexOf("scientist_ID");
    int idNamesComputerID = myQuery.record().indexOf("computer_ID");
    int idName = myQuery.record().indexOf("firstname");
    int idName2 = myQuery.record().indexOf("lastname");
    int idName3 = myQuery.record().indexOf("name");
    int idName4 = myQuery.record().indexOf("type");
    int idName5 = myQuery.record().indexOf("yearbuilt");

    //This loop is intended to extract data from the database.
    while(myQuery.next())
    {
        int IdScientist = myQuery.value(idNamesScientistID).toInt();
        int IdComputer = myQuery.value(idNamesComputerID).toInt();
        string firstname = myQuery.value(idName).toString().toStdString();
        string lastname = myQuery.value(idName2).toString().toStdString();
        string compname = myQuery.value(idName3).toString().toStdString();
        string comptype = myQuery.value(idName4).toString().toStdString();
        int yearbuilt = myQuery.value(idName5).toInt();

        searching s(IdScientist, IdComputer,firstname, lastname, compname, comptype, yearbuilt);
        joinQueryComputer.push_back(s);
    }
    return joinQueryComputer;
}

//This function displays a list of connections between scientists and computers (in an decending order by the computers name).
vector<searching> DataLayer::displayComputerNamefromSearchingDescendingOrder()
{
    vector<searching> joinQueryComputer;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT connect.scientist_ID, connect.computer_ID, scientist.firstname, scientist.lastname, computer.name, computer.type, computer.yearbuilt FROM Connect JOIN computer ON Connect.Computer_ID =  computer.ID JOIN scientist ON Connect.scientist_ID = scientist.ID ORDER BY computer.name DESC;");
    myQuery.exec();

    int idNamesScientistID = myQuery.record().indexOf("scientist_ID");
    int idNamesComputerID = myQuery.record().indexOf("computer_ID");
    int idName = myQuery.record().indexOf("firstname");
    int idName2 = myQuery.record().indexOf("lastname");
    int idName3 = myQuery.record().indexOf("name");
    int idName4 = myQuery.record().indexOf("type");
    int idName5 = myQuery.record().indexOf("yearbuilt");

    //This loop is intended to extract data from the database.
    while(myQuery.next())
    {
        int IdScientist = myQuery.value(idNamesScientistID).toInt();
        int IdComputer = myQuery.value(idNamesComputerID).toInt();
        string firstname = myQuery.value(idName).toString().toStdString();
        string lastname = myQuery.value(idName2).toString().toStdString();
        string compname = myQuery.value(idName3).toString().toStdString();
        string comptype = myQuery.value(idName4).toString().toStdString();
        int yearbuilt = myQuery.value(idName5).toInt();

        searching s(IdScientist, IdComputer,firstname, lastname, compname, comptype, yearbuilt);
        joinQueryComputer.push_back(s);
    }
    return joinQueryComputer;
}

//This function displays a list of connections between scientisst and computers (in an ascending order by the type of computer).
vector<searching> DataLayer::displayComputerTypefromSearchingAscendingOrder()
{
    vector<searching> joinQueryComputer;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT connect.scientist_ID, connect.computer_ID, scientist.firstname, scientist.lastname, computer.name, computer.type, computer.yearbuilt FROM Connect JOIN computer ON Connect.Computer_ID =  computer.ID JOIN scientist ON Connect.scientist_ID = scientist.ID ORDER BY computer.type ASC;");
    myQuery.exec();

    int idNamesScientistID = myQuery.record().indexOf("scientist_ID");
    int idNamesComputerID = myQuery.record().indexOf("computer_ID");
    int idName = myQuery.record().indexOf("firstname");
    int idName2 = myQuery.record().indexOf("lastname");
    int idName3 = myQuery.record().indexOf("name");
    int idName4 = myQuery.record().indexOf("type");
    int idName5 = myQuery.record().indexOf("yearbuilt");

    //This loop is intended to extract data from the database.
    while(myQuery.next())
    {
        int IdScientist = myQuery.value(idNamesScientistID).toInt();
        int IdComputer = myQuery.value(idNamesComputerID).toInt();
        string firstname = myQuery.value(idName).toString().toStdString();
        string lastname = myQuery.value(idName2).toString().toStdString();
        string compname = myQuery.value(idName3).toString().toStdString();
        string comptype = myQuery.value(idName4).toString().toStdString();
        int yearbuilt = myQuery.value(idName5).toInt();

        searching s(IdScientist, IdComputer,firstname, lastname, compname, comptype, yearbuilt);
        joinQueryComputer.push_back(s);
    }
    return joinQueryComputer;
}

//This function displays a list of connections between scientists and computers (in an descending order by the type of computer).
vector<searching> DataLayer::displayComputerTypefromSearchingDescendingOrder()
{
    vector<searching> joinQueryComputer;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT connect.scientist_ID, connect.computer_ID, scientist.firstname, scientist.lastname, computer.name, computer.type, computer.yearbuilt FROM Connect JOIN computer ON Connect.Computer_ID =  computer.ID JOIN scientist ON Connect.scientist_ID = scientist.ID ORDER BY computer.type DESC;");
    myQuery.exec();

    int idNamesScientistID = myQuery.record().indexOf("scientist_ID");
    int idNamesComputerID = myQuery.record().indexOf("computer_ID");
    int idName = myQuery.record().indexOf("firstname");
    int idName2 = myQuery.record().indexOf("lastname");
    int idName3 = myQuery.record().indexOf("name");
    int idName4 = myQuery.record().indexOf("type");
    int idName5 = myQuery.record().indexOf("yearbuilt");

    //This loop is intended to extract data from the database.
    while(myQuery.next())
    {
        int IdScientist = myQuery.value(idNamesScientistID).toInt();
        int IdComputer = myQuery.value(idNamesComputerID).toInt();
        string firstname = myQuery.value(idName).toString().toStdString();
        string lastname = myQuery.value(idName2).toString().toStdString();
        string compname = myQuery.value(idName3).toString().toStdString();
        string comptype = myQuery.value(idName4).toString().toStdString();
        int yearbuilt = myQuery.value(idName5).toInt();

        searching s(IdScientist, IdComputer,firstname, lastname, compname, comptype, yearbuilt);
        joinQueryComputer.push_back(s);
    }
    return joinQueryComputer;
}

//This function displays a list of connections between scientists and computers (in an ascending order by the year they were created).
vector<searching> DataLayer::displayComputerYearfromSearchingAscendingOrder()
{
    vector<searching> joinQueryComputer;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT connect.scientist_ID, connect.computer_ID, scientist.firstname, scientist.lastname, computer.name, computer.type, computer.yearbuilt FROM Connect JOIN computer ON Connect.Computer_ID =  computer.ID JOIN scientist ON Connect.scientist_ID = scientist.ID ORDER BY computer.yearBuilt ASC;");
    myQuery.exec();

    int idNamesScientistID = myQuery.record().indexOf("scientist_ID");
    int idNamesComputerID = myQuery.record().indexOf("computer_ID");
    int idName = myQuery.record().indexOf("firstname");
    int idName2 = myQuery.record().indexOf("lastname");
    int idName3 = myQuery.record().indexOf("name");
    int idName4 = myQuery.record().indexOf("type");
    int idName5 = myQuery.record().indexOf("yearbuilt");

    //This loop is intended to extract data from the database.
    while(myQuery.next())
    {
        int IdScientist = myQuery.value(idNamesScientistID).toInt();
        int IdComputer = myQuery.value(idNamesComputerID).toInt();
        string firstname = myQuery.value(idName).toString().toStdString();
        string lastname = myQuery.value(idName2).toString().toStdString();
        string compname = myQuery.value(idName3).toString().toStdString();
        string comptype = myQuery.value(idName4).toString().toStdString();
        int yearbuilt = myQuery.value(idName5).toInt();

        searching s(IdScientist, IdComputer,firstname, lastname, compname, comptype, yearbuilt);
        joinQueryComputer.push_back(s);
    }
    return joinQueryComputer;
}

//This function displays a list of connections between scientists and computers (in an descending order by the year they were created).
vector<searching> DataLayer::displayComputerYearfromSearchingDescendingOrder()
{
    vector<searching> joinQueryComputer;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT connect.scientist_ID, connect.computer_ID, scientist.firstname, scientist.lastname, computer.name, computer.type, computer.yearbuilt FROM Connect JOIN computer ON Connect.Computer_ID =  computer.ID JOIN scientist ON Connect.scientist_ID = scientist.ID ORDER BY computer.yearBuilt DESC;");
    myQuery.exec();

    int idNamesScientistID = myQuery.record().indexOf("scientist_ID");
    int idNamesComputerID = myQuery.record().indexOf("computer_ID");
    int idName = myQuery.record().indexOf("firstname");
    int idName2 = myQuery.record().indexOf("lastname");
    int idName3 = myQuery.record().indexOf("name");
    int idName4 = myQuery.record().indexOf("type");
    int idName5 = myQuery.record().indexOf("yearbuilt");

    //This loop is intended to extract data from the database.
    while(myQuery.next())
    {
        int IdScientist = myQuery.value(idNamesScientistID).toInt();
        int IdComputer = myQuery.value(idNamesComputerID).toInt();
        string firstname = myQuery.value(idName).toString().toStdString();
        string lastname = myQuery.value(idName2).toString().toStdString();
        string compname = myQuery.value(idName3).toString().toStdString();
        string comptype = myQuery.value(idName4).toString().toStdString();
        int yearbuilt = myQuery.value(idName5).toInt();

        searching s(IdScientist, IdComputer,firstname, lastname, compname, comptype, yearbuilt);
        joinQueryComputer.push_back(s);
    }
    return joinQueryComputer;
}

//This function deletes the scientist with the ID x, where x is input from the user.
bool DataLayer::deleteFunction(int x)
{
    bool deleteF;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT firstname FROM scientist WHERE ID = (:x)");
    myQuery.addBindValue(x);
    myQuery.exec();

    if (myQuery.next())
    {
        myQuery.prepare("DELETE FROM scientist WHERE ID = (:x)");
        myQuery.addBindValue(x);
        myQuery.exec();
        deleteF = true;
    }
    else
    {
          deleteF = false;
    }
    return deleteF;
}

//This function deletes the scientist with the ID x, where x is input from the user.
bool DataLayer::deleteFunctionComputer(int x)
{
    bool deleteC ;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT name FROM computer WHERE ID = (:x)");
    myQuery.addBindValue(x);
    myQuery.exec();
    if (myQuery.next())
    {
        myQuery.prepare("DELETE FROM computer WHERE ID = (:x)");
        myQuery.addBindValue(x);
        myQuery.exec();
        deleteC = true;
    }
    else
    {
          deleteC = false;
    }
    return deleteC;
}

//This function deletes deletes a connection between a scientist with the id x, and all computer connected with them. This is called when a scientist is deleted.
bool DataLayer::deleteConnectionFunctionScientist(int x)
{
    bool deleteF;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT * FROM connect WHERE scientist_ID = (:x)");
    myQuery.addBindValue(x);
    myQuery.exec();
    if(myQuery.next())
    {
        myQuery.prepare("DELETE FROM connect WHERE scientist_ID = (:x)");
        myQuery.addBindValue(x);
        myQuery.exec();
        deleteF = true;
    }
    else
    {
        deleteF = false;
    }
    return deleteF;
}

//This function deletes a connection between a computer with the id x, and all scientists connected to it. This function is called when a computer is deleted.
bool DataLayer::deleteConnectionFunctionComputer(int x)
{
    bool deleteF;
    QSqlQuery myQuery;
    myQuery.prepare("SELECT * FROM connect WHERE scientist_ID = (:x)");
    myQuery.addBindValue(x);
    myQuery.exec();

    if(myQuery.next())
    {
        myQuery.prepare("DELETE FROM scientist WHERE scientist_ID = (:x)");
        myQuery.addBindValue(x);
        myQuery.exec();
        deleteF = true;
    }
    else
    {
        deleteF = false;
    }
    return deleteF;
}

//This function adds a new scientist to the database.
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

    //
    if (query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//This function returns all scientists matching the search word entered by the user, Searching by name.
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

//This function returns all scientists matching the search word entered by the user, Searching by nationality.
vector<Scientist> DataLayer::searchNationality(string name)
{
    vector<Scientist> scientists;
    QSqlQuery query;
    QString qName = QString::fromStdString(name);
    query.prepare("SELECT * FROM scientist WHERE nationality LIKE (:name)");
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

//This function returns all scientists matching the search word entered by the user.
vector<Scientist> DataLayer::searchFullNameFromDatabase(string name)
{
    vector<Scientist> scientists;
    QSqlQuery query;
    QString qName = QString::fromStdString(name);
    query.prepare("SELECT * FROM scientist WHERE firstname LIKE (:name) AND lastname LIKE (:name) COLLATE NOCASE");
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

    //This loop is intended to extract data from the database
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

//The functions below return their current size.
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

//This function sorts all scientists in Ascending order by their ID.
vector<Scientist> DataLayer::readInAscendingByID()
{
    vector<Scientist> returnScientist;
    QSqlQuery query("SELECT * FROM scientist s ORDER BY s.ID ASC");

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");

    //This loop is intended to extract data from the database.
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

//This function sorts all scientists in Descending order by their ID.
vector<Scientist> DataLayer::readInDiscendingByID()
{
    vector<Scientist> returnScientist;
    QSqlQuery query("SELECT * FROM scientist s ORDER BY s.ID DESC");

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");

    //This loop is intended to extract data from the database.
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

//This function sorts all scientists in alphabetical order into a vector and returns it.
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

    //This loop is intended to extract data from the database.
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

//This function sorts all scientists in reverse alphabetical order into a vector and returns it.
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

    //This loop is intended to extract data from the database.
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

//This function sorts all scientists in alphabetical order by nationality into a vector and returns it.
vector<Scientist> DataLayer::readInAlphabeticalOrderNationality()
{
    vector<Scientist> returnScientist;
    QSqlQuery query("SELECT * FROM scientist s ORDER BY s.nationality ASC");

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");

    //This loop is intended to extract data from the database.
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

//This function sorts all scientists in reverse alphabetical order by nationality into a vector and returns it.
vector<Scientist> DataLayer::readInReverseAlphabeticalOrderNationality()
{
    vector<Scientist> returnScientist;
    QSqlQuery query("SELECT * FROM scientist s ORDER BY s.nationality DESC");

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");

    //This loop is intended to extract data from the database.
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

//This function sorts all scientists in order of birth year in ascending order into a vector and returns it.
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

    //This loop is intended to extract data from the database.
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

//This function sorts all scientists in descending order of birth year and returns it.
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

    //This loop is intended to extract data from the database.
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

//This function sorts all scientists in alphabetical order by gender into a vector and returns it.
vector<Scientist> DataLayer::readInAlphabeticalOrderGender()
{
    vector<Scientist> returnScientist;
    QSqlQuery query("SELECT * FROM scientist s ORDER BY s.gender ASC");

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");

    //This loop is intended to extract data from the database.
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

//This function sorts all scientists in reverse alphabetical order by gender into a vector and returns it.
vector<Scientist> DataLayer::readInReverseAlphabeticalOrderGender()
{
    vector<Scientist> returnScientist;
    QSqlQuery query("SELECT * FROM scientist s ORDER BY s.gender DESC");

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");

    //This loop is intended to extract data from the database.
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

//This function sorts all scientists in Ascending order by the year they recived the Turning award.
vector<Scientist> DataLayer::readInAscendingByYOA()
{
    vector<Scientist> returnScientist;
    QSqlQuery query("SELECT * FROM scientist s ORDER BY s.YOA ASC");

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");

    //This loop is intended to extract data from the database.
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

//This function sorts all scientists in Descending order by the year they recived the Turning award.
vector<Scientist> DataLayer::readInDescendingByYOA()
{
    vector<Scientist> returnScientist;
    QSqlQuery query("SELECT * FROM scientist s ORDER BY s.YOA DESC");

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");

    //This loop is intended to extract data from the database.
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

//This returns all scientists who have won a Turing award in the year x, where x is input from the user.
vector<Scientist> DataLayer::searchForTuringAwardWinners(int x)
{
    vector<Scientist> scientists;
    QString qNumber = QString::number(x);
    QSqlQuery query;
    query.prepare("SELECT * FROM scientist WHERE YOA = (:x)");
    query.addBindValue(qNumber);
    query.exec();

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");

    //This loop is intended to extract data from the database.
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

//This returns all scientists who have died in the year x, where x is an input from the user.
vector<Scientist> DataLayer::searchForDeadPeople(int x)
{
    vector<Scientist> scientists;
    QString qNumber = QString::number(x);
    QSqlQuery query;
    query.prepare("SELECT * FROM scientist WHERE YOD = (:x)");
    query.addBindValue(qNumber);
    query.exec();

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("firstname");
    int idname1 = query.record().indexOf("lastname");
    int idname2 = query.record().indexOf("gender");
    int idname3 = query.record().indexOf("nationality");
    int idname4 = query.record().indexOf("YOB");
    int idname5 = query.record().indexOf("YOD");
    int idname6 = query.record().indexOf("YOA");

    //This loop is intended to extract data from the database.
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

//This returns all scientists born in the year x, where x is input from the user.
vector<Scientist> DataLayer::searchForYearOfBirth(int x)
{
    vector<Scientist> scientists;
    QSqlQuery query;
    query.prepare("SELECT * FROM scientist WHERE YOB = (:x) OR YOA = (:x)");
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

    //This loop is intended to extract data from the database.
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

//This returns all scientists who were born between x and y, where x and y are both input from the user.
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

    //This loop is intended to extract data from the database.
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

//This returns all computers in alphabetical order in a vector.
vector<Computer> DataLayer::readInAlphabeticalOrderComputer()
{
    vector<Computer> returnComputer;
    QSqlQuery query("SELECT * FROM computer s ORDER BY s.name ASC");

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");

    //This loop is intended to extract data from the database.
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

//This returns all computers in reverse alphabetical order in a vector.
vector<Computer> DataLayer::readInReverseAlphabeticalOrderComputer()
{
    vector<Computer> returnComputer;
    QSqlQuery query("SELECT * FROM computer s ORDER BY s.name DESC");

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");

    //This loop is intended to extract data from the database.
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

//This returns all computers in order of descending age in a vector.
vector<Computer> DataLayer::readInOldestOrderComputer()
{
    vector<Computer> returnComputer;
    QSqlQuery query("SELECT * FROM computer s ORDER BY s.yearBuilt ASC");

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");

    //This loop is intended to extract data from the database.
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

//This returns all computers in order of ascending age in a vector.
vector<Computer> DataLayer::readInYoungestOrderComputer()
{
    vector<Computer> returnComputer;
    QSqlQuery query("SELECT * FROM computer s ORDER BY s.yearBuilt DESC");

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");

    //This loop is intended to extract data from the database.
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

//This function adds a new computer to the database. The new instance of computer, newComputer has been created in another function.
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

//This function adds a new connection between a scientist and a computer.  The connection newConnection is created in another function.
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

//This function searches for the name x in the database and returns all relevant computers.  x is input from the user.
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

    //This loop is intended to extract data from the database.
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

    //This loop is intended to extract data from the database.
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

//This function searches the database and returns a vector with computer which was built from searching year range.
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

    //This loop is intended to extract data from the database.
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

// This function searches the database and returns a vector with computer which was built from searching year.
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

    //This loop is intended to extract data from the database.
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

// Checks what computers did get built in database and returns a vector with those computers.
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

    //This loop is intended to extract data from the database.
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

// Checks what computers did not get built in database and returns a vector with those computers.
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

    //This loop is intended to extract data from the database.
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

// Updates database for first in scientist, takes in ID and changes that scientist.
bool DataLayer::updateFirstName(string x, int y)
{
    bool check;
    QSqlQuery query;
    QString qName = QString::fromStdString(x);
    query.prepare("UPDATE scientist SET firstname = (:x) WHERE ID = (:y)");
    query.addBindValue(qName);
    query.addBindValue(y);
    query.exec();

    if (query.next())
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

// Updates data base for last name in scientist, takes in ID and changes that scientist.
bool DataLayer::updateLastName(string x, int y)
{
    bool check;
    QSqlQuery query;
    QString qName = QString::fromStdString(x);
    query.prepare("UPDATE scientist SET lastname = (:x) WHERE ID = (:y)");
    query.addBindValue(qName);
    query.addBindValue(y);
    query.exec();

    if (query.next())
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

// Updates data base for scientist for y, takes in ID and changes that scientist.
bool DataLayer::updateGender(char g, int y)
{
    bool check;
    QSqlQuery query;
    QString qGender = QChar(g);
    //QString qGender = QChar(newScientist.getGender());
    query.prepare("UPDATE scientist SET gender = (:g) WHERE ID = (:y)");
    query.addBindValue(qGender);
    query.addBindValue(y);
    query.exec();

    if (query.next())
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

// Updates data base for nationality in scientist, takes in ID and changes that scientist.
bool DataLayer::updateNationality(string x, int y)
{
    bool check;
    QSqlQuery query;
    QString qName = QString::fromStdString(x);
    query.prepare("UPDATE scientist SET nationality = (:x) WHERE ID = (:y)");
    query.addBindValue(qName);
    query.addBindValue(y);
    query.exec();

    if (query.next())
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

// Updates database for scientist for year of birth, takes in ID and changes that scientist.
bool DataLayer::updateYOB (int x, int y)
{
    bool check;
    QSqlQuery query;
    query.prepare("UPDATE scientist SET YOB = (:x) WHERE ID = (:y)");
    query.addBindValue(x);
    query.addBindValue(y);
    query.exec();

    if (query.next())
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

// Updates database for scientist for year of death, takes in ID and changes that scientist.
bool DataLayer::updateYOD (int x, int y)
{
    bool check;
    QSqlQuery query;
    query.prepare("UPDATE scientist SET YOD = (:x) WHERE ID = (:y)");
    query.addBindValue(x);
    query.addBindValue(y);
    query.exec();

    if (query.next())
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

// Updates database for scientist for year of award, takes in ID and changes that scientist.
bool DataLayer::updateYOA (int x, int y)
{
    bool check;
    QSqlQuery query;
    query.prepare("UPDATE scientist SET YOA = (:x) WHERE ID = (:y)");
    query.addBindValue(x);
    query.addBindValue(y);
    query.exec();

    if (query.next())
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

// Updates database for name of computer, takes in new name and ID for that computer and changes it.
bool DataLayer::updateNameComputer(string x, int y)
{
    bool check;
    QSqlQuery query;
    QString qName = QString::fromStdString(x);
    query.prepare("UPDATE computer SET name = (:x) WHERE ID = (:y)");
    query.addBindValue(qName);
    query.addBindValue(y);
    query.exec();

    if (query.next())
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

// Updates database for type of computer, takes in the new type and computer ID and changes that computer.
bool DataLayer::updateTypeComputer(string x, int y)
{
    bool check;
    QSqlQuery query;
    QString qName = QString::fromStdString(x);
    query.prepare("UPDATE computer SET type = (:x) WHERE ID = (:y)");
    query.addBindValue(qName);
    query.addBindValue(y);
    query.exec();

    if (query.next())
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

// Updates database for year of built, takes in new year and ID and changes computer with same ID.
bool DataLayer::updateYOCComputer (int x, int y)
{
    bool check;
    QSqlQuery query;
    query.prepare("UPDATE computer SET yearBuilt = (:x) WHERE ID = (:y)");
    query.addBindValue(x);
    query.addBindValue(y);
    query.exec();

    if (query.next())
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

// Updates in datalayer if computer was built.
bool DataLayer::updateWasComputerBuilt (int x, int y)
{
    bool check;
    QSqlQuery query;
    //QString qName = QString::fromStdString(x);
    query.prepare("UPDATE computer SET wasbuilt = (:x) WHERE ID = (:y)");
    query.addBindValue(x);
    query.addBindValue(y);
    query.exec();

    if (query.next())
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

//This function displays a list of computers in an ascending order by their ID.
vector<Computer> DataLayer::readIdInAscendingOrder()
{
    vector<Computer> idAscendingOrder;
    QSqlQuery query("SELECT * FROM computer ORDER BY ID ASC");

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");

    //This loop is intended to extract data from the database.
    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string name = query.value(idName).toString().toStdString();
        string type = query.value(idName1).toString().toStdString();
        int yearbuilt = query.value(idName2).toInt();
        bool wasbuilt = query.value(idName3).toBool();

        Computer s(id, name, type, yearbuilt, wasbuilt);
        idAscendingOrder.push_back(s);
    }
    return idAscendingOrder;
}

//This function displays a list of computers in a descending order by their ID.
vector<Computer> DataLayer::readIdInDescindingOrder()
{
    vector<Computer> idDescendingOrder;
    QSqlQuery query("SELECT * FROM computer ORDER BY ID DESC");

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");

    //This loop is intended to extract data from the database
    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string name = query.value(idName).toString().toStdString();
        string type = query.value(idName1).toString().toStdString();
        int yearbuilt = query.value(idName2).toInt();
        bool wasbuilt = query.value(idName3).toBool();

        Computer s(id, name, type, yearbuilt, wasbuilt);
        idDescendingOrder.push_back(s);
    }
    return idDescendingOrder;
}

//This function displays a list of computers in an alphabetical order by their type.
vector<Computer> DataLayer::readTypeInAlphabeticalOrder()
{
    vector<Computer> typeAscendingOrder;
    QSqlQuery query("SELECT * FROM computer ORDER BY type ASC");

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");

    //This loop is intended to extract data from the database
    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string name = query.value(idName).toString().toStdString();
        string type = query.value(idName1).toString().toStdString();
        int yearbuilt = query.value(idName2).toInt();
        bool wasbuilt = query.value(idName3).toBool();

        Computer s(id, name, type, yearbuilt, wasbuilt);
        typeAscendingOrder.push_back(s);
    }
    return typeAscendingOrder;
}

//This function displays a list of computers in a reverse alphabetical order by their type.
vector<Computer> DataLayer::readTypeInReverseAlphabeticalOrder()
{
    vector<Computer> typeDescendingOrder;
    QSqlQuery query("SELECT * FROM computer ORDER BY type DESC");

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");

    //This loop is intended to extract data from the database.
    while(query.next())
    {
        int id = query.value(idNames).toInt();
        string name = query.value(idName).toString().toStdString();
        string type = query.value(idName1).toString().toStdString();
        int yearbuilt = query.value(idName2).toInt();
        bool wasbuilt = query.value(idName3).toBool();

        Computer s(id, name, type, yearbuilt, wasbuilt);
        typeDescendingOrder.push_back(s);
    }
    return typeDescendingOrder;
}

//This function searches the database and returns a picture of a scientist.
QByteArray DataLayer::searchForPictureForScientist(int id)
{
    QByteArray myArray;
    QSqlQuery query ("Select * FROM pictures WHERE sciID = (:id)");
    query.addBindValue(id);
    query.exec();

    int idName = query.record().indexOf("picture");
    while(query.next())
    {
        myArray = query.value(idName).toByteArray();
    }
    return myArray;
}

//This function searches the database and checks for users (that is a correct password and username).
vector<userandpass> DataLayer::readLogin()
{
    vector<userandpass> checkForUser;
    QSqlQuery query("SELECT * FROM users");

    int idName = query.record().indexOf("username");
    int idname1 = query.record().indexOf("password");

    //This while loop, like other while(query.next()) loops in this file, is intended to extract data from the database.
    while(query.next())
    {
        string username = query.value(idName).toString().toStdString();
        string password = query.value(idname1).toString().toStdString();
        userandpass users(username, password);
        checkForUser.push_back(users);
    }
    return checkForUser;
}

//This function registers new users to the database (that is makes a new username and password).
bool DataLayer::registerUser(userandpass newUser)
{
    QSqlQuery query;
    QString qName1 = QString::fromStdString(newUser.getuser());
    QString qName2 = QString::fromStdString(newUser.getpassword());
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.addBindValue(qName1);
    query.addBindValue(qName2);
    query.exec();

    //
    if (query.next())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//This function displays a list of computers in an ascending order by if they were created or not.
vector<Computer> DataLayer::ComputerWasBuiltASC()
{
    vector<Computer> myVector;
    QSqlQuery query;
    query.prepare("Select * From computer ORDER BY wasbuilt ASC");
    query.exec();

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");

    //This loop is intended to extract data from the database.
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

//This function displays a list of computers in a descending order by if they were created or not.
vector<Computer> DataLayer::ComputerWasBuiltDESC()
{
    vector<Computer> myVector;
    QSqlQuery query;
    query.prepare("Select * From computer ORDER BY wasbuilt DESC");
    query.exec();

    int idNames = query.record().indexOf("ID");
    int idName = query.record().indexOf("name");
    int idName1 = query.record().indexOf("type");
    int idName2 = query.record().indexOf("yearBuilt");
    int idName3 = query.record().indexOf("wasbuilt");

    //This loop is intended to extract data from the database.
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

//Function to display images in advanced search (We are sorry about the vocabulary)
QByteArray DataLayer::inputPicture(QByteArray bit)
{
    QByteArray fuck;
    return fuck;
}
