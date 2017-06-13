/*tmlz5d Tim M. Lael cs2750 e01 project1*/
#include <stdio.h>
#include <stdlib.h>
#define DECK_SIZE 52


    int deck[DECK_SIZE];
	typedef enum {clubs, diamonds, hearts, spades} suit_t;
	typedef struct {unsigned int rank : 4; suit_t suit : 2;} card_t;
    void init_deck(int deck[], int size);
    void shuffle_deck(int deck[], int size);
    void sort_deck(int deck[], int size);
   	void print_deck(int deck[], int size);
    void print_card(int card);
