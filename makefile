CC=g++
CFLAGS=-c -Wall

all: bytecodeInterpreter

bytecodeInterpreter: main.o bytecodeSimulator.o bytecodeReader.o
	$(CC) main.o bytecodeSimulator.o bytecodeReader.o -o bytecodeInterpreter

main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp

bytecodeSimulator.o: src/bytecodeSimulator.cpp
	$(CC) $(CFLAGS) src/bytecodeSimulator.cpp

bytecodeReader.o: src/bytecodeReader.cpp
	$(CC) $(CFLAGS) src/bytecodeReader.cpp

clean:
	rm *.o bytecodeInterpreter
