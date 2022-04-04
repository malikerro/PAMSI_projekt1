#ifndef SORTOWANIE_HH
#define SORTOWANIE_HH

#include "Wektor.hh"


template <typename typ>
class Sortowanie {

    int *Pomocnicza;

    public:

    // konstruktor klasy Sortowanie
    Sortowanie(){
        Pomocnicza = new int[10];
    }

    // destruktor klasy Sortowanie
    ~Sortowanie(){
        delete[] Pomocnicza;
    }

};


#endif

