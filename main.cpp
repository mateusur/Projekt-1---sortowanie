#include <iostream>
#include "generator.h"
#include"sortowanie.h"

using namespace std;

/* Kr�tki poradnik jak najlepiej generowa� dane i jak dzia�a ten program.
Na wst�pi� dodam, �e uda�o mi si� zrobi� tak, �e introsort jest najszybszy :D
I druga uwaga, �e teraz program jest w takim ustawieniu, �e mo�esz go w�aczy� i zobaczy� wyniki dla jednej tablicy o rozmiarze 100000. GENEROWANIE CHWIL� TRWA.
Jak to zrobisz, to czytaj dalej :)
1. Rzeczy, kt�re zmieni�am, �eby introsort by� najszybszy:
a) linijki 65-87 w pliku introspektywne.h to fragment algorytmu z wikipedii, troch� bardziej to jest rozbudowane ni� ten wcze�niejszy
b) tak naprawd� ca�a zmiana polega�a na wyrzuceniu delete[] pomocnicza (linijka 79 i 125 w pliku sortowanie.h). Og�lnie to powinna by� usuwana ta pami�c, ale z jakiego�
powodu on si� denerwuje i chce, �eby nie usuwa�, wi�c si� nie k��c�
2. Jak generowa� dane?
W tym momencie masz odkomentowan� komend� "generujDane" w mainie. Ta funkcja odpowiada za utworzenie podanej liczb tablic w ka�dym rozmiarze, czyli jak masz teraz
ustawione na 3 tzn. �e utworzy si� po 3 tablice w ka�dym rozmiarze. Polecam przy generowaniu danych zostawi� w mainie jedynie t� linijk�, bez funkcji "wczytaj" i
uruchomi� program jedynie dla generacji 100 tablic, bo to troch� schodzi
3. Jak wczytywa� dane �eby si� nie narobi�?
Nie da si� zbytnio :/ M�j patent jest s�aby, moze ty wymy�lisz co� lepszego. Aby dowiedzie� si� jak ja to robi� przejd� do sortowanie.h i szukaj d�ugiego opisu.
4. Jak wczyta� dane w main?
Czytaj je�li przeczyta�e� sortowanie.h (cho� mo�esz teraz te�, bo to bez r�nicy :P)
Funkcja wczytaj jest prosta - podajesz jako pierwszy argument rozmiar tablicy a jako drugi ilo�� tablic do posortowania.
WA�NE!
Jak zaczniesz sortowa� to pami�taj, �eby zakomentowa� generujDane.

No i to tyle, jakie� tam komentarze ci pododawa�am te� w plikach. Mam nadzi�j�, �e to pomo�e i rozja�ni pewne w�tpliwo�ci.
*/

int main()
{
	//generujDane(100); // tworzenie po 10 tablic za zadanych rozmiarach

	//cout << "PRZYKLADOWE ROZWIAZANIA DLA TABLICY O WYMIARZE 100000" << endl;
	wczytaj(5);

	system("pause");
	return 0;
}

/*
BONUS! PRO TIP DO EXCELA
Przy wklejaniu masz wyniki z kropkami, jak zaznaczysz dane i dasz ctrl+h to wtedy mo�esz zamieni� . na ,
*/

/*
aktualnie jest tak, �e liczbe jaka podasz we "wczytaj" to tyle wypisze ci czasow dla danego sortowania i pozniej leci kolejny rozmiar, na przykladzie:
wpisujesz wczytaj(4); to np w pliku "Quicksort" masz tak:
czas dla tablicy 10000
czas dla tablicy 10000
czas dla tablicy 10000
czas dla tablicy 10000
czas dla tablicy 50000
czas dla tablicy 50000
czas dla tablicy 50000
.
.
.
itd
*/

/*
chce jeszcze zrobic tak zeby bylo "rozmiar_nazwa sortowania.txt" ale nie zdazylem rozkminic jak wrzucac rozmiar ktory jest zmienna. 
No i jak juz ogarne jak to zrobic to tak samo zrobie z % posortowania i np "rozmiar_nazwa sortowania_%posortowania.txt"
a jesli to nie wyjdzie to chociaz dodac jakas informacje, ze teraz bedzie juz czas dla innego rozmiaru
*/