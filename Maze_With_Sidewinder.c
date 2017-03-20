
/*Work through the grid row-wise, starting with the cell at 0,0. Initialize the “run” set to be empty.
Add the current cell to the “run” set.
For the current cell, randomly decide whether to carve east or not.
If a passage was carved, make the new cell the current cell and repeat steps 2-4.
If a passage was not carved, choose any one of the cells in the run set and carve a passage north. Then empty the run set, set the next cell in the row to be the current cell, and repeat steps 2-5.
Continue until all rows have been processed.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
enum Status {RIGHT,LEFT,TOP,DOWN};

void mazeGenerator();
void printMaze(char laby[][(SIZE*2)+1],int edges[][4]);
void printMazex(char arr[][(SIZE*2)+1]);
void mazeTraverse(char a[][(SIZE*2)+1],char* ptr,enum Status gameStatus,char *ptrEnd);
void truncate(int arr[]);

int main()
{
	mazeGenerator();
	return 0;
}//end main

void mazeGenerator()
{
	
	int walls[SIZE*SIZE][4];	
	char maze[(SIZE*2)+1][(SIZE*2)+1];
	char *ptrStart;
	char *ptrFinal;
	size_t i;size_t j;
	for(i=0;i<SIZE*SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			walls[i][j]=1;
		}//end for
	}//Now we have a full walled maze*/
	
	for(i=0;i<=SIZE*2;i++)
	{
		for(j=0;j<=SIZE*2;j++)
		{
			maze[i][j]='.';
			//printf("%2c",maze[i][j]);
		}//end for
	}//end for  --> All valid squares are set as dots.
	int randrow;
	int randcolumn;
	int runGrid[SIZE];
	int *ptrGrid;
	ptrGrid=runGrid;
	
	enum Status setDirection=RIGHT;
	srand(time(NULL));
	
	randrow=rand()%SIZE;
	do 	
	{
		randcolumn=rand()%SIZE;
	}while(randcolumn!=0);//Now I determined the first visited square to be at the one of the edges of the grid.
	ptrStart=&maze[(randrow*2)+1][randcolumn];
	walls[(4*randrow)+randcolumn][0]=0;//starting point has been denoted.
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			*ptrGrid=(4*i)+j;
			if(i==0 && j<SIZE-1)
			{
				walls[(4*i)+j][2]=0;
				walls[(4*i)+j+1][0]=0;
			}
			else if(i!=0)
			{
				int rndEast;
				rndEast=rand()%2;//This will decide whether the current cell will be carved to east or not.
				if(rndEast==0 && j<SIZE-1)
				{
					walls[(4*i)+j][2]=0;
					walls[(4*i)+j+1][0]=0;
					ptrGrid++;
				}//end if
				else
				{
					ptrGrid++;//This is necessary for the arithmetic at the two lines down.
					int size;
					int rndNorth;
					size=ptrGrid-&runGrid[0];
					rndNorth=rand()%size;
					walls[runGrid[rndNorth]][1]=0;
					walls[runGrid[rndNorth]-SIZE][3]=0;
					truncate(runGrid);
					ptrGrid=runGrid;
				}//end else
			}//end else
		}//end for
	}//end for
																			for(i=0;i<SIZE*SIZE;i++)
																			{
																				for(j=0;j<SIZE;j++)
																				{
																					printf("%2d",walls[i][j]);
																				}
																				puts("");
																			}
	randrow=rand()%SIZE;//For final points
	do
	{
		randcolumn=rand()%SIZE;
	}while(randcolumn!=SIZE-1);//Now we guarenteed final point to be at the right edge of the square.
	printf("\n %d,%d\n",randrow,randcolumn);
	walls[(4*randrow)+randcolumn][2/*denotes left side wall of the square*/]=0; 
	ptrFinal=&maze[(randrow*2)+1][SIZE*2];
	printMaze(maze,walls);
	printf("\n---------------Begin-----------------\n");
	*ptrStart='x';
	printMazex(maze);
	mazeTraverse(maze,&*ptrStart,setDirection,&*ptrFinal);
}//end mazegenerator





