#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFFERSIZE 100
typedef struct circularNode
{
	struct circularNode *left;
	int num_of_slices;
	char direction;
	char *task;
	int beginning;
	struct circularNode *right;/*Pointer to the next node*/
}TaskWheel;
void printCurrentSlice(TaskWheel *a)
{
	printf("The number of slices = %d\n",a->num_of_slices);
	printf("The direction of task is %c\n",a->direction);
	printf("The task is %s\n",a->task);
	printf("The right node is %p and the left node is %p\n",(void *)a->right,(void *)a->left);
}
int checkDRILL(char *b)
{
	if(b[0]=='D' && b[1]=='R' && b[2]=='I' && b[3]=='L' && b[4]=='L')
		return 1;
	return 0;
}
TaskWheel * command(TaskWheel *a,int *ip,char *currDir,char *comm)
{
	TaskWheel *temp,*ctrl_temp;
	char *cp,*hold,*task,*cp_beg,*check_drill;
	char c;
	int x,y,z=0,slice_limit=0,i,j=0;
	cp=(char *)malloc(sizeof(char)*40);
	hold=cp;
	check_drill=cp;
	while(comm[j]!='\n')
	{
		*cp++=comm[j];
		comm++;
	}
	*cp='\0';
		
	if(*hold=='A')
	{
		
		while(*check_drill!=' ')
			check_drill++;
		check_drill++;
		x=*check_drill-'0';
		check_drill+=2;
		task=(char *)malloc(sizeof(char)*(x+1));
		cp_beg=task;
		while(*check_drill!='\0')
			*task++=*check_drill++;
		*task='\0';
		check_drill++;
		if((z=checkDRILL(cp_beg))==1)
		{	
			
			temp=(TaskWheel *)malloc(sizeof(TaskWheel));
			if(*currDir=='R')
			{
				if(a->right==NULL)
				{
					a=temp;
					a->right=a;
					a->left=a;
					a->direction='N';
					a->num_of_slices=-1;
					a->task=cp_beg;
					a->beginning=1;
					printf("A %s %s %s\n",a->left->task,a->task,a->right->task);
					*ip=0;
					return a;
				}
				else
				{
					temp->right=a->right;
					a->right->left=temp;
					temp->left=a;
					a->right=temp;
					temp->task=cp_beg;
					temp->direction='N';
					temp->num_of_slices=-1;
					temp->beginning=0;
					a=temp;
					printf("A %s %s %s\n",a->left->task,a->task,a->right->task);
					*ip=0;
					return a;
				}
			}
			else if(*currDir=='L')
			{
				temp->left=a->left;
				a->left->right=temp;
				temp->right=a;
				a->left=temp;
				temp->task=cp_beg;
				temp->direction='N';
				temp->num_of_slices=-1;
				temp->beginning=0;
				a=temp;
				printf("A %s %s %s\n",a->left->task,a->task,a->right->task);
				*ip=0;
				return a;
			}
		}
	}
	
		
		switch(*hold)
		{
			printf("%c\n",*hold);
			
			case 'A':
				if(*currDir=='R')
				{
					if(a->right==NULL && a->left==NULL)/*Then this is an empty task wheel, a special case to handle*/
					{
						while(*hold!=' ')
							hold++;
						hold++;
						x=*hold-'0';
						hold+=2;
						task=(char *)malloc(sizeof(char)*(x+1));
						cp_beg=task;
						while(*hold!=' ')
							*task++=*hold++;
						*task='\0';
						hold++;
						c=*hold;
						hold+=2;
					
						x=atoi(hold);
						a->right=a;
						a->left=a;
						a->task=cp_beg;
						a->direction=c;
						a->num_of_slices=x;
						a->beginning=1;
						printf("A %s %s %s\n",a->left->task,a->task,a->right->task);
						
						
					}	
					else
					{
						temp=(TaskWheel *)malloc(sizeof(TaskWheel));
						while(*hold!=' ')
							hold++;
						hold++;
						x=*hold-'0';
						hold+=2;
						task=(char *)malloc(sizeof(char)*(x+1));
						cp_beg=task;
						while(*hold!=' ')
							*task++=*hold++;
						*task='\0';
						hold++;
						c=*hold;
						hold+=2;
						x=atoi(hold);
						temp->right=a->right;
						temp->left=a;
						a->right->left=temp;
						a->right=temp;
						temp->task=cp_beg;
						temp->direction=c;
						temp->num_of_slices=x;
						temp->beginning=0;
						a=temp;	
						printf("A %s %s %s\n",a->left->task,a->task,a->right->task);
						
					}	
					*ip=0;
					return a;
				}/* end bigger if*/
				else if(*currDir=='L')
				{
				temp=(TaskWheel *)malloc(sizeof(TaskWheel));
				while(*hold!=' ')
					hold++;
				hold++;
				x=*hold-'0';
				hold+=2;
				task=(char *)malloc(sizeof(char)*(x+1));
				cp_beg=task;
				while(*hold!=' ')
					*task++=*hold++;
				*task='\0';
				hold++;
				c=*hold;
				hold+=2;
				x=atoi(hold);
				temp->left=a->left;
				temp->right=a;
				a->left->right=temp;
				a->left=temp;

				temp->task=cp_beg;
				temp->direction=c;
				temp->num_of_slices=x;
				temp->beginning=0;
				a=temp;	
				printf("A %s %s %s\n",a->left->task,a->task,a->right->task);
				
				*ip=0;
				return a;
			}
			break;
		case 'R':
			
			printf("R ");
			if(checkDRILL(a->task))
			{
				printf("DRILL\n");
				*ip=1;
				return a;
			}
			*currDir=a->direction;
			y=a->num_of_slices;
			if(a->direction=='R')
			{
				for(x=0;x<y;x++)
				{
					a=a->right;
					printf("%s ",a->task);
				}
				printf("\n");
			}
			else if(a->direction=='L')
			{
				for(x=0;x<y;x++)
				{
					a=a->left;
					printf("%s ",a->task);
					
				}
				printf("\n");
			}
			
			*ip=0;
			return a;
			break;
		case 'D':
			printf("D %s %s %s\n",a->left->task,a->task,a->right->task);
			if(*currDir=='R')
			{
				a->left->right=a->right;
				a->right->left=a->left;
				a=a->left;
			}
			else
			{
				a->right->left=a->left;
				a->left->right=a->right;
				a=a->left;
			}
			*ip=0;
			return a;
			break;
		case 'C':
			ctrl_temp=a;
			while(!a->beginning)
				a=a->right;
			/*printCurrentSlice(a);*/
			printf("C ");
			temp=a;
			if(a->right==a && a->left==a)
			{
				printf("%s %s\n",a->task,a->task);
				*ip=0;
				return a;
			}	
			printf("%s ",temp->task);
			a=a->right;
			while(a!=temp)
			{	
				printf("%s ",a->task);
				a=a->right;
			}
			temp=a->left;
			
			a=a->left->left;
			while(a!=temp)
			{
				printf("%s ",a->task);
				a=a->left;
			}
			a=ctrl_temp;
			printf("\n");
			*ip=0;
			return a;
			break;
		case 'T':
			
			printf("T ");
			while(*hold!=' ')
				hold++;
			hold++;
			slice_limit=*hold -'0';
			while(!a->beginning)
				a=a->right;
			printf("%s ",a->task);
			i=0;
			while(i<slice_limit)
			{
				if(checkDRILL(a->task))
				{
					printf("DRILL\n");
					*ip=1;
					return a;
				}

				*currDir=a->direction;
				y=a->num_of_slices;
				if(a->direction=='R')
				{
					
					for(x=0;x<y;x++)
					{
						a=a->right;
						printf("%s ",a->task);
						if(checkDRILL(a->task))
						{
							printf("\n");
							*ip=1;
							return a;
						}
					}
					
				}
				else if(a->direction=='L')
				{
					
					for(x=0;x<y;x++)
					{
						a=a->left;
						printf("%s ",a->task);
						if(checkDRILL(a->task))
						{
							printf("\n");
							*ip=1;
							return a;
						}
					
					}
					
				}
				i++;
			}	
			printf("DRILL_NOT_FOUND\n");
			*ip=1;
			return a;
			break;

	}
	
}
int main(int argc,char *argv[])
{
	int end_of_command=0,*ip;
	char currDirection='R',*cp;
	char **buffer,**hold;
    int ch,i=0,j=0;
	TaskWheel *wheel=(TaskWheel *)malloc(sizeof(TaskWheel));
	ip=&end_of_command;
	cp=&currDirection;
	wheel->num_of_slices=0;
	wheel->direction='R';
	wheel->left=NULL;
	wheel->right=NULL;
	wheel->beginning=0;
	buffer=(char**)malloc(sizeof(char *)*50);
	hold=buffer;
	while((ch=fgetc(stdin))!=EOF)
    {
   		*buffer=(char *)malloc(sizeof(char)*BUFFERSIZE);
   		while(ch!='\n')
   		{
    		(*buffer)[j]=ch;
    		j++;
    		ch=fgetc(stdin);
    	}
	    (*buffer)[j]='\n';
	    j=0;
	   
	    buffer++;
	    i++;
    }
	while(!(*ip))
	{
		wheel=command(wheel,ip,cp,*hold);
		hold++;
	}

    
	return 0;
}
