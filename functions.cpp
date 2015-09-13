#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "functions.h"

using namespace std;

bool ** utworzTablice(int nY, int nX)
{
	bool ** tablica = new bool * [nY];
	for(int i=0; i<nY; i++)
	{
		tablica[i] = new bool[nX];
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

void drukujTablice(bool **tablica, int nY, int nX)
{
    system("clear");
    cout<<"------------------------------------------------------------------------"<<endl;
    for(int y=0; y<nY; y++)
    {
        cout<<"|";
        for(int x=0; x<nX; x++)
        {
            if(tablica[y][x]==0)
            {
                cout<<' ';
            }
            else
            {
                cout<<'*';
            }
        }
        cout<<"|"<<endl;
    }
    cout<<"------------------------------------------------------------------------"<<endl;
}

bool czyKonczyc(int i)
{
    if(i%100==0)
    {
        cout<<endl<<endl<<"  1. Continue"<<endl<<"  2. Exit"<<endl<<"   Your choise: ";
        int wybor;
        cin>>wybor;
        switch(wybor)
        {
            case 1: return 0;
            case 2: return 1;
        }
    }
    return 0;
}
