
#pragma once

#include "Event.h"

class Exit: public Event{
public:
    Exit(int, Process*, Simulation*);
    void handleEvent();
};

