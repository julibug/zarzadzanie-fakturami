#include "Klient.h"
#include "KlientIndywidualny.h"

/**
* Konstruktor przyjmujacy dane klienta indywidualnego.
* @param imie imie klienta indywidualnego;
* @param nazwisko nazwisko klienta indywidualnego;
* @param adres adres klienta indywidualnego;
* @param kodPocztowy kod pocztowy klienta indywidualnego;
* @param miejscowosc miejscowosc klienta indywidualnego;
**/
KlientIndywidualny::KlientIndywidualny(string imie, string nazwisko, string adres, string kodPocztowy, string miejscowosc) {
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->adres = adres;
	this->kodPocztowy = kodPocztowy;
	this->miejscowosc = miejscowosc;
}

/**
* Metoda zwracajaca imie i nazwisko klienta indywidualnego.
**/
string KlientIndywidualny::nazwa() {
	return imie + " " + nazwisko;
}

/**
* Metoda wypisujaca nazwe oraz adres klienta indywidualnego.
**/
void KlientIndywidualny::wypisz() {
	cout << nazwa() << endl;
	cout << this->adres << endl;
	cout << this->kodPocztowy << " " << this->miejscowosc << endl;
}