#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "Towar.h"
using namespace std;

/**
* Klasa jednego typu towaru - Artykul. Podklasa, ktora dziedziczy po klasie Towar.
Zawiera informacje o cenie towaru i stawce VAT.
* @param cena cena towaru;
* @param vat stawka VAT;
**/
class Artykul : public Towar {
	float cena;
	int vat;
public:
	Artykul(string nazwaTowaru, string jednostka, float cena, int vat);
	float cenaNetto();
	float cenaBrutto();
	int stawkaVAT();
	float kwotaVAT();
	string vatString();
};