void printMaze(char laby[][(SIZE*2)+1],int edges[][4])//----------------------This function must be generalized. In actual circumstance it can be only used by 9 width-height mazes.
{
	for(size_t i=0;i<SIZE*SIZE;i++)
	{
		if (i>=0 && i<=3)
		{
			if(edges[i][0]==1)
			{
				laby[0][(i%4)*2]='#',laby[1][(i%4)*2]='#',laby[2][(i%4)*2]='#';
			}
			if(edges[i][1]==1)
			{
				laby[0][(i%4)*2]='#',laby[0][((i%4)*2)+1]='#',laby[0][((i%4)*2)+2]='#';
			}
			if(edges[i][2]==1)
			{
				laby[0][((i%4)*2)+2]='#',laby[1][((i%4)*2)+2]='#',laby[2][(((i%4)*2)+2)]='#';
			}
			if(edges[i][3]==1)
			{
				laby[2][(i%4)*2]='#',laby[2][((i%4)*2)+1]='#',laby[2][((i%4)*2)+2]='#';
			}
		}//end if
		else if (i>=4 && i<=7)
		{
			if(edges[i][0]==1)
			{
				laby[2][(i%4)*2]='#',laby[3][(i%4)*2]='#',laby[4][(i%4)*2]='#';
			}
			if(edges[i][1]==1)
			{
				laby[2][(i%4)*2]='#',laby[2][((i%4)*2)+1]='#',laby[2][((i%4)*2)+2]='#';
			}
			if(edges[i][2]==1)
			{
				laby[2][((i%4)*2)+2]='#',laby[3][((i%4)*2)+2]='#',laby[4][((i%4)*2)+2]='#';
			}
			if(edges[i][3]==1)
			{
				laby[4][(i%4)*2]='#',laby[4][((i%4)*2)+1]='#',laby[4][((i%4)*2)+2]='#';
			}
		}//end else if
		else if (i>=8 && i<=11)
		{
			if(edges[i][0]==1)
			{
				laby[4][(i%4)*2]='#',laby[5][(i%4)*2]='#',laby[6][(i%4)*2]='#';
			}
			if(edges[i][1]==1)
			{
				laby[4][(i%4)*2]='#',laby[4][((i%4)*2)+1]='#',laby[4][((i%4)*2)+2]='#';	
			}
			if(edges[i][2]==1)
			{
				laby[4][((i%4)*2)+2]='#',laby[5][((i%4)*2)+2]='#',laby[6][((i%4)*2)+2]='#';
			}
			if(edges[i][3]==1)
			{
				laby[6][(i%4)*2]='#',laby[6][((i%4)*2)+1]='#',laby[6][((i%4)*2)+2]='#';
			}
		}//end else if
		else 
		{
			if(edges[i][0]==1)
			{
				laby[6][(i%4)*2]='#',laby[7][(i%4)*2]='#',laby[8][(i%4)*2]='#';
			}
			if(edges[i][1]==1)
			{
				laby[6][(i%4)*2]='#',laby[6][((i%4)*2)+1]='#',laby[6][((i%4)*2)+2]='#';
			}
			if(edges[i][2]==1)
			{
				laby[6][((i%4)*2)+2]='#',laby[7][(((i%4)*2)+2)]='#',laby[8][((i%4)*2)+2]='#';
			}
			if(edges[i][3]==1)
			{
				laby[8][(i%4)*2]='#',laby[8][((i%4)*2)+1]='#',laby[8][((i%4)*2)+2]='#';
			}
		}//end if
	}//end for
	for(size_t x=0;x<(SIZE*2)+1;x++)
	{	
		for(size_t y=0;y<(SIZE*2)+1;y++)
		{
			printf("%2c",laby[x][y]);
		}
		puts("");
	}
}//end printmaze

void truncate(int arr[])
{
	size_t i=0;
	for(;i<SIZE;i++)
	{
		arr[i]=0;
	}
}//end truncate;

void mazeTraverse(char a[][(SIZE*2)+1],char* ptr,enum Status gameStatus,char *ptrEnd)
{
	unsigned int x;
	if(*ptrEnd=='x')//exit of the maze
	{
		printMazex(a);
	}//end if
	else
	{
		x=sizeof(a[0]);
		
		if(gameStatus==RIGHT)
		{
			
			if(*(ptr+x)=='#')//checks that right of the actual square is whether wall or not.
			{	
				if(*(ptr+1)!='#')
				{
					ptr++;
					*ptr='x';
					printMazex(a);
					mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd);
				}//end if
				else if(*(ptr+1)=='#')	
				{
					gameStatus=TOP;
					ptr-=x;
					*ptr='x';
					printMazex(a);
					mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd);
				}//end else if
				else if(*(ptr-x)=='#')
				{
					gameStatus=DOWN;
					ptr+=x;
					*ptr='x';
					printMazex(a);
					mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd);
				}//end else if
			}//end if
			else
			{
				gameStatus=DOWN;
				ptr+=x;
				*ptr='x';
				printMazex(a);
				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd);
			}//end else
		}//end if
		else if (gameStatus==TOP)
		{
			if(*(ptr+1)!='#')
			{
				gameStatus=RIGHT;
				ptr++;
				*ptr='x';
				printMazex(a);
				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd);
			}
			else if(*(ptr-x)!='#')
			{
				ptr-=x;
				*ptr='x';
				printMazex(a);
				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd);
			}//end else
			else if(*(ptr-x)=='#')
			{
				gameStatus=LEFT;
				ptr--;
				*ptr='x';
				printMazex(a);
				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd);
			}//end else if
		}//end else if
			
		else if(gameStatus==DOWN)
		{	
			if(*(ptr-1)=='#' &&*(ptr+x)!='#')
			{
				ptr+=x;
				*ptr='x';
				printMazex(a);
				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd);
			}//end if
			else if(*(ptr-1)=='#' && *(ptr+x)=='#')
			{
				gameStatus=TOP;
				ptr-=x;
				*ptr='x';
				printMazex(a);
				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd);
			}
			else
			{
				gameStatus=LEFT;
				ptr-=1;
				*ptr='x';
				printMazex(a);
				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd);
			}//end else
		}//end else if
		else if(gameStatus==LEFT)
		{
			if(*(ptr-x)=='#')
			{
				if(*(ptr-1)!='#')
				{
					ptr-=1;
					*ptr='x';	
					printMazex(a);
					mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd);
				}//end if
				else 
				{
					if(*(ptr+1)!='#')
					{
						gameStatus=RIGHT;
						ptr++;
						*ptr='x';
						printMazex(a);
						mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd);
					}
					else
					{
						gameStatus=DOWN;
						ptr+=x;
						*ptr='x';
						printMazex(a);
						mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd);
					}//end else
				}//end else
			}//end if	
			else
			{
				gameStatus=TOP;
				ptr-=x;
				*ptr='x';
				printMazex(a);
				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd);
			}//end else
		}//end else if
	}//end else

}//end mazeTraverse

void printMazex(char arr[][(SIZE*2)+1])
{
	for(size_t i=0;i<(SIZE*2)+1;i++)
	{
		for(size_t j=0;j<(SIZE*2)+1;j++)
		{
			printf("%2c",arr[i][j]);
		}
		puts("");
	}//end for
	getchar();
}//print maze with x's on every visited square.

				
	
