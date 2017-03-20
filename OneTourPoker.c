#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle(unsigned int wDeck[][FACES]);
int deal(unsigned int wDeck[][FACES], const char *wFace[],const char *wSuit[],int *ptrCh,unsigned int arr[],unsigned int columnDeck[],unsigned int rowDeck[]);
int dealComputer(unsigned int wDeck[][FACES],int*ptrCh,unsigned int arr[],unsigned int columnDeck[],unsigned int rowDeck[]);
int checkpair(unsigned int handDeck[], int *ptr);
int checktriple(unsigned int handDeck[],int *ptr);
int checkfour(unsigned int handDeck[]);
int checkflush(unsigned const int columnDeck[],unsigned const int rowDeck[]);
int checkstraight(unsigned int handDeck[]);
void sortArray(unsigned int handDeck[]);
void compare(int a,int b,int *c,int *d);
int evaluate(int final,unsigned int wDeck[][FACES],const char *wFace[],const char *wSuit[],unsigned int columnDeck[],unsigned int rowDeck[],unsigned int arr[]);
void pickCard(unsigned int element,unsigned int arr[],unsigned int wDeck[][FACES],unsigned int columnDeck[],unsigned int rowDeck[]);
void printHand(unsigned int columnDeck[],unsigned int rowDeck[],const char *wFace[],const char *wSuit[]);
enum Status {CONTINUE,END};
int main()
{
	const char* suit[SUITS]={"Hearts","Diamonds","Clubs","Spades"};
	const char* face[FACES]={"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
	int x,y;
	int decide=0;
	int check1=13,check2=13;//13 corresponds to column number which is between 0 and 9. Meaningly, I have made it to explicitly unreachable at first.
	int *pointch1=&check1;
	int *pointch2=&check2;
	int val;
	unsigned int hand[5];
	unsigned int handFlush[5];
	unsigned int bigDeck[CARDS+1]={0};
	enum Status gameStatus;
	gameStatus=CONTINUE;//to explicitly initalize and make the loop work.
	
	unsigned int deck[SUITS][FACES]={0};
	srand(time (NULL));

	shuffle(deck);
	printf("-----------------%s-------------------------\n","PLAYER'S HAND");
	x=deal(deck,face,suit,&check1,bigDeck,hand,handFlush);
	y=dealComputer(deck,&check2,bigDeck,hand,handFlush);	
	printf("--------------------------------------------\n");
	while(gameStatus==CONTINUE)
	{
	 	printf("Computer is being waited....\n");
		val=evaluate(y,deck,face,suit,hand,handFlush,bigDeck);
		while(decide!=-1)
		{
			printf("Please decide which cards do you want to replace(-1 to exit): ");
			scanf("%d",&decide);
			if(decide==-1)
			{
				break;
			}
			pickCard(decide,bigDeck,deck,hand,handFlush);
		}
		printHand(hand,handFlush,face,suit);
		if(x==0 && val==0)
		{
			gameStatus=CONTINUE;
		}
		else
		{
			compare(x,val,&check1,&check2);
			gameStatus=END;
		}//end else
	}//end while. indefinite loop, so a sentinel was needed.
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

int deal(unsigned int wDeck[][FACES], const char* wFace[],const char* wSuit[],int*ptrCh,unsigned int arr[],unsigned int columnDeck[],unsigned int rowDeck[])
{
	size_t card;
	size_t row;
	size_t column;
	size_t choose; 
	int result=0;
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
						columnDeck[card]=column;//To check their pairness.
						rowDeck[card]=row;
					}//end if
				}//end for
			}//end for
		}//end if
		else
		{
			card--;
		}
	}//end for
	
																							/*	for(int a=0;a<5;a++)
																								{
																								printf("%u ",hand[a]);
																								}
																								puts("");	*/	
		
	
	if(checkfour(columnDeck)==4)
	{
		puts("");
		printf("Hand has a fourtet.");
		result=7;
	}
	else
	{
		
		if(checktriple(columnDeck,&*ptrCh))
		{
			puts("");
			printf("Hand has a triple.\n");
			result=3;
			if(checkpair(columnDeck,&*ptrCh))
			{
				printf("Hand has a pair.\n");
				printf("It made full house now.\n");
				result=4;
			}//end if /*These algoritm is not completely true, but not wrong also.Should be optimized.*/
		}//end if
		else
		{
			*ptrCh=13;//It should be resetted.
			if(checkpair(columnDeck,&*ptrCh)==2)
			{
			printf("\nHand has two pair.\n");
			result=2;
			}
			*ptrCh=13;//It should be resetted again.
			if(checkpair(columnDeck,&*ptrCh)==1)
			{
				printf("\nHand has a pair.\n");
				result=1;
			}//end else if
			*ptrCh=13;//It should be resetted again.
			if(checkpair(columnDeck,&*ptrCh)==0)
			{
				result=0;
			}
		}//end else
			
	}//end else
		
	
	if(checkflush(columnDeck,rowDeck))
	{
		puts("");
		printf("Hand is a flush.");
		result=5;
	}	

	
	if(checkstraight(columnDeck))
	{
		puts("");
		printf("Hand is a straight.");
		result=6;
	}
	return result;
}//end deal
int dealComputer(unsigned int wDeck[][FACES],int*ptrCh,unsigned int arr[],unsigned int columnDeck[],unsigned int rowDeck[])
{
	size_t card;
	size_t row;
	size_t column;
	size_t choose; 
	int result=0;
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
						
						columnDeck[card]=column;//To check their pairness.
						rowDeck[card]=row;
					}//end if
				}//end for
			}//end for
		}//end if
		else
		{
			card--;
		}
	}//end for

	if(checkfour(columnDeck)==4)
	{
		result=7;
	}
	else
	{
		if(checktriple(columnDeck,&*ptrCh))
		{
			result=3;
			if(checkpair(columnDeck,&*ptrCh))
			{
				result=4;
			}//end if /*These algoritm is not completely true, but not wrong also.Should be optimized.*/
		}//end if
		else
		{
			*ptrCh=13;//It should be resetted.
			if(checkpair(columnDeck,&*ptrCh)==2)
			{
				result=2;
			}
			*ptrCh=13;//It should be resetted again.
			if(checkpair(columnDeck,&*ptrCh)==1)
			{
				
				result=1;
			}//end else if
			*ptrCh=13;//It should be resetted again.
			if(checkpair(columnDeck,&*ptrCh)==0)
			{
				result=0;
			}
		}//end else
			
	}//end else
		
	
	if(checkflush(columnDeck,rowDeck))
	{
		result=5;
	}	

	
	if(checkstraight(columnDeck))
	{
		result=6;
	}
	return result;
}//end deal

