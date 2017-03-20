#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
enum Status {RIGHT,LEFT,TOP,DOWN};
int checkmaze(int arr[][SIZE]);
int findNeighbor(int row,int column,int arr[][2]);
void mazeGenerator();
void checkwall(int Rowbefore,int Columnbefore,int Rowafter,int Columnafter, int edges[][4]);
void printMaze(char laby[][(SIZE*2)+1],int edges[][4]);
void printMazex(char arr[][(SIZE*2)+1]);
void mazeTraverse(char a[][(SIZE*2)+1],char* ptr,enum Status gameStatus,char *ptrEnd);
int mazeNumeric[SIZE][SIZE]={0};

int main()
{
	mazeGenerator();
	return 0;
}//end main

void mazeGenerator()
{
	int neighborList[SIZE][2]={0};
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
	int randpoint;
	int maxNeighbor;//counts how many neighbor point there are.
	enum Status setDirection=RIGHT;
	srand(time(NULL));
	
	randrow=rand()%SIZE;
	do 	
	{
		randcolumn=rand()%SIZE;
	}while(randcolumn!=0);//Now I determined the first visited square to be at the one of the edges of the grid.
	ptrStart=&maze[(randrow*2)+1][randcolumn];
	walls[(4*randrow)+randcolumn][0]=0;
	mazeNumeric[randrow][randcolumn]=1;//random starting point has been defined.
	while(checkmaze(mazeNumeric)!=1)
	{
		maxNeighbor=findNeighbor(randrow,randcolumn,neighborList);	
		randpoint=rand()% maxNeighbor;
		if(mazeNumeric[neighborList[randpoint][0]][neighborList[randpoint][1]]!=1)
		{
			checkwall(randrow,randcolumn,neighborList[randpoint][0],neighborList[randpoint][1],walls);
			randrow=neighborList[randpoint][0];
			randcolumn=neighborList[randpoint][1];
			mazeNumeric[randrow][randcolumn]=1;
		}	
		else
		{
			randrow=neighborList[randpoint][0];
			randcolumn=neighborList[randpoint][1];
		}//end else
	}//end while
	
	randrow=rand()%SIZE;//For final points
	do
	{
		randcolumn=rand()%SIZE;
	}while(randcolumn!=SIZE-1);//Now we guarenteed final point to be at the right edge of the square.
	walls[(4*randrow)+randcolumn][2/*denotes left side wall of the square*/]=0; 
	ptrFinal=&maze[(randrow*2)+1][SIZE*2];
	printMaze(maze,walls);
	printf("\n---------------Begin-----------------\n");
	*ptrStart='x';
	printMazex(maze);
	mazeTraverse(maze,&*ptrStart,setDirection,&*ptrFinal);
}


int findNeighbor(int row,int column,int arr[][2])
{
	int x;
	for(size_t i=0;i<SIZE;i++)
	{	
		for(size_t j=0;j<SIZE;j++)
		{
			arr[i][j]=0;
		}
	}//it should be cleaned every time.
	if(row==0 && column==0)
	{
		arr[0][0]=row+1,arr[0][1]=column,arr[1][0]=row,arr[1][1]=column+1;
		x=2;
	}
	else if(row==0 && column == SIZE-1)
	{
		arr[0][0]=row,arr[0][1]=column-1,arr[1][0]=row+1,arr[1][1]=column;
		x=2;
	}
	else if(row==SIZE-1 && column==0)
	{
		arr[0][0]=row-1,arr[0][1]=column,arr[1][0]=row,arr[1][1]=column+1;
		x=2;
	}
	else if((row==SIZE-1 && column==SIZE-1))
	{
		
		arr[0][0]=row-1,arr[0][1]=column,arr[1][0]=row,arr[1][1]=column-1;
		x=2;
	
	}
	else if(row==0 && column!=0 &&column!=SIZE-1)
	{
	
		arr[0][0]=row+1,arr[0][1]=column,arr[1][0]=row,arr[1][1]=column-1,arr[2][0]=row,arr[2][1]=column+1;
		x=3;
	
	}
	else if(row!=0 && row!=SIZE-1 && column==0)
	{
	
		arr[0][0]=row+1,arr[0][1]=column,arr[1][0]=row-1,arr[1][1]=column,arr[2][0]=row,arr[2][1]=column+1;
		
		x=3;
	}//end else if
	else if(column==SIZE-1 && row!=SIZE-1 && row!=0)
	{
	
		arr[0][0]=row+1,arr[0][1]=column,arr[1][0]=row-1,arr[1][1]=column,arr[2][0]=row,arr[2][1]=column-1;
		x=3;
	}
	else if(row==SIZE-1 && column!=0 && column!=SIZE-1)
	{	
		arr[0][0]=row,arr[0][1]=column-1,arr[1][0]=row,arr[1][1]=column+1,arr[2][0]=row-1,arr[2][1]=column;
		x=3;
	}
	else
	{
		arr[0][0]=row-1,arr[0][1]=column,arr[1][0]=row+1,arr[1][1]=column,arr[2][0]=row,arr[2][1]=column-1,arr[3][0]=row,arr[3][1]=column+1;
		x=4;
	}//end else
	return x;
}//end findNeihgbor


void checkwall(int Rowbefore,int Columnbefore,int Rowafter,int Columnafter, int edges[][4])
{	
	if(Rowbefore==Rowafter)
	{
		if (Columnbefore<Columnafter)//That means left edge of the first node, and right edge of the second node will be inserted
		{
			edges[(4*Rowbefore)+Columnbefore][2]=0;
			edges[(4*Rowafter)+Columnafter][0]=0;
		}
		else
		{
			edges[(4*Rowbefore)+Columnbefore][0]=0;
			edges[(4*Rowafter)+Columnafter][2]=0;
		}//end else
	}//end if
	else if(Columnbefore==Columnafter)
	{
		if (Rowbefore<Rowafter)
		{
			edges[(4*Rowbefore)+Columnbefore][3]=0;
			edges[(4*Rowafter)+Columnafter][1]=0;
		}//end if
		else
		{
			edges[(4*Rowbefore)+Columnbefore][1]=0;
			edges[(4*Rowafter)+Columnafter][3]=0;
		}//end else
	}//end else if
}//end checkwall
	
int checkmaze(int arr[][SIZE])
{
	for(size_t i=0;i<SIZE;i++)
	{
		for(size_t j=0;j<SIZE;j++)
		{
			if(0==arr[i][j])
			{
				return 0;
			}//end if
		}//end for
	}//end for
	return 1;
}//end checkmaze*/

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

				
	
