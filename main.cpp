#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int nRandom, choise;

void los(bool tablica[][70])
{
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<70; j++)
        {
            nRandom=rand() %100 +1;
            if(nRandom<26)
            {
                tablica[i][j]=1;
            }
            else
            {
               tablica[i][j]=0;
            }
        }
    }
}

void sprawdz(bool tablica[][70], bool bTabliczka[][70])
{
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<70; j++)
        {
    //SUMOWANIE LICZB ŻYWYCH KOMÓREK        //TYLE ELSÓW, BO BOJĘ SIĘ O WYCHODZENIE ZA TABLICE
            int nLive=0;

            if((i==0)&&(j==0))
            {
                nLive = tablica[i+1][j]+tablica[i][j+1]+tablica[i+1][j+1];
            }
            else if((i==19)&&(j==69))
            {
                nLive = tablica[i-1][j-1]+tablica[i][j-1]+tablica[i-1][j];
            }
            else if(j==0)
            {
                nLive = tablica[i-1][j]+tablica[i+1][j]
                       +tablica[i-1][j+1]+tablica[i][j+1]+tablica[i+1][j+1];
            }
            else if(i==0)
            {
                nLive = tablica[i][j-1]+tablica[i+1][j-1]
                        +tablica[i+1][j]
                        +tablica[i][j+1]+tablica[i+1][j+1];
            }
            else if(i==19)
            {
                nLive = tablica[i-1][j-1]+tablica[i][j-1]
                        +tablica[i-1][j]
                        +tablica[i-1][j+1]+tablica[i][j+1];
            }
            else if(j==69)
            {
                nLive = tablica[i-1][j-1]+tablica[i][j-1]+tablica[i+1][j-1]
                        +tablica[i-1][j]+tablica[i+1][j];
            }
            else
            {
                nLive = tablica[i-1][j-1]+tablica[i][j-1]+tablica[i+1][j-1]
                        +tablica[i-1][j]+tablica[i+1][j]
                        +tablica[i-1][j+1]+tablica[i][j+1]+tablica[i+1][j+1];
            }
    //WPISYWANIE WARTOŚCI DO POMOCNICZEJ TABLICY
            if(tablica[i][j]==0)
            {
                if(nLive==3)
                {
                        bTabliczka[i][j]=1;
                }
            }
            else if(tablica[i][j]==1)
            {
                if((nLive<2)||(nLive>3))
                {
                        bTabliczka[i][j]=0;
                }
            }
        }
    }
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<70; j++)
        {
            tablica[i][j]=bTabliczka[i][j];
        }
    }
}

void drukujTablice(bool tablica[][70])
{
    system("cls");
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<70; j++)
        {
            if(tablica[i][j]==0)   cout<<' ';
            else                   cout<<'*';
        }
        cout<<endl;
    }
}

int main()
{
    srand(time(NULL));
    bool tablica[20][70]={}, bTabliczka[20][70]={};
    los(tablica);
    system("color 5");      //NIE MOGŁEM SIĘ POWSTRZYMAĆ :P
    for(int i=1; ; i++)
    {
        drukujTablice(tablica);
        sprawdz(tablica, bTabliczka);
        Sleep(50);


        if(i%100>98)
        {
            cout<<endl<<endl<<"  1. Continue"<<endl<<"  2. Exit"<<endl<<"   Your choise: ";
            cin>>choise;
            switch(choise)
            {
                case 1: break;
                case 2: return 0;
            }
        }
    }
}
