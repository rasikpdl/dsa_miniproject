#ifndef PROCEEDWINDOW_H
#define PROCEEDWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Proceedwindow;
}
QT_END_NAMESPACE

class Proceedwindow : public QMainWindow
{
    Q_OBJECT

public:
    Proceedwindow(QWidget *parent = nullptr);
    ~Proceedwindow();

private slots:

    void on_checkBox_stateChanged(int arg1);

    void on_Proceed_clicked();

    void on_quitButton_clicked();

private:
    Ui::Proceedwindow *ui;
};
#endif // PROCEEDWINDOW_H
