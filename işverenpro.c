#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
void manager(double salary);
void hourlyWorker(float wage,int hour);
void commissioner(double sale);
void pieceworker(float price,int piece);


int main()
{
	int payload;
	//Universal
	double mSalary;
	//Managers only
	float hWage;
	int hours;
	//Hourly workers
	double sales;
	//Commissioners
	float prices;
	int pieces;
	//Pieceworkers
    payload=1;//just for to get inside of loop.
	while(payload!=-1 && payload<=4 && payload>=1)
	{printf("Please enter the payload  to calculate relative workers' pays:",
		   "1 for managers\n2 for hourly workers\n3 for commisioners\n4 for pieceworkers.",
		   "Payload: ");
	scanf("%d",&payload);
	switch(payload)
	{
		case 1:
			printf("Please enter one manager's weekly salary(fixed):  ");
			scanf("%lf",&mSalary);
			manager(mSalary);
			break;
		case 2:
			printf("Please enter hourly wage of the workers: ");
			scanf("%f",&hWage);
			printf("Please enter how many hours the worker made: ");
			scanf("%d",&hours);
			hourlyWorker(hWage,hours);
			break;
		case 3:
			printf("Please enter weekly sales (in $) of one commissioner: ");
			scanf("%lf",&sales);
			commissioner(sales);
			break;
		case 4:
			printf("Please enter the fixed amount of money for each piece: ");
			scanf("%f",&prices);	
			printf("Please enter how many piece has been created: ");
			scanf("%d",&pieces);
			pieceworker(prices,pieces);
			break;
	}
	}
}//end main

void manager(double salary)
{
	static double total=0;
	total+=salary;
	printf("Total amount of money paid to managers are %lf.",total);
	puts("");
}

void hourlyWorker(float wage,int hour)
{
	static double total=0;
	if(hour>40)
	{
		total+=(hour*wage) + (hour-40)*wage/2;
	}
	else
	{
		total+=hour*wage;
	}
	printf("Total amount of money paid to hourly workers are %lf.",total);
	puts("");
}

void commissioner(double sale)
{
	static double total=0;
	int times;
	double plus=250*0.057;
	if(sale>=250)
	{
		times=(int)sale/250;
		sale+=plus*times;
		total+=sale;
	}	
	else
	{
		total+=sale;
	}
	printf("Total amount of money paid to commisioners are %lf.",total);
	puts("");
}//end func

void pieceworker(float price,int piece)
{
	static double total=0;
	total+=price*piece;
	printf("Total amount of money paid to pieceworkers are %lf.",total);
	puts("");
}
