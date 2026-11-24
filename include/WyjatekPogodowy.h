#ifndef WYJATEK_POGODOWY_H
#define WYJATEK_POGODOWY_H

#include <stdexcept>
#include <string>

using namespace std;

class WyjatekPogodowy : public runtime_error
{
    public:
        explicit WyjatekPogodowy(const string& komunikat);
};

#endif