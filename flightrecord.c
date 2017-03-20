#include <stdio.h>

#define MAX 11
int stringCompare(char str1[],char str2[]);
int main()
{
	int firstBeg=1,check,i=1,ecoBeg=6,j=1,size=0,x;
	char c;
	int seats[MAX]={0};
	char answer[size];
	while(i<=10)
	{
		printf("Please type 1 for \"first class\"");
		puts("");	
		printf("Please type 2 for \"economy\"");
		puts("");
		scanf("%d",&check);
		while(getchar()!='\n')
		{
		}
		if(check==1 && firstBeg<=5)
		{
			seats[firstBeg++]=1;
				
		}
		
		else if(check==1 && firstBeg>=6)
		{
			printf("First class is full. If you accept we can split a seat from economy class.\n");
			while ((c=getchar())!='\n')
			{
				answer[size++]=c;
				
			}
			
			answer[size]='\0';
			
			x=stringCompare(answer,"yes");
			
			if(x)
			{
				printf("%s is answer",answer);
				puts("");
			}
			if(x && ecoBeg<=10)
			{
				seats[ecoBeg++]=1;
			}
			else
			{
				printf("Next flight leaves in 3 hours.\n");
				
				
			}
		}//end else if
		else if(check==2 && ecoBeg <= 10)
		{
			seats[ecoBeg++]=1;
		}
		else if(check==2 && ecoBeg>10)
		{
			printf("Economy class is full. If you accept we can split a seat from first class.\n");	
			while ((c=getchar())!='\n')
			{
				answer[size]=c;
				size++;
			}
			answer[size]='\0';
			x=stringCompare(answer,"yes");
			
			if(x && firstBeg<=5)
			{
				seats[firstBeg++]=1;
			}
			else
			{
				printf("Next flight leaves in 3 hours.\n");
				
				
			}//end else
		}//end else if
		i++;
		size=0;
	}
	printf("--------------FIRST CLASS---------------\n");
	for(;j<=5;j++)
	{
		printf("%d",seats[j]);
		printf("%c",j%2==0 ? '\n' : '\t');
	}	
	puts("");
	printf("-------------ECONOMY CLASS--------------\n");
	for(;j<=10;j++)	
	{
		printf("%d",seats[j]);
		printf("%c",j%2==1 ? '\n' : '\t');
	}
	return 0;
}
	

int stringCompare(char str1[],char str2[]){
    int i=0,flag=0;
   
    while(str1[i]!='\0' && str2[i]!='\0'){
         if(str1[i]!=str2[i]){
             flag=1;
             break;
         }
         i++;
    }

    if (flag==0 && str1[i]=='\0' && str2[i]=='\0')
         return 1;
    else
         return 0;

}