int checkpair(unsigned int handDeck[], int *ptr)
{
	size_t i;
	size_t j;
	
	int pairs=0;
	sortArray(handDeck);
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

int checktriple(unsigned int handDeck[],int *ptr)
{
	size_t i;
	size_t j;
	sortArray(handDeck);
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
int checkfour(unsigned int handDeck[])
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

int checkstraight(unsigned int handDeck[])
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
		printf("Player 1 wins by a=%d>b=%d.",a,b);
	}
	else if(b>a)
	{
		puts("");
		printf("Player 2 wins by b=%d>a=%d.",b,a);
	}//end else if
	else
	{
		if(*c>*d && *d!=0 && *c!=13 && *d!=13)
		{
			puts("");
			printf("Player 1 wins by check1=%d>check2=%d.",*c,*d);
		}
		else if(*d>*c && *c!=0 && *c!=13 && *d!=13)
		{
			puts("");
			printf("Player 2 wins by check2=%d>check1=%d.",*d,*c);
		}
		else if(*c==0)
		{
			puts("");
			printf("Player 1 wins by check1=0");
		}//end inner else
		else if(*d==0)
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

int evaluate(int final,unsigned int wDeck[][FACES],const char *wFace[],const char *wSuit[],unsigned int columnDeck[],unsigned int rowDeck[],unsigned int arr[])
{
	int flag;
	size_t card;
	unsigned int odd;
	unsigned int choose;
	size_t row;
	size_t column;
	int sentinel=13;
	int *ptrSentinel=&sentinel;
	
	if(final>2)
	{
		return final;
	}
	else
	{
		sortArray(columnDeck);
		if(2==final)
		{
			
			for(size_t i=0;i<5;i++)
			{
				for(size_t j=0;j<5;j++)
				{
					if(columnDeck[i]==columnDeck[j] && j!=i)	
					{
						flag=1;
						break;
					}
					flag=0;
				}//end for
				if(flag==0)
				{
					odd=i;
					break;
				}//end if
			}//end for
			pickCard(odd,arr,wDeck,columnDeck,rowDeck);

		/*	for(card=0;card<1;card++)
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
						
								columnDeck[odd]=column;//New card has been pulled.

								rowDeck[odd]=row;
							}//end if
						}//end for
					}//end for
				}//end if
				else
				{
					card--;
				}
			}//end for*/
			if(checktriple(columnDeck,&sentinel))
			{
				//Because the hand already had 2 pairs. If it passes triple check, then it means the hand has full house now
				printf("It made full house now.\n");
				final=4;
			}//end if
			sentinel=13;
			if(checkpair(columnDeck,&sentinel)==2)
			{
				printf("Hand has two pair.\n");
				final=3;
			}
		}//end if
		else if(1==final)
		{
			for(size_t i=0;i<5;i++)
			{
				for(size_t j=0;j<5;j++)
				{
					if(columnDeck[i]==columnDeck[j] && j!=i)	
					{
						flag=1;
						break;
					}
					flag=0;
				}//end for
				if(flag==0 && columnDeck[i]!=0)
				{
					columnDeck[i]=13;//trivial value.
				}//end if
			}//end for
			for(card=0;card<5;card++)
			{
				if(columnDeck[card]==13)
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
									columnDeck[card]=column;//New card has been pulled.
									rowDeck[card]=row;
								}//end if
							}//end for
						}//end for
					}//end if
				}//end if
			}//end for
			if(checkfour(columnDeck))
			{
				final=7;
			}
			else
			{
				if(checktriple(columnDeck,&sentinel))
				{
					final=3;
					if(checkpair(columnDeck,&sentinel))
					{
						final=4;
					}//end if
				}
				else
				{
					*ptrSentinel=13;//It should be resetted.
					if(checkpair(columnDeck,&sentinel)==2)
					{
						printf("\nHand has two pair.\n");
						final=2;
					}//end if
					*ptrSentinel=13;
					if(checkpair(columnDeck,&sentinel)==1)
					{
						printf("\nHand has a pair.\n");
					}//end if
					
				}//end else
				*ptrSentinel=13;
			}//end else
		}//end else if
		else
		{
			final=deal(wDeck,wFace,wSuit,&sentinel,arr,columnDeck,rowDeck);
		}//end else
		return final;
	}//end else
}//end evaluate

void pickCard(unsigned int element,unsigned int arr[],unsigned int wDeck[][FACES],unsigned int columnDeck[],unsigned int rowDeck[])
{		
	int card;
	unsigned int choose;
	size_t row;
	size_t column;
	for(card=0;card<1;card++)
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
						
						columnDeck[element]=column;//New card has been pulled.

						rowDeck[element]=row;
						}//end if
				}//end for
			}//end for
		}//end if
		else
		{
			card--;
		}
	}//end for
}//end pickCard

void printHand(unsigned int columnDeck[],unsigned int rowDeck[],const char *wFace[],const char *wSuit[])
{
	size_t i;
	printf("-------------Player's hand after replacement.------------\n");
	for(i=0;i<5;i++)
	{
			printf("%5s of %-8s\n",wFace[columnDeck[i]],wSuit[rowDeck[i]]);
	}
}//end printHand
					

			
				
			
				
			
