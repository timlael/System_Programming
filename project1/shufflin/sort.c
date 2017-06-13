/*tmlz5d Tim M. Lael cs2750 e01 project1*/
/* Sorts the deck*/
#include <stdio.h>
#include <stdlib.h>


	void sort_deck(int deck[], int size){
            int i, j, temp;
			for(i=0; i<size-1; i++)
			for(j=i+1; j<size; j++)
			if(deck[i]%13>deck[j]%13){
                temp=deck[i];
                deck[i]=deck[j];
                deck[j]=temp;
			}
	}

