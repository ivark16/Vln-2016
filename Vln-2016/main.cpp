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
    db.readAllFromDataBase();
    db.searchForNameFromDatabase("Clifford");

    if (db.deleteFunction("Ivar"))
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
    }

    db.readInAlphabeticalOrder();

    return 0;
}
