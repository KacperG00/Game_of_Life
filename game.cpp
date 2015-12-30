#include <unistd.h>
#include <stdio.h>
#include "functions.h"
#include "non-blocking.h"
#include "game.h"

zwracana game(int nY, int nX, bool **tablica, unsigned long int nrGen)
{
    int V=1;
	
	char c;
    int i=0;
    unsigned long int iterator=0;
    
    nonblock(NB_ENABLE);
    while(!i)
    {
		if(iterator%5==0)
		{
			nrGen++;
			if((V<100)||(iterator%25==0))
			{
				drukujTablice(tablica, nY, nX, nrGen);
			}
			bool ** bTymczasowa = utworzTablice(nY, nX);
			bTymczasowa = kolejnaGeneracja(tablica, bTymczasowa, nY, nX);
			usunTablice(tablica, nY);
			tablica = bTymczasowa;
		}
		
		
		i=kbhit();
		if(i!=0)
		{
			c=fgetc(stdin);
			switch(c)
			{
				case (char)27:
				{
					zwracana doEdycji;
					doEdycji.tablica = tablica;
					doEdycji.nrGen = nrGen;
					doEdycji.wynik = 1;
					return doEdycji;
				} break;
				case (char)9:
				{
					zwracana doEdycji;
					doEdycji.tablica = tablica;
					doEdycji.nrGen = nrGen;
					doEdycji.wynik = 0;
					return doEdycji;
				} break;
				case '+': V+=1; break;
				case '-':
				{
					V--;
					if(V<=0)
					{
						zwracana doEdycji;
						doEdycji.tablica = tablica;
						doEdycji.nrGen = nrGen;
						doEdycji.wynik = 0;
						return doEdycji;
					}
				} break;
				case '*': V=V*2; break;
				case '/':
				{
					if(V%2==1)
					{
						V++;
					}
					V=V/2;
				} break;
				case '1': V=1; break;
				case '2': V=5; break;
				case '3': V=10; break;
				case '4': V=20; break;
				case '5': V=100; break;
			}
			
			i=0;
		}
		usleep(200000/V);
		iterator++;
	}
    nonblock(NB_DISABLE);
}
