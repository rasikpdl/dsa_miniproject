#include "book.h"

//  Book Constructor
Book::Book(const QString& title,
           const QString& author,
           const QString& isbn)
    : title(title),
    author(author),
    isbn(isbn),
    isIssued(false),   // new books start as available
    next(nullptr)
{
}

//  toDisplayString :Produces a single line
//  Example : "[AVAILABLE] The Alchemist â€” Paulo Coelho (ISBN: 978)"

QString Book::toDisplayString() const
{
    QString status = isIssued ? "[ISSUED]   " : "[AVAILABLE]";
    return status + " " + title + " â€” " + author + " (ISBN: " + isbn + ")";
}
