/*************************************************
* A program that calculates any factorial up to  *
* 600 echelons.                                  *
*************************************************/




#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 600

int factorial(int a);
void operation (char j[],int c,int *m,int *n);
void print_result(char arr[],int inp,int i,int k,int j){
	
	printf("%d!=",inp);
	if(inp<=12)//This is for the numbers less than or equal to 12.
	{
		for (i=k,k=0;k<=i-1;k++)
			{

				if ((k%3)==(i%3)&& k!=0 && k<i)
				{
					printf (",");
				}//for comma separation

				printf ("%c",arr[k]);
			}//end for
	}//end if
	else
	{
	for (k=0;k<=i-1;k++)
			{

				if ((k%3)==(i%3)&& k!=0 && k<i&& k>j)
				{
					printf (",");
				}//for comma separation

				printf ("%c",arr[k]);
			}//end for
	}//end else

	puts("");
	puts("");
}
void count_j(char arr[],int *j)
{
	*j=0;
	while ( arr[*j] == '0')//in order to delete unnecessary 0's at the beginning
	{
		arr[*j] =0x00;
		(*j)++;
	}//end while
}
int main()
{
	int input;
	char resultArray[SIZE]={0};
	int i,j=0,k;

	printf ("Enter N: ");
	scanf("%d",&input);
	
	operation(resultArray,input-2,&i,&k);
	count_j(resultArray,&j);
	print_result(resultArray,input-2,i,k,j);
	
	operation(resultArray,input-1,&i,&k);
	count_j(resultArray,&j);
	print_result(resultArray,input-1,i,k,j);
	
	operation(resultArray,input,&i,&k);
	count_j(resultArray,&j);
	print_result(resultArray,input,i,k,j);
}//end main

int factorial(int a)
{
	int i;
	int result=a;
	i=a-1;
	for (;i>0;i--)
	{
		result=result*i;
	}//end for
	return result;
}//end factorial

