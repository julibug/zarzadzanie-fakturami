#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "Towar.h"
using namespace std;

/**
* Klasa jednego typu towaru - Usluga. Podklasa, ktora dziedziczy po klasie Towar.
Zawiera informacje o cenie towaru i stawce VAT.
* @param cena cena towaru;
* @param vat stawka VAT;
**/
class Usluga : public Towar {
	float cena;
	int vat;
public:
	Usluga(string nazwaTowaru, float cena, int vat);
	float cenaNetto();
	float cenaBrutto();
	int stawkaVAT();
	float kwotaVAT();
	string vatString();
};

