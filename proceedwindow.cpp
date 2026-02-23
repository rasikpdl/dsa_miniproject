#include "proceedwindow.h"
#include "./ui_proceedwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>

Proceedwindow::Proceedwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Proceedwindow)
{
    ui->setupUi(this);
}

Proceedwindow::~Proceedwindow()
{
    delete ui;
}


void Proceedwindow::on_checkBox_stateChanged(int arg1)
{
    ui->Proceed->setEnabled(arg1 == Qt::Checked);
}


void Proceedwindow::on_Proceed_clicked()
{
    if(!ui->checkBox->isChecked())
    {
        QMessageBox::warning(this,"Warning","Please accept rules first.");
        return;
    }
    MainWindow *w = new MainWindow();
    w->show();
    this->close();
}


void Proceedwindow::on_quitButton_clicked()
{
QApplication::quit();
}

