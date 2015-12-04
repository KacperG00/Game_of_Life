#include <iostream>
#include "functions.h"

using namespace std;

bool ** utworzTablice(int nY, int nX)
{
	bool ** tablica = new bool * [nY];
	for(int i=0; i<nY; i++)
	{
		tablica[i] = new bool[nX];
	}
	
	for(int y=0; y<nY; y++)
	{
		for(int x=0; x<nX; x++)
		{
			tablica[y][x]=0;
		}
	}
	
	return tablica;
}

void usunTablice(bool ** tablica, int nY)
{
	for(int i=0; i<nY; i++)
	{
		delete [] tablica[i];
	}
	delete [] tablica;
}

void glider(bool **tablica, int nY, int nX)
{
	for(int y=0; y<nY; y++)
    {
		for(int x=0; x<nX; x++)
		{
			tablica[y][x]=0;
		}
    }
    tablica[5][5] = 1;
    tablica[6][6] = 1;
    tablica[7][4] = 1;
    tablica[7][5] = 1;
    tablica[7][6] = 1;
}

void los(bool **tablica, int nY, int nX)
{
    int nLosowa;

    for(int y=0; y<nY; y++)
    {
		for(int x=0; x<nX; x++)
		{
			nLosowa=rand() %100 +1;
			if(nLosowa<26)
			{
				tablica[y][x]=1;
			}
			else
			{
				tablica[y][x]=0;
			}
		}
    }
}

void drukujTablice(bool **tablica, int nY, int nX, unsigned long int nrGeneracji)
{
    system("clear");
    cout<<"Wcisnij: ESC:wyjscie|'-':zwolnij|'+':przyspiesz|SPACJA:zatrzymaj"<<endl;
    for(int x=0; x<nX+2; x++)
    {
		cout<<'-';
	}
	cout<<endl;
    for(int y=0; y<nY; y++)
    {
        cout<<"|";
        for(int x=0; x<nX; x++)
        {
            if(tablica[y][x]==0)
            {
                cout<<' ';
            }
            else if(tablica[y][x]==1)
            {
                cout<<'*';
            }
        }
        cout<<"|"<<endl;
    }
    for(int x=0; x<nX+2; x++)
    {
		cout<<'-';
	}
    cout<<endl<<"Numer generacji: "<<nrGeneracji<<endl;
}

void drukujTabliceEdycja(bool **tablica, int nY, int nX, unsigned long int nrGeneracji, int Y, int X)
{
	system("clear");
    cout<<"Wcisnij: ESC:wyjscie|'-':zwolnij|'+':przyspiesz|SPACJA:zatrzymaj"<<endl;
    for(int x=0; x<nX+2; x++)
    {
		cout<<'-';
	}
	cout<<endl;
    for(int y=0; y<nY; y++)
    {
        cout<<"|";
        for(int x=0; x<nX; x++)
        {
			if((y==Y)&&(x==X))
			{
				if(tablica[y][x]==0)
				{
					cout<<'.';
				}
				else if(tablica[y][x]==1)
				{
					cout<<'^';
				}
			}
			else
			{
				if(tablica[y][x]==0)
				{
					cout<<' ';
				}
				else if(tablica[y][x]==1)
				{
					cout<<'*';
				}
			}
        }
        cout<<"|"<<endl;
    }
    for(int x=0; x<nX+2; x++)
    {
		cout<<'-';
	}
    cout<<endl<<"Numer generacji: "<<nrGeneracji<<endl;
}

int mod (int a, int b)
{
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}

void przeliczGeneracjeNaKomorce(bool **tablica, bool **bTymczasowa, int nY, int nX)
{
    for(int y=0; y<nY; y++)
    {
        for(int x=0; x<nX; x++)
        {
            int nLive=0;

            nLive = tablica[mod(y-1, nY)][mod(x-1, nX)]+tablica[y][mod(x-1, nX)]+tablica[mod(y+1, nY)][mod(x-1, nX)]
                +tablica[mod(y-1, nY)][mod(x, nX)]+tablica[mod(y+1, nY)][mod(x, nX)]
                +tablica[mod(y-1, nY)][mod(x+1, nX)]+tablica[mod(y, nY)][mod(x+1, nX)]+tablica[mod(y+1, nY)][mod(x+1, nX)];


            if(tablica[y][x]==0)
            {
                if(nLive==3)
                {
                    bTymczasowa[y][x]=1;
                }
                else
                {
                    bTymczasowa[y][x]=0;
                }
            }
            else if(tablica[y][x]==1)
            {
                if((nLive<2)||(nLive>3))
                {
                    bTymczasowa[y][x]=0;
                }
                else
                {
                    bTymczasowa[y][x]=1;
                }
            }
        }
    }
}

bool ** kolejnaGeneracja(bool **tablica, bool **bTymczasowa, int nY, int nX)
{
    przeliczGeneracjeNaKomorce(tablica, bTymczasowa, nY, nX);
    return bTymczasowa;
}
