#include "functions.h"
#include "non-blocking.cpp"

using namespace std;

int main()
{
    unsigned short int nY=20, nX=70, nrGeneracji=0;
    short int V=1;
    srand(time(NULL));

    bool ** tablica = utworzTablice(nY, nX);

    los(tablica, nY, nX);
    //glider(tablica, nY, nX);
    
    char c;
    int i=0;
    
    nonblock(NB_ENABLE);
    while(!i)
    {
		nrGeneracji++;
		usleep(100000*V);
		i=kbhit();
		if(i!=0)
		{
			c=fgetc(stdin);
			if(c=='q')
			{
				usunTablice(tablica, nY);
				system("^C");
			}
			else if(c=='s')
			{
				getchar();
				i=0;
			}
			else if(c=='+')
			{
				V++;
				i=0;
			}
			else if(c=='-')
			{
				V-=1;
				i=0;
			}
		}
		drukujTablice(tablica, nY, nX, nrGeneracji);
        bool ** bTymczasowa = utworzTablice(nY, nX);
        bTymczasowa = kolejnaGeneracja(tablica, bTymczasowa, nY, nX);
        usunTablice(tablica, nY);
        tablica = bTymczasowa;
	}
    nonblock(NB_DISABLE);
}
