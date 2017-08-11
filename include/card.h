#ifndef CARD_H_
#define CARD_H_
#include "mergesort.h"

#define SUITS 4
#define FACES 13
#define CARDS 52
#define HAND_DECK_SIZE 5

#define P1_WINS 1
#define P2_WINS 2
#define P1_WITHC 99
#define P2_WITHC -99
#define TIE 0

#define TRIPLET 3
#define FULL_HOUSE 4
#define FLUSH 5
#define STRAIGHT 6
#define FOURTET 7



const char* suit[SUITS]={"Hearts","Diamonds","Clubs","Spades"};
const char* face[FACES]={"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
unsigned int deck[SUITS][FACES]={0};
unsigned int bigDeck[CARDS+1]={0};

void shuffle()
{
	size_t row;	
	size_t column;
	size_t card;

	for(card=1;card<=CARDS;card++)
	{
		do{
			row=rand() % SUITS;
			column=rand() % FACES;
		}while (deck[row][column]!=0);//first row and column are chosen. then if that particular place's value is 0, start to insert the cards.

		
		deck[row][column]=card;
	}//end for
}



int checkpair(unsigned const int handDeck[], int *ptr)
{
	int pairs=0;
	for(int i=0;i<HAND_DECK_SIZE;i++)
	{
		for(int j=i+1;j<HAND_DECK_SIZE;j++)
		{
			if(handDeck[i]==handDeck[j] && *ptr!=handDeck[i])
			{
				*ptr=handDeck[i];
				pairs++;
			}//end if
		}//end for
	}//end for
	return pairs;
}

int checktriple(unsigned const int handDeck[], int *ptr)
{
	for(int i=0;i<HAND_DECK_SIZE;i++)
	{
		for(int j=i+1;j<HAND_DECK_SIZE;j++)
		{
			if(handDeck[i]==handDeck[j] && *ptr==handDeck[j])
				return 1;
			else if(handDeck[i]==handDeck[j] && *ptr!=handDeck[j])
				*ptr=handDeck[j];
		}//end for
	}//end for
	return 0;
}
int checkHand(unsigned int handDeck[],unsigned const int handFlushDeck[], int* ptrCh){
	
	mergeSort(handDeck,0,HAND_DECK_SIZE-1);
	int count = 0;
	int save_face=FACES; //Initially assign it to the impossible value.
	int pairs=0;
	for(int i=0;i<4;i++){
		if((handDeck[i]+1)==handDeck[i+1])
			count++;
		else
			break;
	}//check whether hand is straight
	if(count == 4)
		return STRAIGHT;

	count = 0;//clear count.
	
	
	for(int i=0,j=1;j<HAND_DECK_SIZE;j++)
	{
		if(handFlushDeck[i]==handFlushDeck[j])
			count++;
		else
			break;
	}
	if(count == 4)	
		return FLUSH;
		
	
	count=1;// save_face won't match with the handDeck[j] at the first time.So that match should be counted as happened.
	for(int i=0;i<2;i++)
	{
		for(int j=i+1;j<HAND_DECK_SIZE;j++)
		{
			if(handDeck[i]==handDeck[j] && save_face==handDeck[j])
				count++;
			else if(handDeck[i]==handDeck[j] && save_face!=handDeck[j])
				save_face=handDeck[j];
		}
		count=1;//This variable must be resetted.So in one hand there can't be two fourtets.
	}
	if(count == 4)
		return FOURTET;



	if(checktriple(handDeck,ptrCh)){
		if(checkpair(handDeck,ptrCh))
			return FULL_HOUSE;
		return TRIPLET;
	}//end if
	else{
		*ptrCh=13;//It should be resetted.
		return checkpair(handDeck,ptrCh);
	}

}


int deal(int*ptrCh)
{
	size_t card;
	size_t row;
	size_t column;
	size_t choose; 
	int result=0;
	
	
	
	unsigned int hand[HAND_DECK_SIZE];
	unsigned int handFlush[HAND_DECK_SIZE];

	for(card=0;card<HAND_DECK_SIZE;card++)
	{
		choose=rand()%52 + 1;
		if(bigDeck[choose]==0)
		{
			for(row=0;row<SUITS;row++)
			{
				for(column=0;column<FACES;column++)
				{
					if(deck[row][column]==choose)
					{
						deck[row][column]=0;
						bigDeck[choose]++;
						printf("%5s of %-8s\n",face[column],suit[row]);
						hand[card]=column;//To check their pairness.
						handFlush[card]=row;
					}//end if
				}//end for
			}//end for
		}//end if
		else
		{
			card--;
		}
	}//end for
	
	for(int a = 0; a < HAND_DECK_SIZE;a++)
		printf("%u ",hand[a]);
	puts("");

	result = checkHand(hand,handFlush,ptrCh);
	return result;
}//end deal





int compare(int a,int b,int c,int d)
{
	if(a>b)
		return P1_WINS;
	else if(b>a)
		return P2_WINS;
	else
	{
		if(c>d && d!=0 || c==0)
			return P1_WITHC;
		else if(d>c && c!=0 || d==0)
			return P2_WITHC;
		else
			return TIE;
	}//end outer else
}

#endif

