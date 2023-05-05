#pragma once
#include "Klient.h"
#include <iostream>
#include <vector>
using namespace std;

/**
* Klasa jednego typu klienta - Klient Firmowy. Podklasa, ktora dziedziczy po klasie Klient.
Zawiera nazwe firmy, NIP oraz informacje czy klient jest zwolniony z podatku VAT.
* @param nazwaFirmy nazwa firmy;
* @param NIP NIP klienta;
* @param zwolnionyZVat zawiera informacje czy klient jest zwolniony z podatku VAT;
**/
class KlientFirmowy :public Klient {
	string nazwaFirmy;
	string NIP;
	bool zwolnionyZVat;
public:
	KlientFirmowy();
	KlientFirmowy(string nazwaFirmy, string nip, string adres, string kodPocztowy, string miejscowosc, string zwolnionyZVat);
	string nazwa();
	void wypisz();
};

