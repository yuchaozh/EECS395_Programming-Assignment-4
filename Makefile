CXXFLAGS=-g -Wall
CPPFLAGS=-g 
CFLAGS=-g

ALL: main.o town.o node.o map.o list.o dijkstra.o minHeap.o
	g++ -g -o proj4 main.o town.o node.o map.o list.o dijkstra.o minHeap.o

%.o:

clean:
	rm -r *.o proj4

