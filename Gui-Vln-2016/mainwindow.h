#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scientist.h"
#include "listservices.h"
#include "computer.h"
#include <vector>
#include <QMainWindow>
#include <string>
#include <cstdlib>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_tableViewScientist_clicked(const QModelIndex &index);
    void on_tableWidget_2_clicked(const QModelIndex &index);
    void on_pushButtonSearchScientist_clicked();

private:
    Ui::MainWindow *ui;
    void displayAllScientists();
    void displayScientist (vector <Scientist> scientists);

    void displayAllComputer();
    void displayComputer (vector<Computer> computers);

    listServices scientistService;
};

#endif // MAINWINDOW_H
