#pragma once
#include <iostream>
#include <vector>
#include "Towar.h"
#include "Klient.h"
#include "Faktura.h"
using namespace std;

/**
* Klasa zajmuje siê tworzeniem i przechowywaniem utworzonych faktur, a takze wypisywaniem ich i usuwaniem.
* @param sprzedawca dane sprzedajacego;
* @param klienci baza klientow;
* @param towary baza towarow;
* @param faktury utworzone faktury;
**/
class KreatorFaktur {
	KlientFirmowy sprzedawca;
	vector<Klient*> klienci;
	vector<Towar*> towary;
	vector<Faktura*> faktury;
public:
	KreatorFaktur(KlientFirmowy sprzedawca, vector<Klient*> k, vector<Towar*> t);
	void wypisywanieKlientow();
	void wypisywanieTowarow();
	void dodajFakture();
	void wypiszListeFaktur();
	void wypiszFakture(int i);
	void usunFakture(int i);
	void wyczyscPamiec();
private:
	template <class T>
	void zwolnijPamiec(vector<T*> wskazniki);
};

