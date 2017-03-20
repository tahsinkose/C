#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FINAL 69
int main()
{
	int tortoise=0;
	int hare=0;// beginning conditions for both
	
	char course[FINAL+1];
	course[0]='B';
	
	for(size_t i=1;i<FINAL+1;i++)
	{
		course[i]='-';
	}
	//course is filled
	for(size_t j=0;j<FINAL+1;j++)
	{
		printf("%2c",course[j]);
	}//end for
	puts("");
	//printed beginning condition.
	printf("BANG !!!!!\nAND THEY'RE OFF !!!!!\n");
	srand(time(NULL));
	for(int tour=1;course[FINAL]=='-';tour++)
	{
		int i;
		i=1 + rand()%10;
		printf(" i = %d\n",i);
		if(i>=1 && i<=2)
		{
			course[tortoise]='-';
			if((tortoise+3)>FINAL)
				tortoise=FINAL;
			else
				tortoise+=3;
		}
		else if(i>=3 && i<=4)
		{
			course[tortoise]='-';
			course[hare]='-';
			if((tortoise+3)>FINAL)
				tortoise=FINAL;
			else
				tortoise+=3;
			if((hare+9)>FINAL)
				hare=FINAL;
			else
				hare+=9;
		}	
		else if(i>4 && i<=5)
		{
			course[tortoise]='-';
			course[hare]='-';
			if((tortoise+3)>FINAL)
				tortoise=FINAL;
			else
				tortoise+=3;
			if((hare-12)<0)
			{
				
				hare=0;
			}
			else
			{
				hare-=12;
			}
		}
		else if(i>=6 && i<=7)
		{
			course[tortoise]='-';
			course[hare]='-';
			if((tortoise-6)<0)
			{
				
				tortoise=0;
			}
			else
				tortoise-=6;
			hare+=1;
		}
		else if(i>7 && i<=8)
		{
			course[tortoise]='-';
			course[hare]='-';
			tortoise+=1;
			hare+=1;
		}
		else
		{
			course[tortoise]='-';
			course[hare]='-';
			tortoise+=1;
			if((hare-2)<0)
			{
				hare=0;
			}
			else
				hare-=2;
		}//end else

		//Now it's time to decide where they are after their movements.
		
		
		if(tortoise==hare)
		{
			course[tortoise]='B';//It could be written as course[hare] as well, since they're equal, it doesn't matter which one to subscprit.
			printf("OUCH !!!!!\n");
		}
		else 
		{
			course[tortoise]='T';
			course[hare]='H';
		}
			
	
		for(size_t j=0;j<FINAL+1;j++)
		{
			printf("%2c",course[j]);
		}//end for
		puts("");
		getchar();
	}//end while
	if(course[FINAL]=='T')
		printf("Tortoise is the winner.");
	else
		printf("Hare is the winner.");
		
		
}
	

