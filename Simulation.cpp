#include <iostream>
#include "Simulation.h"
#include "Arrival.h"

Simulation::Simulation() {
    CPU = new Queue;
    IO = new Queue;
    eventQueue = new PriorityQueue;
    processes = new PriorityQueue;
    timeSlice = 0;
    id = 1;

}

void Simulation::runSimulation(char* fileName) {

    //inFile.open("C:\\Users\\mrmal\\CLionProjects\\2150\\A2\\input.txt");
    inFile.open(fileName);
    if(inFile.is_open()){
        inFile >> timeSlice;               // reads in the first line of the text file
        string line;
        inFile.ignore();                   // flushes out the stream

        getline(inFile,line);        // reads the next line of the text file
        int arriveTime, firstCPUBurst;
        istringstream iss(line);            // breaks the line in tokens
        iss >> arriveTime;                  // first token reads the arrival time of teh process
        iss >> firstCPUBurst;               // second token reads the run time needed by the first CPU burst
        Process* process = new Process(id, arriveTime, line, firstCPUBurst);
        incrementID();                      // increments the ID count of the processes
        Arrival* arrive = new Arrival(arriveTime, process, this);
        addToEventQueue(arrive);            // adds the first arrive event to the event queue

        // traverse eventQueue
        while(eventQueue->getSize() > 0){
            Event * event = dynamic_cast<Event* >(eventQueue->dequeue());
            event->handleEvent();
        }

    }else{
        cout << "File is not open" << endl;
    }


    inFile.close();
}

// reads the next line from the file and returns it as a string
string Simulation::readNextLine() {
    if(!inFile.eof()){
        string line;
        getline(inFile, line);
        return line;
    }else{
        return "";
    }
}

void Simulation::summary() {
    cout << endl;
    cout << "Process #" << "\t" << "Arrival Time" << "\t" << "Exit Time" << "\t"  << endl;
    cout << "-------------------------------------------" << endl;
    while(processes->getSize() > 0){
        Process* item = dynamic_cast<Process*>(processes->dequeue());
        cout << item->getProcessID() << "\t \t" << item->getArrivalTime() << "\t \t" << item->getEndTime() << endl;
    }
}

void Simulation::addToCPU(ListItem *item) {
    CPU->enqueue(item);
}

void Simulation::addToIO(ListItem *item) {
    IO->enqueue(item);
}

void Simulation::addToEventQueue(ListItem *item) {
    eventQueue->enqueue(item);
}

void Simulation::dequeueCPU() {
    CPU->dequeue();
}

void Simulation::dequeueIO() {
    IO->dequeue();
}

void Simulation::dequeueEventQueue(){
    eventQueue->dequeue();
}

// pulls out the next process waiting for processing
Process* Simulation::getNextCPUProcess() {
    Process* process = dynamic_cast<Process*>(CPU->getFront());
    return process;
}


Process* Simulation::getNextIOProcess() {
    Process* process = dynamic_cast<Process*>(IO->getFront());
    return process;
}

int Simulation::getTimeSlice() {
    return timeSlice;
}


// increments the global ID count
void Simulation::incrementID() {
    id++;
}

int Simulation::getID() {
    return id;
}

bool Simulation::isCPUEmpty() {
    return CPU->isEmpty();
}

bool Simulation::isIOEmpty() {
    return IO->isEmpty();
}

void Simulation::addToProcesses(ListItem *item) {
    processes->enqueue(item);
}