#include "../include/PrognozaPogody.h"
#include "../include/WyjatekPogodowy.h"
#include <iomanip>

using namespace std;

PrognozaPogody::PrognozaPogody() : miasto("Nieznane"), data("1970-01-01"), temperatura(0.0), wilgotnosc(50){}

PrognozaPogody::PrognozaPogody(const string& miasto, const string& data, double temperatura, int wilgotnosc)
{
    ustawMiasto(miasto);
    ustawDate(data);
    ustawTemperature(temperatura);
    ustawWilgotnosc(wilgotnosc);
}

PrognozaPogody::~PrognozaPogody(){}

string PrognozaPogody::pobierzMiasto() const{return miasto;}
string PrognozaPogody::pobierzDate() const{return data;}
double PrognozaPogody::pobierzTemperature() const{return temperatura;}
int PrognozaPogody::pobierzWilgotnosc() const{return wilgotnosc;}

void PrognozaPogody::ustawMiasto(const string& noweMiasto)
{
    if (noweMiasto.empty())
    {
        throw WyjatekPogodowy("Nazwa miasta nie moze byc pusta!");
    }
    miasto = noweMiasto;
}

void PrognozaPogody::ustawDate(const string& nowaData)
{
    if (nowaData.empty())
    {
        throw WyjatekPogodowy("Data nie moze byc pusta!");
    }
    data = nowaData;
}

void PrognozaPogody::ustawTemperature(double nowaTemperatura)
{
    if (nowaTemperatura < -273.15 || nowaTemperatura > 70.0)
    {
        throw WyjatekPogodowy("Nieprawidlowa temperatura! Dopuszczalny zakres: -273.15 C do 70.0 C.");
    }
    temperatura = nowaTemperatura;
}

void PrognozaPogody::ustawWilgotnosc(int nowaWilgotnosc)
{
    if (nowaWilgotnosc < 0 || nowaWilgotnosc > 100)
    {
        throw WyjatekPogodowy("Wilgotnosc musi miescic sie w przedziale 0-100%!");
    }
    wilgotnosc = nowaWilgotnosc;
}

bool PrognozaPogody::operator==(const PrognozaPogody& inna) const {
    return (this->miasto == inna.miasto && this->data == inna.data);
}

bool PrognozaPogody::operator<(const PrognozaPogody& inna) const{
    return this ->temperatura < inna.temperatura;
}

ostream& operator<<(ostream& os, const PrognozaPogody& prognoza)
{
    os << "[" << prognoza.pobierzTypPrognozy() << "] " << prognoza.miasto << " (" << prognoza.data << ") | Temp: " << fixed << setprecision(1) << prognoza.temperatura << " C | Wilg: " << prognoza.wilgotnosc << "%";
    return os;
}
