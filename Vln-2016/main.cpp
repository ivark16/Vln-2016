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

    if (db.deleteFunction("ABC"))
    {
        cout << "Person deleted" << endl;
    } else {
        cout  << endl << "Fail" << endl;
    }

    return 0;
}
