#include <stdio.h>

unsigned long long int fibonacci(int i);
int main(){
    
	unsigned long long int result;
	unsigned long long int sum=0;

	for(int k=0;k<40;k++)
	{	
		result=fibonacci(k);
		if(result%2==0 && result<4000000)
		{
			printf("Fibonacci(%d)=%llu\n",k,result);
			sum+=result;
		}
	}
   	printf("%llu",sum);
   
}

unsigned long long int fibonacci(int i)
{
	
	if (0==i || 1==i)
	{	
		return i ;
	}
	else
	{
		return fibonacci(i-1)+fibonacci(i-2);
	}//end else
	
	

}
