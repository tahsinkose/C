#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void printStrings(char ** strings,int size){

	for(int j=0;j<size;j++)
	{
		printf("%s",strings[j]);
	}
}

int main(int argc, char** argv)
{
	if(argc!=2){
		printf("Usage : %s <file>\n",argv[0]);
		exit(0);
	} 
	FILE * fp;
	char* line = NULL;
	fp = fopen("test.txt","r");
	if (fp == NULL)
        	exit(EXIT_FAILURE); 
	int total_string_number = 0;
	size_t len = 0;
	ssize_t read;
	char **strings = NULL, **additional_strings = NULL;
	

	while ((read = getline(&line, &len, fp)) != -1) {
		char *string = NULL;
		int i=0;
		for(;i<strlen(line);i++){
			string = realloc(string,sizeof(char)*(i+1));
			string[i] = line[i];
		}
		string = realloc(string,sizeof(char)*(i+1));
		string[i] = '\0';
    		
		total_string_number++;
		additional_strings = (char **) realloc(strings,total_string_number*sizeof(char*));

		if(additional_strings!=NULL){
			strings = additional_strings;
			strings[total_string_number-1] = string;
			
		}
		else{
			printf("Error (re)allocating memory\n");
			exit(1);
		}
	}
	
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
	
	
}//end main
