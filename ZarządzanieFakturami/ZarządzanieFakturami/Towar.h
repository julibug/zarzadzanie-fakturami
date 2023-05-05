#pragma once
#include <iostream>
using namespace std;

/**
* Klasa zawierajaca informacje na temat nazwy towaru, jednostki, ilosci oraz wirtualne metody.
* @param nazwaTowaru nazwa towaru;
* @param jednostka jednostka;
* @param ilosc ilosc towaru z domyslna wartoscia 1;
**/
class Towar {
protected:
	string nazwaTowaru;
	string jednostka;
	int ilosc = 1;
public:
	virtual float cenaNetto() = 0;
	virtual float cenaBrutto() = 0;
	virtual int stawkaVAT() = 0;
	virtual float kwotaVAT() = 0;
	virtual string vatString() = 0;
	void wypisz();
	string nazwa();
	void setIlosc(int ilosc);
	int getIlosc();
};

