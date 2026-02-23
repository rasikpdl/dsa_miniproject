#include "linkedlist.h"

//  Constructor â€” empty list
LinkedList::LinkedList()
    : head(nullptr), size(0)
{
}

//  Destructor â€” walk the list and delete every node keeping a current pointer, save next before  deleting.
LinkedList::~LinkedList()
{
    Book* current = head;

    while (current != nullptr) {
        Book* nextBook = current->next;  // save link before delete
        delete current;                  // free this node
        current = nextBook;              // move to saved next
    }

    head = nullptr;
    size = 0;
}

//  addBook â€” append to the TAIL of the list:So books display in insertion order oldest first.
bool LinkedList::addBook(const QString& title,
                         const QString& author,
                         const QString& isbn)
{
    // â€” duplicate check
    if (findByISBN(isbn) != nullptr) {
        return false;   // ISBN already exists
    }

    //  â€” allocate the new node
    Book* newBook = new Book(title, author, isbn);

    //  â€” empty list edge case
    if (head == nullptr) {
        head = newBook;
        size++;
        return true;
    }

    //  â€” walk to the last node
    Book* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newBook;   // attach at tail
    size++;
    return true;
}

//  removeBook â€” find by ISBN and unlink the node
bool LinkedList::removeBook(const QString& isbn)
{
    if (head == nullptr) return false;   // empty list

    // Special case: head is the target
    if (head->isbn == isbn) {
        Book* toDelete = head;
        head = head->next;       // move head forward
        delete toDelete;
        size--;
        return true;
    }

    //  General case: search from second node onwards
    Book* prev    = head;
    Book* current = head->next;

    while (current != nullptr) {
        if (current->isbn == isbn) {
            prev->next = current->next;  // bypass the target node
            delete current;
            size--;
            return true;
        }
        prev    = current;
        current = current->next;
    }

    return false;   // ISBN not found
}

//  findByISBN â€” O(n) linear search
Book* LinkedList::findByISBN(const QString& isbn) const
{
    Book* current = head;

    while (current != nullptr) {
        if (current->isbn == isbn) {
            return current;   // found
        }
        current = current->next;
    }

    return nullptr;   // not found
}

//  findByTitle â€” O(n) linear search, case-insensitive
Book* LinkedList::findByTitle(const QString& title) const
{
    Book* current = head;
    QString lowerTarget = title.toLower();

    while (current != nullptr) {
        if (current->title.toLower() == lowerTarget) {
            return current;
        }
        current = current->next;
    }

    return nullptr;
}

//  getAllBooks â€” collect all Book pointers for the UI
//  We return pointers (not copies) so the UI reflects live data.
//  The UI must NOT delete these â€” the list owns them.

QList<Book*> LinkedList::getAllBooks() const
{
    QList<Book*> result;
    Book* current = head;

    while (current != nullptr) {
        result.append(current);
        current = current->next;
    }

    return result;
}

//  getSize / isEmpty â€” simple accessors
int LinkedList::getSize() const
{
    return size;
}

bool LinkedList::isEmpty() const
{
    return size == 0;
}
