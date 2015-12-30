#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <unistd.h>
#include <string>
#include <fstream>
#include <dirent.h>
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

void los(bool **tablica, int nY, int nX)
{
	srand(time(NULL));
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

bool ** wczytajPlansze(int* nY, int* nX)
{
	system("ls Plansze/");
	cout<<"\n\n Wybierz plik: ";
	string nazwaPliku;
	cin>>nazwaPliku;
	
	bool** tablica = NULL;
	if(nazwaPliku == "wroc")
	{
		return tablica;
	}
	
	string linia;
	
	ifstream plik(("Plansze/"+nazwaPliku).c_str());
	
	int test = 0;
	int test2 = 0;
	
	getline(plik, linia);
	test = atoi(linia.c_str());
	getline(plik, linia);
	test2 = atoi(linia.c_str());
	if((test > 5) && (test2 >5))
	{
		*nY = test;
		*nX = test2;
	}
	else
	{
		cout<<"Tablica musi miec przynajmniej 6 wierszy i 6 kolumn"<<endl;
		return tablica;
	}
	cout<<*nX<<endl;
	getline(plik, linia);
	
	plik.close();
	tablica = utworzTablice(*nY, *nX);
	int y=0;
	int x=0;
	int i=0;
	do
	{
		tablica[y][x] = (linia[i] == '1');
		
		i++;
		x++;
		if(x>=*nX)
		{
			x=0;
			y++;
		}
	} while(y<*nY);
	return tablica;
}

void zapiszPlansze(bool **tablica, int nY, int nX)
{
	string nazwaPliku;
	
	cout<<"Nazwa pliku: ";
	cin>>nazwaPliku;
	
	ofstream plik(("Plansze/"+nazwaPliku+".txt").c_str());
	
	plik<<nY<<endl;
	plik<<nX<<endl;
	for(int y=0; y<nY; y++)
	{
		for(int x=0; x<nX; x++)
		{
			plik<<tablica[y][x];
		}
	}
	
	plik.close();
}
