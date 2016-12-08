#include "consoleui.h"
#include "DataLayer.h"
#include "ui.h"
using namespace std;

    static const QString path = "Scientists.db";

int main(int argc, char *argv[])
{
    //consoleUI Master;
    //Master.run();

    QCoreApplication a(argc, argv);

    DataLayer db;

    //db.readAllDataFromSearchingDatabse();

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


    //db.deleteFunctionComputer("bla");
    //db.checkInComputer("B");

    //db.searchForNameFromDatabase("ring");
    //db.readInReverseAlphabeticalOrder();
   // db.readInReverseAlphabeticalOrderComputer();
    ui Master;
    Master.run();

    return 0;
}
