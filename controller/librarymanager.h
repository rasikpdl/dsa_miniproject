#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include "../dsa/linkedlist.h"
#include "../dsa/queue.h"
#include "../dsa/hashtable.h"
#include <QString>
#include <QList>

// ============================================================
//  LibraryManager — the single controller between UI and DSA
//
//  Architecture:
//    MainWindow  →  LibraryManager  →  LinkedList / Queue / HashTable
//
//  Rules:
//    * MainWindow NEVER touches DSA classes directly
//    * LibraryManager NEVER touches Qt UI classes (no QLabel, etc.)
//    * All results returned as QString / QList<QString> for UI to display
//
//  This class owns one instance of each DSA structure.
// ============================================================

// Simple struct to return rich results back to the UI
struct OperationResult {
    bool    success;    // did it work?
    QString message;    // human-readable feedback for the UI
};

class LibraryManager {
public:

    LibraryManager();
    ~LibraryManager();

    // --------------------------------------------------------
    //  Book Management
    // --------------------------------------------------------

    // Add a brand-new book to the catalogue.
    // Inserts into LinkedList + HashTable simultaneously.
    OperationResult addBook(const QString& title,
                            const QString& author,
                            const QString& isbn);

    // Issue a book to a borrower.
    // If book is already issued → auto-add borrower to waiting queue.
    OperationResult issueBook(const QString& isbn,
                              const QString& borrowerName);

    // Return a book. If someone is queued for it,
    // automatically re-issues to the next person.
    OperationResult returnBook(const QString& isbn);

    // Permanently remove a book from the system.
    OperationResult deleteBook(const QString& isbn);

    // --------------------------------------------------------
    //  Search
    // --------------------------------------------------------

    // Fast O(1) lookup via HashTable.
    // Returns a formatted string about the book, or an error message.
    QString searchByISBN(const QString& isbn) const;

    // O(n) scan via LinkedList (title search can't use hash easily).
    QString searchByTitle(const QString& title) const;

    // --------------------------------------------------------
    //  Display helpers for UI population
    // --------------------------------------------------------

    // Returns all books as display strings (for QListWidget).
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
