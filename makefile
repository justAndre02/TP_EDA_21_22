all: compile clean

compile: functions.o main.o
	gcc -Wall functions.o main.o -o main.exe

main.o: main.c
	gcc -Wall -c main.c

functions.o: functions.c functions.h
	gcc -Wall -c functions.c functions.h

clean:
	del *.o