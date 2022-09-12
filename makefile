CC=g++
CFLAGS=-c -g -O0 -std=c++11 -Wall
LDFLAGS=
SOURCES=wordtree.cpp proj5.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=proj5

all: $(EXECUTABLE)

deps=$(patsubst %.o,%.d,$(OBJECTS))

-include $(deps)

DEPFLAGS=-MMD -MF $(@:.o=.d)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(DEPFLAGS)

clean:
	rm -f core $(EXECUTABLE) $(OBJECTS) $(deps)