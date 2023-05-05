#include "Artykul.h"

/**
* Konstruktor przyjmuj¹cy dane do utworzenia faktury.
* @param nazwaTowaru nazwa towaru;
* @param jednostka jednostka;
* @param cena cena towaru;
* @param vat stawka VAT;
**/
Artykul::Artykul(string nazwaTowaru, string jednostka, float cena, int vat) {
	this->nazwaTowaru = nazwaTowaru;
	this->jednostka = jednostka;
	this->cena = cena;
	this->vat = vat;
};

/**
* Metoda wyliczajaca i zwracajaca cene netto.
**/
float Artykul::cenaNetto() {
	return this->cena * this->ilosc;
};

/**
* Metoda wyliczajaca i zwracajaca cene brutto.
**/
float Artykul::cenaBrutto() {
	float x = this->vat * 0.01 + 1;
	float a = this->cena * x;
	return a * this->ilosc;
};

/**
* Metoda zwracajaca stawke VAT.
**/
int Artykul::stawkaVAT() {
	return this->vat;
};

/**
* Metoda zwracajaca stawke VAT w stringu.
**/
string Artykul::vatString() {
	return to_string(this->stawkaVAT()) + "%";
}

/**
* Metoda wyliczajaca i zwracajaca kwote VAT.
**/
float Artykul::kwotaVAT() {
	return this->cenaNetto() * (this->stawkaVAT() * 0.01);
}
