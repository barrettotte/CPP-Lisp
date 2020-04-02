CC = g++
CCFLAGS = -g -Wall
LIBS = 

TARGET = lisp

.PHONY: default all clean

default:	$(TARGET)
all:		default

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp) $(wildcard */*.cpp))
HEADERS = $(wildcard *.hpp) $(wildcard */*.hpp)

%.o: %.cpp $(HEADERS)
	$(CC) $(CCFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)