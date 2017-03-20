#include <stdio.h>

int main()
{
	unsigned int distance;
	unsigned int velocity;
	unsigned int interval;
	unsigned int minutes;
	double current_distance;
	
	printf ("Enter total distance (km)  : ");
	scanf("%u",&distance);
	printf("Enter velocity(km/hour)  : ");
	scanf("%u",&velocity);
	printf ("Enter time interval(min.)  : ");
	scanf("%u",&interval);

	printf ("%s %15s\n","Time(min.)", "Distance(km)");
	printf("%s %15s\n","**********", "************");
	
	double km_minute=(velocity/60.00);
	

	for (minutes=0;(minutes*(double)velocity/60)<=distance;minutes=minutes+interval)
	{
		printf ("%6u%19.2f\n",minutes,(minutes*velocity/60.00));
		current_distance= (minutes*velocity/60.00);
		
	}//end for

	unsigned int fold_time;
	if (current_distance < distance)
	{
		fold_time=(double)distance/km_minute;
	}
		
	printf ("%6u%19.2f",fold_time,(double)distance);
	
}
