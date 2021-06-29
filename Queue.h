
#pragma once
#include "SuperQueue.h"

class Queue : public SuperQueue{

public:

    Queue();

    virtual void enqueue(ListItem *item);

}; // class Queue/
