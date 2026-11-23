#include "../include/PrognozaPogody.h"
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
string PrognozaPogody::pobierzMiasto() const{return data;}
double PrognozaPogody::pobierzTemperature() const{return temperatura;}
int PrognozaPogody::pobierzWilgotnosc() const{return wilgotnosc;}

void PrognozaPogody::ustawMiasto(const string& nowaData)
{
    data = nowaData;
}

void PrognozaPogody::ustawDate(const string& nowaData)
{
    data = nowaData;
}

void PrognozaPogody::ustawTemperature(double nowaTemperatura)
{
    temperatura = nowaTemperatura;
}

void PrognozaPogody::ustawWilgotnosc(int nowaWilgotnosc)
{
    wilgotnosc = nowaWilgotnosc;
}

bool PrognozaPogody::operator<(const PrognozaPogody& inna) const{
    return this ->temperatura < inna.temperatura;
}

ostream& operator<<(ostream& os, const PrognozaPogody& prognoza)
{
    os << "[" << prognoza.pobierzTypPrognozy() << "] " << prognoza.miasto << " (" << prognoza.data << ") | Temp: " << fixed << setprecision(1) << prognoza.temperatura << " C | Wilg: " << prognoza.wilgotnosc << "%";
    return os;
}