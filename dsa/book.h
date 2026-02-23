#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

struct Book
{
    int id;
    string title;
    string author;
    bool issued;
    Book* next;
};

#endif
