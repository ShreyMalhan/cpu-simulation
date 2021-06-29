

#pragma once
#include "SuperQueue.h"

class PriorityQueue : public SuperQueue{

public:

    PriorityQueue();
    virtual void enqueue(ListItem *item);

}; // class PriorityQueue

