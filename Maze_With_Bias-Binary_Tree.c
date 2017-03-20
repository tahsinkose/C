#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
enum Status {RIGHT,LEFT,TOP,DOWN};


void mazeGenerator();
void printMaze(char laby[][(SIZE*2)+1],int edges[][4]);
void printMazex(char arr[][(SIZE*2)+1]);
void mazeTraverse(char a[][(SIZE*2)+1],char* ptr,enum Status gameStatus,char *ptrEnd,char *ptrStart);


int main()
{
	mazeGenerator();
	printf("Exit has been succesfully found.\n");
	return 0;
}//end main

void mazeGenerator()
{
	int pattern;
	int walls[SIZE*SIZE][4];	
	char maze[(SIZE*2)+1][(SIZE*2)+1];
	char *ptrInit,*ptrHoldStart;
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
			
		}//end for
	}//end for  --> All valid squares are set as dots.
	int randrow;
	int randcolumn;
	
	
	enum Status setDirection=RIGHT;
	srand(time(NULL));
	
	randrow=rand()%SIZE;

	do 	
	{
		randcolumn=rand()%SIZE;
	}while(randcolumn!=0);//Now I determined the first visited square to be at the one of the edges of the grid.
	ptrInit=&maze[(randrow*2)+1][randcolumn];
	ptrHoldStart=ptrInit;
	walls[(4*randrow)+randcolumn][0]=0;
	printf("Please decide what pattern will have the biased maze:\n1-Northwest\n2-Northeast\n3-Southwest\n4-Southeast : ");
	scanf("%d",&pattern);
	
	
	int rnd;
	if(pattern==1)
	{
		for(i=0;i<SIZE;i++)
		{
			for(j=0;j<SIZE;j++)
			{
				if(i==0 && j==0)
					continue;
				else if(i==0 && j!=0)
				{
					walls[(4*i)+j][0]=0;//these are obligatory, since we can't delete the top walls.
					walls[(4*i)+j-1][2]=0;//when a latter square's left wall is deleted, the corresponding right wall of the previous square should be deleted,too.
				}
				else if(j==0 && i!=0)
				{
					walls[(4*i)+j][1]=0;
					walls[(4*i)+j-SIZE][3]=0;
				}
				else
				{
					rnd=rand()%2; // 0 means horizontal walls be deleted, and 1 means vertical walls be deleted.
					switch(rnd)
					{
						case 0:
							walls[(4*i)+j][0]=0;
							walls[(4*i)+j-1][2]=0;
							break;
						case 1:
							walls[(4*i)+j][1]=0;
							walls[(4*i)+j-SIZE][3]=0;
							break;
					}//end switch
				}//end else
			}//end for
		}//end for
	}//end if
	else if(pattern == 2)
	{
		for(i=0;i<SIZE;i++)
		{
			for(j=0;j<SIZE;j++)
			{
				if(i==0 && j==SIZE-1)
					continue;
				else if(i==0 && j!=SIZE-1)
				{
					walls[(4*i)+j][2]=0;//these are obligatory, since we can't delete the top walls.
					walls[(4*i)+j+1][0]=0;//when a latter square's left wall is deleted, the corresponding right wall of the previous square should be deleted,too.
				}//end else if
				else if(j==SIZE-1 && i!=0)
				{
					walls[(4*i)+j][1]=0;
					walls[(4*i)+j-SIZE][3]=0;
				}
				else
				{
					rnd=rand()%2; // 0 means horizontal walls be deleted, and 1 means vertical walls be deleted.
					switch(rnd)
					{
						case 0:
							walls[(4*i)+j][2]=0;
							walls[(4*i)+j+1][0]=0;
							break;
						case 1:
							walls[(4*i)+j][1]=0;
							walls[(4*i)+j-SIZE][3]=0;
							break;
					}//end switch
				}//end else
			}//end for
		}//end for
	}//end else if
	else if(pattern==3)
	{
		for(i=0;i<SIZE;i++)
		{
			for(j=0;j<SIZE;j++)
			{
				if(i==SIZE-1 && j==0)
					continue;
				else if(i!=SIZE-1 && j==0)
				{
					walls[(4*i)+j][3]=0;
					walls[(4*i)+j+SIZE][1]=0;
				}//end else if
				else if(i==SIZE-1 && j!=0)
				{
					walls[(4*i)+j][0]=0;//these are obligatory, since we can't delete the top walls.
					walls[(4*i)+j-1][2]=0;//when a latter square's left wall is deleted, the corresponding right wall of the previous square should be deleted,too.
				}
				else
				{
					rnd=rand()%2; // 0 means horizontal walls be deleted, and 1 means vertical walls be deleted.
					switch(rnd)
					{
						case 0:
							walls[(4*i)+j][0]=0;
							walls[(4*i)+j-1][2]=0;
							break;
						case 1:
							walls[(4*i)+j][3]=0;
							walls[(4*i)+j+SIZE][1]=0;
							break;
					}//end switch
				}//end else
			}//end for
		}//end for
	}//end else if
	else
	{
		for(i=0;i<SIZE;i++)
		{
			for(j=0;j<SIZE;j++)
			{
				if(i==SIZE-1 && j==SIZE-1)
					continue;
				else if(i==SIZE-1 && j!=SIZE-1)
				{
					walls[(4*i)+j][2]=0;
					walls[(4*i)+j+1][0]=0;
				}//end else if
				else if(j==SIZE-1 && i!=SIZE-1)
				{
					walls[(4*i)+j][3]=0;//these are obligatory, since we can't delete the top walls.
					walls[(4*i)+j+SIZE][1]=0;//when a latter square's left wall is deleted, the corresponding right wall of the previous square should be deleted,too.
				}//end else if
				else
				{
					rnd=rand()%2; // 0 means horizontal walls be deleted, and 1 means vertical walls be deleted.
					switch(rnd)
					{
						case 0:
							walls[(4*i)+j][2]=0;
							walls[(4*i)+j+1][0]=0;
							break;
						case 1:
							walls[(4*i)+j][3]=0;
							walls[(4*i)+j+SIZE][1]=0;
							break;
					}//end switch
				}
			}//end for
		}//end for
	}//end else
		
														


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
	walls[(4*randrow)+randcolumn][2/*denotes left side wall of the square*/]=0; 
	ptrFinal=&maze[(randrow*2)+1][SIZE*2];
	printMaze(maze,walls);
	printf("\n---------------Begin-----------------\n");
	*ptrInit='x';
	printMazex(maze);
	mazeTraverse(maze,&*ptrInit,setDirection,&*ptrFinal,&*ptrHoldStart);
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

