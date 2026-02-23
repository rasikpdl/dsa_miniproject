#include "proceedwindow.h"
#include <QPalette>
#include <QFont>
#include <QColor>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //  Force the app-wide dark palette ──────────────────
    QPalette dark;
    dark.setColor(QPalette::Window,          QColor(15,  15,  15));
    dark.setColor(QPalette::WindowText,      QColor(224, 216, 204));
    dark.setColor(QPalette::Base,            QColor(10,  10,  10));
    dark.setColor(QPalette::AlternateBase,   QColor(22,  22,  22));
    dark.setColor(QPalette::Text,            QColor(224, 216, 204));
    dark.setColor(QPalette::Button,          QColor(22,  22,  22));
    dark.setColor(QPalette::ButtonText,      QColor(224, 216, 204));
    dark.setColor(QPalette::Highlight,       QColor(200, 169, 110));
    dark.setColor(QPalette::HighlightedText, QColor(0,   0,   0  ));
    dark.setColor(QPalette::ToolTipBase,     QColor(22,  22,  22));
    dark.setColor(QPalette::ToolTipText,     QColor(224, 216, 204));
    dark.setColor(QPalette::Mid,             QColor(37,  37,  37));
    dark.setColor(QPalette::Dark,            QColor(10,  10,  10));
    a.setPalette(dark);

    // ── Font ─────────────────────────────────────────────────
    QFont font("Consolas", 10);
    a.setFont(font);

    Proceedwindow w;
    w.show();
    return a.exec();
}
