/*tmlz5d Tim M. Lael cs2750 e01 project1*/
/* Shuffles the deck.*/
#include <stdio.h>
#include <stdlib.h>


	void shuffle_deck(int deck[], int size){
            int i, r, temp;
			for(i=0; i<size; i++){
                r=rand()%size;
				temp=deck[i];
				deck[i]=deck[r];
				deck[r]=temp ;
            }
    }
