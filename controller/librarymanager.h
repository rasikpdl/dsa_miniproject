#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include "../dsa/linkedlist.h"
#include "../dsa/queue.h"
#include "../dsa/hashtable.h"
#include <QString>
#include <QList>

struct OperationResult {
    bool    success;
    QString message;
};

class LibraryManager {
public:

    LibraryManager();
    ~LibraryManager();

    //  Book Management

    // Add a brand-new book to the catalogue.
    OperationResult addBook(const QString& title,
                            const QString& author,
                            const QString& isbn);

    // Issue a book to a borrower.
    OperationResult issueBook(const QString& isbn,
                              const QString& borrowerName);

    // Return a book. If someone is queued for it,
    OperationResult returnBook(const QString& isbn);

    // Permanently remove a book from the system.
    OperationResult deleteBook(const QString& isbn);

    //  Search

    // Fast O(1) lookup via HashTable.
    QString searchByISBN(const QString& isbn) const;

    // O(n) scan via LinkedList
    QString searchByTitle(const QString& title) const;


    //  Display helpers for UI population

    // Returns all books as display strings
    QList<QString> getAllBooksDisplay() const;

    // Returns all waiting-list entries as display strings.
    QList<QString> getWaitingListDisplay() const;

    // Summary counts for a status bar or dashboard labels.
    int totalBooks()     const;
    int issuedBooks()    const;
    int waitingEntries() const;

private:

    LinkedList* bookList;       // owns all Book objects
    Queue*      waitingList;    // waiting queue
    HashTable*  searchIndex;    // fast ISBN lookup index

    // Internal helper: formats one Book* into a display string.
    QString formatBook(Book* book) const;
};

#endif // LIBRARYMANAGER_H
