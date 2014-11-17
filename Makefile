CC=g++
CFLAGS= -Wall -Wextra -pedantic -O3 -ansi
SOURCES=main.cpp demo.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
.PRECIOUS: test.o $(SOURCES:.cpp=_test.o)
EXECUTABLE=main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%_test: %_test.o %.o test.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXECUTABLE) *_test
