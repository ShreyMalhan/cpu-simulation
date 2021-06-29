
#pragma once

#include "Event.h"

class Timeout: public Event{
public:
    Timeout(int, Process*, Simulation*);
    void handleEvent();
};
