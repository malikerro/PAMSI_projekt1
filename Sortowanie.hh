#ifndef SORTOWANIE_HH
#define SORTOWANIE_HH

#include <string>
#include "Wektor.hh"


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
    Wektor<Pakiet> Pomocnicza;
    int Rozmiar_tab;


    //////////////////////////////////////////////////////////////////////////////
    // funkcje używane w algorytmie merge sort:


    // funkcja "merge" scalająca posortowane podtablice
    void merge (Wektor<Pakiet> & Tab_wej, int LewyInd, int SrodInd, int PrawyInd)
    {
        // przepisanie wartości tablicy wejściowej do tablicy pomocniczej
        for (int i = LewyInd; i <= PrawyInd; i++) {
            Pomocnicza[i] = Tab_wej[i];
        }

        // LewyElem i PrawyElem - indeksy porównywanych wyrazów
        int LewyElem = LewyInd;
        int PrawyElem = SrodInd + 1;

        for(int biezacy = LewyInd; biezacy <= PrawyInd; biezacy++) {
            if(LewyElem <= SrodInd) { // i = LewyElem, j = PrawyElem, k = biezacy
                if(PrawyElem <= PrawyInd) {
                    if(Pomocnicza[PrawyElem].numer < Pomocnicza[LewyElem].numer) {
                        Tab_wej[biezacy] = Pomocnicza[PrawyElem++];
                    } else { Tab_wej[biezacy] = Pomocnicza[LewyElem++]; }
                } else { Tab_wej[biezacy] = Pomocnicza[LewyElem++]; }
            } else { Tab_wej[biezacy] = Pomocnicza[PrawyElem++]; }
        }
    }


    // funkcja dokonująca podziału tablicy na podtablice i właściwego sortowania
    // przez scalanie wywoływana rekurencyjnie
    void m_sort (Wektor<Pakiet> & Tab_wej, int LewyInd, int PrawyInd)
    {    
	    if(PrawyInd <= LewyInd) return; // sytuacja gdy został już tylko jeden element 
	
	    int SrodInd = (PrawyInd + LewyInd)/2;  // indeks elementu środkowego, zostanie zaokrąglony w dół
	
	    //  podział tablicy na dwie części
	    m_sort(Tab_wej, LewyInd, SrodInd); 
	    m_sort(Tab_wej, SrodInd + 1, PrawyInd);
	
        //  scalanie posortowanych tablic
	    merge(Tab_wej, LewyInd, SrodInd, PrawyInd);
    }

//////////////////////////////////////////////////////////////////////////////


public:

    // ostateczna funkcja wywołująca i ustalająca parametry
    // funkcji m_sort, tak żeby można ją było łatwo wywołać w mainie
    void merge_sort (Wektor<Pakiet> & Tab_wej)
    {
        Rozmiar_tab = Tab_wej.Indeks() + 1;
        // zaalokowanie przestrzeni sla tablicy pomocniczej
        for (int i = 0; i < Rozmiar_tab; i++) {
            Pomocnicza.push_back(Tab_wej[i]);
        }

        // wywołanie funkcji m_sort przy użyciu parametrów podanych funkcji merge_sort
        // potrzebne do wyznaczenia parametrów: "LewyInd" i "PrawyInd" w pierwszym
        // wywołaniu funkcji
        m_sort(Tab_wej, 0, Rozmiar_tab - 1);
    }

    // konstruktor klasy Sortowanie
    Sortowanie() {}

    // destruktor klasy Sortowanie
    ~Sortowanie() {}
};


#endif
