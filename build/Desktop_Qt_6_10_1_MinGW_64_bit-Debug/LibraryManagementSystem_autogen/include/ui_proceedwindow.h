/********************************************************************************
** Form generated from reading UI file 'proceedwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCEEDWINDOW_H
#define UI_PROCEEDWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Proceedwindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLabel *label;
    QTextEdit *textEdit;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Proceed;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *quitButton;
    QSpacerItem *horizontalSpacer;
    QFrame *headerFrame;
    QLabel *label_2;
    QLabel *label_3;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuLMS;

    void setupUi(QMainWindow *Proceedwindow)
    {
        if (Proceedwindow->objectName().isEmpty())
            Proceedwindow->setObjectName("Proceedwindow");
        Proceedwindow->resize(800, 606);
        centralwidget = new QWidget(Proceedwindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 160, 616, 354));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("color: gray;\n"
"font-size: 12px;"));

        verticalLayout->addWidget(label_4);

        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName("textEdit");
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName("checkBox");

        verticalLayout->addWidget(checkBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        Proceed = new QPushButton(widget);
        Proceed->setObjectName("Proceed");
        Proceed->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: palette(button-text);\n"
"    border: 1px solid rgba(128, 128, 128, 120); \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #28a745;\n"
"    color: white;\n"
"    border-color: #28a745;\n"
"}"));

        horizontalLayout->addWidget(Proceed);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        quitButton = new QPushButton(widget);
        quitButton->setObjectName("quitButton");
        quitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: palette(button-text);\n"
"    border: 1px solid rgba(128, 128, 128, 120);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #dc3545;\n"
"    color: white;\n"
"    border-color: #dc3545;\n"
"}"));

        horizontalLayout->addWidget(quitButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        headerFrame = new QFrame(centralwidget);
        headerFrame->setObjectName("headerFrame");
        headerFrame->setGeometry(QRect(60, 0, 611, 131));
        headerFrame->setStyleSheet(QString::fromUtf8("\n"
"background-color: #34495e;"));
        headerFrame->setFrameShape(QFrame::Shape::StyledPanel);
        headerFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(headerFrame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(120, 40, 481, 41));
        label_2->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 22px;\n"
"font-weight: bold;"));
        label_3 = new QLabel(headerFrame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 91, 101));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/lms.jpg")));
        label_3->setScaledContents(true);
        Proceedwindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Proceedwindow);
        statusbar->setObjectName("statusbar");
        Proceedwindow->setStatusBar(statusbar);
        menubar = new QMenuBar(Proceedwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuLMS = new QMenu(menubar);
        menuLMS->setObjectName("menuLMS");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        menuLMS->setFont(font1);
        Proceedwindow->setMenuBar(menubar);

        menubar->addAction(menuLMS->menuAction());

        retranslateUi(Proceedwindow);

        QMetaObject::connectSlotsByName(Proceedwindow);
    } // setupUi

    void retranslateUi(QMainWindow *Proceedwindow)
    {
        Proceedwindow->setWindowTitle(QCoreApplication::translate("Proceedwindow", "Proceedwindow", nullptr));
        label_4->setText(QCoreApplication::translate("Proceedwindow", "Please read and accept rules before proceeding!", nullptr));
        label->setText(QCoreApplication::translate("Proceedwindow", "Library Rules:", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Proceedwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1. A user can issue only one book at a time.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2. Book must be returned within 7 days.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3. If book is already issued, user will be added to waiting l"
                        "ist.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">4. Lost books must be reported.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">5. Misuse may suspend access.</p></body></html>", nullptr));
        checkBox->setText(QCoreApplication::translate("Proceedwindow", "I have read all the terms and conditions and agree to the above terms and conditions.", nullptr));
        Proceed->setText(QCoreApplication::translate("Proceedwindow", "Proceed", nullptr));
        quitButton->setText(QCoreApplication::translate("Proceedwindow", "Quit", nullptr));
        label_2->setText(QCoreApplication::translate("Proceedwindow", "Welcome to the Library Management System", nullptr));
        label_3->setText(QString());
        menuLMS->setTitle(QCoreApplication::translate("Proceedwindow", "Library  Management  System  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Proceedwindow: public Ui_Proceedwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCEEDWINDOW_H
