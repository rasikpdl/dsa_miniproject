#ifndef BOOK_H
#define BOOK_H

#include <QString>


class Book {
public:

    // Data Fields
    QString title;      // e.g. "The Alchemist"
    QString author;     // e.g. "Paulo Coelho"
    QString isbn;       // unique identifier, e.g. "978"
    bool    isIssued;   // true = checked out, false = available

    // LinkedList
    Book* next;         // pointer to the next book in the list

    // Constructor
    // Sets all fields and defaults isIssued = false, next = nullptr
    Book(const QString& title,
         const QString& author,
         const QString& isbn);

    // Returns a tidy one-line summary for display in the UI
    QString toDisplayString() const;
};

#endif // BOOK_H
