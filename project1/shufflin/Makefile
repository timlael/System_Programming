CC=gcc 
CFLAGS=-I. 
DEPS =	../cards.h 
OBJ =	init.o main.o print.o shuffle.o sort.o

%.o: %.c $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS) 
 
shufflin: $(OBJ) 
	$(CC) -o  $@  $^  $(CFLAGS) 

