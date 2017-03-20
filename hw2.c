#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.14
#define MAXSIZE 80
/*Initial Declarations and Notes
I didn't create any memory function, because all the calculating functions automatically evaluate and take to memory the last result. 
I didn't create any clear function, honestly, I didn't unterstand the difference between MC and C. So when someone types C, program will direct it to MemoryClear
function.*/


double sineFunc(double a);//user may enter a decimal degree, so parameter is the type of double. Return value will already be a float number.
double cosineFunc(double a);//same explanation as sineFunc's
double tangentFunc(double a);//same explanation as sineFunc's
void  powerFunc(int a,double *b);//takes only integer type values for its first parameter, in order to evaluate the value of hold, second parameter is determined as a pointer
double absFunc(double c);//this can take a decimal number parameter, and returned value would be a decimal one too, undoubtedly.
void piFunc(double *b);//this will not take any parameter, when 'P' is entered, it prints the PI value
void expFunc(double a,double *b);//this function takes double parameters, evaluates them in its body.
unsigned long long int factFunc(unsigned int c);//this should take positive numbers only as its parameter. Return value could be too large, so unsigned long long int is decided as return type.
void addFunc(double a,double *b);//this and proceeding 4 functions take double type parameters, and in order to evaluate the value of hold, second parameter is determined as a pointer.
void subFunc(double a,double *b);
void divFunc(double a,double *b);
void multiplyFunc(double a,double *b);
void modFunc(int a,double *b);
//Functions until here from addFunc are returning no value, but they are making processions in their own body.
void convert(char b[],double *c);
double memoryReturn(double *b);//this simply returns the hold value, that is automatically evaluated when a calculation is performed. Last value is returned.
void memoryClear(double *b);//this clears the hold value, and evaluates it to 0.

int main()
{
	
	char ch;
	char buffer[MAXSIZE];
	int  exit = 0;
	int  valid_choice;
	size_t counter;
	double hold;
	//Initialization of variables.
	
	
	puts("");
	printf("%s","------------------------------------------------------------------\n");
	printf("The list of operations in this simple calculator:\n"
		   "sine (S), cosine (N), tangent (T), exponent (E)\n" 
		   "power (W), absolute (A), factorial (F) \n"
           "add (+), subtract (-), divide(/), multiply(*), modulus (%)\n" 
		   "pi (P)\n" 
		   "Quit (Q)\n"
		   "Memory (M)\n" 
		   "Clear (C)\n" 
		   "Memory Clear (MC)\n" 
		   "Memory Return (MR)\n");
	 printf("%s","------------------------------------------------------------------\n");
	 puts("");
	 while (exit == 0)//main loop
	 {
		printf("Enter user input: ");
	 	ch = getchar();
		counter = 0;
		while ( ch != '\n' )
		{
			buffer[counter++]=ch;
			ch = getchar();
		}
		buffer[counter] = 0x00;      /*buffer termination, this provides an input that does not include an end of line character. So harmful repetitions of proceeding
									 user input demands don't happen.*/
		
		

		if (buffer[0]>='A' && buffer[0]<='z')//this decision statement determines whether the entry's first character is between 'letter' limits,if it is
		{									 //takes it to the body.
			switch(buffer[0])//this is the decision mechanism for different letter entries
			{
				
				case 'A':	
				case 'a':
					printf("Absolute(%.1f) = %.1f\n",hold,absFunc(hold));
					break;
				case 'C':
				case 'c':
					memoryClear(&hold);
					break;
					case 'E':
					case 'e':
					expFunc(hold,&hold);
					break;
				case 'F':	
				case 'f':
					printf("Factorial(%d) = %llu\n",(int)hold,factFunc((unsigned int)hold));
					hold=(double)factFunc((unsigned int)hold);//in order to keep result
					break;
				case 'M':
				case 'm':
					if (buffer[1]=='R')
						{printf("%.2f\n",memoryReturn(&hold));}
					else if(buffer[1]=='C')
						{memoryClear(&hold);}
					else
						{
						printf ("Invalid character. Choose from the operators below.\n");
						printf("%s","------------------------------------------------------------------\n");
						printf("sine (S), cosine (N), tangent (T), exponent (E)"		 
								"power (W), absolute (A), factorial (F) "
								"add (+), subtract (-), divide(/), multiply(*), modulus (%) "
								"PI (P) "
								"Quit (Q)"
								"MemoryReturn (MR) \n");
						}//end else
					break;
				case 'N':
				case 'n':
					printf("Cos(%.1f) = %.2f\n",hold,cosineFunc(hold));
					hold=cosineFunc(hold);
					break;
				case 'P':
				case 'p':
					piFunc(&hold);
					break;
				case 'S':	
				case 's':	
					printf("Sin(%.1f) = %.2f\n",hold,sineFunc(hold));
					hold=sineFunc(hold);
					break;
				case 'W':
				case 'w':
					powerFunc((unsigned int)hold,&hold);
					break;
				case 'Q':
				case 'q':	
					exit++;
					break;
				case 'T':
				case 't':
					printf("Tan(%.1f) = %.2f\n",hold,tangentFunc(hold));
					hold=tangentFunc(hold);
					break;
				default:
					printf ("Invalid character. Choose from the operators below.\n");
					printf("%s","------------------------------------------------------------------\n");
					printf("sine (S), cosine (N), tangent (T), exponent (E)"		 
							"power (W), absolute (A), factorial (F) "
							"add (+), subtract (-), divide(/), multiply(*), modulus (%) "
							"? (P) "
							"Quit (Q)"
							"Memory (M) \n");
					break;
					
			}//end switch
 		 }//end if
	 	else//for non-letter entries
		{
		
			switch(buffer[0])
			{
				case '+':
					addFunc(hold,&hold);
					break;
				case '-':
				subFunc(hold,&hold);
				break;
				case '/':
				divFunc(hold,&hold);
				break;
				case '*':
				multiplyFunc(hold,&hold);
				break;
				case '%':
				modFunc((int)hold,&hold);
				break;
				default :
					convert(buffer,&hold);//if entry is not one like the above cases, then it means that it is an integer. Thus it should be converted to double type
					break;//from string.
			}//end switch
				
		}//end else

	}//end while(main loop)
	printf("Successfully quited.");
}//end main

