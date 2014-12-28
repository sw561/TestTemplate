CC=g++
CFLAGS= -Wall -Wextra -pedantic -O3 -ansi
SOURCES=main.cpp demo.cpp parameter.cpp
OBJECTS=$(SOURCES:.cpp=.o)
.PRECIOUS: test.o $(SOURCES:.cpp=_test.o)
EXECUTABLE=main

all: param_defi.h.auto param_decl.h.auto param_proc.h.auto $(EXECUTABLE)

-include $(SOURCES:.cpp=.d) $(SOURCES:.cpp=_test.d) test.d

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%_test: param_defi.h.auto param_decl.h.auto param_proc.h.auto %_test.o %.o test.o parameter.o
	$(CC) $(CFLAGS) $*_test.o $*.o test.o parameter.o -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	$(CC) -MM $< > $*.d

%_defi.h.auto %_decl.h.auto %_proc.h.auto: %_list.txt
	python generate.py $<

clean:
	rm -f *.o $(EXECUTABLE) *_test *.pyc *.auto *.d
