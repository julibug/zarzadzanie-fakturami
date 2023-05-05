#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdexcept>
#include "Klient.h"
#include "KlientIndywidualny.h"
#include "KlientFirmowy.h"
#include "Towar.h"
#include "Artykul.h"
#include "Usluga.h"
#include "Zestaw.h"
using namespace std;

/**
Klasa zajmuje siê wczytywaniem klientow, towarow i danych sprzedawcy.
**/
class WczytywaczDanych {
public:
	vector<Klient*> wczytajKlientow(string sciezka);
	vector<Towar*> wczytajTowary(string sciezka);
	KlientFirmowy wczytajSprzedawce(string sciezka);
private:
	const char SEPARATOR = ';';
	const int INDEX_TYP = 0;
	const int INDEX_NAZWA = 1;
	const int INDEX_JEDNOSTKA = 2;
	const int INDEX_CENA = 3;
	const int INDEX_VAT = 4;
	const int INDEX_IMIE = 1;
	const int INDEX_NAZWISKO = 2;
	const int INDEX_NAZWA_FIRMY = 3;
	const int INDEX_NIP = 4;
	const int INDEX_ADRES = 5;
	const int INDEX_KOD_POCZTOWY = 6;
	const int INDEX_MIEJSCOWOSC = 7;
	const int INDEX_ZWOLNIENIE_VAT = 8;

	string readFileIntoString(const string& sciezka);
};

