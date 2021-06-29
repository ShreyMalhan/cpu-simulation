
#include "StartIO.h"
#include "Process.h"
#include "Simulation.h"
#include "CompleteIO.h"

StartIO::StartIO(int eventTime, Process *theProcess, Simulation *sim) : Event(eventTime, theProcess, sim) {}

void StartIO::handleEvent() {

    // checks for the time needed to complete the I/O burst and schedule the completeIO call

    string IO = getProcess()->nextToken();
    getProcess()->incrementNumToken();

    int IOTime = stoi(IO);
    if(IOTime < 0){
        // complete IO
        cout<<"Time:    " << getEventTime() << ": Process    " << getProcess()->getProcessID() << " begins I/O burst of length " <<
                                                                                                                                 (-IOTime) << endl;
        CompleteIO* completeIo = new CompleteIO(getEventTime() - IOTime, getProcess(), sim);
        sim->addToEventQueue(completeIo);
    }
}
