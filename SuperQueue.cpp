

#include "SuperQueue.h"
#include "ListItem.h"
#include "Node.h"


SuperQueue::SuperQueue(): front(nullptr), back(nullptr), size(0) {}

int SuperQueue::getSize(){
    return size;
}
bool SuperQueue::isEmpty(){
    return size == 0;
}


ListItem *SuperQueue::dequeue(){
    ListItem *theItem = nullptr;
    Node *theNode = front;
    if(front != nullptr){
        theItem = front->getItem();
        // special case: removing last item
        if(size == 1){
            front = back = nullptr;
        } else {
            front = front->getNext();
        }
        size--;
        delete(theNode);
    }
    return theItem;
}// dequeue


ListItem *SuperQueue::getFront(){
    ListItem *theItem = nullptr;
    if(front != nullptr){
        theItem = front->getItem();
    }
    return theItem;
}// getFront
