#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"

int main()
{
	
	int x,y;
	int check1=13,check2=13;//13 corresponds to column number which is between 0 and 9. Meaningly, I have made it to explicitly unreachable at first.
	unsigned int bigDeck[CARDS+1]={0};
	
	unsigned int deck[SUITS][FACES]={0};
	srand(time (NULL));

	shuffle(deck);
	printf("-----------------%s-------------------------\n","PLAYER ONE'S HAND");
	x=deal(deck,&check1,bigDeck);
	printf("check1 = %d\n",check1);
	
	printf("-----------------%s-------------------------\n","PLAYER TWO'S HAND");
	y=deal(deck,&check2,bigDeck);	
	printf("check2=%d\n",check2);
	printf("--------------------------------------------\n");
	if(x==0 && y==0)
	{
		puts("");
		printf("Tie.");
	}
	else
	{
		printf("x= %d , y=%d\n",x,y);
		compare(x,y,&check1,&check2);
	}

}//end main
