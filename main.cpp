<<<<<<< HEAD
#include "Menu.h"
=======
#include <iostream>
#include "EditMode.h"
#include "non-blocking.h"
#include "functions.h"
>>>>>>> f84cb32387f86a6b3b4c4e46274b6d7ccbb19c72

using namespace std;

int main()
{
<<<<<<< HEAD
	unsigned short int nY=20, nX=70;
    Menu(nY, nX);
    
	return 0;
=======
    unsigned short int nY=20, nX=70;
    float V=1;
    srand(time(NULL));

    bool ** tablica = utworzTablice(nY, nX);

    //los(tablica, nY, nX);
    glider(tablica, nY, nX);

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
			if(V<100)
			{
				drukujTablice(tablica, nY, nX, nrGen);
			}
			else if(iterator%25==0)
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
				case (char)32: edytuj(tablica, nY, nX, iterator); break;	//Spacja
				case '+': V+=1; break;
				case '-': V-=1; if(V==0) { edytuj(tablica, nY, nX, nrGen); V++; } break;
				case '*': V=V*2; break;
				case '/': V=V/2; break;
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
>>>>>>> f84cb32387f86a6b3b4c4e46274b6d7ccbb19c72
}
