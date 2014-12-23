CC=g++
CFLAGS=-Wall -std=c++11  -c
LDFLAGS=-lz
SOURCES=main.cc gzip.cc time.cc
OBJECTS=$(SOURCES:.cc=.o)
TESTFILES=time.cc test.cc
TESTOBJECTS=$(TESTFILES:.cc=.o)
EXECUTABLE=elf
all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
test: test.o $(TESTOBJECTS)
	$(CC) $(LDFLAGS) -lboost_unit_test_framework $(TESTOBJECTS) -o test 
clean:
	rm -f *.o test elf
