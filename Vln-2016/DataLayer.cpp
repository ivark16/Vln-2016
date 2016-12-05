#include "DataLayer.h"
#include <iostream>
#include <vector>
//#include <sqlite3.h>
//#include <sql.h>


ScientisListFromSQL::ScientisListFromSQL()
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

