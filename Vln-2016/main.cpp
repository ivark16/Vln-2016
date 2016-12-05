#include "consoleui.h"
#include "DataLayer.h"
using namespace std;

int main(int argc, char *argv[])
{
    //consoleUI Master;
    //Master.run();
    static const QString path = "Scientists.db";
    QCoreApplication a(argc, argv);

    DataLayer db(path);
    db.readAllFromDataBase();
    return 0;
}
