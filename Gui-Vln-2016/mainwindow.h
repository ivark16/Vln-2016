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

    //Edit, add and delete buttons for scientist
    void on_pushButtonEditScientist_clicked();
    void on_pushButtonDeleteScientist_clicked();
    void on_pushButtonAddScientist_clicked();

    //Displaying help window
    void on_actionHelp_triggered();

    //Add and delete buttons for connection
    void on_pushButtonAddConnection_clicked();
    void on_pushButtonDeleteConnection_clicked();

    //Clicking connnection in table
    void on_tableWidgetConnection_clicked(const QModelIndex &index);

    //Clicking scientist in table
    void on_tableWidget_clicked(const QModelIndex &index);

    //Clicking computer in table
    void on_tableWidget_2_clicked(const QModelIndex &index);

    //Searches scientists
    void on_lineEditScientist_textChanged(const QString &arg1);
    void on_lineEdit_textChanged(const QString &arg1);

    //Searches computer
    void on_lineEditComputer_textChanged(const QString &arg1);

    //Displays scientist in ascending or descending order when clicked
    void on_pushButtonAscending_clicked();
    void on_pushButtonDescending_clicked();

    //Edit, add and delete buttons for computer
    void on_pushButtonEditComputers_clicked();
    void on_pushButtonDeleteComputer_clicked();
    void on_addComputers_clicked();

    //Displays computer in ascending or descending order when clicked
    void on_pushButtonAscendingComputer_clicked();
    void on_pushButtonDescendingComputer_clicked();

    //Displays connection in ascending or descending order when clicked
    void on_pushButtonAscendingConnection_clicked();
    void on_pushButtonDesendingConnection_clicked();

    //Searches connection
    void on_lineEditSearchConnection_textChanged(const QString &arg1);

    //Plays music
    void playMusic(bool checkStatus);
    void on_playAudio_clicked();

    //void on_tableWidget_2_doubleClicked(const QModelIndex &index);
    void on_tableWidget_doubleClicked(const QModelIndex &index);

    //Push ASC and DESC buttons eneble/disable
    void on_comboBoxScientist_currentIndexChanged(const QString &arg1);
    void on_comboBoxComputer_currentIndexChanged(const QString &arg1);
    void on_comboBoxConnection_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    //Displaying scientist
    void displayAllScientists();
    void displayScientist (vector <Scientist> scientists);

    //Displaying computer
    void displayAllComputer();
    void displayComputer (vector<Computer> computers);

    //Displaying connections
    void displayAllConnections();
    void displayConnection(vector<searching> connections);

    //Currently displayed in tables
    vector<Scientist> currentlyDisplayScientist;
    vector<Computer> currentlyDisplayComputer;
    vector<searching> currentlyDisplayConnection;

    //For editing either connections, scientists or computers
    listServices scientistService;
    editscientist _edit;
    editcomputer _editComputer;
    ConnectionTable _connection;

    //For music
    QMediaPlaylist *_sweetPlaylist = new QMediaPlaylist();
    QMediaPlayer *_sweetMusic = new QMediaPlayer();
};

#endif // MAINWINDOW_H
