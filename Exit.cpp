

#include "Exit.h"
#include "Process.h"
#include "Simulation.h"

Exit::Exit(int eventTime, Process *theProcess, Simulation *sim) : Event(eventTime, theProcess, sim) {}

void Exit::handleEvent() {
    getProcess()->setEndTime(getEventTime()); // records the exit time
    sim->addToProcesses(getProcess());   // adds in the completed process queue
}