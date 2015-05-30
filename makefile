CC=g++
CFLAGS=-c -Wall

all: bytecodeInterpreter

bytecodeInterpreter: main.o bytecodeSimulator.o bytecodeReader.o
	$(CC) bin/main.o bin/bytecodeSimulator.o bin/bytecodeReader.o -o bytecodeInterpreter
	mv bytecodeInterpreter bin/

main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp
	mv main.o bin/

bytecodeSimulator.o: src/bytecodeSimulator.cpp
	$(CC) $(CFLAGS) src/bytecodeSimulator.cpp
	mv bytecodeSimulator.o bin/

bytecodeReader.o: src/bytecodeReader.cpp
	$(CC) $(CFLAGS) src/bytecodeReader.cpp
	mv bytecodeReader.o  bin/

clean:
	rm bin/*.o bin/bytecodeInterpreter
