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
    return 0;
}
