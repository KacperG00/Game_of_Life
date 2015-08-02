#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int nRandom;

void los(bool tablica[][10])
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            nRandom=rand() %100 +1;
            if(nRandom<26)  {tablica[i][j]=1;}//miały być klamry
            else            {tablica[i][j]=0;}// :D
        }
    }
}

void drukujTablice(bool tablica[][10])
{
    system("cls");
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(tablica[i][j]==0)   cout<<' ';  //Jak dla mnie to
            else                   cout<<'*';  //nie wygląda
        }                                      //źle...
        cout<<endl;
    }//... a szkoda linijek na klamerki :P
}

int main()
{
    srand(time(NULL));
    bool tablica[10][10]={};
    los(tablica);
    drukujTablice(tablica);
    return 0;
}
