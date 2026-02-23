#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "book.h"
#include <QList>
#include <QString>

class LinkedList {
public:

    LinkedList();   // sets head = nullptr, size = 0
    ~LinkedList();  // deletes every node to prevent memory leak

    // Creates a new Book and appends it to the tail.
    bool addBook(const QString& title,
                 const QString& author,
                 const QString& isbn);

    // Finds and removes the book with the given ISBN.
    bool removeBook(const QString& isbn);

    // Returns a pointer to the Book with matching ISBN, or nullptr.
    Book* findByISBN(const QString& isbn) const;

    // Returns a pointer to the FIRST book whose title matches
    Book* findByTitle(const QString& title) const;

    // Walks the list and collects every Book* into the QList.
    QList<Book*> getAllBooks() const;

    // Returns the current number of books in the list.
    int getSize() const;

    // Returns true if the list has no books.
    bool isEmpty() const;

private:
    Book* head;   // first node; nullptr when list is empty
    int   size;   // tracked manually — no .size() call needed
};

#endif // LINKEDLIST_H
