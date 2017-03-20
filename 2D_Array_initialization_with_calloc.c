#include <stdio.h>
#include <stdlib.h>

void print2DArray(int *arr,int row,int col);


int main()
{
	
	int row1,row2,col1,col2;
	int *arrP1,*arrP2;
	int i,j;

	printf ("%s","Enter row and column number of a 2-D array : ");
	scanf("%d %d",&row1,&col1);
	
	printf ("%s","Enter row and column number of another 2-D array : ");
	scanf("%d %d",&row2,&col2);
	
	
	arrP1=(int *)calloc(row1*col1,sizeof(int));
	arrP2=(int *)calloc(row2*col2,sizeof(int));
	
	
	printf("\n sizeof(array) yields the size of the array as %lu bytes\n",sizeof(int)*row1*col1);

	for (i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			scanf("%d",arrP1);
			arrP1++;
		}
	}/*end for*/

	arrP1-=row1*col1;
	for (i=0;i<row2;i++)
	{
		for (j=0;j<col2;j++)
		{
			scanf("%d",arrP2);
			arrP2++;
	
		}/*end inner for*/
	}/*end outer for*/

	arrP2-=row2*col2;
	puts("First 2-D array is: ");
	
	print2DArray(arrP1,row1,col1);
	
	puts("");
	puts("Second 2-D array is ");
	puts("");
	
	print2DArray(arrP2,row2,col2);
	free(arrP1);
	free(arrP2);
	return 0;
}/*end main*/


void print2DArray(int *arr,int row,int col)
{
	size_t i;
	size_t j;

	for(i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
			printf("%5d",arr[i*row+j]);
		}
		
		puts("");
	}
}

