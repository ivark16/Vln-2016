#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QDialog>

namespace Ui
{
class HelpWindow;
}

class HelpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HelpWindow(QWidget *parent = 0);
    ~HelpWindow();
    void on_HelpWindow_accepted();
    void on_pushButton_clicked();

private slots:

private:
    Ui::HelpWindow *ui;
};

#endif // HELPWINDOW_H
