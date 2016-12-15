#ifndef CONNECTIONTABLE_H
#define CONNECTIONTABLE_H
#include "connection.h"
#include "listservices.h"
#include <QPixmap>
#include <QByteArray>
#include <vector>
#include <QDialog>
#include <QFileDialog>

using namespace std;

namespace Ui
{
class ConnectionTable;
}

class ConnectionTable : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionTable(QWidget *parent = 0);
    ~ConnectionTable();
    //void on_pushButtonAdvancedSearch_clicked();
    void display(int id);

private slots:
    void on_pushButtonAdvancedSearch_clicked();

private:
    Ui::ConnectionTable *ui;
    int _id;
    listServices _list;
};

#endif // CONNECTIONTABLE_H
