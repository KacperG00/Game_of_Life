#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include "functions.h"
#include "game.h"
#include "Menu.h"

using namespace std;

int nowaPlansza(unsigned short int nY, unsigned short int nX)
{
	for(;;)
	{
		system("clear");
		cout<<"1. Stworz plansze ("<<nX<<" - "<<nY<<")\n";
		cout<<"2. Wymiary planszy\n";
		cout<<"3. Wroc\n";
	
		int wybor;
		cin>>wybor;
	
		switch(wybor)
		{
			case 1: 
				{	
					bool ** tablica = utworzTablice(nY, nX);
					game(nY, nX, tablica);
				}
				break;
			case 2:
				{	
					system("clear");
					cout<<"Komorki w poziomie: ";
					cin>>nX;
					cout<<"Komorki w pionie: ";
					cin>>nY;
				}
				break;
			case 3: return 0;
		}
	}
}

int Menu(unsigned short int nY, unsigned short int nX)
{
	for(;;)
	{
		system("clear");
		cout<<"1. Nowa plansza\n";
		cout<<"2. Wczytaj plansze\n";
		cout<<"3. Wyjscie\n";
	
		int wybor;
		cin>>wybor;
	
		switch(wybor)
		{
			case 1: nowaPlansza(nY, nX); break;
			case 3: return 0;
		}
	}
}
