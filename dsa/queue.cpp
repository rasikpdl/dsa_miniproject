#include "queue.h"
#include <QList>
Queue::Queue()
    : front(nullptr), rear(nullptr), size(0)
{
}

Queue::~Queue()
{
    QueueNode* current = front;
    while (current != nullptr) {
        QueueNode* next = current->next;
        delete current;
        current = next;
    }
    front = rear = nullptr;
    size = 0;
}

//  enqueue â€” add to the REAR   O(1)/
bool Queue::enqueue(const QString& borrowerName, const QString& isbn)
{
    // â€” duplicate check
    QueueNode* check = front;
    while (check != nullptr) {
        if (check->borrowerName == borrowerName && check->isbn == isbn) {
            return false;   // already in line for this book
        }
        check = check->next;
    }

    //  â€” allocate
    QueueNode* newNode = new QueueNode(borrowerName, isbn);

    //  â€” empty queue
    if (rear == nullptr) {
        front = rear = newNode;
        size++;
        return true;
    }

    // â€” attach at rear
    rear->next = newNode;
    rear       = newNode;
    size++;
    return true;
}

//  dequeue â€” remove from FRONT   O(1)
bool Queue::dequeue(QString& outBorrowerName, QString& outIsbn)
{
    if (front == nullptr) return false;   // empty

    // Capture data before deleting
    outBorrowerName = front->borrowerName;
    outIsbn         = front->isbn;

    QueueNode* toDelete = front;
    front = front->next;

    // If the queue is now empty, rear must also be reset
    if (front == nullptr) {
        rear = nullptr;
    }

    delete toDelete;
    size--;
    return true;
}


//  peekFront â€” look without removing
bool Queue::peekFront(QString& outBorrowerName, QString& outIsbn) const
{
    if (front == nullptr) return false;

    outBorrowerName = front->borrowerName;
    outIsbn         = front->isbn;
    return true;
}

//  countWaitingFor â€” walk and count entries matching an ISBN
int Queue::countWaitingFor(const QString& isbn) const
{
    int count = 0;
    QueueNode* current = front;
    while (current != nullptr) {
        if (current->isbn == isbn) count++;
        current = current->next;
    }
    return count;
}

//  isEmpty / getSize
bool Queue::isEmpty() const  { return size == 0; }
int  Queue::getSize()  const { return size; }

//  getAllEntries â€” build display strings for the UI
QList<QString> Queue::getAllEntries() const
{
    QList<QString> result;
    QueueNode* current = front;
    int position = 1;

    while (current != nullptr) {
        QString entry = QString::number(position) + ". "
                        + current->borrowerName
                        + " â€” waiting for ISBN: "
                        + current->isbn;
        result.append(entry);
        current = current->next;
        position++;
    }

    return result;
}
