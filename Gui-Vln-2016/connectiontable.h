#ifndef CONNECTIONTABLE_H
#define CONNECTIONTABLE_H
#include "connection.h"
#include "listservices.h"
#include <QPixmap>
#include <vector>
#include <QDialog>

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

private slots:
    void on_pushButtonAdvancedSearch_clicked();

private:
    Ui::ConnectionTable *ui;
    listServices _list;
};

#endif // CONNECTIONTABLE_H