void convert(char b[],double *c)
{
	*c=atof(b);//strings will be converted to float integers in here
}//end convert function
double sineFunc(double a)
{
	double x;
	double powseven;
	double powfive;
	double powthree;
	double sinx;

	x=(a*PI)/180;//in order to transform radian values to degrees
	powseven=(x*x*x*x*x*x*x);
	powfive=(x*x*x*x*x);
	powthree=(x*x*x);

	sinx=(x - (powthree/6) + (powfive/120) - (powseven/5040));//taylor series for sine are evaluated in here.Respectively 6=3!,120=5! and 5040=7! when powthree,powfive and powseven denote to the x^3,x^5 and x^7.
	return sinx;//And the definition of taylor series relative to sine function is: sinx approximately equals to x-(x^3/3!) + (x^5/5!) - (x^7/7!)
	
}

double cosineFunc(double a)
{
	double x;
	double powsix;
	double powfour;
	double powtwo;
	double cosx;

	x=(a*PI)/180;
	poweight=(x*x*x*x*x*x*x*x);
	powsix=(x*x*x*x*x*x);
	powfour=(x*x*x*x);
	powtwo=(x*x);
	cosx=(1-(powtwo/2) + (powfour/24) -(powsix/720));//taylor series for cosine function is: 1- x^2/2! + x^4/4! - x^6/6!
	return cosx;
}

double tangentFunc(double a)
{
	return sineFunc(a)/cosineFunc(a);//just uses the conversion of tanx=sinx/cosx.
}
unsigned long long int factFunc(unsigned int c)
{
	if (c==0)
	{
		return 1;
	}//end if
	else 
	{
		return c*factFunc(c-1);
	}//end else
}//end factorial function

double absFunc(double c)
{
	if (c>=0)
	{
		return c;
	}//end if
	else
	{
		return c*-1;//if a negative value has, this makes it positive.
	}//end else
}//end absolute function

