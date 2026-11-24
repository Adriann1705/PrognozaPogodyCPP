#include "../include/PrognozaDzienna.h"
#include "../include/WyjatekPogodowy.h"
#include <iostream>

using namespace std;

PrognozaDzienna::PrognozaDzienna():PrognozaPogody(), stanNieba("Bezchmurnie"), predkoscWiatru(0.0){}

PrognozaDzienna::PrognozaDzienna(const string& miasto, const string& data, double temperatura, int wilgotnosc, const string& stanNieba, double predkoscWiatru): PrognozaPogody(miasto, data, temperatura, wilgotnosc), stanNieba(stanNieba)
{
    ustawPredkoscWiatru(predkoscWiatru);
}

string PrognozaDzienna::pobierzStanNieba() const { return stanNieba; }
double PrognozaDzienna::pobierzPredkoscWiatru() const { return predkoscWiatru; }

void PrognozaDzienna::ustawPredkoscWiatru(double predkosc)
{
    if (predkosc < 0.0)
    {
        throw WyjatekPogodowy("Predkosc wiatru nie moze byc ujemna!");
    }
    predkoscWiatru = predkosc;
}

void PrognozaDzienna::wyswietlSzczegoly() const
{
    cout << *this << " | Niebo: " << stanNieba << " | Wiatr: " << predkoscWiatru << " km/h\n";
}

string PrognozaDzienna::pobierzTypPrognozy() const {
    return "PROGNOZA DZIENNA";
}
