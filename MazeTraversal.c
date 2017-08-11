#include <stdio.h>
#include <stdlib.h>

#define SIZE 12
enum Status {RIGHT,LEFT,TOP,DOWN};
void mazeTraverse(char a[][SIZE],char* ptr,enum Status gameStatus);
void printMaze(char arr[][SIZE]);


int main()
{
	
	enum Status setDirection=RIGHT;//beginning
	char maze[][SIZE]={{'#','#','#','#','#','#','#','#','#','#','#','#'},
				 {'#','.','.','.','#','.','.','.','.','.','.','#'},
				 {'.','.','#','.','#','.','#','#','#','#','.','#'},
				 {'#','#','#','.','#','.','.','.','.','#','.','#'},
				 {'#','.','.','.','.','#','#','#','.','#','.','.'},
				 {'#','#','#','#','.','#','.','#','.','#','.','#'},	
				 {'#','.','.','#','.','#','.','#','.','#','.','#'},	
				 {'#','#','.','#','.','#','.','#','.','#','.','#'},
				 {'#','.','.','.','.','.','.','.','.','#','.','#'},
				 {'#','#','#','#','#','#','.','#','#','#','.','#'},
				 {'#','.','.','.','.','.','.','#','.','.','.','#'},
				 {'#','#','#','#','#','#','#','#','#','#','#','#'}};

	char *pointToMaze=&maze[2][0];
	*pointToMaze='x';//entry of the maze.

	printMaze(maze);
	mazeTraverse(maze,&maze[2][0],setDirection);
}//end main

void mazeTraverse(char a[][SIZE],char* ptr,enum Status gameStatus)
{
	unsigned int x;
	if(a[4][11]=='x')//exit of the maze
	{
		printMaze(a);
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
					printMaze(a);
					mazeTraverse(a,ptr,gameStatus);
				}//end if
				else if(*(ptr+1)=='#')	
				{
					gameStatus=TOP;
					ptr-=x;
					*ptr='x';
					printMaze(a);
					mazeTraverse(a,ptr,gameStatus);
				}//end else if
				else if(*(ptr-x)=='#')
				{
					gameStatus=DOWN;
					ptr+=x;
					*ptr='x';
					printMaze(a);
					mazeTraverse(a,ptr,gameStatus);
				}//end else if
			}//end if
			else
			{
				gameStatus=DOWN;
				ptr+=x;
				*ptr='x';
				printMaze(a);
				mazeTraverse(a,ptr,gameStatus);
			}//end else
		}//end if
		else if (gameStatus==TOP)
		{
			if(*(ptr+1)!='#')
			{
				gameStatus=RIGHT;
				ptr++;
				*ptr='x';
				printMaze(a);
				mazeTraverse(a,ptr,gameStatus);
			}
			else if(*(ptr-x)!='#')
			{
				ptr-=x;
				*ptr='x';
				printMaze(a);
				mazeTraverse(a,ptr,gameStatus);
			}//end else
			else if(*(ptr-x)=='#')
			{
				gameStatus=LEFT;
				ptr--;
				*ptr='x';
				printMaze(a);
				mazeTraverse(a,ptr,gameStatus);
			}//end else if
		}//end else if
			
		else if(gameStatus==DOWN)
		{	
			if(*(ptr-1)=='#' &(ptr+x)!='#')
			{
				ptr+=x;
				*ptr='x';
				printMaze(a);
				mazeTraverse(a,ptr,gameStatus);
			}
			else
			{
				gameStatus=LEFT;
				ptr-=1;
				*ptr='x';
				printMaze(a);
				mazeTraverse(a,ptr,gameStatus);
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
					printMaze(a);
					mazeTraverse(a,ptr,gameStatus);
				}//end if
				else 
				{
					if(*(ptr+1)!='#')
					{
						gameStatus=RIGHT;
						ptr++;
						*ptr='x';
						printMaze(a);
						mazeTraverse(a,ptr,gameStatus);
					}
					else
					{
						gameStatus=DOWN;
						ptr+=x;
						*ptr='x';
						printMaze(a);
						mazeTraverse(a,ptr,gameStatus);
					}//end else
				}//end else
			}//end if	
			else
			{
				gameStatus=TOP;
				ptr-=x;
				*ptr='x';
				printMaze(a);
				mazeTraverse(a,ptr,gameStatus);
			}//end else
		}//end else if
	}//end else

}//end mazeTraverse
			
		
		


void printMaze(char arr[][SIZE])
{
	for(size_t i=0;i<SIZE;i++)
	{
		for(size_t j=0;j<SIZE;j++)
		{
			printf("%2c",arr[i][j]);
		}
		puts("");
	}//end for
	getchar();
}
