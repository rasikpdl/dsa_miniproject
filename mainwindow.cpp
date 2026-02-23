#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new LibraryManager();

    // ── Apply the global dark stylesheet ─────────────────────
    this->setStyleSheet(

        /* Base */
        "QWidget {"
        "  background-color: #0f0f0f;"
        "  color: #e0d8cc;"
        "  font-family: Consolas, Menlo, Monospace;"
        "  font-size: 10pt;"
        "  border: none;"
        "}"

        /* Input Fields */
        "QLineEdit {"
        "  background-color: #0a0a0a;"
        "  color: #e0d8cc;"
        "  border: 1px solid #252525;"
        "  border-radius: 3px;"
        "  padding: 5px 10px;"
        "  selection-background-color: #c8a96e;"
        "  selection-color: #000000;"
        "}"
        "QLineEdit:focus {"
        "  border: 1px solid #c8a96e;"
        "}"

        /* Buttons base */
        "QPushButton {"
        "  background-color: transparent;"
        "  color: #e0d8cc;"
        "  border: 1px solid #252525;"
        "  border-radius: 3px;"
        "  padding: 6px 14px;"
        "}"
        "QPushButton:hover {"
        "  background-color: #1a1a1a;"
        "  border-color: #3a3a3a;"
        "}"
        "QPushButton:pressed {"
        "  background-color: #111111;"
        "}"
        "QPushButton:disabled {"
        "  color: #333333;"
        "  border-color: #1a1a1a;"
        "}"

        /* List Widget */
        "QListWidget {"
        "  background-color: #0f0f0f;"
        "  border: 1px solid #1a1a1a;"
        "  border-radius: 3px;"
        "  outline: none;"
        "  padding: 4px;"
        "}"
        "QListWidget::item {"
        "  background-color: #161616;"
        "  border: 1px solid #1e1e1e;"
        "  border-radius: 3px;"
        "  padding: 10px 14px;"
        "  margin-bottom: 4px;"
        "  color: #e0d8cc;"
        "}"
        "QListWidget::item:selected {"
        "  background-color: #1e1e1e;"
        "  border: 1px solid #c8a96e;"
        "  color: #e0d8cc;"
        "}"
        "QListWidget::item:hover {"
        "  background-color: #1a1a1a;"
        "  border-color: #2e2e2e;"
        "}"

        /* Scrollbar */
        "QScrollBar:vertical {"
        "  background: transparent;"
        "  width: 6px;"
        "  margin: 0;"
        "}"
        "QScrollBar::handle:vertical {"
        "  background: #2a2a2a;"
        "  border-radius: 3px;"
        "  min-height: 30px;"
        "}"
        "QScrollBar::handle:vertical:hover {"
        "  background: #3a3a3a;"
        "}"
        "QScrollBar::add-line:vertical,"
        "QScrollBar::sub-line:vertical {"
        "  height: 0px;"
        "}"

        /* Labels */
        "QLabel {"
        "  color: #888888;"
        "  font-size: 9pt;"
        "}"

        /* Tooltip */
        "QToolTip {"
        "  background-color: #161616;"
        "  color: #e0d8cc;"
        "  border: 1px solid #252525;"
        "  padding: 4px 8px;"
        "  border-radius: 2px;"
        "  font-size: 9pt;"
        "}"
        );

    // ── Individual button colours ─────────────────────────────
    ui->addBookBtn->setStyleSheet(
        "QPushButton { border-color: #6ec87a; color: #6ec87a; }"
        "QPushButton:hover { background-color: rgba(110,200,122, 30); }"
        );
    ui->issueBookBtn->setStyleSheet(
        "QPushButton { border-color: #c8a96e; color: #c8a96e; }"
        "QPushButton:hover { background-color: rgba(200,169,110, 30); }"
        );
    ui->returnBookBtn->setStyleSheet(
        "QPushButton { border-color: #6e9ec8; color: #6e9ec8; }"
        "QPushButton:hover { background-color: rgba(110,158,200, 30); }"
        );
    ui->deleteBookBtn->setStyleSheet(
        "QPushButton { border-color: #c86e6e; color: #c86e6e; }"
        "QPushButton:hover { background-color: rgba(200,110,110, 30); }"
        );
    ui->searchISBNBtn->setStyleSheet(
        "QPushButton { border-color: #333333; color: #888888; }"
        "QPushButton:hover { background-color: #1a1a1a; color: #e0d8cc; }"
        );
    ui->searchTitleBtn->setStyleSheet(
        "QPushButton { border-color: #333333; color: #888888; }"
        "QPushButton:hover { background-color: #1a1a1a; color: #e0d8cc; }"
        );
    ui->showWaitingBtn->setStyleSheet(
        "QPushButton { border-color: #c8b96e; color: #c8b96e; }"
        "QPushButton:hover { background-color: rgba(200,185,110, 30); }"
        );

    // ── Status label default style ────────────────────────────
    ui->statusLabel->setStyleSheet(
        "QLabel {"
        "  color: #555555;"
        "  border: 1px solid #1a1a1a;"
        "  border-left: 3px solid #333333;"
        "  padding: 8px 12px;"
        "  border-radius: 3px;"
        "  font-size: 10pt;"
        "}"
        );

    refreshBookList();
}

