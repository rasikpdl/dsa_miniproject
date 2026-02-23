/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_isbn;
    QLineEdit *isbnInput;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_title;
    QLineEdit *titleInput;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_author;
    QLineEdit *authorInput;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_borrower;
    QLineEdit *borrowerInput;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *addBookBtn;
    QPushButton *issueBookBtn;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *deleteBookBtn;
    QPushButton *returnBookBtn;
    QPushButton *searchTitleBtn;
    QPushButton *searchISBNBtn;
    QPushButton *showWaitingBtn;
    QLabel *statusLabel;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QLabel *waitingLabel;
    QLabel *totalLabel;
    QLabel *issuedLabel;
    QListWidget *bookListWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 600);
        MainWindow->setMinimumSize(QSize(900, 600));
        MainWindow->setMaximumSize(QSize(1100, 700));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #0f0f0f;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(20, 20, 686, 507));
        splitter->setOrientation(Qt::Orientation::Horizontal);
        widget = new QWidget(splitter);
        widget->setObjectName("widget");
        verticalLayout_8 = new QVBoxLayout(widget);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_isbn = new QLabel(widget);
        label_isbn->setObjectName("label_isbn");

        verticalLayout->addWidget(label_isbn);

        isbnInput = new QLineEdit(widget);
        isbnInput->setObjectName("isbnInput");
        isbnInput->setMinimumSize(QSize(0, 22));
        QFont font;
        font.setPointSize(10);
        isbnInput->setFont(font);
        isbnInput->setFrame(false);
        isbnInput->setReadOnly(false);

        verticalLayout->addWidget(isbnInput);


        verticalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_title = new QLabel(widget);
        label_title->setObjectName("label_title");

        verticalLayout_2->addWidget(label_title);

        titleInput = new QLineEdit(widget);
        titleInput->setObjectName("titleInput");
        titleInput->setMinimumSize(QSize(0, 22));
        titleInput->setFont(font);
        titleInput->setFrame(false);

        verticalLayout_2->addWidget(titleInput);


        verticalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_author = new QLabel(widget);
        label_author->setObjectName("label_author");

        verticalLayout_3->addWidget(label_author);

        authorInput = new QLineEdit(widget);
        authorInput->setObjectName("authorInput");
        authorInput->setMinimumSize(QSize(0, 22));
        authorInput->setFont(font);
        authorInput->setFrame(false);

        verticalLayout_3->addWidget(authorInput);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_borrower = new QLabel(widget);
        label_borrower->setObjectName("label_borrower");

        verticalLayout_4->addWidget(label_borrower);

        borrowerInput = new QLineEdit(widget);
        borrowerInput->setObjectName("borrowerInput");
        borrowerInput->setMinimumSize(QSize(0, 22));
        borrowerInput->setFont(font);
        borrowerInput->setFrame(false);

        verticalLayout_4->addWidget(borrowerInput);


        verticalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_7->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addBookBtn = new QPushButton(widget);
        addBookBtn->setObjectName("addBookBtn");
        addBookBtn->setMinimumSize(QSize(0, 34));
        addBookBtn->setFont(font);
        addBookBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addBookBtn->setStyleSheet(QString::fromUtf8("QPushButton { border-color: #6ec87a; color: #6ec87a; }\n"
"QPushButton:hover { background-color: rgba(110,200,122, 0.08); }"));

        horizontalLayout->addWidget(addBookBtn);

        issueBookBtn = new QPushButton(widget);
        issueBookBtn->setObjectName("issueBookBtn");
        issueBookBtn->setMinimumSize(QSize(0, 34));
        issueBookBtn->setFont(font);
        issueBookBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        issueBookBtn->setStyleSheet(QString::fromUtf8("QPushButton { border-color: #c8a96e; color: #c8a96e; }\n"
"QPushButton:hover { background-color: rgba(200,169,110, 0.08); }"));

        horizontalLayout->addWidget(issueBookBtn);


        verticalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        deleteBookBtn = new QPushButton(widget);
        deleteBookBtn->setObjectName("deleteBookBtn");
        deleteBookBtn->setMinimumSize(QSize(0, 34));
        deleteBookBtn->setFont(font);
        deleteBookBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        deleteBookBtn->setStyleSheet(QString::fromUtf8("QPushButton { border-color: #c86e6e; color: #c86e6e; }\n"
"QPushButton:hover { background-color: rgba(200,110,110, 0.08); }"));

        horizontalLayout_2->addWidget(deleteBookBtn);

        returnBookBtn = new QPushButton(widget);
        returnBookBtn->setObjectName("returnBookBtn");
        returnBookBtn->setMinimumSize(QSize(0, 34));
        returnBookBtn->setFont(font);
        returnBookBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        returnBookBtn->setStyleSheet(QString::fromUtf8("QPushButton { border-color: #6e9ec8; color: #6e9ec8; }\n"
"QPushButton:hover { background-color: rgba(110,158,200, 0.08); }"));

        horizontalLayout_2->addWidget(returnBookBtn);


        verticalLayout_6->addLayout(horizontalLayout_2);

        searchTitleBtn = new QPushButton(widget);
        searchTitleBtn->setObjectName("searchTitleBtn");
        searchTitleBtn->setMinimumSize(QSize(0, 34));
        searchTitleBtn->setFont(font);
        searchTitleBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout_6->addWidget(searchTitleBtn);

        searchISBNBtn = new QPushButton(widget);
        searchISBNBtn->setObjectName("searchISBNBtn");
        searchISBNBtn->setMinimumSize(QSize(0, 34));
        searchISBNBtn->setFont(font);
        searchISBNBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        searchISBNBtn->setStyleSheet(QString::fromUtf8("QPushButton { border-color: #333333; color: #888888; }\n"
"QPushButton:hover { background-color: #1a1a1a; color: #e0d8cc; }"));

        verticalLayout_6->addWidget(searchISBNBtn);

        showWaitingBtn = new QPushButton(widget);
        showWaitingBtn->setObjectName("showWaitingBtn");
        showWaitingBtn->setMinimumSize(QSize(0, 34));
        showWaitingBtn->setFont(font);
        showWaitingBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        showWaitingBtn->setStyleSheet(QString::fromUtf8("QPushButton { border-color: #c8b96e; color: #c8b96e; }\n"
"QPushButton:hover { background-color: rgba(200,185,110, 0.08); }"));

        verticalLayout_6->addWidget(showWaitingBtn);


        verticalLayout_7->addLayout(verticalLayout_6);


        verticalLayout_8->addLayout(verticalLayout_7);

        statusLabel = new QLabel(widget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setMinimumSize(QSize(0, 50));

        verticalLayout_8->addWidget(statusLabel);

        splitter->addWidget(widget);
        widget1 = new QWidget(splitter);
        widget1->setObjectName("widget1");
        verticalLayout_10 = new QVBoxLayout(widget1);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        waitingLabel = new QLabel(widget1);
        waitingLabel->setObjectName("waitingLabel");

        verticalLayout_9->addWidget(waitingLabel);

        totalLabel = new QLabel(widget1);
        totalLabel->setObjectName("totalLabel");

        verticalLayout_9->addWidget(totalLabel);

        issuedLabel = new QLabel(widget1);
        issuedLabel->setObjectName("issuedLabel");

        verticalLayout_9->addWidget(issuedLabel);


        verticalLayout_10->addLayout(verticalLayout_9);

        bookListWidget = new QListWidget(widget1);
        bookListWidget->setObjectName("bookListWidget");
        bookListWidget->setFont(font);
        bookListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        bookListWidget->setSpacing(4);
        bookListWidget->setUniformItemSizes(true);

        verticalLayout_10->addWidget(bookListWidget);

        splitter->addWidget(widget1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Library Management System", nullptr));
        label_isbn->setText(QCoreApplication::translate("MainWindow", "I S B N", nullptr));
        isbnInput->setText(QCoreApplication::translate("MainWindow", "ISBN NO:", nullptr));
        isbnInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "e. g.  978-0062315007", nullptr));
        label_title->setText(QCoreApplication::translate("MainWindow", "T I T L E", nullptr));
        titleInput->setText(QCoreApplication::translate("MainWindow", "titleInput", nullptr));
        titleInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "e. g.  The Alchemist", nullptr));
        label_author->setText(QCoreApplication::translate("MainWindow", "A U T H O R", nullptr));
        authorInput->setText(QCoreApplication::translate("MainWindow", "authorInput", nullptr));
        authorInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "e. g.  Paulo Coelho", nullptr));
        label_borrower->setText(QCoreApplication::translate("MainWindow", " B O R R O W E R N A M E", nullptr));
        borrowerInput->setText(QCoreApplication::translate("MainWindow", "borrowerInput", nullptr));
        borrowerInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "e. g.  Alice", nullptr));
        addBookBtn->setText(QCoreApplication::translate("MainWindow", "+ Add Book", nullptr));
        issueBookBtn->setText(QCoreApplication::translate("MainWindow", "\342\206\227 Issue Book", nullptr));
        deleteBookBtn->setText(QCoreApplication::translate("MainWindow", "\342\234\225 Delete Book", nullptr));
        returnBookBtn->setText(QCoreApplication::translate("MainWindow", "\342\206\231 Return Book", nullptr));
        searchTitleBtn->setText(QCoreApplication::translate("MainWindow", "\342\214\225 Search By Title", nullptr));
        searchISBNBtn->setText(QCoreApplication::translate("MainWindow", "\342\214\225 Search By ISBN", nullptr));
        showWaitingBtn->setText(QCoreApplication::translate("MainWindow", "\342\211\241 Waiting List", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "Ready. Fill in the fields and click an action  to proceed.", nullptr));
        waitingLabel->setText(QCoreApplication::translate("MainWindow", "waitingLabel", nullptr));
        totalLabel->setText(QCoreApplication::translate("MainWindow", "totalLabel", nullptr));
        issuedLabel->setText(QCoreApplication::translate("MainWindow", "issuedLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
