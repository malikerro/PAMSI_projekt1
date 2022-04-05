#include "Sortowanie.hh"


void Sortowanie::q_sort (Wektor<Pakiet> & Tab_wej, int LewyInd, int PrawyInd)
    {
        Pakiet pivot;
        int lewy, prawy, PivotInd;
        int n = PrawyInd - LewyInd + 1;

        if(LewyInd < PrawyInd) {
            // indeks pivota jest losowany z zakresu od LewyInd do n + LewyInd,
            // czyli od pierwszego, do ostatniego indeksu sortowanej tablicy
            PivotInd = rand() % n + LewyInd;
            pivot = Tab_wej[PivotInd];

            // zamieniamy pivot z pierwszym elementem
            Tab_wej[PivotInd] = Tab_wej[LewyInd];
            Tab_wej[LewyInd] = pivot;

            lewy = LewyInd;
            prawy = PrawyInd;

            while(lewy < prawy) {
                while(Tab_wej[lewy].numer <= pivot.numer && lewy < PrawyInd) {
                    lewy++;
                }
                while(Tab_wej[prawy].numer > pivot.numer && prawy > LewyInd) {
                    prawy--;
                }
                if(lewy < prawy) {
                    // ustawiamy wszystkie elementy mniejsze i większe od pivota
                    // po dwóch stronach - zamieniamy jeśli są po złej stronie
                    swap(Tab_wej[lewy], Tab_wej[prawy]);
                }
            }
        
            // ustawienie pivota na prawidłowej pozycji
            swap(Tab_wej[LewyInd], Tab_wej[prawy]);

            // wywołanie q_sort dla prawej i lewej podtablicy
            q_sort(Tab_wej, LewyInd, prawy - 1);
            q_sort(Tab_wej, prawy + 1, PrawyInd);
        }
        return;
    }


    void Sortowanie::quick_sort (Wektor<Pakiet> & Tab_wej)
    {
        Rozmiar_tab = Tab_wej.Indeks() + 1;
        //  wywołanie funkcji q_sort przy użyciu parametrów podanych funkcji quick_sort,
        //  dla ułatwienia rekurencyjności, analogicznie jak w merge_sort
        q_sort(Tab_wej, 0, Rozmiar_tab - 1);
    }