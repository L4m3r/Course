CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=graph.cpp dsu.cpp utils.cpp solver.cpp main.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o

test:
	g++ -c graph.cpp dsu.cpp utils.cpp solver.cpp test.cpp 
	g++ graph.o dsu.o utils.o solver.o test.o 
