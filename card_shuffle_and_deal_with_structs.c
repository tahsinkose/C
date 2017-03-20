#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

struct card {
	const char *face;
	const char *suit;
};//the type "struct card" has two pointers in it.

typedef struct card Card; //the type is assigned to simply the name "Card"
//---------------------INITIALIZATON OF FUNCTIONS-------------------------
void fillDeck( Card *const wDeck,const char *wFace[],const char *wSuit[]); // The function takes 3 parameters which are a pointer to the Card data type, and two 2-dimensional array.
void shuffle (Card *const wDeck);
void deal(const Card *const wDeck);

int main()
{
	Card deck[CARDS];//Variable sized array in the type of Card structure, so it is legitimate to define this way
	
	const char *face[]={"Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};

	const char *suit[]={"Hearts","Diamonds","Clubs","Spades"};

	srand(time(NULL));

	fillDeck(deck,face,suit);
	shuffle(deck);
	deal(deck);
}//end main

void fillDeck( Card *const wDeck,const char *wFace[],const char *wSuit[])
{
	size_t i;
	
	for( i=0;i<CARDS;++i)
	{
		wDeck[i].face=wFace[i%FACES];//It should be noted that the array of structures wDeck is reached to its elements by the subscription operator.	
		wDeck[i].suit=wSuit[i/FACES];
	}//end for This uniformly fills the deck starting from Ace of Hearts (0%13=0 --> wFace[0] == face[0] and 0/13==0 --> wSuit[0]==suit[0])
}//end function fillDeck

void shuffle(Card *const wDeck)
{
	size_t i;
	size_t j;
	
	Card temp;//temporary structure variable

	for(i=0;i<CARDS;++i)
	{
		j=rand()%CARDS;	
		temp=wDeck[i];//Perfectly equal
		wDeck[i]=wDeck[j];
		wDeck[j]=temp;
		//Ordinary replacement algorithm
	}//end for
}//end function shuffle

void deal(const Card *const wDeck)
{
	size_t i;
	
	for(i=0;i<CARDS;++i)
	{	
		printf("%5s of %-8s%s",wDeck[i].face,wDeck[i].suit, (i+1) %4 ? " ": "\n");
	}//end for
}//end function deal
	
	
