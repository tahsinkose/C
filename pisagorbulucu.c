#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>


int main()
{
   	int x,y,z;
	for(x=1;x<=500;x++)
	{
		for(y=1;y<=500;y++)
		{
			for(z=1;z<=500;z++)
			{	
				if(pow(x,2)+pow(y,2)==pow(z,2))
				{
					printf("%d %d %d is a pythagorean\n",x,y,z);
					getchar();
				}
			}
		}
	}//end for
	return 0;
}//end main
