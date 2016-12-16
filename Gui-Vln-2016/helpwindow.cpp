#include "helpwindow.h"
#include "ui_helpwindow.h"

HelpWindow::HelpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
    //get rid of the default question mark button
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

HelpWindow::~HelpWindow()
{
    delete ui;
}

void HelpWindow::on_HelpWindow_accepted()
{

}

