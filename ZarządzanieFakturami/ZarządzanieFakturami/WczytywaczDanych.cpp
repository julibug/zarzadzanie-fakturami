#include "WczytywaczDanych.h"

using namespace std;

/**
* Metoda wczytujaca klientow z pliku.
* @param sciezka sciezka do pliku;
**/
vector<Klient*> WczytywaczDanych::wczytajKlientow(string sciezka) {
    istringstream sstream(readFileIntoString(sciezka));
    vector<string> items;
    string record;
    vector<Klient*> klienci;
    while (getline(sstream, record)) {
        istringstream line(record);
        while (getline(line, record, SEPARATOR)) {
            items.push_back(record);
        }
        string typKlienta = items[INDEX_TYP];
        if (typKlienta == "0") {
            klienci.push_back(new KlientIndywidualny(items[INDEX_IMIE], items[INDEX_NAZWISKO], items[INDEX_ADRES], items[INDEX_KOD_POCZTOWY], items[INDEX_MIEJSCOWOSC]));
        }
        else if (typKlienta == "1") {
            klienci.push_back(new KlientFirmowy(items[INDEX_NAZWA_FIRMY], items[INDEX_NIP], items[INDEX_ADRES], items[INDEX_KOD_POCZTOWY], items[INDEX_MIEJSCOWOSC], items[INDEX_ZWOLNIENIE_VAT]));
        }
        else {
            throw invalid_argument("Niepoprawny typ klienta: " + typKlienta);
        }
        items.clear();
    }
    return klienci;
}

/**
* Metoda wczytujaca zawartosc pliku do stringa.
* @param sciezka sciezka do pliku;
**/
string WczytywaczDanych::readFileIntoString(const string& sciezka) {
    auto ss = ostringstream{};
    ifstream input_file(sciezka);
    if (!input_file.is_open()) {
        throw runtime_error("Blad podczas wczytywania tresci pliku: " + sciezka);
    }
    ss << input_file.rdbuf();
    return ss.str();
}

/**
* Metoda wczytujaca towary z pliku.
* @param sciezka sciezka do pliku;
**/
vector<Towar*> WczytywaczDanych::wczytajTowary(string sciezka) {
    istringstream sstream(readFileIntoString(sciezka));
    vector<string> items;
    string record;
    vector<Towar*> towary;
    Zestaw* zestaw = nullptr;
    while (getline(sstream, record)) {
        istringstream line(record);
        while (getline(line, record, SEPARATOR)) {
            items.push_back(record);
        }
        int typTowaru = stoi(items[INDEX_TYP]);
        switch (typTowaru) {
        case 0:
            if (zestaw != nullptr) {
                towary.push_back(zestaw);
                zestaw = nullptr;
            }
            towary.push_back(new Artykul(
                items[INDEX_NAZWA], items[INDEX_JEDNOSTKA], stof(items[INDEX_CENA]), stoi(items[INDEX_VAT])));
            break;
        case 1:
            if (zestaw != nullptr) {
                towary.push_back(zestaw);
                zestaw = nullptr;
            }
            towary.push_back(new Usluga(items[INDEX_NAZWA], stof(items[INDEX_CENA]), stoi(items[INDEX_VAT])));
            break;
        case 2:
            if (zestaw != nullptr) {
                towary.push_back(zestaw);
                zestaw = nullptr;
            }
            zestaw = new Zestaw(items[1]);
            break;
        case 3:
            zestaw->dodajTowar(
                new Artykul(items[INDEX_NAZWA], items[INDEX_JEDNOSTKA], stof(items[INDEX_CENA]), stoi(items[INDEX_VAT])));
            break;
        default:
            throw invalid_argument("Niepoprawny typ towaru: " + typTowaru);
        }
        items.clear();
    }
    if (zestaw != nullptr) {
        towary.push_back(zestaw);
    }
    return towary;
}

/**
* Metoda wczytujaca dane sprzedawcy z pliku.
* @param sciezka sciezka do pliku;
**/
KlientFirmowy WczytywaczDanych::wczytajSprzedawce(string sciezka) {
    istringstream sstream(readFileIntoString(sciezka));
    vector<string> items;
    string record;
    vector<Klient*> klienci;
    getline(sstream, record);
    istringstream line(record);
    while (getline(line, record, SEPARATOR)) {
        items.push_back(record);
    }
    return KlientFirmowy(items[INDEX_NAZWA_FIRMY], items[INDEX_NIP], items[INDEX_ADRES], items[INDEX_KOD_POCZTOWY], items[INDEX_MIEJSCOWOSC], items[INDEX_ZWOLNIENIE_VAT]);
}