#ifndef QUEUE_H
#define QUEUE_H

#include <QString>
struct QueueNode {
    QString borrowerName;   // person waiting
    QString isbn;           // book they are waiting for
    QueueNode* next;        // link to next person in line

    QueueNode(const QString& name, const QString& isbn)
        : borrowerName(name), isbn(isbn), next(nullptr) {}
};

class Queue {
public:

    Queue();    // front = rear = nullptr, size = 0
    ~Queue();   // deletes all remaining nodes

    // Add a person to the END of the waiting list.
    bool enqueue(const QString& borrowerName, const QString& isbn);

    // Remove and return the FRONT person from the waiting list.
    bool dequeue(QString& outBorrowerName, QString& outIsbn);

    // Peek at the front without removing — useful for display.
    bool peekFront(QString& outBorrowerName, QString& outIsbn) const;

    // Check how many people are waiting for a specific ISBN.
    int countWaitingFor(const QString& isbn) const;

    // Is the queue completely empty?
    bool isEmpty() const;

    // Total entries across all ISBNs.
    int getSize() const;

    // Returns all entries as formatted strings for UI display.
    QList<QString> getAllEntries() const;

private:
    QueueNode* front;   // dequeue from here
    QueueNode* rear;    // enqueue here
    int        size;
};

#endif // QUEUE_H
