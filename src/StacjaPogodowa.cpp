#include "../include/StacjaPogodowa.h"
#include <iostream>
#include <algorithm>

using namespace std;

StacjaPogodowa::StacjaPogodowa(const string& nazwa):nazwaStacji(nazwa){}

void StacjaPogodowa::dodajProgonze(const shared_ptr<PrognozaPogody>& prognoza)
{
    for(const auto& element: prognozy){}
    prognozy.push_back(prognoza);


}

void StacjaPogodowa::usunPrognoze(size_t indeks)
{
    prognozy.erase(prognozy.begin() + indeks);
}

void StacjaPogodowa::aktualizujTemperature(size_t indeks, double nowaTemperatura)
{
    prognozy[indeks]->ustawTemperature(nowaTemperatura);
}

void StacjaPogodowa::szukajPoMiescie(const string& miasto) const
{
    bool znaleziono = false;
    cout << "\n--- Wyniki wyszukiwania dla: " << miasto << " ---\n";
    for (size_t i = 0; i < prognozy.size(); ++i) {
        if (prognozy[i]->pobierzMiasto() == miasto) {
            cout << "[" << i << "] ";
            prognozy[i]->wyswietlSzczegoly();
            znaleziono = true;
        }
    }
    if (!znaleziono) {
        cout << "Brak prognoz dla podanego miasta.\n";
    }
}

void StacjaPogodowa::sortujPoTemperaturze()
{
    sort(prognozy.begin(), prognozy.end(), [](const shared_ptr<PrognozaPogody>& a, const shared_ptr<PrognozaPogody>& b)
        {
            return *a < *b;
        }
    );
}

void StacjaPogodowa::wyswietlWszystkie() const
 {
    cout << "\n=== STACJA POZNAN: " << nazwaStacji << " ===\n";
    if (prognozy.empty())
    {
        cout << "Brak zapisanych prognoz.\n";
        return;
    }
    for (size_t i = 0; i < prognozy.size(); ++i) {
        cout << "[" << i << "] ";
        prognozy[i]->wyswietlSzczegoly();
    }
}

size_t StacjaPogodowa::pobierzLiczbePrognoz() const {
    return prognozy.size();
}
