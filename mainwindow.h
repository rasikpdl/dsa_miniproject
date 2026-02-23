#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "controller/librarymanager.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    LibraryManager* manager;
    void refreshBookList();
};

#endif // MAINWINDOW_H
