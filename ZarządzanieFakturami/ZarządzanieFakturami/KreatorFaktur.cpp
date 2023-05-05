#include "KreatorFaktur.h"

/**
* Konstruktor.
* @param sprzedawca sprzedawca;
* @param k klienci;
* @param t towary;
**/
KreatorFaktur::KreatorFaktur(KlientFirmowy sprzedawca, vector<Klient*> k, vector<Towar*> t) {
	this->sprzedawca = sprzedawca;
	this->klienci = k;
	this->towary = t;
};

/**
* Metoda czyszczaca pamiec pol.
**/
void KreatorFaktur::wyczyscPamiec() {
	zwolnijPamiec<Faktura>(faktury);
	zwolnijPamiec<Towar>(towary);
	zwolnijPamiec<Klient>(klienci);
}

/**
* Szablon. Metoda zwalniajaca pamiec wektora wskaznikow.
* @param wskazniki wskazniki;
**/
template <class T>
void KreatorFaktur::zwolnijPamiec(vector<T*> wskazniki) {
	for (int i = 0; i < wskazniki.size(); i++) {
		delete wskazniki[i];
	}
}

/**
* Metoda wypisujaca liste klientow.
**/
void KreatorFaktur::wypisywanieKlientow() {
	cout << "Lista klientow:" << endl;
	for (int i = 0; i < klienci.size(); i++) {
		cout << i << " " << klienci[i]->nazwa() << endl;
	}
};

/**
* Metoda wypisujaca liste towarow.
**/
void KreatorFaktur::wypisywanieTowarow() {
	cout << "Lista towarow:" << endl;
	for (int i = 0; i < towary.size(); i++) {
		cout << i << " " << towary[i]->nazwa() << endl;
	}
};

/**
* Metoda tworzaca i dodajaca fakture.
**/
void KreatorFaktur::dodajFakture() {
	Faktura* faktura = new Faktura();
	faktura->setSprzedawca(this->sprzedawca);
	cout << "Tworzenie nowej faktury" << endl;
	cout << "Wpisz numer faktury: ";
	string numerFaktury;
	cin >> numerFaktury;
	faktura->setNumerFaktury(numerFaktury);
	cout << "Wpisz miejsce wystawienia faktury: ";
	string miejsceWystawienia;
	cin >> miejsceWystawienia;
	faktura->setMiejsceWystawienia(miejsceWystawienia);
	cout << "Wpisz date sprzedazy towaru: ";
	string dataSprzedazy;
	cin >> dataSprzedazy;
	faktura->setDataSprzedazy(dataSprzedazy);
	cout << "Wybierz klienta: " << endl;
	wypisywanieKlientow();
	int indexKlienta;
	cin >> indexKlienta;
	faktura->setKlient(klienci[indexKlienta]);
	bool zmienna;
	do {
		cout << "Wybierz towar: " << endl;
		wypisywanieTowarow();
		int indexTowaru;
		cin >> indexTowaru;
		cout << "Podaj ilosc:" << endl;
		int ilosc;
		cin >> ilosc;
		faktura->dodajTowar(ilosc, towary[indexTowaru]);
		cout << "Dodac kolejny towar ? 0 - NIE, 1 - TAK" << endl;
		int odp;
	    cin >> odp;
		if (odp == 0) {
			zmienna = false;
		}
		else if (odp == 1) {
				zmienna = true;
		}
		else {
			throw invalid_argument("Niepoprawne dane");
		};
	} while (zmienna == true);
	string formaPlatnosci;
	cout << "Wybierz forme platnosci: " << endl;
	cout << "0 - gotowka" << endl;
	cout << "1 - karta platnicza" << endl;
	cout << "2 - przelew" << endl;
	int platnosc;
	cin >> platnosc;
	if (platnosc == 0) {
		formaPlatnosci = "Gotowka";
	}
	else if (platnosc == 1) {
		formaPlatnosci = "Karta platnicza";
	}
	else if (platnosc == 2) {
		formaPlatnosci = "Przelew";
	}
	else {
		throw invalid_argument("Niepoprawne dane");
	}
	faktura->setFormaPlatnosci(formaPlatnosci);
	cout << "Czy faktura jest oplacona? 0 - NIE, 1 - TAK" << endl;
	bool czyOplacone;
	int odp1;
	cin >> odp1;
	if (odp1 == 0) {
		czyOplacone = false;
	}
	else if (odp1 == 1) {
		czyOplacone = true;
	}
	else {
		throw invalid_argument("Niepoprawne dane");
	}
	cout << "Uwagi dla urzedu skarbowego: ";
	string uwagi;
	cin >> uwagi;
	faktura->setUwagi(uwagi);
	faktury.push_back(faktura);
	faktura->wypisz();
}

/**
* Metoda wypisujaca liste faktur.
**/
void KreatorFaktur::wypiszListeFaktur() {
	for (int i = 0; i < this->faktury.size(); i++) {
		cout << i << ": ";
		faktury[i]->wypiszNumerFaktury();
	}
}

/**
* Metoda wypisujaca fakture.
**/
void KreatorFaktur::wypiszFakture(int i) {
	if (i < faktury.size() && i >= 0) {
		faktury[i]->wypisz();
	}
}
/**
* Metoda usuwajaca fakture.
**/
void KreatorFaktur::usunFakture(int i) {
	if (i < faktury.size() && i >= 0) {
		Faktura* faktura = faktury[i];
		faktury.erase(faktury.begin() + i);
		delete faktura;
	}
}