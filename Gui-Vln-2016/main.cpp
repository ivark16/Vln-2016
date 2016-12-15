#include "login.h"
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMessageBox msgBox;

    MainWindow w;
    w.show();

    login log;
    if (log.exec() != QDialog::Accepted)
    {
        a.quit();
    }
    else
    {
        a.exec();
    }
    return 0;
}
