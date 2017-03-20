#include <stdio.h>
#include <stdlib.h>

void dream(int a,int b);


int main()
{
	int level;
	int step = 1;//recursion step
	printf ("Enter the recursion level of dreams : ");
	scanf("%d",&level);
	printf("To live in a dream\n");
	dream(level,step);
	
	
	printf("makes hard to unravel the inception");
}//end main

void dream(int a,int b)
{
	int i=0;
	if (a>=1)
	{	
		for(;i<b;i++)
			printf("***");
		printf ("as a rank %d thief within a dream \n",a);
		dream(a-1,b+1);
		for (i=0;i<b;i++)
			printf("***");
		printf("caught by the police of rank %d\n",a+1);
	}//end if
	
	else
	{
		
	}//end else
}//end function thief


