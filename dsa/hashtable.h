#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "book.h"
#include <QString>

// ============================================================
//  HashTable — fixed-size array of buckets with chaining
//
//  Concept:
//    isbn → hash() → index 0..TABLE_SIZE-1
//    Each bucket is a linked chain of HashNodes (for collisions)
//
//    index 0 → [node] → [node] → nullptr
//    index 1 → nullptr
//    index 2 → [node] → nullptr
//    ...
//
//  Average case: O(1) insert, lookup, delete
//  Worst case (all collide): O(n) — but rare with a good hash
//
//  We store Book POINTERS — the LinkedList owns the actual Book
//  objects. HashTable is purely an index for fast lookup.
//  NEVER delete a Book through the HashTable.
// ============================================================

// Tune this for your expected catalogue size.
// Prime numbers reduce collision clustering.
static const int TABLE_SIZE = 101;

// ============================================================
//  HashNode — one entry in a bucket's chain
// ============================================================
struct HashNode {
    QString isbn;       // key
    Book*   book;       // pointer to the actual Book (not owned here)
    HashNode* next;     // next node in the same bucket (chaining)

    HashNode(const QString& isbn, Book* book)
        : isbn(isbn), book(book), next(nullptr) {}
};

// ============================================================
//  HashTable class
// ============================================================
class HashTable {
public:

    HashTable();    // initialise all bucket slots to nullptr
    ~HashTable();   // delete HashNodes only (NOT the Books they point to)

    // Insert a Book pointer under its ISBN key.
    // Returns false if ISBN is already present.
    bool insert(Book* book);

    // Look up a Book by ISBN. Returns nullptr if not found.
    Book* search(const QString& isbn) const;

    // Remove the entry for this ISBN from the table.
    // Does NOT delete the Book object itself.
    // Returns false if not found.
    bool remove(const QString& isbn);

    // For debugging / visualisation: returns how many
    // entries are stored in total across all buckets.
    int getCount() const;

private:

    HashNode* table[TABLE_SIZE];   // raw array of bucket heads
    int       count;               // total entries stored

    // Hash function: maps an ISBN string → 0..TABLE_SIZE-1
    // Uses polynomial rolling hash (classic and beginner-readable)
    int hash(const QString& isbn) const;
};

#endif // HASHTABLE_H
