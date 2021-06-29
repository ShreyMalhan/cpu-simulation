
#include "PriorityQueue.h"
#include "ListItem.h"
#include "Node.h"

/**** Queue implementation */
PriorityQueue::PriorityQueue() : SuperQueue() {}

void PriorityQueue::enqueue(ListItem *item) {
    Node* temp = new Node(item, nullptr);
    Node* curr = front;
    // special case: adding to empty queue
    if(front == nullptr){
        front = temp;
    }
    // Special case: the head of the list has lesser priority than the new node
    else if(getFront()->compareTo(item) > 0){
        temp->setNext(front);
        front = temp;
    }
    else{
        // find the correct position to insert by checking if the next item's priority.
        while(curr->getNext() != nullptr && curr->getNext()->getItem()->compareTo(item) < 0){
            curr = curr->getNext();
        }
        //inserting the node in the list
        temp->setNext(curr->getNext());
        curr->setNext(temp);
    }
    size++;
}// enqueue

