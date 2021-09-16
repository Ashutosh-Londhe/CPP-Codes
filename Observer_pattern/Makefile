CC = g++
CFLAGS = -Wall -g -std=c++11

SRCS = Observer_pattern.cpp Subject.cpp Dependents.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = Observer_pattern.EXE

all: $(TARGET)

$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	$(RM) *.o *~ $(TARGET)

