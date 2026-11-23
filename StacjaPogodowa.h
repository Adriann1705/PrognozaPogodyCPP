#ifndef STACJA_POGODOWA_H
#define STACJA_POGODOWA_H

#include <vector>
#include <memory>
#include <string>
#include "PrognozaPogody.h"

class StacjaPogodowa{
    private:
        string nazwaStacji;
        vector<shared_ptr<PrognozaPogody>> prognozy;
    public:
        explicit StacjaPogodowa(const string& nazwa);
        
        void DodajProgonze(const shared_ptr<PrognozaPogody>& prognoza);
        void usunPrognoze(size_t indeks);
        void aktualizujTemperature(size_t indeks, double nowaTemperatura);
        void szukajPoMiescie(const string& miasto) const;
        void sortujPoTemperaturze();
        void wyswietlWszystkie() const;
        size_t pobierzLiczbePrognoz() const;

};

#endif