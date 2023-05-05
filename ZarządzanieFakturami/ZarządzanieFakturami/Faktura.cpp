#include "Faktura.h"

/**
* Konstruktor ustawiajacy wartosci domyslne pola czyOplacone oraz klient.
**/
Faktura::Faktura() {
	this->czyOplacone = false;
	this->klient = NULL; 
}

/**
* Szablon. Metoda zwracajaca sume podanych argumentow.
* @param a skladnik;
* @param b skladnik;
**/
template <typename T>
T Faktura::suma(const T& a, const T& b) {
	return a + b;
}
/**
* Metoda zwracajaca dane sprzedawcy.
**/
KlientFirmowy Faktura::getSprzedawca() {
	return this->sprzedawca;
}

/**
* Metoda przypisujaca nowa wartosc do pola sprzedawca.
* @param sprzedawca obiekt reprezentujacy sprzedawce;
**/
void Faktura::setSprzedawca(KlientFirmowy sprzedawca) {
	this->sprzedawca = sprzedawca;
}

/**
* Metoda zwracajaca numer faktury.
**/
string Faktura::getNumerFaktury() { 
	return this->numerFaktury;
}

/**
* Metoda przypisujaca nowa wartosc do pola numerFaktury;
* @param numerFaktury numer faktury;
**/
void Faktura::setNumerFaktury(string numerFaktury) {
	this->numerFaktury = string(numerFaktury);
};

/**
* Metoda zwracajaca miejsce wystawienia faktury;
**/
string Faktura::getMiejsceWystawienia() {
	return this->miejsceWystawienia;
};

/**
* Metoda przypisujaca nowa wartosc do pola miejsceWystawienia.
* @param miejsceWystawienia miejsce wystawienia faktury;
**/
void Faktura::setMiejsceWystawienia(string miejsceWystawienia) {
	this->miejsceWystawienia = string(miejsceWystawienia);
};

/**
* Metoda zwracajaca date sprzedazy towaru.
**/
string Faktura::getDataSprzedazy() {
	return this->dataSprzedazy;
};

/**
* Metoda przypisujaca nowa wartosc do pola dataSprzedazy.
* @param dataSprzedazy data sprzedazy towaru;
**/
void Faktura::setDataSprzedazy(string dataSprzedazy) {
	this->dataSprzedazy = string(dataSprzedazy);
};

/**
* Metoda zwracajaca klienta.
**/
Klient* Faktura::getKlient() {
	return this->klient;
};

/**
* Metoda przypisujaca nowa wartosc do pola klient;
* @param klient klient;
**/
void Faktura::setKlient(Klient* klient) {
	this->klient = klient;
};

/**
* Metoda zwracajaca liste towarow.
**/
vector<Towar*> Faktura::getListaTowarow() {
	return this->listaTowarow;
};

/**
* Metoda dodajaca towar do listy towarow w zadanej ilosci.
* @param ilosc ilosc; 
* @param towar dodawany towar;
**/
void Faktura::dodajTowar(int ilosc, Towar* towar) {
	towar->setIlosc(ilosc);
	this->listaTowarow.push_back(towar);
};

/**
* Metoda wyliczajaca i zwracajaca kwote netto faktury.
**/
float Faktura::getKwotaNetto() {
	float kwotaNetto = 0.0;
	for (int i = 0; i < listaTowarow.size(); i++) {
		kwotaNetto = suma<float>(kwotaNetto, listaTowarow[i]->cenaNetto()); //sumuje cene netto wszystkich pozycji na fakturze
	}
	return kwotaNetto;
};

/**
* Metoda wyliczajaca i zwracajaca kwote brutto faktury.
**/
float Faktura::getKwotaBrutto() {
	float kwotaBrutto = 0.0;
	for (int i = 0; i < listaTowarow.size(); i++) {
		kwotaBrutto += listaTowarow[i]->cenaBrutto();
	}
	return kwotaBrutto;
};

/**
* Metoda zwraca forme platnosci.
**/
string Faktura::getFormaPlatnosci() {
	return this->formaPlatnosci;
};

/**
* Metoda przypisujaca nowa wartosc do pola formaPlatnosci.
* @param formaPlatnosci forma platnosci;
**/
void Faktura::setFormaPlatnosci(string formaPlatnosci) {
	this->formaPlatnosci = formaPlatnosci;
};

/**
* Metoda zwracajaca wartosc, ktora zawiera informacje czy faktura zostala oplacona.
**/
bool Faktura::getCzyOplacone() {
	return this->czyOplacone;
};

/**
* Metoda przypisujaca nowa wartosc do pola czyOplacone.
* @param czyOplacone;
**/
void Faktura::setCzyOplacone(bool czyOplacone) {
	this->czyOplacone = czyOplacone;
};

/**
*  Metoda zwracajaca uwagi.
**/
string Faktura::getUwagi() {
	return this->uwagi;
};

/**
* Metoda przypisujaca nowa wartosc do pola uwagi.
* @param uwagi uwagi dla urzedu skarbowego;
**/
void Faktura::setUwagi(string uwagi) {
	this->uwagi = uwagi;
};

/**
* Metoda wypisujaca numer faktury.
**/
void Faktura::wypiszNumerFaktury() {
	cout << this->numerFaktury << endl;
}

/**
* Metoda wypisujaca szczegoly faktury.
**/
void Faktura::wypisz() {
	cout << "-----------------------------------------------------------------" << endl;
	cout << "Faktura numer: " << this->getNumerFaktury() << endl;
	cout << "Miejsce wystawienia: " << this->miejsceWystawienia << endl;
	cout << "Data sprzeda¿y: " << this->dataSprzedazy << endl << endl;
	cout << "Sprzedawca: " << endl;
	this->getSprzedawca().wypisz();
	cout << endl;
	cout << "Kupujacy: " << endl;
	this->klient->wypisz();
	cout << endl;
	cout << "Pozycje: " << endl;
	for (int i = 0; i < this->getListaTowarow().size(); i++) {
		this->getListaTowarow()[i]->wypisz();
	}
	cout << "-----------------------------------------------------------------" << endl;
}
