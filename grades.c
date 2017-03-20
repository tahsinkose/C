#include <stdio.h>
#define STUDENTS 3
#define GRADES 4

void minimum(int b[][GRADES]);
void maximum(int b[][GRADES]);
void average( int b[][GRADES]);
void printArray(int b[][GRADES]);
//End of prototypes

int main()
{
	size_t student;
	unsigned int choice;
	int a[STUDENTS][GRADES]={73,42,65,33,
							 12,65,34,43,
							 89,95,57,75};
	
	void(*processGrades[4])(int[][GRADES])={printArray,minimum,maximum,average};
	do
	{
		printf("Enter a choice:\n\t0 Print the array of grades\n\t1 Find the minimum grade\n\t2 Find the maximum grade\n\t3 Print the average on all tests for each student\n\t4 End program :");
		scanf("%u",&choice);
		if(choice<4)
		{
			(*processGrades[choice])(a);
		}
	}while(choice<4);
}//end main

void minimum (int b[][GRADES])
{
	int check=100;
	int i;
	int j;

	for (i=0;i<STUDENTS;i++)
	{
		for(j=0;j<GRADES;j++)
		{
			if ( b[i][j] < check)
			{
				check=b[i][j];
			}//end if
		}//end inner for
	}//end outer for
	printf("Minimum of all grades is : %d .\n",check);
}//end minimum

void maximum(int b[][GRADES])
{
	int check=0;
	int i;
	int j;
	for (i=0;i<STUDENTS;i++)
	{
		for (j=0;j<GRADES;j++)
		{
			if ( b[i][j]>check)
			{
				check=b[i][j];
			}//end if
		}//end inner for
	}//end outer for
	printf("Maximum of all grades is : %d\n",check);
}//end maximum

void average(int b[][GRADES])//in order to prevent from changing the values of the array setOfGrades, constant data type has been used.
{
	int total=0;//in order to prevent from total to have a garbage value, we should have initialize it to 0
	size_t i;
	size_t j;
	for (i=0;i<STUDENTS;i++)
	{
		for(j=0;j<GRADES;j++)
		{
			total+=b[i][j];
		}//end for
		printf("The average of student %lu = %.2lf\n",i,(double)total/GRADES);
		total=0;
	}//end for
}//end average

void printArray(int b[][GRADES])
{
	size_t i;
	size_t j;

	for (i=0;i<STUDENTS;i++)
	{
		for (j=0;j<GRADES;j++)
		{
			printf("%5d",b[i][j]);
		}//end for

		puts("");
	}//end for
}//end function

