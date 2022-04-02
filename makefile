all: compile clean

compile: functions.o main.o
	gcc  functions.o main.o -o main.exe

main.o: main.c
	gcc  -c main.c

functions.o: functions.c functions.h
	gcc  -c functions.c functions.h

clean:
	del *.o