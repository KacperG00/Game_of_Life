#include "functions.h"
#include "non-blocking.cpp"

using namespace std;

int main()
{
    unsigned short int nY=20, nX=70;
    float V=1;
    srand(time(NULL));

    bool ** tablica = utworzTablice(nY, nX);

    //los(tablica, nY, nX);
    glider(tablica, nY, nX);

    char c;
    int i=0;
    unsigned long int iterator=0;
    
    nonblock(NB_ENABLE);
    while(!i)
    {
		iterator++;

		i=kbhit();
		if(i!=0)
		{
			c=fgetc(stdin);
			switch(c)
			{
				case (char)27: usunTablice(tablica, nY); return 0;	//ESC
				case (char)32: getchar(); break;	//Spacebar
				case '+': V+=1; break;
				case '-': V-=1; if(V==0) {getchar(); V+=1;} break;
				case '*': V=V*2; break;
				case '/': V=V/2; break;
				case '1': V=1; break;
				case '2': V=5; break;
				case '3': V=10; break;
				case '4': V=100; break;
			}
			
			i=0;
		}
		if(iterator%5==0)
		{
			if(V<100)
			{
				drukujTablice(tablica, nY, nX, iterator);
			}
			else if(iterator%25==0)
			{
				drukujTablice(tablica, nY, nX, iterator);
			}
			bool ** bTymczasowa = utworzTablice(nY, nX);
			bTymczasowa = kolejnaGeneracja(tablica, bTymczasowa, nY, nX);
			usunTablice(tablica, nY);
			tablica = bTymczasowa;
			
			usleep(1000000/V);
		}
	}
    nonblock(NB_DISABLE);
}
