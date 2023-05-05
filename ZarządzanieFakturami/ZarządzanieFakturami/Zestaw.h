#pragma once
#include <vector>
#include "Towar.h"
#include "Artykul.h"
using namespace std;

/**
* Klasa jednego typu towaru - Zestaw. Podklasa, ktora dziedziczy po klasie Towar. Zawiera w sobie wektor towarow.
* @param listaTowarow baza towarow;
**/
class Zestaw : public Towar{
	vector<Towar*> listaTowarow;
public:
	Zestaw();
	Zestaw(string nazwaTowaru);
	~Zestaw();
	void dodajTowar(Artykul* artykul);
	float cenaNetto();
	float cenaBrutto();
	float kwotaVAT();
	int stawkaVAT();
	string vatString();
};

