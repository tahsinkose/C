#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle(unsigned int wDeck[][FACES]);
int deal(unsigned int wDeck[][FACES], const char *wFace[],const char *wSuit[],int *ptrCh,unsigned int arr[]);
int checkpair(unsigned const int handDeck[], int *ptr);
int checktriple(unsigned const int handDeck[],int *ptr);
int checkfour(unsigned const int handDeck[]);
int checkflush(unsigned const int columnDeck[],unsigned const int rowDeck[]);
int checkstraight(unsigned int handDeck[]);
void sortArray(unsigned int handDeck[]);
void compare(int a,int b,int *c,int *d);
int main()
{
	const char* suit[SUITS]={"Hearts","Diamonds","Clubs","Spades"};
	int x,y;
	int check1=13,check2=13;//13 corresponds to column number which is between 0 and 9. Meaningly, I have made it to explicitly unreachable at first.
	int *pointch1=&check1;
	int *pointch2=&check2;
	unsigned int bigDeck[CARDS+1]={0};
	const char* face[FACES]={"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
	unsigned int deck[SUITS][FACES]={0};
	srand(time (NULL));

	shuffle(deck);
	printf("-----------------%s-------------------------\n","PLAYER ONE'S HAND");
	x=deal(deck,face,suit,&check1,bigDeck);
	printf("check1 = %d\n",check1);
	
	printf("-----------------%s-------------------------\n","PLAYER TWO'S HAND");
	y=deal(deck,face,suit,&check2,bigDeck);	
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

void shuffle(unsigned int wDeck[][FACES])
{
	size_t row;	
	size_t column;
	size_t card;

	for(card=1;card<=CARDS;card++)
	{
		do{
			row=rand() % SUITS;
			column=rand() % FACES;
		}while (wDeck[row][column]!=0);//first row and column are chosen. then if that particular place's value is 0, start to insert the cards.

		
		wDeck[row][column]=card;
	}//end for
}//end shuffle

int deal(unsigned int wDeck[][FACES], const char* wFace[],const char* wSuit[],int*ptrCh,unsigned int arr[])
{
	size_t card;
	size_t row;
	size_t column;
	size_t choose; 
	int result=0;
	
	
	
	unsigned int hand[5];
	unsigned int handFlush[5];

	for(card=0;card<5;card++)
	{
		choose=rand()%52 + 1;
		if(arr[choose]==0)
		{
			for(row=0;row<SUITS;row++)
			{
				for(column=0;column<FACES;column++)
				{
					if(wDeck[row][column]==choose)
					{
						wDeck[row][column]=0;
						arr[choose]++;
						printf("%5s of %-8s\n",wFace[column],wSuit[row]);
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
	
																								for(int a=0;a<5;a++)
																								{
																								printf("%u ",hand[a]);
																								}
																								puts("");					
		
	
	if(checkfour(hand)==4)
	{
		puts("");
		printf("Hand has a fourtet.");
		result=7;
	}
	else
	{
		
		if(checktriple(hand,&*ptrCh))
		{
			puts("");
			printf("Hand has a triple.\n");
			result=3;
			if(checkpair(hand,&*ptrCh))
			{
				printf("Hand has a pair.\n");
				printf("It made full house now.\n");
				result=4;
			}//end if /*These algoritm is not completely true, but not wrong also.Should be optimized.*/
		}//end if
		else
		{
			*ptrCh=13;//It should be resetted.
			if(checkpair(hand,&*ptrCh)==2)
			{
			printf("\nHand has two pair.\n");
			result=2;
			}
			*ptrCh=13;//It should be resetted again.
			if(checkpair(hand,&*ptrCh)==1)
			{
				printf("\nHand has a pair.\n");
				result=1;
			}//end else if
			*ptrCh=13;//It should be resetted again.
			if(checkpair(hand,&*ptrCh)==0)
			{
				result=0;
			}
		}//end else
			
	}//end else
		
	
	if(checkflush(hand,handFlush))
	{
		puts("");
		printf("Hand is a flush.");
		result=5;
	}	

	
	if(checkstraight(hand))
	{
		puts("");
		printf("Hand is a straight.");
		result=6;
	}
	return result;
}//end deal

int checkpair(unsigned const int handDeck[], int *ptr)
{
	size_t i;
	size_t j;
	
	int pairs=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(handDeck[i]==handDeck[j] && j>i && *ptr!=handDeck[i])
			{
				*ptr=handDeck[i];
				pairs++;
			}//end if
		}//end for
	}//end for
	return pairs;
}//end checkpair

int checktriple(unsigned const int handDeck[], int *ptr)
{
	size_t i;
	size_t j;
	
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(handDeck[i]==handDeck[j] && j>i && *ptr==handDeck[j])
			{
				return 1;
			}//end if
			else if(handDeck[i]==handDeck[j] && j>i && *ptr!=handDeck[j])
			{
				*ptr=handDeck[j];
			}//end else if
			
		}//end for
	}//end for
	return 0;
}//end checktriple
int checkfour(unsigned const int handDeck[])
{
	size_t i;
	size_t j;	
	int check=13;
	int count=1;//Because variable check won't match with the handDeck[j] at the first time.So that match should be counted as happened.
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(handDeck[i]==handDeck[j] && j>i && check==handDeck[j])
			{
				if(++count==4)
				{
					return count;
				}
				
			}
			else if(handDeck[i]==handDeck[j] && j>i && check!=handDeck[j])
			{
				check=handDeck[j];
			}
		}//end for
		count=1;//This variable must be resetted.So in one hand there can't be two fourtets.
	}//end for
	return 0;
	
}//end checkfour

int checkflush(unsigned const int columnDeck[],unsigned const int rowDeck[])
{
	size_t i=0;
	
	for(size_t j=0;j<5;j++)
	{
		if(rowDeck[i]!=rowDeck[j] && j>i)
		{
			return 0;
		}//end if
		
	}//end for
	return 1;
}//end checkflush

int checkstraight(unsigned  int handDeck[])
{
	sortArray(handDeck);
	size_t i=0;
	for(;i<4;i++)
	{
		if((handDeck[i]+1)!=handDeck[i+1])
		{
			return 0;
		}//end if
	}//end for
	return 1;
}

void sortArray(unsigned int handDeck[])
{
	unsigned int hold;
	for(int pass=0;pass<4;pass++)
	{
		for(size_t i=0;i<4;i++)
		{
			if(handDeck[i]>handDeck[i+1])
			{
				hold=handDeck[i];
				handDeck[i]=handDeck[i+1];
				handDeck[i+1]=hold;
			}
		}//end for
	}//end for
}//end sortArray

void compare(int a,int b,int*c,int*d)
{
	if(a>b)
	{
		puts("");
		printf("Player 1 wins by a>b.");
	}
	else if(b>a)
	{
		puts("");
		printf("Player 2 wins by b>a.");
	}//end else if
	else
	{
		if(c>d && d!=0)
		{
			puts("");
			printf("Player 1 wins by check1>check2.");
		}
		else if(d>c && c!=0)
		{
			puts("");
			printf("Player 2 wins by check2>check1.");
		}
		else if(c==0)
		{
			puts("");
			printf("Player 1 wins by check1=0");
		}//end inner else
		else if(d==0)
		{
			puts("");
			printf("Player 2 wins by check2=0");
		}
		else
		{
			puts("");
			printf("Tie.");
		}//end else
	}//end outer else
}
