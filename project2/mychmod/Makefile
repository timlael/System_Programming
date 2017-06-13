CC=gcc
CFLAGS=	-I. -g -Wall 
DEPS =	../mychmod.h 
OBJ =	mychmod.o input.o files.o changes.o 

%.o: %.c $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS) 
 
mychmod: $(OBJ) 
	$(CC) -o  $@  $^  $(CFLAGS)
