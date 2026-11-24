#include <iostream>
#include <memory>
#include <limits>
#include "../include/StacjaPogodowa.h"
#include "../include/PrognozaDzienna.h"
#include "../include/AlertBurzowy.h"
#include "../include/WyjatekPogodowy.h"


using namespace std;

void wyczyscBufor()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void wyswietlMenu() {
    cout << "\n--- SYSTEM PROGNOZY POGODY ---\n"
         << "1. Wyswietl wszystkie prognozy\n"
         << "2. Dodaj prognoze dzienna\n"
         << "3. Dodaj ostrzezenie burzowe (Alert)\n"
         << "4. Wyszukaj prognoze po miescie\n"
         << "5. Modyfikuj temperature prognozy\n"
         << "6. Usun prognoze\n"
         << "7. Sortuj prognozy rosnaco wg temperatury\n"
         << "0. Wyjscie\n"
         << "Wybor: ";
}

int main()
{
    StacjaPogodowa stacja("Poznan Polanka");
    try {
        stacja.dodajProgonze(make_shared<PrognozaDzienna>("Lodz", "2026-11-24", 8.5, 72, "Pochmurno", 18.0));
        stacja.dodajProgonze(make_shared<PrognozaDzienna>("Warszawa", "2026-11-24", 7.0, 68, "Slonecznie", 12.5));
    } catch (const WyjatekPogodowy& e) {
        cerr << "Blad inicjalizacji: " << e.what() << "\n";
    }

    int wybor = -1;
    while(wybor != 0)
    {
        wyswietlMenu();
        if(!(cin >> wybor))
        {
            cout << "Blad: Wprowadz liczbe!\n";
            wyczyscBufor();
            continue;
        }
        wyczyscBufor();

        try
        {
            if(wybor == 1)
            {
                stacja.wyswietlWszystkie();
            }
            else if(wybor == 2)
            {
                string miasto, data, stanNieba;
                double temperatura, wiatr;
                int wilgotnosc;

                cout << "Miasto: ";
                getline(cin, miasto);
                cout << "Data (RRRR-MM-DD): ";
                getline(cin, data);
                cout << "Temperatura (C):";
                cin >> temperatura;
                cout << "Wilgotnosc (%): ";
                cin >> wilgotnosc;
                wyczyscBufor();
                cout << "Stan Nieba: ";
                getline(cin, stanNieba);
                cout << "Predkosc wiatru (km/h): ";
                cin >> wiatr;

                stacja.dodajProgonze(make_shared<PrognozaDzienna>(miasto, data, temperatura, wilgotnosc, stanNieba, wiatr));
                cout << "Dodano prognoze dzienna. \n";
            }
            else if(wybor == 3)
            {
                string miasto, data, zjawisko;
                double temperatura;
                int wilgotnosc, stopien;

                cout << "Miasto: ";
                getline(cin, miasto);
                cout << "Data (RRRR-MM-DD): ";
                getline(cin, data);
                cout << "Temperatura (C): ";
                cin >> temperatura;
                cout << "Wilgotnosc (%): ";
                cin >> wilgotnosc;
                cout << "Stopien zagrozenia (1-3): ";
                cin >> stopien;
                wyczyscBufor();
                cout << "Zjawisko (np. Grad, Burza): ";
                getline(cin, zjawisko);

                stacja.dodajProgonze(make_shared<AlertBurzowy>(miasto, data, temperatura, wilgotnosc, stopien, zjawisko));
                cout << "Dodano alert pogodowy.\n";
            }
            else if (wybor == 4)
            {
                string miasto;
                cout << "Podaj nazwe miasta: ";
                getline(cin, miasto);
                stacja.szukajPoMiescie(miasto);
            } 
            else if (wybor == 5)
            {
                size_t indeks;
                double nowaTemperatura;
                stacja.wyswietlWszystkie();
                cout << "Podaj indeks prognozy do edycji: "; cin >> indeks;
                cout << "Podaj nowa temperature: "; cin >> nowaTemperatura;
                stacja.aktualizujTemperature(indeks, nowaTemperatura);
                cout << "Zaktualizowano temperature.\n";
                } 
            else if (wybor == 6) {
                size_t indeks;
                stacja.wyswietlWszystkie();
                cout << "Podaj indeks prognozy do usuniecia: "; cin >> indeks;
                stacja.usunPrognoze(indeks);
                cout << "Usunieto prognoze.\n";
            } 
            else if (wybor == 7) {
                stacja.sortujPoTemperaturze();
                cout << "Posortowano prognozy wedlug temperatury.\n";
                stacja.wyswietlWszystkie();
            }
        }
        catch (const WyjatekPogodowy& e)
        {
            cerr << "\n[WYJATEK SYSTEMU POGODOWEGO]: " << e.what() << "\n";
            wyczyscBufor();
        }
        catch (const exception& e)
        {
            cerr << "\n[BLAD KRYTYCZNY]: " << e.what() << "\n";
            wyczyscBufor();
        }
    }
    return 0;
}
