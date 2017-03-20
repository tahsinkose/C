#include <stdio.h>
#include <string.h>

int main()
{
	char *amount;
	char c;
	size_t i=0;
	size_t length;
	printf("Please enter your cash amount with dots at every thousand.\n");
	while((c=getchar())!='\n')
	{
		amount[i++]=c;
	}//end while
	amount[i]='\0';
	length=strlen(amount);
	
	if(length<9)
	{
		size_t j=length;
		for(;j<9;j++)
		{
			printf("*");
		}
		printf("%s\n",amount);
	}
	else
	{
		printf("%s\n",amount);
	}//end else
}
