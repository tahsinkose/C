#include <stdio.h>
#include <stddef.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100
void perfect(int number);

int main()
{
	for(int i=1;i<=10000;i++)
	{
		perfect(i);
	}
}//end main

void perfect(int number)
{
	int check=0;
	int j=1;
	int i=0;
	
	int factors[MAXSIZE];
	for(;j<number;j++)
	{
		if(number%j==0)
		{
			check += j;
			factors[i] = j;	
			i++;
		}//end if
	}//end for
	if(check==number)
	{	
		for(j=0;j<i;j++)
		{
			printf("%d",factors[j]);
			printf("*");
		}//end for
		printf("= %d",check);
		puts("");
	}//end if
}//end perfect

	
