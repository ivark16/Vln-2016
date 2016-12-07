#include "consoleui.h"
#include "DataLayer.h"
using namespace std;

    static const QString path = "Scientists.db";

int main(int argc, char *argv[])
{
    //consoleUI Master;
    //Master.run();

    QCoreApplication a(argc, argv);

    DataLayer db;

    //db.readAllDataFromSearchingDatabse();
    //db.readAllFromScientistsDataBase();
    //db.searchForNameFromDatabase("Clifford");

    /*if (db.deleteFunction("Ivar"))

    {
        cout << "Person deleted" << endl;
    } else {
        cout  << endl << "Fail" << endl;
    }

    if (db.addFunction("anna", "Kristjansson", 'M', "Icelandic", 1995, 2000, 1999))
    {
        cout << "Person added to database" << endl;
    } else {
        cout << "add function failed" << endl;
    }*/

    //db.readInAlphabeticalOrder();

    //db.readInOldestOrder();
    //cout << endl << endl;
    //db.readInYoungestOrder();

    //db.readInAlphabeticalOrderComputer();

    if (db.addFunctionComputer("bla", "Electronic", 1956 , false))
    {
        cout << "Computer added to database" << endl;
    } else {
        cout << "add function failed" << endl;
    }

    db.deleteFunctionComputer("bla");

    return 0;
}
