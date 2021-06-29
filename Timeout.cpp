

#include "Timeout.h"
#include "Simulation.h"
#include "StartCPU.h"

Timeout::Timeout(int eventTime, Process *theProcess, Simulation *sim) : Event(eventTime, theProcess, sim){}

void Timeout::handleEvent() {

    // process goes to the end of CPU queue and wait for its turn again
    // also checks if another process needs to start execution


    // decrease the remaining burst time for the current process
    getProcess()->setRemainingBurst(getProcess()->getRemainingBurst(), sim->getTimeSlice());

    cout<<"Time:    " << getEventTime() << ": Process    " << getProcess()->getProcessID() << " times out (needs " <<
    getProcess()->getRemainingBurst() << " more units)" << endl;

    sim->dequeueCPU(); // removes the process from the top of the queue
    sim->addToCPU(getProcess()); // add the process to the back of the CPU queue


   // check for the next process in the CPU queue
    Process* nextProcess = sim->getNextCPUProcess();

    if(nextProcess != nullptr){
        StartCPU* startCpu = new StartCPU(getEventTime(), nextProcess, sim); // creates a new startCPU event with
        sim->addToEventQueue(startCpu);
    }

}