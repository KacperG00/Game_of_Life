bool ** utworzTablice(int nY, int nX);
void usunTablice(bool ** tablica, int nY);
void los(bool **tablica, int nY, int nX);
void drukujTablice(bool **tablica, int nY, int nX, unsigned long int nrGeneracji);
void drukujTabliceEdycja(bool **tablica, int nY, int nX, unsigned long int nrGeneracji, int Y, int X);
int mod (int a, int b);
void przeliczGeneracjeNaKomorce(bool **tablica, bool **bTymczasowa, int nY, int nX);
bool ** kolejnaGeneracja(bool **tablica, bool **bTymczasowa, int nY, int nX);
bool ** wczytajPlansze(int* nY, int* nX);
void zapiszPlansze(bool **tablica, int nY, int nX);
