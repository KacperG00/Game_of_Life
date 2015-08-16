#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

unsigned short const int nY=20, nX=70;

void glider(bool tablica[][nX]);
//void los(bool tablica[][nX]);
void przeliczGeneracjeNaKomorce(bool tablica[][nX], bool bTymczasowa[][nX]);
void kopiujTablice(bool tablica[][nX], bool bTymczasowa[][nX]);
void kolejnaGeneracja(bool tablica[][nX], bool bTymczasowa[][nX]);
void drukujTablice(bool tablica[][nX]);
bool czyKonczyc(int i);

int main()
{
    srand(time(NULL));
    bool tablica[nY][nX]={}, bTymczasowa[nY][nX]={};
    //los(tablica);
    glider(tablica);
    system("color 5");      //NIE MOGŁEM SIĘ POWSTRZYMAĆ :P
    for(int i=1; ; i++)
    {
        drukujTablice(tablica);
        kolejnaGeneracja(tablica, bTymczasowa);
        Sleep(50);
        if(czyKonczyc(i)==1)
        {
            return 0;
        }
    }
}

void glider(bool tablica[][nX])
{
    tablica[5][5] = 1;
    tablica[6][6] = 1;
    tablica[7][4] = 1;
    tablica[7][5] = 1;
    tablica[7][6] = 1;
}

/*
void los(bool tablica[][nX])
{
    bool *wb;
    wb = &tablica[0][0];
    int nLosowa;

    for(int i=0; i<nX*nY; i++)
    {
        nLosowa=rand() %100 +1;
        if(nLosowa<26)
        {
            *(wb++)=1;
        }
        else
        {
            *(wb++)=0;
        }
    }
}
*/

void przeliczGeneracjeNaKomorce(bool tablica[][nX], bool bTymczasowa[][nX])
{
    for(int y=0; y<nY; y++)
    {
        for(int x=0; x<nX; x++)
        {
            int nLive=0;

            if((y!=0)||(y!=nY-1)||(x!=0)||(x!=nX-1))
            {
                nLive = tablica[y-1][x-1]+tablica[y][x-1]+tablica[y+1][x-1]
                        +tablica[y-1][x]+tablica[y+1][x]
                        +tablica[y-1][x+1]+tablica[y][x+1]+tablica[y+1][x+1];
            }
            else if(y==0)
            {
                if(x==0)
                {
                    nLive = tablica[y+1][x]+tablica[y][x+1]+tablica[y+1][x+1];
                    nLive += tablica[1][nX-1]+tablica[0][nX-1]
                             +tablica[nY-1][nX-1]
                             +tablica[nY-1][0]+tablica[nY-1][1];

                }
                else if(x==nX-1)
                {
                    nLive = tablica[y+1][x]+tablica[y][x+1]+tablica[y+1][x+1];
                    nLive += tablica[0][1]+tablica[0][0]
                             +tablica[nY-1][0]
                             +tablica[nY-1][nX-2]+tablica[nY-1][nX-1];
                }
                else
                {
                    nLive = tablica[y][x-1]+tablica[y+1][x-1]
                            +tablica[y+1][x]
                            +tablica[y][x+1]+tablica[y+1][x+1];
                    nLive += tablica[nY-1][x-1]+tablica[nY-1][x]+tablica[nY-1][x+1];
                }
            }
            else if(y==nY-1)
            {
                if(x==0)
                {
                    nLive = tablica[y-1][x]+tablica[y-1][x+1]+tablica[y][x+1];
                    nLive += tablica[0][1]+tablica[0][0]
                             +tablica[0][nX-1]
                             +tablica[nY-2][nX-1]+tablica[nY-1][nX-1];
                }
                else if(x==nX-1)
                {
                    nLive = tablica[y-1][x-1]+tablica[y][x-1]+tablica[y-1][x];
                    nLive += tablica[nY-2][0]+tablica[nY-1][0]
                             +tablica[0][0]
                             +tablica[0][nX-2]+tablica[0][nX-1];
                }
                else
                {
                    nLive = tablica[y-1][x-1]+tablica[y][x-1]
                            +tablica[y-1][x]
                            +tablica[y-1][x+1]+tablica[y][x+1];
                    nLive += tablica[0][x-1]+tablica[0][x]+tablica[0][x+1];
                }
            }
            else if(x==0)
            {
                nLive = tablica[y-1][x]+tablica[y+1][x]
                        +tablica[y-1][x+1]+tablica[y][x+1]+tablica[y+1][x+1];
                nLive += tablica[y-1][nX-1]+tablica[y][nX-1]+tablica[y+1][nX-1];
            }
            else if(x==nX-1)
            {
                nLive = tablica[y-1][x-1]+tablica[y][x-1]+tablica[y+1][x-1]
                        +tablica[y-1][x]+tablica[y+1][x];
                nLive += tablica[y-1][0]+tablica[y][0]+tablica[y+1][0];
            }


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

void kopiujTablice(bool tablica[][nX], bool bTymczasowa[][nX])
{
    for(int y=0; y<nY; y++)
    {
        for(int x=0; x<nX; x++)
        {
            tablica[y][x]=bTymczasowa[y][x];
        }
    }
}

void kolejnaGeneracja(bool tablica[][nX], bool bTymczasowa[][nX])
{
    przeliczGeneracjeNaKomorce(tablica, bTymczasowa);
    kopiujTablice(tablica, bTymczasowa);
}

void drukujTablice(bool tablica[][nX])
{
    system("cls");
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
    else
    {
        return 0;
    }
}
