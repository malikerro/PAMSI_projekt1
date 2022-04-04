# dla przypomnienia: 
# Jeśli chciałbym skompilować to bez makefifa,
# to muszę wrzucić wszystko do jednego folderu i odpalić komendę:
# g++ main.cpp Sortowanie.cpp Wektor.cpp (ew. więcej plików składowych
# w zachowanej kolejności - main -> pliki2-korzystający z plik1 -> plik1 i tp.)
# program odpalamy: ./a.exe

#  To sa opcje dla kompilacji
CXXFLAGS=-g -Iinc -Wall -pedantic #-std=c++0x

__start__: projekt_1
	./projekt_1

projekt_1: main.o Sortowanie.o Wektor.o
	g++ -Wall -pedantic main.o Sortowanie.o Wektor.o -o projekt_1

main.o: main.cpp
	g++ -c ${CXXFLAGS} main.cpp

Sortowanie.o: Sortowanie.cpp
	g++ -c ${CXXFLAGS} Sortowanie.cpp

Wektor.o: Wektor.cpp
	g++ -c ${CXXFLAGS} Wektor.cpp

clean:
	rm *.o projekt_1.exe