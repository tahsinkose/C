#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SUITS 4
#define FACES 13
#define CARDS 52


void shuffle(int wDeck[][FACES]);
void swap(int arr[][FACES],size_t nRow,size_t nColumn,size_t oRow,size_t oColumn);
void printDeck(int arr[][FACES]);
int main()
{
	int deck[][FACES]={{1,2,3,4,5,6,7,8,9,10,11,12,13},
					   {14,15,16,17,18,19,20,21,22,23,24,25,26},
					   {27,28,29,30,31,32,33,34,35,36,37,38,39},		
					   {40,41,42,43,44,45,46,47,48,49,50,51,52}};
	printDeck(deck);
	puts("");
	
	srand(time(NULL));

	shuffle(deck);
	shuffle(deck);
	shuffle(deck);
	printDeck(deck);
	
	return 0;
}

void shuffle(int wDeck[][FACES])
{
	
	size_t newRow;//this will be new row number of the card
	size_t newColumn;//this will be new column number of the card
	for(int card=1;card<=52;card++)
	{
		int flag=0;//to reset.
		for(size_t row=0;row<SUITS;row++)
		{
			if(flag)
			{
				break;
			}
			for(size_t column=0;column<FACES;column++)
			{
				if (wDeck[row][column]==card)
				{
					newRow=rand()%SUITS;
					newColumn=rand()%FACES;
					swap(wDeck,newRow,newColumn,row,column);
					flag=1;
					break;
				}
			}//at least one loop is terminated without any trivial progress.
		}//end for	
	}//end for
}//end shuffle

void swap(int arr[][FACES],size_t nRow,size_t nColumn,size_t oRow,size_t oColumn)
{
	int hold;
	hold=arr[nRow][nColumn];
	arr[nRow][nColumn]=arr[oRow][oColumn];
	arr[oRow][oColumn]=hold;
}//end swap,

void printDeck(int arr[][FACES])
{
	for(size_t i=0;i<SUITS;i++)
	{
		for(size_t j=0;j<FACES;j++)
		{
			printf("%3d %c",arr[i][j],(j==12) ? '\n' : ' ');
		}//end for
	}//end for
}//end printDeck

