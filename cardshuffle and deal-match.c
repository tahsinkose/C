#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"




void printHandStatus(int result){
	switch(result){
		case STRAIGHT:
			printf("Hand has a STRAIGHT\n");
			break;
		case FLUSH:
			printf("Hand has a FLUSH\n");
			break;
		case FOURTET:
			printf("Hand has a FOURTET\n");
			break;
		case FULL_HOUSE:
			printf("Hand has a FULL_HOUSE\n");
			break;
		case TRIPLET:
			printf("Hand has a TRIPLET\n");
			break;
		case 2:
			printf("Hand has a DOUBLE PAIR\n");
			break;
		case 1:
			printf("Hand has a PAIR\n");
			break;
		default:
			;
	}
}


void printFinalStatus(int final){
	switch(final){
		case P1_WINS:
			printf("Player 1 wins by superior hand.");
			break;
		case P2_WINS:
			printf("Player 2 wins by superior hand.");
			break;
		case P1_WITHC:
			printf("Player 1 wins by strong hand.");
			break;
		case P2_WITHC:
			printf("Player 2 wins by strong hand.");
			break;
		case TIE:
			printf("Tie.");
			break;
		default:
			;
	}
	puts("");
}

int main()
{
	
	int x,y;
	int check1=13,check2=13;//13 corresponds to column number which is between 0 and 9. Meaningly, I have made it to explicitly unreachable at first.
	
	
	
	srand(time (NULL));

	shuffle();
	printf("-----------------%s-------------------------\n","PLAYER ONE'S HAND");
	x=deal(&check1);
	printHandStatus(x);
	
	printf("-----------------%s-------------------------\n","PLAYER TWO'S HAND");
	y=deal(&check2);
	printHandStatus(y);
		
	printf("--------------------------------------------\n");
	if(x==0 && y==0)
	{
		puts("");
		printf("Tie.");
	}
	else
	{
		int final = compare(x,y,check1,check2);
		printFinalStatus(final);
	}

}
