CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cc
OBJECTS=$(SOURCES:.cpp=.o)
	EXECUTABLE=elf-optimization

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(OBJECTS) 
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
		$(CC) $(CFLAGS) $< -o $@