void powerFunc(int a,double* b)
{
	//SAME PROMPT	
	char ch;
	static char buffer[MAXSIZE];
	size_t counter;
	printf("Enter user input: ");
	ch = getchar();
	counter = 0;
	while ( ch != '\n' )
	{
		buffer[counter++]=ch;
		ch = getchar();
	}
	buffer[counter] = 0x00;
	//SAME PROMPT
	int result=1;
	int c;//in order to convert the string to integer
	c=atoi(buffer);//in order to convert the string to integer
	for (counter=1;counter<=c;counter++)
	{
		result=a*result;//main process
	}//end for
	printf("%d^%d = %d\n",a,c,result);
	*b=(double)result;
}//end power function
void expFunc(double a,double *b)
{
	char ch;
	char buffer[MAXSIZE];
	size_t counter;
	double localhold=a;//in order to hold parameter a;
		
	
	printf("Enter user input: ");
	ch = getchar();
	counter = 0;
	while ( ch != '\n' )
	{
		buffer[counter++]=ch;
		ch = getchar();
	}
	buffer[counter] = 0x00;
	int c;//in order to convert the string to integer
	c=atoi(buffer);//in order to convert the string to integer
	for (counter=1;counter<=c;counter++)
	{
		a*=10.0;
	}//multiply it as many times as until counter is satisfied
	printf ("%.2f*exp(%d) = %.1f\n",localhold,c,a);
	*b=a;
}//end exp func

void piFunc(double *b)
{
	printf("PI = %.2f \n",PI);
	*b=PI;
}//end pi function

void addFunc(double a,double *b)
{
	//SAME PROMPT
	char ch;
	char buffer[MAXSIZE];
	size_t counter;
	printf("Enter user input: ");
	ch = getchar();
	counter = 0;
	while ( ch != '\n' )
	{
		buffer[counter++]=ch;
		ch = getchar();
	}
	buffer[counter] = 0x00;
	//SAME PROMPT
	double x;
	x=atof(buffer);
	printf ("%.2f + %.2f = %.2f\n",a,x,a+x);
	*b=a+x;
}//end add function

void subFunc(double a,double *b)
{
	//SAME PROMPT
	char ch;
	char buffer[MAXSIZE];
	size_t counter;
	printf("Enter user input: ");
	ch = getchar();
	counter = 0;
	while ( ch != '\n' )
	{
		buffer[counter++]=ch;
		ch = getchar();
	}
	buffer[counter] = 0x00;
	//SAME PROMPT
	double x;
	x=atof(buffer);
	printf ("%.2f - %.2f = %.2f\n",a,x,a-x);
	*b=a-x;
}//end subtract function

void divFunc(double a,double *b)
{
	//SAME PROMPT
	char ch;
	char buffer[MAXSIZE];
	size_t counter;
	printf("Enter user input: ");
	ch = getchar();
	counter = 0;
	while ( ch != '\n' )
	{
		buffer[counter++]=ch;
		ch = getchar();
	}
	buffer[counter] = 0x00;
	//SAME PROMPT
	double x;
	x=atof(buffer);
	printf("%.2f / %.2f = %.2f\n",a,x,a/x);
	*b=(double)a/x;
}//end division function

void multiplyFunc(double a,double *b)
{
	//SAME PROMPT
	char ch;
	char buffer[MAXSIZE];
	size_t counter;
	printf("Enter user input: ");
	ch = getchar();
	counter = 0;
	while ( ch != '\n' )
	{
		buffer[counter++]=ch;
		ch = getchar();
	}
	buffer[counter] = 0x00;
	//SAME PROMPT
	double x;
	x=atof(buffer);
	printf("%.2f * %.2f = %.2f\n",a,x,a*x);
	*b=(double)a*x;
}//end multiply function

void modFunc(int a,double *b)
{
			//SAME PROMPT
	char ch;
	char buffer[MAXSIZE];
	size_t counter;
	printf("Enter user input: ");
	ch = getchar();
	counter = 0;
	while ( ch != '\n' )
	{
		buffer[counter++]=ch;
		ch = getchar();
	}
	buffer[counter] = 0x00;
	//SAME PROMPT
	int x;
	x=atoi(buffer);
	printf("%d %% %d = %d\n",a,x,a%x);
	*b=a%x;
}//end modulus function

double memoryReturn(double *b)
{
	return *b;
}//end function memoryReturn
void memoryClear(double *b)
{
	*b=0;
	
}//end function memoryClear

