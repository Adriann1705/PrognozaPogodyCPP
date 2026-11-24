# System Prognozy Pogody (C++ OOP)

Aplikacja konsolowa służąca do zarządzania bazą prognoz pogody oraz ostrzeżeń meteorologicznych w ramach stacji pogodowej.

---

## Funkcjonalności programu
- Dodawanie standardowych prognoz dziennych (`PrognozaDzienna`) oraz ostrzeżeń meteorologicznych (`AlertBurzowy`).
- Wyświetlanie wszystkich zapisanych prognoz z wykorzystaniem polimorfizmu.
- Wyszukiwanie prognoz dla wybranego miasta.
- Modyfikacja temperatury dla wybranej prognozy (z walidacją poprawności danych).
- Usuwanie prognoz z listy.
- Sortowanie prognoz rosnąco według temperatury.
- Walidacja danych wejściowych oraz obsługa błędów za pomocą mechanizmu wyjątków.

---

## Architektura i zastosowane mechanizmy

Projekt został podzielony na pliki nagłówkowe (`include/*.h`) oraz implementacyjne (`src/*.cpp`) i realizuje następujące paradygmaty programowania obiektowego:

1. **Enkapsulacja i walidacja danych:**
   - Atrybuty klas są chronione modyfikatorami `private` oraz `protected`.
   - Dostęp i modyfikacja pól odbywają się wyłącznie poprzez gettery (oznaczone jako `const`) oraz settery weryfikujące poprawność danych.
2. **Dziedziczenie i Polimorfizm:**
   - Abstrakcyjna klasa bazowa `PrognozaPogody` definiuje wspólne atrybuty oraz metody czysto wirtualne (`wyswietlSzczegoly()`, `pobierzTypPrognozy()`).
   - Klasy pochodne `PrognozaDzienna` i `AlertBurzowy` rozszerzają klasę bazową o specyficzne pola i przesłaniają metody wirtualne (`override`).
   - Klasa `StacjaPogodowa` przechowuje kolekcję inteligentnych wskaźników polimorficznych (`std::vector<std::shared_ptr<PrognozaPogody>>`).
3. **Przeciążanie operatorów:**
   - `operator==` - sprawdza unikalność prognozy dla pary *(miasto, data)* i blokuje dodawanie duplikatów.
   - `operator<` - porównuje prognozy na podstawie temperatury, umożliwiając sortowanie przy użyciu `std::sort`.
   - `operator<<` - zaprzyjaźniony operator strumieniowy formatujący podstawowe informacje o prognozie na wyjściu `std::ostream`.
4. **Obsługa wyjątków:**
   - Własna klasa `WyjatekPogodowy` dziedzicząca po `std::runtime_error` przechwytuje nieprawidłowe dane (np. temperatura poza zakresem od -273.15°C do 70.0°C, wilgotność spoza przedziału 0–100%, ujemna prędkość wiatru, nieprawidłowy stopień zagrożenia lub błędny indeks).

---

## Schemat klas UML

```mermaid
classDiagram
    class WyjatekPogodowy {
        +WyjatekPogodowy(komunikat: string)
    }

    class PrognozaPogody {
        <<abstract>>
        #miasto: string
        #data: string
        #temperatura: double
        #wilgotnosc: int
        +PrognozaPogody()
        +PrognozaPogody(miasto: string, data: string, temperatura: double, wilgotnosc: int)
        +~PrognozaPogody()
        +pobierzMiasto() string
        +pobierzDate() string
        +pobierzTemperature() double
        +pobierzWilgotnosc() int
        +ustawMiasto(noweMiasto: string) void
        +ustawDate(nowaData: string) void
        +ustawTemperature(nowaTemperatura: double) void
        +ustawWilgotnosc(nowaWilgotnosc: int) void
        +wyswietlSzczegoly()* void
        +pobierzTypPrognozy()* string
        +operator==(inna: PrognozaPogody) bool
        +operator<(inna: PrognozaPogody) bool
    }

    class PrognozaDzienna {
        -stanNieba: string
        -predkoscWiatru: double
        +PrognozaDzienna()
        +PrognozaDzienna(miasto: string, data: string, temperatura: double, wilgotnosc: int, stanNieba: string, predkoscWiatru: double)
        +pobierzStanNieba() string
        +pobierzPredkoscWiatru() double
        +ustawPredkoscWiatru(predkosc: double) void
        +wyswietlSzczegoly() void
        +pobierzTypPrognozy() string
    }

    class AlertBurzowy {
        -stopienZagrozenia: int
        -zjawisko: string
        +AlertBurzowy()
        +AlertBurzowy(miasto: string, data: string, temperatura: double, wilgotnosc: int, stopienZagrozenia: int, zjawisko: string)
        +pobierzStopienZagrozenia() int
        +ustawStopienZagrozenia(stopien: int) void
        +wyswietlSzczegoly() void
        +pobierzTypPrognozy() string
    }

    class StacjaPogodowa {
        -nazwaStacji: string
        -prognozy: vector~shared_ptr~PrognozaPogody~~
        +StacjaPogodowa(nazwa: string)
        +dodajPrognoze(prognoza: shared_ptr~PrognozaPogody~) void
        +usunPrognoze(indeks: size_t) void
        +aktualizujTemperature(indeks: size_t, nowaTemperatura: double) void
        +szukajPoMiescie(miasto: string) void
        +sortujPoTemperaturze() void
        +wyswietlWszystkie() void
        +pobierzLiczbePrognoz() size_t
    }

    PrognozaPogody <|-- PrognozaDzienna : dziedziczenie
    PrognozaPogody <|-- AlertBurzowy : dziedziczenie
    StacjaPogodowa *-- PrognozaPogody : kompozycja
    PrognozaPogody ..> WyjatekPogodowy : rzuca wyjatek
    PrognozaDzienna ..> WyjatekPogodowy : rzuca wyjatek
    AlertBurzowy ..> WyjatekPogodowy : rzuca wyjatek
    StacjaPogodowa ..> WyjatekPogodowy : rzuca wyjatek
