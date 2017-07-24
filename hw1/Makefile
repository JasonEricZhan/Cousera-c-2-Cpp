CC=g++

CFLAGS=-g -c -Wall -std=c++0x


PriorityQueue.o:  PriorityQueue.hpp PriorityQueue.cpp

	$(CC) $(CFLAGS) PriorityQueue.cpp



graph.o: graph.hpp graph.cpp

	$(CC) $(CFLAGS) graph.cpp
	
	
ShortestPath.o:  graph.hpp PriorityQueue.hpp ShortestPath.hpp ShortestPath.cpp

	$(CC) $(CFLAGS) ShortestPath.cpp


	
main: main.o ShortestPath.o PriorityQueue.o graph.o 

	$(CC) graph.o PriorityQueue.o ShortestPath.o main.o -o main




main.o:  graph.hpp ShortestPath.hpp main.cpp

	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *.o main