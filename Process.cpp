
#include "Process.h"

Process::Process(int ID, int arrival, string line, int remainingBurst) : processID(ID), arrivalTime(arrival), line(line) {
    waitTime = 0;
    endTime = 0;
    numToken = 3;
    remainingCPUBurst = remainingBurst;
}

void Process::setWaitTime(int wait) {
    this->waitTime = wait;
}

void Process::setEndTime(int end) {
    this->endTime = end;
}

int Process::getProcessID() {
    return this->processID;
}

int Process::getArrivalTime() {
    return this->arrivalTime;
}

int Process::getWaitTime() {
    return this->waitTime;
}

int Process::getEndTime() {
    return this->endTime;
}

int Process::compareTo(ListItem *other){
    Process *p = dynamic_cast<Process *>(other);
    if(p != nullptr){
        if(this->processID < p->getProcessID())
            return -1;
        else if (this->processID == p->getProcessID())
            return 0;
        else
            return 1;
    }
}

// gets the next token if present, otherwise returns an empty string
string Process::nextToken() {
    string check, token;
    istringstream iss(line);

    // makes sure to get the right token
    for(int i =0; i<numToken; i++){
        if(iss >> check){
            token = check;
        }else{
            token = "";
        }
    }
    return token;
}

void Process::incrementNumToken() {
    numToken++;
}

void Process::setRemainingBurst(int remaining, int timeSlice) {
    remainingCPUBurst = remaining - timeSlice;
}

int Process::getRemainingBurst() {
    return remainingCPUBurst;
}