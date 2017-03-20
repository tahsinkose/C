/* ------------- Program array of pointers'in içindeki eleman sayısını sayamıyor. Bunu saydırmayı becerirsen program daha otomatik 
 *  bir hal alır. Ayrıca, array of pointers'a input girmek istediğimde çekirdek döküldü hatası geliyor.*/






#include <stdio.h>
#include <string.h>

int main()
{
	const char *towns[]={"Istanbul","Diyarbakır","Bursa","Ankara","Antalya","Kars","Muğla","Denizli"};
	
	int pass=0;
	
	const char *swap;
	for(;pass<6;pass++)
	{
		for(size_t i=0;i<7;i++)
		{
			if((strcmp(towns[i],towns[i+1]))>0)
			{
				swap=towns[i];
				towns[i]=towns[i+1];
				towns[i+1]=swap;
			}//end if
		}//end for
	}//end for
	size_t j=0;
	for(;j<8;j++)
	{
		printf("%s\n",towns[j]);
	}
}//end main
