#pragma once
#include "Klient.h"
#include <iostream>
#include <vector>

using namespace std;

/**
* Klasa jednego typu klienta - Klient Indywidualny. Podklasa, ktora dziedziczy po klasie Klient.
Zawiera informacje na temat imienia oraz nazwiska klienta.
@param imie imie klienta;
@param nazwisko nazwisko klienta;
**/
class KlientIndywidualny : public Klient {
	string imie;
	string nazwisko;
public:
	KlientIndywidualny(string imie, string nazwisko, string adres, string kodPocztowy, string miejscowosc);
	string nazwa();
	void wypisz();
};

