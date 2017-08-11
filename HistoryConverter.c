#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20
int main()
{
	char date[SIZE];
	const char s[2]="/";
	printf("Please enter the date in slash format as like '01/01/2047': ");
	char c;
	char *tok;
	int count=0,month,day,year;
	size_t i=0;
	while((c=getchar())!='\n')
	{
		date[i++]=c;
	}
	date[i]='\0';
	
	
	tok=strtok(date,s);
	while(tok!=NULL)
	{
		if(count==0)
		{
			month=atoi(tok);
			switch(month)
			{
				case 1:
					printf("January");
					break;
				case 2:
					printf("February");
					break;
				case 3:
					printf("March");
					break;
				case 4:
					printf("April");
					break;
				case 5:
					printf("May");
					break;
				case 6:
					printf("June");
					break;
				case 7:
					printf("July");
					break;
				case 8:
					printf("August");
					break;
				case 9:
					printf("September");
					break;
				case 10:
					printf("October");
					break;
				case 11:
					printf("November");
					break;
				case 12:
					printf("December");
					break;
			}//end switch
			
		}//end if
		else if(count==1)
		{
			day=atoi(tok);
			printf("%3d,",day);
		}//end else if
		else if(count==2)
		{
			year=atoi(tok);
			printf("%5d",year);
		}//end else if
		//printf("%s\n",tok);
		tok=strtok(NULL,s);
		count++;
	}
	puts("");
}  