void mazeTraverse(char a[][(SIZE*2)+1],char* ptr,enum Status gameStatus,char *ptrEnd,char *ptrStart)
{
	unsigned int x;
	if(*ptrEnd=='x')//exit of the maze
	{
		printMazex(a);
	}//end if
	else
	{
		x=sizeof(a[0]);
		if(ptr==ptrStart)
		{
			gameStatus=RIGHT;
		}
		if(gameStatus==RIGHT)
		{
			if(*(ptr+x)=='#')//checks that right of the actual square is whether wall or not.
			{	
				if(*(ptr+1)!='#')
				{
					ptr++;
					*ptr='x';
					printMazex(a);
					mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd,&*ptrStart);
				}//end if
				else if(*(ptr+1)=='#')	
				{
					if(*(ptr-x)=='#')
					{
						gameStatus=LEFT;	
						ptr--;
						*ptr='x';
						printMazex(a);
						mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd,&*ptrStart);
					}//end if
					else
					{
						gameStatus=TOP;
						ptr-=x;
						*ptr='x';
						printMazex(a);
						mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd,&*ptrStart);
					}//end else
				}//end else if
				else if(*(ptr-x)=='#')
				{
					gameStatus=DOWN;
					ptr+=x;
					*ptr='x';
					printMazex(a);
					mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd,&*ptrStart);
				}//end else if
			}//end if
			else
			{
				gameStatus=DOWN;
				ptr+=x;
				*ptr='x';
				printMazex(a);
				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd,&*ptrStart);
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

				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd,&*ptrStart);
			}
			else if(*(ptr-x)!='#')
			{
				ptr-=x;
				*ptr='x';
				printMazex(a);
				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd,&*ptrStart);
			}//end else
			else if(*(ptr-x)=='#' && *(ptr-1)!='#')
			{
				gameStatus=LEFT;
				ptr--;
				*ptr='x';
				printMazex(a);
				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd,&*ptrStart);
			}//end else if
			else
			{
				gameStatus=DOWN;
				ptr+=x;
				*ptr='x';
				printMazex(a);
				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd,&*ptrStart);
			}//end else
		}//end else if
			
		else if(gameStatus==DOWN)
		{	
			if(*(ptr-1)!='#')
			{
				gameStatus=LEFT;
				ptr--;
				*ptr='x';
				printMazex(a);
				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd,&*ptrStart);
			}
			else if(*(ptr-1)=='#' &&*(ptr+x)!='#')
			{
				ptr+=x;
				*ptr='x';
				printMazex(a);
				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd,&*ptrStart);
			}//end if
			else if(*(ptr-1)=='#' && *(ptr+x)=='#' && *(ptr+1)!='#')
			{
				gameStatus=RIGHT;
				ptr++;
				*ptr='x';
				printMazex(a);
				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd,&*ptrStart);
			}
			else
			{
				gameStatus=TOP;
				ptr-=x;
				*ptr='x';
				printMazex(a);
				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd,&*ptrStart);
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
					mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd,&*ptrStart);
				}//end if
				else 
				{
					if(*(ptr+1)!='#' && *(ptr+x)=='#')
					{
						gameStatus=RIGHT;
						ptr++;
						*ptr='x';
						printMazex(a);
						mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd,&*ptrStart);
					}
					else
					{
						gameStatus=DOWN;
						ptr+=x;
						*ptr='x';
						printMazex(a);
						mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd,&*ptrStart);
					}//end else
				}//end else
			}//end if	
			else
			{
				gameStatus=TOP;
				ptr-=x;
				*ptr='x';
				printMazex(a);
				mazeTraverse(a,&*ptr,gameStatus,&*ptrEnd,&*ptrStart);
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

				
	
