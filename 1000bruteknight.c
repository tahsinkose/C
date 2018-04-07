#include <stdio.h>
#include <time.h>
#include <stddef.h>
#include <stdlib.h>
#define SIZE 8

int main()
{
	
	int arr[1000]={0};
	int horizontal[SIZE] = {2,1,-1,-2,-2,-1,1,2};
    	int vertical[SIZE] = {-1,-2,-2,-1,1,2,2,1};
	srand(time( NULL ));
	for(int k=0;k<1000;k++) 
	{
		int move=0;
        int ** chessboard;
        chessboard = (int **)malloc(sizeof(int*)*SIZE);
        for(int i=0;i<SIZE;i++)
            chessboard[i] = (int *)malloc(sizeof(int)*SIZE);
        for(int i=0;i<SIZE;i++)
            for(int j=0;j<SIZE;j++)
                chessboard[i][j] = 0;
		int currentRow=3,currentColumn=3;//starting point
		
		chessboard[currentRow][currentColumn]=1;
		int counter=0;
		
		int loopStatus=0;
		while(counter<64)
		{
			for(int k=0;k<SIZE;k++)
			{
				if(currentRow+vertical[k]<=7 && currentRow+vertical[k]>=0 && 
                    currentColumn+horizontal[k]<=7 && currentColumn+horizontal[k]>=0 &&
                    (chessboard[currentRow+vertical[k]][currentColumn+horizontal[k]]==0)){
					loopStatus=0;
					break;
				}
				loopStatus=1;
			}//end for
			if(loopStatus==0)
			{	
				move = rand() % 8;
				if(currentRow+vertical[move]<=7 && currentRow+vertical[move]>=0 && 
                currentColumn+horizontal[move]<=7 && currentColumn+horizontal[move]>=0){
					if(chessboard[currentRow+vertical[move]][currentColumn+horizontal[move]]!=1)
					{
						currentRow+=vertical[move];
						currentColumn+=horizontal[move];
						chessboard[currentRow][currentColumn]=1;
						counter++;
					}//end if
				}//end if
			}//end if
			else
				break;
		}//end while
		arr[counter]++;

        for(int i=0;i<SIZE;i++)
            free(chessboard[i]);
        free(chessboard);
	}//end for
	printf("%s-------%10s\n","Length","Times");
	for(int a=0;a<1000;a++)
	{
		if(arr[a])
			printf("%d-------%10d\n",a,arr[a]);
	}//end for
}//end main
