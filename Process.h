
#pragma once

#include <sstream>
#include "ListItem.h"
#include <string>

using namespace std;

class Process: public ListItem{

private:
    string line;
    int processID;
    int arrivalTime;
    int waitTime;
    int endTime;
    int numToken;
    int remainingCPUBurst;

public:

    Process(int, int, string, int);
    void setWaitTime(int);
    void setEndTime(int);
    int getProcessID();
    int getArrivalTime();
    int getWaitTime();
    int getEndTime();
    int compareTo(ListItem *other);
    string nextToken();
    void incrementNumToken();
    void setRemainingBurst(int, int);
    int getRemainingBurst();

};
