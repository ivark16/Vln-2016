#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scientist.h"
#include "listservices.h"
#include "editscientist.h"
#include "helpwindow.h"
#include "computer.h"
#include "connection.h"
#include "searching.h"
#include "editcomputer.h"
#include "connectiontable.h"
#include <vector>
#include <QMainWindow>
#include <string>
#include <cstdlib>
#include <QMediaPlayer>
#include <QMediaPlaylist>



using namespace std;

namespace Ui
{
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
    void on_pushButtonEditScientist_clicked();
    void on_pushButtonDeleteScientist_clicked();
    void on_lineEditScientist_textChanged(const QString &arg1);

    void on_pushButtonAddScientist_clicked();

    //void on_pushButtonSearchConnection_clicked();
    void on_pushButtonAddConnection_clicked();
    void on_pushButtonDeleteConnection_clicked();
    void on_tableWidgetConnection_clicked(const QModelIndex &index);

    void on_tableWidget_clicked(const QModelIndex &index);
    void on_lineEdit_textChanged(const QString &arg1);
    void on_lineEditComputer_textChanged(const QString &arg1);

    void on_pushButtonDeleteComputer_clicked();

    void on_actionHelp_triggered();
    void on_addComputers_clicked();

    void on_pushButtonAscending_clicked();
    void on_pushButtonDescending_clicked();

    void on_pushButtonEditComputers_clicked();

    void on_pushButtonAscendingComputer_clicked();
    void on_pushButtonDescendingComputer_clicked();

    void on_pushButtonAscendingConnection_clicked();
    void on_pushButtonDesendingConnection_clicked();

    void on_lineEditSearchConnection_textChanged(const QString &arg1);

    void on_pushButtonAdvancedSearchScientist_clicked();

    void playMusic(bool checkStatus);
    void on_playAudio_clicked();

private:
    Ui::MainWindow *ui;
    void displayAllScientists();
    void displayScientist (vector <Scientist> scientists);

    void displayAllComputer();
    void displayComputer (vector<Computer> computers);

    void displayAllConnections();
    void displayConnection(vector<searching> connections);

    vector<Scientist> currentlyDisplayScientist;
    vector<Computer> currentlyDisplayComputer;
    vector<searching> currentlyDisplayConnection;


    listServices scientistService;
    editscientist _edit;
    editcomputer _editComputer;

    QMediaPlaylist *_sweetPlaylist = new QMediaPlaylist();
    QMediaPlayer *_sweetMusic = new QMediaPlayer();



};

#endif // MAINWINDOW_H
