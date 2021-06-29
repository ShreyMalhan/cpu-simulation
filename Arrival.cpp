
#include "Arrival.h"
#include "Simulation.h"
#include "StartCPU.h"

Arrival::Arrival(int theTime, Process *theProcess, Simulation *sim) : Event(theTime, theProcess, sim){}

void Arrival::handleEvent() {
    string line;
    int arriveTime, firstCPUBurst;
    Process* process = getProcess();
    // add the arrived process to the queue and if the there is no other process in the queue then schedule a startCPU

    if(sim->isCPUEmpty()){
        // startCPU
        cout<<"Time:    " << getEventTime() << ": Process    " << getProcess()->getProcessID() << " arrives in the system: CPU is "
                                                                                                  "free(begins execution)" << endl;
        StartCPU *startCpu = new StartCPU(process->getArrivalTime(), process, sim);
        sim->addToEventQueue(startCpu);
    }else{
        cout<<"Time:    " << getEventTime() << ": Process    " << getProcess()->getProcessID() << " arrives in the system: CPU is "
                                                                                                  "busy(process will be queued)" << endl;
    }

    sim->addToCPU(process);  //add the process to the CPU burst FIFO queue

    line = sim->readNextLine();    // reads the next line of the input file

    if(!line.empty()){ // checks for eof

        istringstream iss(line);
        iss>>arriveTime;       // reads the first token of the line
        iss >> firstCPUBurst;  // reads the second token of the line

        Process* theProcess = new Process(sim->getID(), arriveTime, line, firstCPUBurst);
        sim->incrementID(); // increments the private int variable in Simulation class

        Arrival *arrive = new Arrival(arriveTime, theProcess, sim);

        sim->addToEventQueue(arrive); // add the arrival event to the priority queue
    }
}