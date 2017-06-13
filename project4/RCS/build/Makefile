CC=gcc

mysh: sh.o main.c 
	$(CC) -g main.c sh.o -o mysh

sh.o: sh.c sh.h
	$(CC) -g -c sh.c

clean:
	rm -rf sh.o mysh
