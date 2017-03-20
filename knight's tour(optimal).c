#include <stdio.h>
#include <time.h>
#include <stddef.h>
#include <stdlib.h>
#define SIZE 8
void check(int arr[][SIZE],int *ptrRow,int *ptrColumn,int access[][SIZE],int h[],int v[],int *ptrCheck);
int main()
{
	int chessboard[SIZE][SIZE]={0};// all squares are empty.
	int accesibility[SIZE][SIZE]={{2,3,4,4,4,4,3,2},
								  {3,4,6,6,6,6,4,3},
								  {4,6,8,8,8,8,6,4},
								  {4,6,8,8,8,8,6,4},
								  {4,6,8,8,8,8,6,4},
								  {4,6,8,8,8,8,6,4},
								  {3,4,6,6,6,6,4,3},
								  {2,3,4,4,4,4,3,2}};
	int horizontal[SIZE],vertical[SIZE];
	horizontal[0]=2,horizontal[1]=1,horizontal[2]=-1,horizontal[3]=-2,horizontal[4]=-2,horizontal[5]=-1,horizontal[6]=1,horizontal[7]=2;
	vertical[0]=-1,vertical[1]=-2,vertical[2]=-2,vertical[3]=-1,vertical[4]=1,vertical[5]=2,vertical[6]=2,vertical[7]=1;
	int currentRow=3,currentColumn=4;//starting point
	int ch=0;
	int *ptrCh=&ch;
	int *pointRow=&currentRow;
	int *pointColumn=&currentColumn;
	chessboard[currentRow][currentColumn]=1;
	int counter=0;
	while(counter<64 && ch!=1)
	{
		check(chessboard,&currentRow,&currentColumn,accesibility,horizontal,vertical,&ch);
		printf("Knight is on %d %d\n",*pointRow,*pointColumn);
		printf("%d move has been made.\n",++counter);
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
}

void check(int arr[][SIZE],int *ptrRow,int *ptrColumn,int access[][SIZE],int h[],int v[],int *ptrCheck)
{
	

	int hold=8;//holds accesibility degrees of possible moves.
	int temp;
	int flag=0;
	printf("%d ,%d\n",*ptrRow,*ptrColumn);
	
	for(int j=0;j<SIZE;j++)
	{
		if(*ptrRow+v[j]>=0 && *ptrRow+v[j]<=7 && *ptrColumn+h[j]>=0 && *ptrColumn+h[j]<=7 && arr[*ptrRow+v[j]][*ptrColumn+h[j]]!=1)
		{
			if(hold>=access[*ptrRow+v[j]][*ptrColumn+h[j]])
			{
				hold=access[*ptrRow+v[j]][*ptrColumn+h[j]];
				temp=j;
				flag=1;
			}//this algorithm for to find least accessable square.
		}//end if
	}//end for
	if(flag)
	{
		*ptrRow+=v[temp];
		*ptrColumn+=h[temp];
		arr[*ptrRow][*ptrColumn]=1;
		if(*ptrRow+2<=7 && *ptrColumn+1<=7)
		{
			access[*ptrRow+2][*ptrColumn+1]--;
		}
		else if(*ptrRow+2<=7 && *ptrColumn-1>=0)
		{
			access[*ptrRow+2][*ptrColumn-1]--;
		}	
		else if(*ptrRow+1<=7 && *ptrColumn+2<=7)
		{
			access[*ptrRow+1][*ptrColumn+2]--;
		}
		else if(*ptrRow+1<=7 && *ptrColumn-2>=0)
		{
			access[*ptrRow+1][*ptrColumn-2]--;
		}
		else if(*ptrRow-1>=0 && *ptrColumn+2<=7)
		{
			access[*ptrRow-1][*ptrColumn+2]--;
		}	
		else if(*ptrRow-1>=0&& *ptrColumn-2>=0)
		{
			access[*ptrRow-1][*ptrColumn-2]--;
		}
		else if(*ptrRow-2>=0 && *ptrColumn+1<=7)
		{
			access[*ptrRow-2][*ptrColumn+1]--;
		}
		else if(*ptrRow-2>=0 && *ptrColumn-1>=0)
		{
			access[*ptrRow-2][*ptrColumn-1]--;
		}
	}//end flag if
	else
	{	
		*ptrCheck=1;
	}
}//end check
