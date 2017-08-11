#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void printStrings(char ** strings,int size){

	for(int j=0;j<size;j++)
	{
		printf("%s\n",strings[j]);
	}
}

int main()
{
	int count = 0,total_string_number;
	char **strings = NULL, **additional_strings = NULL;
	char *string;
	printf("Please enter the total number of strings you want to sort : ");
	scanf("%d",&total_string_number);
	do{
		printf("Enter a string name : ");
		string = malloc(sizeof(char)*16);
		scanf("%15s",string);
		count++;
		
		additional_strings = (char **) realloc(strings,count*sizeof(char*));

		if(additional_strings!=NULL){
			strings = additional_strings;
			strings[count-1] = string;
		}
		else{
			//free(strings);
			printf("Error (re)allocating memory\n");
			exit(1);
		}
	}while(count<total_string_number);
	
	
	char *swap;
	for(int pass = 0;pass<total_string_number-1;pass++)
	{
		for(int i=0;i<total_string_number-1;i++)
		{	
			if((strcmp(strings[i],strings[i+1]))>0)
			{
				swap=strings[i];
				strings[i]=strings[i+1];
				strings[i+1]=swap;
			}//end if
		}//end for
	}//end for
	
	printStrings(strings,total_string_number);
	for(int i=0;i<total_string_number;i++)
		free(strings[i]);
	free(strings);
}
