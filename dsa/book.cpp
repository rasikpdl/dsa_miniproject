#include "book.h"

//  Book Constructor
//  Initialises every field so no garbage values exist.
Book::Book(const QString& title,
           const QString& author,
           const QString& isbn)
    : title(title),
    author(author),
    isbn(isbn),
    isIssued(false),   // new books start as available
    next(nullptr)      // not linked to anything yet
{
}

//  toDisplayString :Produces a single line suitable for a QListWidget or label.
//  Example output:
//    "[AVAILABLE] The Alchemist â€” Paulo Coelho (ISBN: 978)"

QString Book::toDisplayString() const
{
    QString status = isIssued ? "[ISSUED]   " : "[AVAILABLE]";
    return status + " " + title + " â€” " + author + " (ISBN: " + isbn + ")";
}
