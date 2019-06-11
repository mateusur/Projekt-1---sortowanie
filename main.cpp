#include <iostream>
#include "generator.h"
#include"sortowanie.h"

using namespace std;

/* Krótki poradnik jak najlepiej generowaæ dane i jak dzia³a ten program.
Na wstêpiê dodam, ¿e uda³o mi siê zrobiæ tak, ¿e introsort jest najszybszy :D
I druga uwaga, ¿e teraz program jest w takim ustawieniu, ¿e mo¿esz go w³aczyæ i zobaczyæ wyniki dla jednej tablicy o rozmiarze 100000. GENEROWANIE CHWILÊ TRWA.
Jak to zrobisz, to czytaj dalej :)
1. Rzeczy, które zmieni³am, ¿eby introsort by³ najszybszy:
a) linijki 65-87 w pliku introspektywne.h to fragment algorytmu z wikipedii, trochê bardziej to jest rozbudowane ni¿ ten wczeœniejszy
b) tak naprawdê ca³a zmiana polega³a na wyrzuceniu delete[] pomocnicza (linijka 79 i 125 w pliku sortowanie.h). Ogólnie to powinna byæ usuwana ta pamiêc, ale z jakiegoœ
powodu on siê denerwuje i chce, ¿eby nie usuwaæ, wiêc siê nie k³ócê
2. Jak generowaæ dane?
W tym momencie masz odkomentowan¹ komendê "generujDane" w mainie. Ta funkcja odpowiada za utworzenie podanej liczb tablic w ka¿dym rozmiarze, czyli jak masz teraz
ustawione na 3 tzn. ¿e utworzy siê po 3 tablice w ka¿dym rozmiarze. Polecam przy generowaniu danych zostawiæ w mainie jedynie t¹ linijkê, bez funkcji "wczytaj" i
uruchomiæ program jedynie dla generacji 100 tablic, bo to trochê schodzi
3. Jak wczytywaæ dane ¿eby siê nie narobiæ?
Nie da siê zbytnio :/ Mój patent jest s³aby, moze ty wymyœlisz coœ lepszego. Aby dowiedzieæ siê jak ja to robiê przejdŸ do sortowanie.h i szukaj d³ugiego opisu.
4. Jak wczytaæ dane w main?
Czytaj jeœli przeczyta³eœ sortowanie.h (choæ mo¿esz teraz te¿, bo to bez ró¿nicy :P)
Funkcja wczytaj jest prosta - podajesz jako pierwszy argument rozmiar tablicy a jako drugi iloœæ tablic do posortowania.
WA¯NE!
Jak zaczniesz sortowaæ to pamiêtaj, ¿eby zakomentowaæ generujDane.

No i to tyle, jakieœ tam komentarze ci pododawa³am te¿ w plikach. Mam nadziêjê, ¿e to pomo¿e i rozjaœni pewne w¹tpliwoœci.
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
Przy wklejaniu masz wyniki z kropkami, jak zaznaczysz dane i dasz ctrl+h to wtedy mo¿esz zamieniæ . na ,
*/

/*
aktualnie jest tak, ¿e liczbe jaka podasz we "wczytaj" to tyle wypisze ci czasow dla danego sortowania i pozniej leci kolejny rozmiar, na przykladzie:
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