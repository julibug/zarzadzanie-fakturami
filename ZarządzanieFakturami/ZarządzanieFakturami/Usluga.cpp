#include "Usluga.h"

/**
* Konstruktor przyjmujacy dane do utworzenia faktury.
* @param nazwaTowaru nazwa towaru;
* @param cena cena towaru;
* @param vat stawka VAT;
**/
Usluga::Usluga(string nazwaTowaru, float cena, int vat) {
	this->nazwaTowaru = nazwaTowaru;
	this->cena = cena;
	this->vat = vat;
}

/**
* Metoda wyliczajaca i zwracajaca cene netto.
**/
float Usluga::cenaNetto() {
	return this->cena * this->ilosc;
};

/**
* Metoda wyliczajaca i zwracajaca cene brutto.
**/
float Usluga::cenaBrutto() {
	float x = this->vat * 0.01 + 1;
	float a = this->cena * x;
	return a * this->ilosc;
};

/**
* Metoda zwracajaca stawke VAT.
**/
int Usluga::stawkaVAT() {
	return this->vat;
};

/**
* Metoda zwracajaca stawke VAT w stringu.
**/
string Usluga::vatString() {
	return to_string(this->stawkaVAT()) + "%";
}

/**
* Metoda wyliczajaca i zwracajaca kwote VAT.
**/
float Usluga::kwotaVAT() {
	return this->cenaNetto() * (this->stawkaVAT() * 0.01);
}
