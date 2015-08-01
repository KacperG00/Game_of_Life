#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int nRandom;

void drukujTablice(bool tablica[][10])
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            nRandom=rand() %100 +1;
            if(nRandom<26)  tablica[i][j]=1;
            else            tablica[i][j]=0;

            if(tablica[i][j]==0)   cout<<' ';
            else                   cout<<'*';
        }
        cout<<endl;
    }
}

int main()
{
    srand(time(NULL));
    bool tablica[10][10]={};
    drukujTablice(tablica);
    return 0;
}
