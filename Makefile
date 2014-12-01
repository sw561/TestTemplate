CC=g++
CFLAGS= -Wall -Wextra -pedantic -O3 -ansi
SOURCES=main.cpp demo.cpp
OBJECTS=$(SOURCES:.cpp=.o)
.PRECIOUS: test.o $(SOURCES:.cpp=_test.o)
EXECUTABLE=main

all: param_defi.h.auto param_decl.h.auto param_proc.h.auto $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) parameter.o
	$(CC) $(CFLAGS) $^ -o $@

%_test: %_test.o %.o test.o parameter.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

parameter.o: parameter.cpp parameter.h param_defi.h.auto param_decl.h.auto param_proc.h.auto
	$(CC) $(CFLAGS) -c $< -o $@

%_defi.h.auto %_decl.h.auto %_proc.h.auto: %_list.txt
	python generate.py

clean:
	rm -f *.o $(EXECUTABLE) *_test *.pyc *.auto
