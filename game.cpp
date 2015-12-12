#include <unistd.h>
#include <stdio.h>
#include "functions.h"
#include "non-blocking.h"
#include "EditMode.h"
#include "game.h"

using namespace std;

int game(unsigned short int nY, unsigned short int nX, bool **tablica)
{
    int V=1;
	
	char c;
    int i=0;
    unsigned long int iterator=0;
    unsigned long int nrGen=0;
    
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
		usleep(200000/V);
		
		
		i=kbhit();
		if(i!=0)
		{
			c=fgetc(stdin);
			switch(c)
			{
				case (char)27: usunTablice(tablica, nY); return 0;	//ESC
				case (char)32:										//Spacja
					if(edytuj(tablica, nY, nX, nrGen)==1)
					{
						usunTablice(tablica, nY);
						return 0;
					} break;
				case '+': V+=1; break;
				case '-': V-=1;
					if(V<=0)
					{
						if(edytuj(tablica, nY, nX, nrGen)==0) V++;
						else if(edytuj(tablica, nY, nX, nrGen)==1)
						{
							usunTablice(tablica, nY);
							return 0;
						}
					} break;
				case '*': V=V*2; break;
				case '/': if(V%2==1)
						  {
							  V++;
						  }
						  V=V/2; break;
				case '1': V=1; break;
				case '2': V=5; break;
				case '3': V=10; break;
				case '4': V=20; break;
				case '5': V=100; break;
			}
			
			i=0;
		}
		iterator++;
	}
    nonblock(NB_DISABLE);
}
