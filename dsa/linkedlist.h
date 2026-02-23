#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "book.h"

class LinkedList
{
private:
    Book* head;

public:
    LinkedList();

    void insertBook(int id,string title,string author);
    Book* searchBook(int id);
    void displayBooks();
};

#endif
