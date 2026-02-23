#include "hashtable.h"

//  Constructor â€” set every bucket slot to nullptr
HashTable::HashTable() : count(0)
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

//  Destructor â€” delete HashNodes only, NOT the Book objects
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

//  hash â€” polynomial rolling hash
int HashTable::hash(const QString& isbn) const
{
    long long hashValue = 0;
    for (QChar ch : isbn) {
        hashValue = hashValue * 31 + ch.unicode();
        hashValue %= TABLE_SIZE;   // keep it in range at each step
    }
    return static_cast<int>(hashValue);
}

//  insert â€” add Book* to the table under its ISBN
bool HashTable::insert(Book* book)
{
    if (book == nullptr) return false;

    int index = hash(book->isbn);

    //  â€” duplicate check in this bucket
    HashNode* current = table[index];
    while (current != nullptr) {
        if (current->isbn == book->isbn) {
            return false;   // already indexed
        }
        current = current->next;
    }

    //  â€” prepend at bucket head
    HashNode* newNode = new HashNode(book->isbn, book);
    newNode->next  = table[index];
    table[index]   = newNode;
    count++;
    return true;
}

//  search â€” find Book by ISBN   average O(1)
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


//  remove â€” unlink and delete the HashNode for this ISBN
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

//  getCount
int HashTable::getCount() const { return count; }
