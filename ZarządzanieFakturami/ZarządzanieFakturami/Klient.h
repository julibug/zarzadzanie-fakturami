#include <iostream>
#pragma once
using namespace std;
/**
* Klasa zawiera informacje dotyczace klienta oraz wirtualna metode nazwa i wypisz;
* @param adres adres klienta;
* @param kodPocztowy kod pocztowy klienta;
* @param miejscowosc miejscowosc klienta;
**/
class Klient {
protected:
	string adres;
	string kodPocztowy;
	string miejscowosc;
public: 
	virtual string nazwa() = 0;
	virtual void wypisz() = 0;
};

