
#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include "Queue.h"
#include "PriorityQueue.h"
#include "Process.h"

using namespace std;

class Simulation {
private:
    // you will need to add fields
    // including: Queues for CPU and IO, and priority queues for Events
    Queue* CPU;
    Queue* IO;
    PriorityQueue* eventQueue;
    PriorityQueue* processes;
    int timeSlice, id;
    ifstream inFile;

//    int token;
//    string line2;

public:
    Simulation();

    // runSimulation -- start the simulation with the given filename.
    // Called by main.
    void runSimulation(char* fileName);
//    void runSimulation(char *fileName);
    // summary -- print a summary of all the processes, as shown in the
    // assignment.  Called by main.
    void summary();

    // you may need to add more methods

    void addToCPU(ListItem* item);
    void addToIO(ListItem* item);
    void addToEventQueue(ListItem* item);
    void addToProcesses(ListItem* item);

    void dequeueCPU();
    void dequeueIO();
    void dequeueEventQueue();

    Process *getNextCPUProcess();
    Process *getNextIOProcess();
    //ListItem *getNextEvent()

    int getTimeSlice();

    string readNextLine();

    void incrementID();
    int getID();

    bool isCPUEmpty();
    bool isIOEmpty();


};// class Simulation
