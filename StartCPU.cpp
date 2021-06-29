
#include "CompleteCPU.h"
#include "StartCPU.h"
#include "Simulation.h"
#include "Timeout.h"


StartCPU::StartCPU(int eventTime, Process* theProcess, Simulation* sim) : Event(eventTime, theProcess, sim) {}


void StartCPU::handleEvent() {
    // process starts execution and either gets timed out or complete the burst.
    // if remaining burst - time slice > 0 then process times out else complete CPU

    if(getProcess()->getRemainingBurst() - sim->getTimeSlice() > 0){
        cout<<"Time:    " << getEventTime() << ": Process    " << getProcess()->getProcessID() << " begins CPU burst(will time out)" << endl;

        Timeout* timeOut = new Timeout(getEventTime() + sim->getTimeSlice(), getProcess(), sim);
        sim->addToEventQueue(timeOut);
    }else{
        // call completeCPU
        cout<<"Time:    " << getEventTime() << ": Process    " << getProcess()->getProcessID() << " begins CPU burst" << endl;
        CompleteCPU* completeCpu = new CompleteCPU(getEventTime()+getProcess()->getRemainingBurst(), getProcess(), sim);
        sim->addToEventQueue(completeCpu);
    }
}