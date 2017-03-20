#include <stdio.h>
#include <time.h>
#include <stddef.h>
#include <stdlib.h>
#define SIZE 8

int main()
{
	int move=0;
	int chessboard[SIZE][SIZE]={0};// all squares are empty.
	
	int horizontal[SIZE],vertical[SIZE];
	horizontal[0]=2,horizontal[1]=1,horizontal[2]=-1,horizontal[3]=-2,horizontal[4]=-2,horizontal[5]=-1,horizontal[6]=1,horizontal[7]=2;
	vertical[0]=-1,vertical[1]=-2,vertical[2]=-2,vertical[3]=-1,vertical[4]=1,vertical[5]=2,vertical[6]=2,vertical[7]=1;
	
	int currentRow=3,currentColumn=3;//starting point
	srand(time( NULL ));
	chessboard[currentRow][currentColumn]=1;
	int counter=0;
	printf("Knight is on %d %d\n",currentRow,currentColumn);
	printf("%d move has been made.\n",++counter);
	int loopStatus=0;
	while(counter<64)
	{
		for(int k=0;k<SIZE;k++)
		{
			if((chessboard[currentRow+vertical[k]][currentColumn+horizontal[k]]==0) && currentRow+vertical[k]<=7 && currentRow+vertical[k]>=0 && currentColumn+horizontal[k]<=7 && currentColumn+horizontal[k]>=0)
			{
				loopStatus=0;
				break;
			}
			loopStatus=1;
		}//end for
		if(loopStatus==0)
		{	
			move = rand() % 8;
			if(currentRow+vertical[move]<=7 && currentRow+vertical[move]>=0 && currentColumn+horizontal[move]<=7 && currentColumn+horizontal[move]>=0)
			{
			
				if(chessboard[currentRow+vertical[move]][currentColumn+horizontal[move]]!=1)
				{
					currentRow+=vertical[move];
					currentColumn+=horizontal[move];
					chessboard[currentRow][currentColumn]=1;
					printf("Knight is on %d %d\n",currentRow,currentColumn);
					printf("%d move has been made.\n",++counter);
				}//end if
				else
				{
					printf("move %d goes to an already filled square.\n",move);
				}//end else
			}//end if
			else
			{
				printf("Move %d goes to an invalid square.\n",move);
			}//end else
		}//end if
		else
		{
			printf("No valid move is left.\n");
			break;
		}//end else
			
	}//end while
	int i=0;
	for(;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			printf("%4c",chessboard[i][j] ? '*' : '-');
		}
		puts("");
	}//end for
	
}//end main


