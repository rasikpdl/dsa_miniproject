#include "librarymanager.h"

//  Constructor â€” create each DSA structure on the heap
LibraryManager::LibraryManager()
{
    bookList    = new LinkedList();
    waitingList = new Queue();
    searchIndex = new HashTable();
}
//  Destructor â€” delete DSA structures
LibraryManager::~LibraryManager()
{
    delete bookList;      // LinkedList destructor frees all Book nodes
    delete waitingList;   // Queue destructor frees all QueueNodes
    delete searchIndex;   // HashTable destructor frees all HashNodes
}

//  addBook
//
//  Must insert into BOTH LinkedList AND HashTable If either fails, we do not proceed.

OperationResult LibraryManager::addBook(const QString& title,
                                        const QString& author,
                                        const QString& isbn)
{
    // Validate inputs
    if (title.trimmed().isEmpty() || author.trimmed().isEmpty() || isbn.trimmed().isEmpty()) {
        return { false, "Error: Title, author, and ISBN cannot be empty." };
    }

    // Try to add to LinkedList (will reject duplicate ISBN)
    bool added = bookList->addBook(title.trimmed(), author.trimmed(), isbn.trimmed());
    if (!added) {
        return { false, "Error: A book with ISBN [" + isbn + "] already exists." };
    }

    // Retrieve the pointer just created and add to HashTable
    Book* newBook = bookList->findByISBN(isbn.trimmed());
    searchIndex->insert(newBook);

    return { true, "Success: \"" + title + "\" added to the catalogue." };
}

//  issueBook
OperationResult LibraryManager::issueBook(const QString& isbn,
                                          const QString& borrowerName)
{
    if (borrowerName.trimmed().isEmpty()) {
        return { false, "Error: Borrower name cannot be empty." };
    }

    // O(1) lookup via HashTable
    Book* book = searchIndex->search(isbn.trimmed());
    if (book == nullptr) {
        return { false, "Error: No book found with ISBN [" + isbn + "]." };
    }

    if (book->isIssued) {
        // Book is out â€” add to waiting queue
        bool queued = waitingList->enqueue(borrowerName.trimmed(), isbn.trimmed());
        if (!queued) {
            return { false, "Error: " + borrowerName + " is already in the waiting list for this book." };
        }
        int pos = waitingList->countWaitingFor(isbn.trimmed());
        return { true, "\"" + book->title + "\" is currently issued.\n"
                          + borrowerName + " added to waiting list (position " + QString::number(pos) + ")." };
    }

    // Book is available â€” issue it
    book->isIssued = true;
    return { true, "Success: \"" + book->title + "\" issued to " + borrowerName + "." };
}

//  returnBook
OperationResult LibraryManager::returnBook(const QString& isbn)
{
    Book* book = searchIndex->search(isbn.trimmed());
    if (book == nullptr) {
        return { false, "Error: No book found with ISBN [" + isbn + "]." };
    }

    if (!book->isIssued) {
        return { false, "Error: \"" + book->title + "\" is not currently issued." };
    }

    // Mark as returned
    book->isIssued = false;

    // Check the waiting queue for this specific ISBN
    QString nextBorrower = "";
    QString nextIsbn     = "";
    int     totalSize    = waitingList->getSize();
    bool    found        = false;

    for (int i = 0; i < totalSize; i++) {
        QString name, isbnOut;
        waitingList->dequeue(name, isbnOut);

        if (!found && isbnOut == isbn.trimmed()) {
            // This is the next person for this book
            nextBorrower = name;
            nextIsbn     = isbnOut;
            found        = true;
        } else {
            // Put everyone else back
            waitingList->enqueue(name, isbnOut);
        }
    }

    if (found) {
        // Auto-issue to the next borrower
        book->isIssued = true;
        return { true, "\"" + book->title + "\" returned.\n"
                                           "Automatically issued to next in queue: " + nextBorrower + "." };
    }

    return { true, "\"" + book->title + "\" returned successfully. Now available." };
}

//  deleteBook â€” remove from both LinkedList AND HashTable
OperationResult LibraryManager::deleteBook(const QString& isbn)
{
    Book* book = searchIndex->search(isbn.trimmed());
    if (book == nullptr) {
        return { false, "Error: No book found with ISBN [" + isbn + "]." };
    }

    if (book->isIssued) {
        return { false, "Error: Cannot delete \"" + book->title + "\" â€” it is currently issued." };
    }

    QString title = book->title;

    // Remove from HashTable first
    searchIndex->remove(isbn.trimmed());

    // Remove from LinkedList
    bookList->removeBook(isbn.trimmed());

    return { true, "\"" + title + "\" permanently removed from the catalogue." };
}

//  searchByISBN â€” O(1) via HashTable
QString LibraryManager::searchByISBN(const QString& isbn) const
{
    Book* book = searchIndex->search(isbn.trimmed());
    if (book == nullptr) {
        return "No book found with ISBN: " + isbn;
    }
    return formatBook(book);
}

//  searchByTitle â€” O(n) via LinkedList
QString LibraryManager::searchByTitle(const QString& title) const
{
    Book* book = bookList->findByTitle(title.trimmed());
    if (book == nullptr) {
        return "No book found with title: \"" + title + "\"";
    }
    return formatBook(book);
}

//  getAllBooksDisplay â€” for populating QListWidget in MainWindow
QList<QString> LibraryManager::getAllBooksDisplay() const
{
    QList<QString> display;
    QList<Book*> books = bookList->getAllBooks();

    for (Book* b : books) {
        display.append(formatBook(b));
    }

    if (display.isEmpty()) {
        display.append("No books in the catalogue yet.");
    }

    return display;
}

QList<QString> LibraryManager::getWaitingListDisplay() const
{
    QList<QString> entries = waitingList->getAllEntries();
    if (entries.isEmpty()) {
        entries.append("No one is currently on the waiting list.");
    }
    return entries;
}

//  Summary counters
int LibraryManager::totalBooks() const
{
    return bookList->getSize();
}

int LibraryManager::issuedBooks() const
{
    int count = 0;
    QList<Book*> books = bookList->getAllBooks();
    for (Book* b : books) {
        if (b->isIssued) count++;
    }
    return count;
}

int LibraryManager::waitingEntries() const
{
    return waitingList->getSize();
}

//  formatBook â€” internal helper for display strings
QString LibraryManager::formatBook(Book* book) const
{
    QString status = book->isIssued ? "[ISSUED]   " : "[AVAILABLE]";
    return status + " " + book->title
           + " | Author: " + book->author
           + " | ISBN: "   + book->isbn;
}
