#include "Zestaw.h"

/**
* Konstruktor bez parametrow.
**/
Zestaw::Zestaw() {}

/**
* Destruktor zwalniajacy pamiec.
**/
Zestaw::~Zestaw() {
	for (int i = 0; i < listaTowarow.size(); i++) {
		delete listaTowarow[i];
	}
}

/**
* Konstruktor ustawiajacy nazwe towaru.
* @param nazwaTowaru nazwa towaru;
**/
Zestaw::Zestaw(string nazwaTowaru) {
	this->nazwaTowaru = nazwaTowaru;
}

/**
* Metoda dodajaca artykul do listy towarow.
* @param artykul typ towaru;
**/
void Zestaw::dodajTowar(Artykul* artykul) { 
	listaTowarow.push_back(artykul);
}

/**
* Metoda wyliczajaca i zwracajaca kwote netto.
**/
float Zestaw::cenaNetto() {
	float kwota = 0.0;
	for (int i = 0; i < this->listaTowarow.size(); i++) {
		kwota = kwota + listaTowarow[i]->cenaNetto();
	}
	return kwota;
};

/**
* Metoda wyliczajaca i zwracajaca kwote brutto.
**/
float Zestaw::cenaBrutto() {
	float kwota = 0.0;
	for (int i = 0; i < this->listaTowarow.size(); i++) {
		kwota = kwota + listaTowarow[i]->cenaBrutto();
	}
	return kwota;
};

/**
* Metoda zwracajaca pusta stawke VAT.
**/
int Zestaw::stawkaVAT() {
	return 0;
}

/**
* Metoda zwracajaca pusty VAT;
**/
string Zestaw::vatString() {
	return "";
}

/**
* Metoda wyliczajaca i zwracajaca kwote VAT.
**/
float Zestaw::kwotaVAT() {
	float kwota = 0.0;
	for (int i = 0; i < this->listaTowarow.size(); i++) {
		Towar* t = this->listaTowarow[i];
		kwota = kwota + (t->cenaNetto() * (0.01 * t->stawkaVAT()));
	}
	return kwota;
}

