#include <stdio.h>
#define SIZE 20

void function1 (int a);
void function2 (int b);
void function3 (int c);

int main()
{
	/* Initialize array of 3 pointers to functions that each take an int argument and return nothing*/
	void (*f[3]) (int ) ={function1,function2,function3};
	size_t choice ;
	printf ("Please enter a number between 0-2, 3 to terminate : \n");
	scanf("%u",&choice);

	while (choice>=0 && choice <3 )
	{
		(*f[choice])(choice);
		
		printf ("Enter a number between 0-2, 3 to terminate : \n");
		scanf("%u",&choice);
	}

	puts("Succesfully terminated.");
}//end main

void function1 (int a)
{
	printf ("You have entered %d, so function1 is called\n",a);
}

void function2 (int b)
{
	printf ("You have entered %d, so function2 is called \n",b);
}

void function3 (int c)
{
	printf ("You have entered %d, so function3 is called \n",c);
}
