#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <stdlib.h>
#include <time.h>


#define ROZMIAR_STARTOWY 8

using namespace std;


template <typename Typ>
class Wektor {

    Typ *Tablica;  // tablica dynamicznie alokowana
    int ind;       // indeks ostatniego zapisanego elementu tablicy
    int rozmiar;   // aktualny rozmiar zaalokowanej tablicy

    // Funkcja obsługująca realokację pamięci 
    void realocate()
    {
        Typ *Nowa_tablica = new Typ[rozmiar*2];
        for (int i = 0; i < rozmiar; i++)
        {
            Nowa_tablica[i] = Tablica[i];
        }
        rozmiar = rozmiar*2;
        delete[] Tablica;
        Tablica = Nowa_tablica;
    }

public:    

    // Funkcja dodająca element do tablicy, wywołująca realokację
    // pamięci w przypadku braku miejsca 
    void push_back(Typ nowy_element)
    {
        if(ind == rozmiar - 1){
            realocate();
        }
        ind++;
        Tablica[ind] = nowy_element;
    }


    void wymieszaj(int ilosc_przemieszan)
    {
        Typ tmp;
        for (int i = 0; i < ilosc_przemieszan; i++)
        {
            int ind1 = rand() % ind;
            int ind2 = rand() % ind;
            if (ind1 != ind2)
            {
                tmp = Tablica[ind1];
                Tablica[ind1] = Tablica[ind2];
                Tablica[ind2] = tmp;
            }
            
        }
    }


    // przeciążenie operatora wyłuskania umożliwiające dostęp przez 
    // referencję do pola Tablica, które jest prywatne
    Typ & operator[](int indeks) {
        if ((indeks > rozmiar) || (indeks < 0)) {
            cout << "Blad. Niepoprawne odwolanie do elementu wektora\n";
            exit(-1);
        } else return Tablica[indeks];
    }


    // przeciążenie operatora wyłuskania tylko do odczytu
    const Typ & operator[](int indeks) const {
        if ((indeks > rozmiar) || (indeks < 0)) {
            cout << "Blad. Niepoprawne odwolanie do elementu wektora\n";
            exit(-1);
        } else return Tablica[indeks];
    }

    // metoda zwracająca indeks ostatniego elementu
    int Indeks() {
        return ind;
    }

    // konstruktor klasy Wektor
    Wektor(){
        Tablica = new Typ[ROZMIAR_STARTOWY];
        ind = -1;
        rozmiar = ROZMIAR_STARTOWY;
    }


    // destruktor klasy Wektor
    ~Wektor(){
        delete[] Tablica;
    }
    
};

#endif
