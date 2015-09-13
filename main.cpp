#include "functions.cpp"

using namespace std;

int main()
{
    unsigned short int nY=20, nX=70;
    srand(time(NULL));

    bool ** tablica = utworzTablice(nY, nX);

    los(tablica, nY, nX);
    //glider(tablica, nY, nX);
    for(int i=1; ; i++)
    {
        drukujTablice(tablica, nY, nX);
        bool ** bTymczasowa = utworzTablice(nY, nX);
        bTymczasowa = kolejnaGeneracja(tablica, bTymczasowa, nY, nX);
        usunTablice(tablica, nY);
        tablica = bTymczasowa;
        usleep(100000);
        if(czyKonczyc(i)==1)
        {
            usunTablice(tablica, nY);
            return 0;
        }
    }
}