void MainWindow::setStatus(const QString& msg, const QString& type)
{
    ui->statusLabel->setText(msg);

    // Choose border + text colour based on type
    QString colour;
    if      (type == "success") colour = "#6ec87a";   // green
    else if (type == "error")   colour = "#c86e6e";   // red
    else if (type == "info")    colour = "#6e9ec8";   // blue
    else if (type == "warning") colour = "#c8b96e";   // amber
    else                        colour = "#555555";   // default muted

    ui->statusLabel->setStyleSheet(
        "QLabel {"
        "  color: " + colour + ";"
                   "  border: 1px solid #1a1a1a;"
                   "  border-left: 3px solid " + colour + ";"
                   "  background-color: transparent;"
                   "  padding: 8px 12px;"
                   "  border-radius: 3px;"
                   "  font-size: 10pt;"
                   "  text-transform: none;"  /* override label uppercase rule */
                   "}"
        );
}

MainWindow::~MainWindow()
{
    delete manager;
    delete ui;
}

void MainWindow::on_addBookBtn_clicked()
{
    OperationResult r = manager->addBook(
        ui->titleInput->text(),
        ui->authorInput->text(),
        ui->isbnInput->text()
        );
    setStatus(r.message, r.success ? "success" : "error");
    if (r.success) {
        ui->titleInput->clear();
        ui->authorInput->clear();
        ui->isbnInput->clear();
        refreshBookList();
    }
}


void MainWindow::on_issueBookBtn_clicked()
{
    OperationResult r = manager->issueBook(
        ui->isbnInput->text(),
        ui->borrowerInput->text()
        );
   setStatus(r.message, r.success ? "success" : "warning");
    if (r.success) refreshBookList();
}


void MainWindow::on_returnBookBtn_clicked()
{
    OperationResult r = manager->returnBook(ui->isbnInput->text());
   setStatus(r.message, r.success ? "info" : "error");
    if (r.success) refreshBookList();
}


void MainWindow::on_searchISBNBtn_clicked()
{
    setStatus(manager->searchByISBN(ui->isbnInput->text()), "info");
}


void MainWindow::on_searchTitleBtn_clicked()
{
     setStatus(manager->searchByTitle(ui->titleInput->text()), "info");
}



void MainWindow::on_showWaitingBtn_clicked()
{
    ui->bookListWidget->clear();
    for (const QString& entry : manager->getWaitingListDisplay()) {
        ui->bookListWidget->addItem(entry);
    }
}
// Private helper — refreshes the book list widget
void MainWindow::refreshBookList()
{
    // Clear and repopulate the list
    ui->bookListWidget->clear();
    for (const QString& line : manager->getAllBooksDisplay()) {
        ui->bookListWidget->addItem(line);
    }

    // Update stat labels
    int total   = manager->totalBooks();
    int issued  = manager->issuedBooks();
    int avail   = total - issued;
    int waiting = manager->waitingEntries();

    ui->totalLabel->setText(
        ""
        + QString::number(total) + " Total");

    ui->issuedLabel->setText(
        ""
        + QString::number(issued) + " Issued");

    ui->waitingLabel->setText(
        ""
        + QString::number(waiting) + " Waiting");

    // Enable rich text on these labels
    ui->totalLabel->setTextFormat(Qt::RichText);
    ui->issuedLabel->setTextFormat(Qt::RichText);
    ui->waitingLabel->setTextFormat(Qt::RichText);
}
