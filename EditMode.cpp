#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include <ctime>
#include "EditMode.h"
#include "functions.h"
#include "game.h"
#include "non-blocking.h"

int edytuj(bool **tablica, int nY, int nX, unsigned long int nrGeneracji)
{
	int Y=0, X=0;
	
	unsigned int iterator=0;
	
	char c;
	int i=0;
	nonblock(NB_ENABLE);
	while(!i)
	{
		if(iterator%2==0)
		{
			if(iterator%10<5)
			{
				drukujTabliceEdycja(tablica, nY, nX, nrGeneracji, Y, X);
			}
			else if(iterator%10>=5)
			{
				drukujTablice(tablica, nY, nX, nrGeneracji);
			}
		}
		
		i=kbhit();
		if(i!=0)
		{
			c=fgetc(stdin);
			switch(c)
			{
				case 'w': if(Y>0)Y=Y-1; break;
				case 's': if(Y<nY-1)Y=Y+1; break;
				case 'a': if(X>0)X=X-1; break;
				case 'd': if(X<nX-1)X=X+1; break;
				case 'l': los(tablica, nY, nX); break;
				case '`': zapiszPlansze(tablica, nY, nX); break;
				case (char)32: if(tablica[Y][X]==1) tablica[Y][X]=0;
							else if(tablica[Y][X]==0) tablica[Y][X]=1; break;
				case (char)9:
				{
					zwracana doEdycji = game(nY, nX, tablica, nrGeneracji);
					tablica = doEdycji.tablica;
					nrGeneracji = doEdycji.nrGen;
					if(doEdycji.wynik == 1)
					{
						usunTablice(tablica, nY);
						return 0;
					}
				} break;
				case (char)27:
				{
					usunTablice(tablica, nY);
					return 0;
				} break;
			}
			
			i=0;
		}
		usleep(100000);
		iterator++;
	}
	nonblock(NB_DISABLE);
	return 0;
}
