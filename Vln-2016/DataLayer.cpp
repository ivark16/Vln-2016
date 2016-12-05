#include "DataLayer.h"
#include <iostream>
#include <vector>
//#include <sqlite3.h>
//#include <sql.h>


ScientisListFromSQL::ScientisListFromSQL()
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection")) {
            db = QSqlDatabase::database("qt_sql_default_connection");
        } else {
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("PersonCompSci.sqlite");
            db.open();
        }
}

