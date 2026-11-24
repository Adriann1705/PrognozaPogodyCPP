#include "../include/AlertBurzowy.h"
#include "../include/WyjatekPogodowy.h"

using namespace std;

AlertBurzowy::AlertBurzowy(): PrognozaPogody(), stopienZagrozenia(1), zjawisko("Burza"){}

AlertBurzowy::AlertBurzowy(const string& miasto, const string& data, double temperatura, int wilgotnosc, int stopienZagrozenia, const string& zjawisko): PrognozaPogody(miasto, data, temperatura, wilgotnosc), zjawisko(zjawisko)
{
    ustawStopienZagrozenia(stopienZagrozenia);
}

int AlertBurzowy::pobierzStopienZagrozenia() const { return stopienZagrozenia; }
void AlertBurzowy::ustawStopienZagrozenia(int stopien)
{
    if (stopien < 1 || stopien > 3)
    {
        throw WyjatekPogodowy("Stopien zagrozenia musi wynosic 1, 2 lub 3!");
    }
    stopienZagrozenia = stopien;
}

void AlertBurzowy::wyswietlSzczegoly() const
{
    cout << *this << " | !!! ALERT STOPNIA " << stopienZagrozenia << " (" << zjawisko << " ) !\n";
}

string AlertBurzowy::pobierzTypPrognozy() const
{
    return "OSTRZEZENIE";
}

