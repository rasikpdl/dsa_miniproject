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

private slots:
    void on_addBookBtn_clicked();

    void on_issueBookBtn_clicked();

    void on_returnBookBtn_clicked();

    void on_searchISBNBtn_clicked();

    void on_searchTitleBtn_clicked();

    void on_showWaitingBtn_clicked();

private:
    Ui::MainWindow *ui;
    LibraryManager* manager;
    void refreshBookList();
    void setStatus(const QString& msg, const QString& type = "default");
};

#endif // MAINWINDOW_H
