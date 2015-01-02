CC=clang++
CXX=clang++
CXXFLAGS=-Wall -std=c++11  
LDFLAGS=-lz -lboost_iostreams
SOURCES=main.cc time.cc readcsv.cc stats.cc queue.cc 
OBJECTS=$(SOURCES:.cc=.o)
TESTFILES=time.cc test.cc queue.cc
TESTOBJECTS=$(TESTFILES:.cc=.o)
EXECUTABLE=elf

all: subsystem $(SOURCES) $(EXECUTABLE) 
#	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
#
#.cc.o:
#	$(CC) $(CPPFLAGS)  $< -o $@
test: test.o $(TESTOBJECTS)  
	$(CC) $(LDFLAGS) -g -lboost_unit_test_framework $(TESTOBJECTS) -o test 
clean:
	rm -f *.o test elf
subsystem: 
	$(MAKE) -C staging
