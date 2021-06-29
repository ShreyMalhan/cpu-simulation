
#include "Event.h"
#include "Process.h"
#include "Arrival.h"
#include "Timeout.h"

/**** Event implementation */
Event::Event(int theTime, Process *theProcess, Simulation *theSim)
        :eventTime(theTime), process(theProcess), sim (theSim) {}

int Event::getEventTime() {
    return eventTime;
}

Process* Event::getProcess() {
    return process;
}

int Event::compareTo(ListItem *other){
    bool currIsTimeout = false, currIsArrival = false, otherIsTimeout = false, otherIsArrival = false;

    Event *e = dynamic_cast<Event *>(other);

    if(e != nullptr){

        // checking for the Arrival and TimeOut events.
        Arrival* arrCurr = dynamic_cast<Arrival*>(this);
        if(arrCurr != nullptr)
            currIsArrival = true;

        Arrival* arrOther = dynamic_cast<Arrival*>(e);
        if(arrOther != nullptr)
            otherIsArrival = true;

        Timeout* timeCurr = dynamic_cast<Timeout*>(this);
        if(timeCurr != nullptr)
            currIsTimeout = true;

        Timeout* timeOther = dynamic_cast<Timeout*>(e);
        if(timeOther != nullptr)
            otherIsTimeout = true;

        // if the item in the list comes before the new item
        if(this->eventTime < e->getEventTime())
            return -1;


        // if the time unit of two events is same
        // check if any of them are either arrival or timeout
        // if yes then return the appropriately
        else if (this->eventTime == e->getEventTime()){
            // if Arrival is in the list and new node is TimeOut, then new node will add after the Arrival
            if(currIsArrival && otherIsTimeout)
                return -1;

            // if TimeOut is in the list and new node is arrival, then new node will add before the TimeOut
            else if(currIsTimeout && otherIsArrival)
                return 1;

            // if the above conditions doesnt hold then check with process id
            else if(process->getProcessID() < e->getProcess()->getProcessID()){
                return -1;
            }

            else{
                return 1;
            }
        }

        // if the item in the list comes after the new item
        else
            return 1;
    }
     // you should implement this method.
}