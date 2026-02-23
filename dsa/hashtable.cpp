#include "hashtable.h"

// ============================================================
//  Constructor â€” set every bucket slot to nullptr
// ============================================================
HashTable::HashTable() : count(0)
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

// ============================================================
//  Destructor â€” delete HashNodes only, NOT the Book objects
//
//  Remember: HashTable is an INDEX. The LinkedList owns the Books.
//  Deleting Books here would cause double-free crashes.
// ============================================================
HashTable::~HashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* current = table[i];
        while (current != nullptr) {
            HashNode* next = current->next;
            delete current;     // delete the node wrapper
            current = next;
        }
        table[i] = nullptr;
    }
}

// ============================================================
//  hash â€” polynomial rolling hash
//
//  How it works:
//    Treat each character as a number (its Unicode value).
//    Accumulate: hash = hash * 31 + char_value
//    Then mod by TABLE_SIZE to fit in the array.
//
//  Why 31? It's prime, which spreads values well and is fast
//  to compute. Used by Java's String.hashCode() too.
//
//  Example: "978-0" â†’ some index between 0 and 100
// ============================================================
int HashTable::hash(const QString& isbn) const
{
    long long hashValue = 0;
    for (QChar ch : isbn) {
        hashValue = hashValue * 31 + ch.unicode();
        hashValue %= TABLE_SIZE;   // keep it in range at each step
        // prevents overflow on long strings
    }
    return static_cast<int>(hashValue);
}

// ============================================================
//  insert â€” add Book* to the table under its ISBN
//
//  Steps:
//    1. Compute bucket index via hash()
//    2. Walk the chain to check for duplicate ISBN
//    3. Prepend new HashNode at the bucket head (O(1) insert)
//
//  Why prepend? Appending would need a walk to the tail.
//  For a hash table index, insertion order doesn't matter.
// ============================================================
bool HashTable::insert(Book* book)
{
    if (book == nullptr) return false;

    int index = hash(book->isbn);

    // Step 2 â€” duplicate check in this bucket
    HashNode* current = table[index];
    while (current != nullptr) {
        if (current->isbn == book->isbn) {
            return false;   // already indexed
        }
        current = current->next;
    }

    // Step 3 â€” prepend at bucket head
    HashNode* newNode = new HashNode(book->isbn, book);
    newNode->next  = table[index];
    table[index]   = newNode;
    count++;
    return true;
}

// ============================================================
//  search â€” find Book by ISBN   average O(1)
// ============================================================
Book* HashTable::search(const QString& isbn) const
{
    int index = hash(isbn);
    HashNode* current = table[index];

    while (current != nullptr) {
        if (current->isbn == isbn) {
            return current->book;   // found
        }
        current = current->next;
    }

    return nullptr;   // not found
}

// ============================================================
//  remove â€” unlink and delete the HashNode for this ISBN
//
//  Same previous-pointer technique as LinkedList::removeBook().
//  Does NOT touch the Book object itself.
// ============================================================
bool HashTable::remove(const QString& isbn)
{
    int index = hash(isbn);
    HashNode* current = table[index];
    HashNode* prev    = nullptr;

    while (current != nullptr) {
        if (current->isbn == isbn) {

            if (prev == nullptr) {
                // removing the head of this bucket
                table[index] = current->next;
            } else {
                prev->next = current->next;
            }

            delete current;   // free the HashNode wrapper only
            count--;
            return true;
        }
        prev    = current;
        current = current->next;
    }

    return false;   // ISBN not in table
}

// ============================================================
//  getCount
// ============================================================
int HashTable::getCount() const { return count; }
