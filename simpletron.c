#include <stdio.h>
#include <math.h>
#include <string.h>
/*SEMANTICHS*/
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define NEWLINE 22
/*ARITHMETICS*/
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define REMAINDER 34
#define EXPONENT 35

/*TRANSPORTS,CALLS*/
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

#define INPUT_STRING 50
#define PRINT_STRING 51
#define MEMORYSIZE 100
void load(float arr[],size_t *counter);
void execution(float arr[],float *acc,size_t *insCount,int *insReg,int *opCode,int *op,size_t *counter);
void dump(float arr[],float acc,int insCount,int insReg,int opCode,int op);
int main()
{
	float memory[MEMORYSIZE]={0.0};
	float accumulator=+0000;
	size_t instructionCounter=00;
	int operationCode=00;
	int operand=00;
	int instructionRegister=+0000;
	size_t i=0;
	load(memory,&i);
	execution(memory,&accumulator,&instructionCounter,&instructionRegister,&operationCode,&operand,&i);
	dump(memory,accumulator,instructionCounter,instructionRegister,operationCode,operand);	
}//end main

void load(float arr[],size_t *counter)
{
	int flag=0;
	printf("*** Welcome to Simpletron! ***\n"
		   "*** Please enter your program one instruction ***\n"
		   "*** (or data word) at a time. I will type the ***\n"
		   "*** location number and a question mark(?).   ***\n"
		   "*** You then type the word for that location. ***\n"
		   "*** Type the sentinel -99999 to stop entering ***\n"
		   "*** your program. ***\n");
	
	for(;*counter<MEMORYSIZE;(*counter)++)
	{
		if(*counter<10)
		{
			printf("0%u ?",*counter);
			scanf("%f",&arr[*counter]);
			while((int)arr[*counter]>=+10000 || (int)arr[*counter]<=-10000)
			{
				printf("0%u ?",*counter);
				scanf("%f",&arr[*counter]);
				if((int)arr[*counter]==-99999)
				{
					flag=1;
					arr[*counter]=+0000;
					break;
				}//end if
			}//end while
		}//end if
		else
		{
			printf("%u ?",*counter);
			scanf("%f",&arr[*counter]);
			while((int)arr[*counter]>=+10000 || (int)arr[*counter]<=-10000)
			{
				printf("0%u ?",*counter);
				scanf("%f",&arr[*counter]);
				if((int)arr[*counter]==-99999)
				{
					flag=1;
					arr[*counter]=+0000;
					break;
				}//end if
			}//end while
		}//end else
		
		if(flag)
			break;
		
	}//end for
	printf("*** Program loading completed ***\n");
}//end load

void execution(float arr[],float *acc,size_t *insCount,int *insReg,int *opCode,int *op,size_t *counter)
{
	char string[200];
	
	printf("*** Program execution begins ***\n");
	for(;*insCount<*counter;(*insCount)++)
	{
		*insReg =(int) arr[*insCount];
		*opCode = (*insReg)/(10*10);
		*op = (*insReg) %(10*10);
		
		switch(*opCode)
		{
			
			case READ:
				printf("?");
				scanf("%f",&arr[*op]);
				break;
			case WRITE:
				printf("%f\n",arr[*op]);
				break;
			case LOAD:
				*acc=arr[*op];
				break;
			case STORE:
				arr[*op]=*acc;
				break;
			case NEWLINE:
				puts("");
				break;
			case ADD:
				(*acc)+=arr[*op];
				if(*acc > +9999.00)
				{
					printf("*** Simpletron execution abnormally terminated ***\n");
					dump(arr,*acc,*insCount,*insReg,*opCode,*op);	
					return;
				}//end if
				break;
			case SUBTRACT:
				(*acc)-=arr[*op];
				if(*acc < -9999.00)
				{
					printf("*** Simpletron execution abnormally terminated ***\n");
					dump(arr,*acc,*insCount,*insReg,*opCode,*op);	
					return;
				}//end if
				break;
			case DIVIDE:
				if(arr[*op]==0.0)
				{
					printf("*** Attempt do divide by zero ***\n");
					dump(arr,*acc,*insCount,*insReg,*opCode,*op);	
					return;
				}//end if
				(*acc)/=arr[*op];
				break;
			case MULTIPLY:
				(*acc)*=arr[*op];
				if(*acc < -9999.0 || *acc >+9999.0)
				{
					printf("*** Simpletron execution abnormally terminated ***\n");
					dump(arr,*acc,*insCount,*insReg,*opCode,*op);
					return;
				}//end if
				break;
			case REMAINDER:
				(*acc)=(float)((int)(*acc) % (int)arr[*op]);
				break;
			case EXPONENT:
				*acc=(int)pow((double)*acc,(double)arr[*op]);
				if(*acc < -9999.0 || *acc >+9999.0)
				{
					printf("*** Simpletron execution abnormally terminated ***\n");
					dump(arr,*acc,*insCount,*insReg,*opCode,*op);
					return;
				}//end if
				break;
			case BRANCH:
				*insCount =(int) *op;
				break;
			case BRANCHNEG:
				if(*acc < 0.0)
					*insCount =(int) *op;
				break;
			case BRANCHZERO:
				if(*acc == 0)
					*insCount =(int) *op;
				break;
			case INPUT_STRING:
				int length,ch;
				printf("Enter a string : ");
				scanf("%s",string);
				length=strlen(string);
				ch=(length/2)+1;
				arr[(*op)++]=(ch*100.0)+(float)string[0];
				for(size_t i=1; i<length;(*op)++)
				{
					arr[*op]=(float)string[i++]*100.0;
					if(string[i]=='\0')
						break;
					arr[*op]+=(float)string[i++];
				}//end for
				break;
			case PRINT_STRING:
				int count,twodigits;
				*insReg=(int)arr[*op];
				*opCode = (*insReg)/(10*10);
				twodigits = (*insReg) %(10*10);
				count=*opCode;
				
				printf("%c",twodigits);//Latter two digits that denote to character
				for(size_t i=1; i<count;i++)
				{
					*insReg=(int)arr[++(*op)];
					*opCode = (*insReg)/(10*10);
					twodigits = (*insReg) %(10*10);	
					if((*opCode)=='\0' || twodigits=='\0')
						break;
					printf("%c%c",*opCode,twodigits);
				}//end for
				puts("");
				break;
			case HALT:
				printf("*** Simpletron execution terminated ***\n");
				break;
			default:
				//printf("*** An invalid operation code has been entered. It will be ignored ***\n");
				break;
		}//end switch
	}//end for	
}

void dump(float arr[],float acc,int insCount,int insReg,int opCode,int op)
{
	printf("REGISTERS:\n");
	printf("accumulator%12s%+05.2f\n"," ",acc);
	printf("instructionCounter%8s%02d\n"," ",insCount);
	printf("instructionRegister%4s%+05d\n"," ",insReg);
	printf("operationCode%13s%02d\n"," ",opCode);
	printf("operand%19s%02d\n"," ",op);
	printf("MEMORY:\n%3s"," ");
	for(size_t i=0;i<(MEMORYSIZE/10);i++)
	{
		printf("%6d",i);
	}//end for
	puts("");
	for (size_t j=0;j<10;j++)
	{
		printf("%2d%2s",10*j," ");
		for(size_t k=0;k<10;k++)
		{
			printf("%+05.f%s",arr[(j*10)+k]," ");
		}//end for
		puts("");
	}//end for
}//end dump		
		
