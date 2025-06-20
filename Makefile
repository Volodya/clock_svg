CC=g++

CFLAGS=-c -Wall -std=c++20
LDFLAGS=
SOURCES=$(shell find . -name '*.cpp')
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=clock_svg

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@echo Linking
	$(CC) -o $@ $(OBJECTS) $(LDFLAGS)

.cpp.o:
	@echo Compiling
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

