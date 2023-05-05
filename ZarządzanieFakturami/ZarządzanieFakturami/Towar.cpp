#include "Towar.h"

/**
* Metoda zwracajaca nazwe towaru.
**/
string Towar::nazwa() {
	return nazwaTowaru;
}

/**
* Metoda przypisujaca nowa wartosc do pola ilosc.
**/
void Towar::setIlosc(int ilosc) {
	this->ilosc = ilosc;
}

/**
* Metoda zwracajaca ilosc towaru.
**/
int Towar::getIlosc() {
	return this->ilosc;
}

/**
* Metoda wypisujaca nazwe towaru, ilosc, jednostke, cene netto, cene brutto, stawke VAT oraz wartosc VAT.
**/
void Towar::wypisz() {
	cout << this->nazwa() << " "
		<< this->getIlosc() << " " << this->jednostka
		<< " cena netto: " << this->cenaNetto()
		<< " cena brutto: " << this->cenaBrutto()
		<< " stawka VAT: " << this->vatString()
		<< " wartosc VAT:" << this->kwotaVAT()
		<< endl;
}
