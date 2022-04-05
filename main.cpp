#include <fstream>
#include "Sortowanie.hh"


string nazwa_pliku = "tresc_wiadomosci.txt";



void podziel_plik(Wektor<Pakiet> &wektor, ifstream &uchwyt)
{
    Pakiet tmp_pakiet;
    string tmp_ciag_znakow;

    int nr = -1; 
	while(getline(uchwyt, tmp_ciag_znakow, '.')) //dopóki jest co czytać
	{
        nr++;
        tmp_ciag_znakow += ".";
        tmp_pakiet.fragment = tmp_ciag_znakow;
        tmp_pakiet.numer = nr;
        wektor.push_back(tmp_pakiet); // dodanie nowego stringa do wektora   
	}
}


void wczytaj_i_podziel(Wektor<Pakiet> &wektor, bool rekurencja)
{
    if(rekurencja) cin >> nazwa_pliku;
    
    ifstream uchwyt;
    uchwyt.open(nazwa_pliku);
    if (!uchwyt) {
        cout << "Blad! Nie uzyskano dostepu do pliku, badz podano niepoprawna nazwe." << endl;
        cout << "Podaj ponownie nazwe pliku: ";
        wczytaj_i_podziel(wektor, 1);
    } else {
        podziel_plik(wektor, uchwyt);
    }
    uchwyt.close();
}


void wczytaj_i_wyswietl(bool rekurencja)
{
    if(rekurencja) cin >> nazwa_pliku;

    string tmp_ciag_znakow;
    ifstream uchwyt;
    uchwyt.open(nazwa_pliku);
    if (!uchwyt) {
        cout << "Blad! Nie uzyskano dostepu do pliku, badz podano niepoprawna nazwe." << endl;
        cout << "Podaj ponownie nazwe pliku: ";
        wczytaj_i_wyswietl(1);
    } else {
	    while(getline(uchwyt, tmp_ciag_znakow)) //dopóki jest co czytać
	    {
            cout << tmp_ciag_znakow;
        }
    }
    uchwyt.close();
}





int main ()
{
    srand (time(NULL));

    Wektor<Pakiet> wektor_pakietow = Wektor<Pakiet>();
    
    cout << "\nTekst wiadomosci:\n";
    wczytaj_i_wyswietl(0);

    wczytaj_i_podziel(wektor_pakietow, 0);
    const int rozmiar = wektor_pakietow.Indeks() + 1;
    int ilosc_przemieszan = (int)(rozmiar/2);
    wektor_pakietow.wymieszaj(ilosc_przemieszan);
    
    cout << "\n\n\nPakiety odebrane w kolejnosci losowej: \n\n";
    for(int i = 0; i < rozmiar; i++)
    {
        cout << wektor_pakietow[i].numer << endl;
        //cout << "nr. " << wektor_pakietow[i].numer << " " << wektor_pakietow[i].fragment << endl;
    }

    Sortowanie sortowanie;
    sortowanie.merge_sort(wektor_pakietow);

    cout << "\n\nTresc poukladanej wiadomosci: \n";
    for(int i = 0; i < rozmiar; i++)
    {
        cout << wektor_pakietow[i].numer << endl;
        //cout << wektor_pakietow[i].fragment;
    }
    cout << endl;

    return 0;
}