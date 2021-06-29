

#pragma once
class Node;
class ListItem;

class SuperQueue{
protected:
    Node *front;
    Node *back;
    int size;
public:
    SuperQueue();
    int getSize();
    bool isEmpty();
    virtual void enqueue(ListItem *item) = 0;
    ListItem *getFront();
    ListItem *dequeue();
};
