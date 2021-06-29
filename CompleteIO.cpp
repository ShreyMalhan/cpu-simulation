
#include "CompleteIO.h"
#include "Process.h"
#include "Simulation.h"
#include "Exit.h"
#include "StartIO.h"
#include "StartCPU.h"

CompleteIO::CompleteIO(int eventTime, Process *theProcess, Simulation *sim) : Event(eventTime,theProcess,sim) {}

void CompleteIO::handleEvent() {
    string token = getProcess()->nextToken();       // checks if there are more tokens in the process
    if(!token.empty()){                             // if more tokens are present then add the process to the CPU queue
        getProcess()->incrementNumToken();
        int CPUTime = stoi(token);
        if(CPUTime > 0){
            cout<<"Time:    " << getEventTime() << ": Process    " << getProcess()->getProcessID() << " completes I/O burst. "
                                                                                                      "Queueing for CPU" << endl;
            getProcess()->setRemainingBurst(CPUTime,0); // reset the amount of time needed to complete the CPU burst

            if(sim->isCPUEmpty()){                  // if CPU queue is empty then schedule a startCPU event for this process
                StartCPU* startCpu = new StartCPU(getEventTime(), getProcess(), sim);
                sim->addToEventQueue(startCpu);
            }
            sim->addToCPU(getProcess());

        }

    }else{              // if no more tokens are present then the process will exit
        cout<<"Time:    " << getEventTime() << ": Process    " << getProcess()->getProcessID() << " completes I/O burst. "
                                                                                                  "Process will exit the system" << endl;
        Exit* exit = new Exit(getEventTime(), getProcess(), sim);
        sim->addToEventQueue(exit);
        //exit
    }
    sim->dequeueIO();       // removes the process from the I/O queue

    // check for next process in the IO queue
    Process* nextProcess = sim->getNextIOProcess();
    if(nextProcess!= nullptr){
        StartIO* startIo = new StartIO(getEventTime(), nextProcess, sim);
        sim->addToEventQueue(startIo);
    }
}