#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scientist.h"
#include "listservices.h"
#include <vector>
#include <QMainWindow>
#include <string>
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

private:
    Ui::MainWindow *ui;
    void displayAllScientists();
    void displayScientist (vector <Scientist> scientists);

    listServices scientistService;
};

#endif // MAINWINDOW_H
