CC=clang++
CFLAGS=--std=c++11

objects = Arrival.o CompleteCPU.o CompleteIO.o Event.o Exit.o ListItem.o Node.o PriorityQueue.o Process.o Queue.o Simulation.o StartCPU.o StartIO.o SuperQueue.o Timeout.o

all: A2main.o $(objects)
	$(CC) $(CFLAGS) -o A2 $< $(objects)

test: test.o $(objects)
	$(CC) $(CFLAGS) -o Test $< $(objects)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm *.o A2 Test