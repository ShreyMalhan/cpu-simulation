
#pragma once
#include "Event.h"

class Arrival : public Event{
public:
    Arrival(int, Process*, Simulation*);
    void handleEvent();
};
