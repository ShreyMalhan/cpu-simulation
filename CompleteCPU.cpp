
#include "Process.h"
#include "Simulation.h"
#include "CompleteCPU.h"
#include "StartCPU.h"
#include "StartIO.h"
#include "Exit.h"

CompleteCPU::CompleteCPU(int eventTime, Process *theProcess, Simulation *sim) : Event(eventTime, theProcess, sim){}

void CompleteCPU::handleEvent() {
    string token = getProcess()->nextToken();   // checks if there are more tokens
    if(!token.empty()){
        if(sim->isIOEmpty()){                   // if the I/O queue is empty then add startIO event to the event queue
            //startIO
            //cout<<"Time:    " << getEventTime() << ": Process    " << getProcess()->getProcessID() << " completes CPU burst. " << endl;
            StartIO* startIo = new StartIO(getEventTime(), getProcess(), sim);
            sim->addToEventQueue(startIo);      // add the startIO event to the queue

        }
        cout<<"Time:    " << getEventTime() << ": Process    " << getProcess()->getProcessID() << " completes CPU burst. "
                                                                                                  "Queueing for I/O" << endl;
        sim->addToIO(getProcess());         // add the process to the I/O queue

    }else{          // if there are no more tokens, then process will exit
        //exit
        cout<<"Time:    " << getEventTime() << ": Process    " << getProcess()->getProcessID() << " complete CPU burst. "
                                                                                                  " Process will exit the system" << endl;
        Exit* exit = new Exit(getEventTime(), getProcess(), sim);
        sim->addToEventQueue(exit);
    }

    sim->dequeueCPU();      // removes the process from the queue

    //check for the next process in the CPU queue
    Process* nextProcess = sim->getNextCPUProcess();
    if(nextProcess != nullptr){
        StartCPU* startCpu = new StartCPU(getEventTime(), nextProcess, sim);
        sim->addToEventQueue(startCpu);
    }
}
