#pragma once
#include <iostream>
#include <vector>
#include "Klient.h"
#include "KlientFirmowy.h"
#include "Towar.h"
using namespace std;
/**
* Klasa zawiera w sobie informacje o elementach faktury;
* @param sprzedawca zawiera informacje na temat sprzedawcy;
* @param numerFaktury zawiera informacje na temat numeru faktury;
* @param miejsceWystawienia zawiera informacje na temat miejsca wystawienia faktury;
* @param dataSprzedazy zawiera informacje na temat daty sprzedazy towaru;
* @param klient zawiera informacje na temat klienta;
* @param listaTowarow pozycje towarow na fakturze;
* @param formaPlatnosci zawiera informacje o wybranym sposobie platnosci klienta;
* @param czyOplacone zawiera informacje o tym czy faktura zostala oplacona;
* @param uwagi przechowuje uwagi dla urzedu skarbowego;
**/
class Faktura
{
	KlientFirmowy sprzedawca;
	string numerFaktury;
	string miejsceWystawienia;
	string dataSprzedazy;
	Klient* klient;
	vector<Towar*> listaTowarow;
	string formaPlatnosci;
	bool czyOplacone;
	string uwagi;
public:
	Faktura();
	template <typename T>
	T suma(const T& lhs, const T& rhs);
	KlientFirmowy getSprzedawca();
	void setSprzedawca(KlientFirmowy sprzedawca);
	string getNumerFaktury();
	void setNumerFaktury(string numerFaktury);
	string getMiejsceWystawienia();
	void setMiejsceWystawienia(string miejsceWystawienia);
	string getDataSprzedazy();
	void setDataSprzedazy(string dataSprzedazy);
	Klient* getKlient();
	void setKlient(Klient* klient);
	vector<Towar*> getListaTowarow();
	void dodajTowar(int ilosc, Towar* towar);
	float getKwotaNetto();
	float getKwotaBrutto();
	string getFormaPlatnosci();
	void setFormaPlatnosci(string formaPlatnosci);
	bool getCzyOplacone();
	void setCzyOplacone(bool czyOplacone);
	string getUwagi();
	void setUwagi(string uwagi);
	void wypisz();
	void wypiszNumerFaktury();
};

