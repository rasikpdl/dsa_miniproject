#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "book.h"
#include <QString>


static const int TABLE_SIZE = 101;

//  HashNode — one entry in a bucket's chain
struct HashNode {
    QString isbn;       // key
    Book*   book;       // pointer to the actual Book (not owned here)
    HashNode* next;     // next node in the same bucket (chaining)

    HashNode(const QString& isbn, Book* book)
        : isbn(isbn), book(book), next(nullptr) {}
};

//  HashTable class
class HashTable {
public:

    HashTable();    // initialise all bucket slots to nullptr
    ~HashTable();   // delete HashNodes only (NOT the Books they point to)

    // Insert a Book pointer under its ISBN key.
    bool insert(Book* book);

    // Look up a Book by ISBN. Returns nullptr if not found.
    Book* search(const QString& isbn) const;

    // Remove the entry for this ISBN from the table.
    bool remove(const QString& isbn);

    // entries are stored in total across all buckets.
    int getCount() const;

private:

    HashNode* table[TABLE_SIZE];   // raw array of bucket heads
    int       count;               // total entries stored
    int hash(const QString& isbn) const;
};

#endif // HASHTABLE_H
