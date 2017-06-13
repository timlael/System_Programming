/*tmlz5d Tim M. Lael cs2750 e01 project1*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../cards.h"



    int main() {
            srand(time(NULL));
			init_deck(deck, DECK_SIZE);
			printf("Initial deck: ");
			putchar('\n');
			print_deck(deck, DECK_SIZE);
			shuffle_deck(deck, DECK_SIZE);
            printf("Shuffled deck: ");
			putchar('\n');
			print_deck(deck, DECK_SIZE);
			sort_deck(deck, DECK_SIZE);
			printf("Re-sorted deck: ");
			putchar('\n');
			print_deck(deck, DECK_SIZE);
            return 0;
    }
