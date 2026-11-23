#ifndef ALERT_BURZOWY_H
#define ALERT_BURZOWY

#include "PrognozaPogody.h"

class AlertBurzowy : public PrognozaPogody{
    private:
        int stopienZagrozenia;
        string zjawisko;

    public:
        AlertBurzowy();
        AlertBurzowy(const string& miasto, const string& data, double temperatura, int wilgotnosc, int stopienZagrozeina, const string& zjawisko);

        int pobierzStopienZagrozenia() const;
        void ustawStopienZagrozenia(int stopien);

        void wyswietlSzczegoly() const override;
        string pobierzTypPrognozy() const override;
};

#endif
