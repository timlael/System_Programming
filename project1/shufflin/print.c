/*tmlz5d Tim M. Lael cs2750 e01 project1*/
/* print_deck() uses print_card() to print the deck*/
/* print_card() prints a card from the deck. (0-12)spades, (13-25)hearts, (26-38)diamonds, (39-51)clubs.*/
#include <stdio.h>
#include <stdlib.h>

void print_card(int card){
        char suit[4][9]={"Spades","Hearts","Diamonds","Clubs"};
		char rank[13][6]={"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
		printf("%s of %s", rank[card%13], suit[card/13]);
		putchar('\n');
    }


	void print_deck(int deck[], int size){
            int i;
			for(i=0; i<size; i++){
                print_card(deck[i]);
			}
			putchar('\n');
    }
