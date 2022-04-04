#ifndef WEKTOR_HH
#define WEKTOR_HH

#define ROZMIAR_STARTOWY 16

using namespace std;


template <typename Typ>
class Wektor {

    Typ *Tablica;           // tablica dynamicznie alokowana
    //Typ &referencja;        // referencja do aktualnej tablicy
    int ind;                // indeks ostatniego zapisanego elementu tablicy
    unsigned int rozmiar;   // aktualny rozmiar zaalokowanej tablicy
    

    public:

    /* Funkcja dodająca element do tablicy, wywołująca realokację
       pamięci w przypadku braku miejsca */
    void push_back(Typ)
    {
        //
    }
    
    /* Funkcja obsługująca realokację pamięci */
    void realocate()
    {
        Typ *Nowa_tablica = new Typ[rozmiar*2];
        for (unsigned int i = 0; i < rozmiar; i++)
        {
            Nowa_tablica[i] = Tablica[i];
        }
        rozmiar = rozmiar*2;
        //referencja = &Nowa_tablica;
        delete Tablica;
        Tablica = &Nowa_tablica;
    }

    // konstruktor klasy Wektor
    Wektor(){
        Tablica = new Typ[ROZMIAR_STARTOWY];
        ind = new int;
        ind = -1;
        rozmiar = new unsigned int;
        rozmiar = ROZMIAR_STARTOWY;
        //referencja = &Tablica;
    }

    // destruktor klasy Wektor
    ~Wektor(){
        delete[] Tablica;
        delete ind;
        delete rozmiar;
    }
};





#endif