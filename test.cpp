////
//// Created by mrmal on 3/13/21.
////
//
//#define CATCH_CONFIG_MAIN
//#include "Arrival.h"
//#include "catch.hpp"
//#include "StartCPU.h"
//#include "StartIO.h"
//#include "PriorityQueue.h"
//#include "Process.h"
//#include "Simulation.h"
//#include "Timeout.h"
//
//TEST_CASE("Testing priority insertion with respect to time"){
//    PriorityQueue* queue = new PriorityQueue;
//    Simulation* sim = new Simulation();
//    string line = "";
//    Process *process1 = new Process(1, 1, line, 1); // (ID, arrivalTime, line, remainingCPUBurst)
//    Process *process2 = new Process(2, 2, line, 1);
//    StartCPU *startCpu = new StartCPU(1, process1, sim); // (eventTime, process, simulation)
//    StartIO *startIo = new StartIO(2,process2, sim);
//    queue->enqueue(startIo);
//    queue->enqueue(startCpu);
//
//    Event* theEvent = dynamic_cast<Event*>(queue->getFront());
//    REQUIRE(theEvent->getProcess()->getProcessID() == 1);
//}
//
//TEST_CASE("testing priority insertion of arrival and timeout event"){
//    PriorityQueue* queue = new PriorityQueue;
//    Simulation* sim = new Simulation();
//    string line = "";
//    Process *process1 = new Process(2, 1, line, 1);
//    Process *process2 = new Process(1, 2, line, 1);
//
//    Arrival *arrival = new Arrival(1, process1, sim);
//    Timeout *timeOut = new Timeout(1,process2, sim);
//    queue->enqueue(timeOut);
//    queue->enqueue(arrival);
//
//    Event* theEvent = dynamic_cast<Event*>(queue->getFront());
//    REQUIRE(theEvent->getProcess()->getProcessID() == 2);
//}
//
//TEST_CASE("testing priority insertion with processID"){
//    PriorityQueue* queue = new PriorityQueue;
//    Simulation* sim = new Simulation();
//    string line = "";
//    Process *process1 = new Process(1, 1, line, 1);
//    Process *process2 = new Process(2, 1, line, 1);
//    StartCPU *startCpu = new StartCPU(1, process1, sim);
//    StartIO *startIo = new StartIO(1,process2, sim);
//    queue->enqueue(startIo);
//    queue->enqueue(startCpu);
//
//    Event* theEvent = dynamic_cast<Event*>(queue->getFront());
//    REQUIRE(theEvent->getProcess()->getProcessID() == 1);
//}
//
//TEST_CASE("testing the correct token in process"){
//    string line = "2 8 -20 12";
//
//    Process *theProcess = new Process(1, 1, line, 1);
//    REQUIRE(theProcess->nextToken() == "-20"); // nextToken() starts reading from the 3rd token because first two are read by Arrival event
//    theProcess->incrementNumToken();
//
//    REQUIRE(theProcess->nextToken() == "12");
//    theProcess->incrementNumToken();
//
//    REQUIRE(theProcess->nextToken() == "");
//}
//
//TEST_CASE("adding and removing from the queue"){
//    PriorityQueue* queue = new PriorityQueue;
//    Simulation* sim = new Simulation();
//    string line = "5 5 -5 5";
//    Process *process1 = new Process(1, 1, line, 1);
//    Process *process2 = new Process(2, 2, line, 1);
//    Process *process3 = new Process(3, 3, line, 1);
//
//    REQUIRE(queue->isEmpty() == true);
//
//    queue->enqueue(new StartIO(2,process2, sim));
//
//    REQUIRE(queue->isEmpty() == false);
//
//    queue->dequeue();
//
//    REQUIRE(queue->isEmpty() == true);
//}