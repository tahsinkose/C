#include <stdio.h>
#include <string.h>
#define SIZE 10000
#define LASTLETTER 123
int tokenFunction(char *tok,char *line,char *newLine,int count_length[]);
void letterCounter(char *arr,size_t size);
int main()
{
	char text[SIZE]="";
	int word_length[18]={0};//largest number of characters can be entered in one line
	char flag='\n',c;
	char *linePtr;
	char *charPtr;
	char *token;
	size_t i=0;
	int n=1;
	while(flag=='\n')
	{
		printf("W: ");
		while ((c=getchar())!='\n')
		{
			text[i++]=c;
		}//end the loop
		text[i++]='\n';
		printf("C: ");
		if((flag=getchar())=='\n')
		{
			n++;//counts the number of lines.
		}//do nothing, meaningly continue to input
		else
		{
			break;//end of input
		}
	}//end while
	text[i]='\0';
	printf("The text is:\n%s",text);
	
	
	/*Now the problem induced to the counting of the words in each line. There should be a pointer, which increases one by one,meaningly
	  every single character should be taken care of in order to find a newline.*/
	linePtr=text;
	
	for(size_t j=1;j<=n;j++)
	{	
		int wordCount=0;
		charPtr=linePtr;
		for(;*(charPtr)!='\n';charPtr++)
		{
		}//end for :to locate where is the endline character.		
		wordCount=tokenFunction(token,linePtr,charPtr,word_length);
		linePtr=charPtr+1;
		printf("Line %lu has %d words\n",j,wordCount);
	}//end for
	letterCounter(text,i);
	printf("%3s%15s\n","Word length","Occurences");
	for(size_t k=1;k<18;k++)
	{
		printf("%10lu%15d",k,word_length[k]);
		puts("");
	}//end for
}//end main

int tokenFunction(char *tok,char *line,char *newLine,int count_length[])
{
	const char s[2]=" ";
	int count=0;
	char *ptrSentence;
	char *copy_text;
	size_t i=0;
	*newLine='\0';
	tok=strtok(line,s);
	while(tok!=NULL && tok<newLine)
	{
		int word_count=1;
		copy_text=tok+strlen(tok)+1;
		ptrSentence=strstr(copy_text,tok);
		while(ptrSentence!=NULL)
		{
			word_count++;
			ptrSentence++;
			ptrSentence=strstr(ptrSentence,tok);
		}
		
		printf("%s %d\n",tok,word_count);
		//printf("There are %lu characters in the word %s\n",strlen(tok),tok);
		count_length[strlen(tok)]++;
		count++;
		tok=strtok(NULL,s);
	}//end while
	return count;
}//end tokenFunction

void letterCounter(char *arr,size_t size)
{
	int rating[LASTLETTER]={0};
	size_t i;
	for(i=0;i<size;i++)
	{
		rating[arr[i]]++;
	}//end for
	for(i=0;i<LASTLETTER;i++)
	{
		if(rating[i]!=0)
		{
			printf("There are %d %c's\n",rating[i],(int)i);
		}//end if
	}//end for
}//end letterCounter

//Algorithm (just an approach): First I need two arrays that one takes the input continously until the sentinel value is entered.
//The other is blank at first, and concetanetad while a line is typed.With this process, ultimately, the text should be created succesfully.
