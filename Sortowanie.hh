#ifndef SORTOWANIE_HH
#define SORTOWANIE_HH

#include <string>
#include "Wektor.hh"


// klasa do przechowywania pakietów danych składająca się
// z fragmentu tekstu oraz jego numeru
class Pakiet
{
public:
    int numer;
    string fragment;

    void operator = (Pakiet drugi_pakiet) {
        numer = drugi_pakiet.numer;
        fragment = drugi_pakiet.fragment;
    }
};




class Sortowanie
{
    int Rozmiar_tab;

    // właściwa funkcja sortująca q_sort wywoływana rekurencyjnie
    void q_sort (Wektor<Pakiet> & Tab_wej, int LewyInd, int PrawyInd);
    
public:

    // ostateczna funkcja wywołująca i ustalająca parametry funkcji
    // q_sort, tak żeby można ją było łatwo wywołać w funkcji main
    void quick_sort (Wektor<Pakiet> & Tab_wej) ;

    // konstruktor klasy Sortowanie
    Sortowanie() {}

    // destruktor klasy Sortowanie
    ~Sortowanie() {}
};


#endif
