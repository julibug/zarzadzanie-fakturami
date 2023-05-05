#include "KlientFirmowy.h"

/**
* Konstruktor ustawiajacy wartosci domyslne pola zwolnionyZVat.
**/
KlientFirmowy::KlientFirmowy() {
	this->zwolnionyZVat = false;
}

/**
* Konstruktor przyjmujacy dane klienta firmowego.
* @param nazwaFirmy nazwa firmy;
* @param nip NIP klienta firmowego;
* @param adres adres klienta firmowego;
* @param kodPocztowy kod pocztowy klienta firmowego;
* @param miejscowosc miejscowosc klienta firmowego;
* @param zwolnionyZVat zawiera informacje czy klient firmowy jest zwolniony z podatku VAT;
**/
KlientFirmowy::KlientFirmowy(string nazwaFirmy, string nip, string adres, string kodPocztowy, string miejscowosc, string zwolnionyZVat) {
	this->nazwaFirmy = nazwaFirmy;
	this->NIP = nip;
	this->adres = adres;
	this->kodPocztowy = kodPocztowy;
	this->miejscowosc = miejscowosc;
	if (zwolnionyZVat == "0") {
		this->zwolnionyZVat = false;
	}
	else if (zwolnionyZVat == "1") {
		this->zwolnionyZVat = true;
	}
	else {
		throw invalid_argument("Blad");
	}
}

/**
* Metoda zwracajaca nazwe firmy.
**/
string KlientFirmowy::nazwa() {
	return nazwaFirmy;
}

/**
* Metoda wypisujaca dane klienta firmowego.
**/
void KlientFirmowy::wypisz() {
	cout << nazwa() << endl;
	cout << "NIP: " << this->NIP << endl;
	cout << this->adres << endl;
	cout << this->kodPocztowy << " " << this->miejscowosc << endl;
}