void operation(char j[],int c,int *m,int*n)
{

	int result;
	int a,b,d,i,k,x,y,z;
	char reverseArray[SIZE]={0};
	char firstArray[SIZE]={0};
	char secondArray[SIZE]={0};
	char thirdArray[SIZE]={0};
	int temporary;
	int carrier=0;
	//Initialization of variables

	if(c<=12)
        {

		result=factorial(c);
		sprintf(j,"%d",result);
		for (*n=0,*m=0;*m<SIZE;(*m)++)
		{
			if(isdigit(j[*m]) == 1)
			{
				(*n)++;
			}
		}//counting of echelons



	}//end if. This is for integers less than or equal to 12.
	else
	{
		if(c==13)
			{

			result=factorial(12);//this will be base step
			sprintf(j,"%d",result);

			a=c/10;//echelon of tens
			b=c%10;//echelon of ones
			k=9;//there are 9 echelons on 12!
			k-=1;//this is for to adjust the k in array subscript notation.
			for(i=0;k>=0;k--)
			{
				reverseArray[i]=j[k];

				i++;
			}//array is reversed. hence, number too.


			for (i=0;i<10;i++)//k is chosen as this, because multiplication by the integers less than 10 could only increase the echelon number by 1.And echelon number at the beginning was 9.
			{
				x=reverseArray[i] - '0';//because elements of reverseArray are characters. They need to be made integers.

				if (x == -48){
						 //-48 is the special value for which the elements are white spaces actually. if it is a white space then, it should be converted to 0.
						 // Because it means that those echelons don't exist in fact. As we do in reality, program ignores unused echelons. But we must make
						//- at least- enough of them, explicitly 0. Because they will be used afterwards.
					x=0;
				}//end if

				temporary = ((x*b) % 10 )+ carrier;
				if (temporary>=10)
				{
					carrier=carrier+(temporary/10);
					temporary=temporary%10;

				}//end if. This is for if temporary before this decision block exceeds 10, then it should be splitted its echelons again.
				carrier = ((x*b) + carrier) / 10;

				firstArray[i]=temporary + '0';

			}//end of 1st stage of multiplication




			for (i=0;i<10;i++)//k is chosen as this, because multiplication by the integers less than 10 could only increase the echelon number by 1.And echelon number at the beginning was 9.
			{
				x=reverseArray[i] - '0';//because elements of reverseArray are characters. They need to be made integers.

				if (x == -48){
						 //-48 is the special value for which the elements are white spaces actually. if it is a white space then, it should be converted to 0.
						 // Because it means that those echelons don't exist in fact. As we do in reality, program ignores unused echelons. But we must make
						//- at least- enough of them, explicitly 0. Because they will be used afterwards.
					x=0;
				}//end if
				temporary=((x*a) %10) + carrier;
				if (temporary>=10)
				{
					carrier=carrier+(temporary/10);
					temporary=temporary%10;
				}//end if. This is for if temporary before this decision block exceeds 10, then it should be splitted its echelons again.
				carrier=((x*a) + carrier) / 10;
				secondArray[i]= temporary + '0';
			}//end 	of 2nd stage of multiplication


			for (*m=0;*m<=9;(*m)++)//why the condition is evaluated according to k is that, the summation could increase the echelon number only 1.
			{
				x=firstArray[(*m)+1] - '0' ;
				if (x == -48){
						 //-48 is the special value for which the elements are white spaces actually. if it is a white space then, it should be converted to 0.
						 // Because it means that those echelons don't exist in fact. As we do in reality, program ignores unused echelons. But we must make
						//- at least- enough of them, explicitly 0. Because they will be used afterwards.
					x=0;
				}//end if
				y=secondArray[*m] - '0';
				if( y== -48){
				//-48 is the special value for which the elements are white spaces actually. if it is a white space then, it should be converted to 0.
						 // Because it means that those echelons don't exist in fact. As we do in reality, program ignores unused echelons. But we must make
						//- at least- enough of them, explicitly 0. Because they will be used afterwards.
					y=0;
				}//end if

				temporary=((x+y)%10) + carrier;//what should be cared in here is, temporary may still exceed 10 now.
				carrier=(x+y)/10;
				reverseArray[(*m)+1]=(temporary%10) + '0' ;
				carrier=carrier+(temporary/10);//so in here , carrier should be determined precisely, according to that possibility.


			}//final summation

			for(*n=*m,*m=0;(*n)>=0;(*n)--)
			{
				j[*m]=reverseArray[*n];
				(*m)++;
			}//Last stage. Array is reversed again. hence, number too.



		}//end if ---> base case
		else
		{
			d=c/100;//for hundreds
			a=(c/10)%10;//for tens
			b=c%10;//for ones
			operation(j,c-1,m,n);//one lower factorial is called. But it is in true order. it should be reversed.

			for(*m-=1,*n=0;(*m)>=0;(*m)--)	//why *m-=1 is applied is to adjust the big value's echelon magnitude to array's subscript.
			{
				reverseArray[*n]=j[*m];
				(*n)++;
			}//Array is reversed

			for (i=0;i<(*n+1);i++)//k is chosen as this, because multiplication by the integers less than 10 could only increase the echelon number by 1.And echelon number at the beginning was *n.
			{
				x=reverseArray[i] - '0';//because elements of reverseArray are characters. They need to be made integers.

				if (x == -48){
						 //-48 is the special value for which the elements are white spaces actually. if it is a white space then, it should be converted to 0.
						 // Because it means that those echelons don't exist in fact. As we do in reality, program ignores unused echelons. But we must make
						//- at least- enough of them, explicitly 0. Because they will be used afterwards.
					x=0;
				}//end if

				temporary = ((x*b) % 10 )+ carrier;
				if (temporary>=10)
				{
					carrier=carrier+(temporary/10);
					temporary=temporary%10;

				}//end if. This is for if temporary before this decision block exceeds 10, then it should be splitted its echelons again.
				carrier = ((x*b) + carrier) / 10;

				firstArray[i]=temporary + '0';

			}//end of 1st stage of multiplication


			for (i=0;i<(*n);i++)//*n+1 is placed, because multiplication by the integers less than 10 could only increase the echelon number by 1.And echelon number at the beginning was *n.
			{
				x=reverseArray[i] - '0';//because elements of reverseArray are characters. They need to be made integers.

				if (x == -48){
						 //-48 is the special value for which the elements are white spaces actually. if it is a white space then, it should be converted to 0.
						 // Because it means that those echelons don't exist in fact. As we do in reality, program ignores unused echelons. But we must make
						//- at least- enough of them, explicitly 0. Because they will be used afterwards.
					x=0;
				}//end if
				temporary=((x*a) %10) + carrier;
				if (temporary>=10)
				{
					carrier=carrier+(temporary/10);
					temporary=temporary%10;
				}//end if. This is for if temporary before this decision block exceeds 10, then it should be splitted its echelons again.
				carrier=((x*a) + carrier) / 10;
				secondArray[i]= temporary + '0';
			}//end 	of 2nd stage of multiplication

			for (i=0;i<(*n);i++)//*n+1 is placed, because multiplication by the integers less than 10 could only increase the echelon number by 1.And echelon number at the beginning was *n.
			{
				x=reverseArray[i] - '0';//because elements of reverseArray are characters. They need to be made integers.

				if (x == -48){
						 //-48 is the special value for which the elements are white spaces actually. if it is a white space then, it should be converted to 0.
						 // Because it means that those echelons don't exist in fact. As we do in reality, program ignores unused echelons. But we must make
						//- at least- enough of them, explicitly 0. Because they will be used afterwards.
					x=0;
				}//end if
				temporary=((x*d) %10) + carrier;
				if (temporary>=10)
				{
					carrier=carrier+(temporary/10);
					temporary=temporary%10;
				}//end if. This is for if temporary before this decision block exceeds 10, then it should be splitted its echelons again.
				carrier=((x*d) + carrier) / 10;
				thirdArray[i]= temporary + '0';
			}//end 	of 3rd stage of multiplication
			for (*m=0;*m<(*n+1);(*m)++)//why the condition is evaluated according to *n is that, the summation could increase the echelon number only 1.
			{
				x=firstArray[(*m)+1] - '0' ;
				if (x == -48){
						 //-48 is the special value for which the elements are white spaces actually. if it is a white space then, it should be converted to 0.
						 // Because it means that those echelons don't exist in fact. As we do in reality, program ignores unused echelons. But we must make
						//- at least- enough of them, explicitly 0. Because they will be used afterwards.
					x=0;
				}//end if
				y=secondArray[*m] - '0';
				if( y== -48){
						//-48 is the special value for which the elements are white spaces actually. if it is a white space then, it should be converted to 0.
						 // Because it means that those echelons don't exist in fact. As we do in reality, program ignores unused echelons. But we must make
						//- at least- enough of them, explicitly 0. Because they will be used afterwards.
					y=0;
				}//end if
				z=thirdArray[(*m)-1] - '0';
				if( z== -48){
				//-48 is the special value for which the elements are white spaces actually. if it is a white space then, it should be converted to 0.
				 // Because it means that those echelons don't exist in fact. As we do in reality, program ignores unused echelons. But we must make
				//- at least- enough of them, explicitly 0. Because they will be used afterwards.
				z=0;
				}//end if

				temporary=((x+y+z)%10) + carrier;//what should be cared in here is, temporary may still exceed 10 now.
				carrier=(x+y+z)/10;
				reverseArray[(*m)+1]=(temporary%10) + '0' ;
				carrier=carrier+(temporary/10);//so in here , carrier should be determined precisely, according to that possibility.
			}//final summation

			for(*n=*m,*m=0;(*n)>=0;(*n)--)
			{
				j[*m]=reverseArray[*n];
				(*m)++;
			}//Last stage. Array is reversed again. hence, number too.

		}//induction phase
	}//end else
}//end function operation
