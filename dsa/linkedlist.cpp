#include "linkedlist.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
    head=NULL;
}

void LinkedList::insertBook(int id,string title,string author)
{
    Book* newBook=new Book{id,title,author,false,NULL};

    if(!head)
    {
        head=newBook;
        return;
    }

    Book* temp=head;
    while(temp->next)
        temp=temp->next;

    temp->next=newBook;
}

Book* LinkedList::searchBook(int id)
{
    Book* temp=head;
    while(temp)
    {
        if(temp->id==id)
            return temp;
        temp=temp->next;
    }
    return NULL;
}

void LinkedList::displayBooks()
{
    Book* temp=head;
    while(temp)
    {
        cout<<temp->id<<" "<<temp->title<<" "<<temp->author<<endl;
        temp=temp->next;
    }
}
