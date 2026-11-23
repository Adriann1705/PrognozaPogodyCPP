#ifndef PROGONZA_POGODY_H
#define PROGONZA_POGODY_H

#include <string>
#include <iostream>

using namespace std;

class PrognozaPogody{
    protected:
        string miasto;
        string data;
        double temperatura;
        int wilgotnosc;
    
    public:
        PrognozaPogody();
        PrognozaPogody(const string& miasto, const string& data, double temperatura, int wilgotnosc);
        

        virtual ~PrognozaPogody();
        
        string pobierzMiasto() const;
        string pobierzDate() const;
        double pobierzTemperature() const;
        int pobierzWilgotnosc() const;
        
        void ustawMiasto(const string& noweMiasto);
        void ustawDate(const string& nowaData);
        void ustawTemperature(double nowaTemperatura);
        void ustawWilgotnosc(int nowaWilgotnosc);
        
        virtual void wyswietlSzczegoly() const = 0;
        virtual string pobierzTypPrognozy() const = 0;
        
        bool operator==(const PrognozaPogody& inna) const;
        bool operator<(const PrognozaPogody& inna) const;
        friend ostream& operator<<(ostream& os, const PrognozaPogody& prognoza);

};
#endif
