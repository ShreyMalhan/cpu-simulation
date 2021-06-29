
#pragma once

#include "Event.h"

class CompleteIO: public Event{
public:
    CompleteIO(int, Process*, Simulation*);
    void handleEvent();
};
