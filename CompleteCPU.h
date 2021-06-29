
#pragma once

#include "Event.h"

class CompleteCPU : public Event{
public:
    CompleteCPU(int, Process*, Simulation*);
    void handleEvent();
};
