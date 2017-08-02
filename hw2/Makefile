CC=g++
CFLAGS=-g -c -Wall -std=c++0x

kruskal_algo.o:  kruskal_algo.hpp graph.hpp disjoint_set.hpp kruskal_algo.cpp
	$(CC) $(CFLAGS) kruskal_algo.cpp

disjoint_set.o:  disjoint_set.hpp disjoint_set.cpp
	$(CC) $(CFLAGS) disjoint_set.cpp

graph.o: graph.hpp graph.cpp
	$(CC) $(CFLAGS) graph.cpp

MST.o: graph.hpp  kruskal_algo.hpp MST.hpp  MST.cpp
	$(CC) $(CFLAGS) MST.cpp


main: main.o  kruskal_algo.o disjoint_set.o  graph.o MST.o
	$(CC) kruskal_algo.o disjoint_set.o  graph.o MST.o main.o -o main

main.o: kruskal_algo.hpp   disjoint_set.hpp graph.hpp MST.hpp main.cpp
	$(CC) $(CFLAGS) main.cpp


clean:
	rm -rf *.o Main