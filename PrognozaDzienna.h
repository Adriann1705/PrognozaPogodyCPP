#ifndef PROGONZA_DZIENNA_H
#define PROGONZA_DZIENNA_H

#include "prognozapogody.h"
using namespace std;

class PrognozaDzienna : public PrognozaPogody{
private:
    string stanNieba;
    double predkoscWiatru;

public:
    PrognozaDzienna();
    PrognozaDzienna(const string& miasto, const string& data, double temperatura, int wilgotonosc, const string& stanNieba, double predkoscWiatru);

    string pobierzStanNieba() const;
    double pobierzPredkoscWiatru() const;
    void ustawPredkoscWiatru(double predkosc);

    void wyswietlSzczegoly() const override;
    string pobierzTypPrognozy() const override;
};

#endif