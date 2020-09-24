CC = gcc
CFLAGS = -Wall -g -std=gnu99
TARGET = proc_fan
TARGET2 = testsim
OBJ1 = runsim.o argFormat.o commandLineParse.o
OBJ2 = testsim.o
all: $(TARGET) $(TARGET2)
$(TARGET): $(OBJ1)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ1)
$(TARGET2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(OBJ2)
runsim.o: runsim.c argFormat.h
	$(CC) $(CFLAGS) -c runsim.c
argFormat.o: argFormat.c argFormat.h
	$(CC) $(CFLAGS) -c argFormat.c
commandLineParse.o: commandLineParse.c commandLineParse.h
	$(CC) $(CFLAGS) -c commandLineParse.c
testsim.o: testsim.c
	$(CC) $(CFLAGS) -c testsim.c

clean:
	/bin/rm -f *.o  $(TARGET) $(TARGET2)

