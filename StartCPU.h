
#pragma once

#include "Event.h"

class StartCPU: public Event{

public:
    StartCPU(int, Process*, Simulation*);
    void handleEvent();
};
