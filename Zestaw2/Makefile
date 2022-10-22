CC = g++
CFLAGS = -Wall -std=c++11

OBJECTS1 = insert.o
OBJECTS2 = bubble.o
OBJECTS3 = quick.o
OBJECTS4 = merge.o

TARGET1 = insert.out
TARGET2 = bubble.out
TARGET3 = quick.out
TARGET4 = merge.out

.PHONY: all
all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4)

%.o : %.c++ Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET1) : $(OBJECTS1)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS1) -o $(TARGET1)

$(TARGET2) : $(OBJECTS2)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS2) -o $(TARGET2)

$(TARGET3) : $(OBJECTS3)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS3) -o $(TARGET3)

$(TARGET4) : $(OBJECTS4)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS4) -o $(TARGET4)

.PHONY: all
all:$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4)

.PHONY : clean

clean :
	$(RM) *.o *.out core
