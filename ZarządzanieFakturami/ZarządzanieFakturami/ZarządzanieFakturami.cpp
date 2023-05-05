#include <iostream>
#include "Klient.h"
#include "WczytywaczDanych.h"
#include "KreatorFaktur.h"
using namespace std;

int main() {
    WczytywaczDanych wczytywaczDanych;
    vector<Klient*> klienci = wczytywaczDanych.wczytajKlientow("klienci.csv");
    vector<Towar*> towary = wczytywaczDanych.wczytajTowary("towary.csv");
    KlientFirmowy sprzedawca = wczytywaczDanych.wczytajSprzedawce("sprzedawca.csv");
    KreatorFaktur kreatorFaktur(sprzedawca, klienci, towary);
    int odp;
    do {
        cout << "Menu:" << endl;
        cout << "1 - Dodaj fakture" << endl;
        cout << "2 - Lista faktur" << endl;
        cout << "3 - Wypisz fakture" << endl;
        cout << "4 - Usun fakture" << endl;
        cout << "0 - Wyjdz" << endl;
        cin >> odp;
        switch (odp) {
        case 1:
            kreatorFaktur.dodajFakture();
            break;
        case 2:
            kreatorFaktur.wypiszListeFaktur();
            break;
        case 3:
            int indexFaktury;
            cout << "Podaj pozycje fakury: ";
            cin >> indexFaktury;
            kreatorFaktur.wypiszFakture(indexFaktury);
            break;
        case 4:
            int pozycjaFaktury;
            cout << "Podaj pozycje fakury: ";
            cin >> pozycjaFaktury;
            kreatorFaktur.usunFakture(pozycjaFaktury);
            break;
        case 0:
            break;
        default:
            throw invalid_argument("Niepoprawny numer");
        }
    } while (odp != 0);
    kreatorFaktur.wyczyscPamiec();
}