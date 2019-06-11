#ifndef SORTOWANIE_H
#define SORTOWANIE_H

#include <chrono>
#include "quicksort.h"
#include "scalanie.h"
#include "introspektywne.h"

#include <fstream>
#include <string>

#include <iomanip>

using namespace std;
using tp = chrono::time_point<std::chrono::system_clock>;
using duration = chrono::duration<float>;

tp start;
duration d;

void zapiszczas(duration d, string algorytm,int wielkosc,int procent)
{
	string nazwa_procent = to_string(procent);
	string nazwa_rozmiar = to_string(wielkosc);
	fstream plik;
	//string sciezka = nazwa_rozmiar+algorytm+"_0,"+nazwa_procent+".txt"; // tworzenie pliku .txt
	//string sciezka =  "Posortowane tablice/"+nazwa_rozmiar + algorytm + "_0," + nazwa_procent + ".txt";
	string sciezka =  "Posortowane tablice/"+algorytm+"/"+nazwa_rozmiar+ "_0," + nazwa_procent + ".txt";
	plik.open(sciezka, fstream::out | fstream::app);
	if (plik.is_open())
	{
		plik << d.count();
		plik << endl;
	}
	else
		cout << "Nie udalo sie zapisac do pliku";

	plik.close();
}

/*
Jeœli to czytasz to znaczy, ¿e ju¿ wiesz jak generowaæ dane i mo¿e masz to ju¿ zrobione. :) Wiêc tak, jeœli chodzi o odpalanie algorytmów to jest lipa. Mój sposób jest spoko
dla tych ma³ych tablic. Ustawiasz double stopnie[1] i po kolei zmieniasz wartoœæ procentu sortowania dla ka¿dego algorytmu OSOBNO!
PRZYK£AD:
double stopnie[1] = { 0.25 };
for (int j = 0; j < 1; j++) -> zwróæ uwagê, ¿e tu jest 1
	{
		wybrany algorytm odkomentowany;
	}
Zawsze odkomentowana musi byæ linijka od 55-58 oraz odpowiednie linijki z wybranych algorytmem. Zauwa¿, ¿e te¿ wrzuci³am osobn¹ funkcjê sortowanie odwrotne, której zawartoœæ
sobie odkomentowujesz, gdy sortujesz odwrotnie (myœlê, ¿e wiesz o co chodzi). W sortowaniu odwrotnym zawsze s¹ odkomentowane linijki 93-100.
W ten sposób w pliku zapisczasu.txt tworzysz 100 czasów dla danego algorytmu oraz wariantu posortowania i takie 100 gotowych tablic sobie kopiujesz do excela.
Nastêpnie usuwasz plik/wycinasz dane, na to samo wychodzi.
Nie polecam robiæ to w pêtli dla wszystkich, za du¿o czasu potem zajmuje sortowanie danych. Myœlê, ¿edo 1M i 500k mo¿esz zmniejszyæ iloœæ sortowania ze 100 na
chocia¿by 75 (zawsze trochê krócej). No i to tyle, teraz mo¿esz wróciæ do maina :)
*/


void sortowanie(int* tablica, int rozmiar)
{
	int* pomocnicza = new int[rozmiar];
	double stopnie[7] = {0, 0.25,0.5,0.75, 0.95, 0.99, 0.997}; //double stopnie[7] = { 0, 0.25, 0.50, 0.75, 0.95, 0.99, 0.997 };
	string nazwy[7] = { "Wszystkie elementy losowe: ",
						"25% pierwszych elementow posortowane: ",
						"50% pierwszych elementow posortowane: ",
						"75% pierwszych elementow posortowane: ",
						"95% pierwszych elementow posortowane: ",
						"99% pierwszych elementow posortowane: ",
						"99.7% pierwszych elementow posortowane: " };
	
	for (int j = 0; j < 7; j++) //for (int j = 0; j < 7; j++)
	{
		int procenty_posortowania=stopnie[j]*1000;
	/*	if (j == 0) procenty_posortowania =0;
		else if (j == 1) procenty_posortowania = 25;
		else if (j == 2)procenty_posortowania = 5;
		else if (j == 3)procenty_posortowania = 75;
		else if (j == 4)procenty_posortowania = 95;
		else if (j == 5)procenty_posortowania = 99;
		else if (j == 6)procenty_posortowania = 997;
*/
		for (int i = 0; i < rozmiar; i++)		{
			pomocnicza[i] = tablica[i];
			}
		quick_sort(pomocnicza, 0, rozmiar*stopnie[j] - 1); //przygotowanie tablicy, okreœlenie procentu wstêpnego posortowania

		cout << nazwy[j] << endl;
		start = chrono::system_clock::now(); // algorytm mergesort
		merge_sort(pomocnicza, 0, rozmiar - 1);
		d = chrono::system_clock::now() - start;
		cout << "Sortowanie przez scalanie: " << d.count();
		zapiszczas(d, "Scalanie", rozmiar, procenty_posortowania);
		cout << endl;

		//rozmiar = to_string(stopnie[j]);
		start = chrono::system_clock::now(); // algorytm quicksort
		quick_sort(pomocnicza, 0, rozmiar - 1);
		d = chrono::system_clock::now() - start;
		cout << "Quicksort: " << d.count();
		zapiszczas(d,"Quicksort",rozmiar, procenty_posortowania);
		cout << endl;

		

		start = chrono::system_clock::now(); // algorytm introsort
		IntroSort(pomocnicza, rozmiar);
		d = chrono::system_clock::now() - start;
		cout << "Sortowanie introspektywne: " << d.count() << endl;
		zapiszczas(d,"Introspektywne", rozmiar, procenty_posortowania);
		cout << endl;
		
	}
	//delete[] pomocnicza;
}

void sortowanie_odwrotne(int* tablica, int rozmiar)
{
	int* pomocnicza1 = new int[rozmiar];

	cout << "Elementy w odwrotnej kolejnosci: " << endl;
	quick_sort(tablica, 0, rozmiar - 1); // przypisanie elementów w odwrotnej kolejnoœci
	for (int i = 0; i < rozmiar; i++)
	{
		pomocnicza1[(rozmiar - 1 - i)] = tablica[i];
	}

	start = chrono::system_clock::now();
	quick_sort(pomocnicza1, 0, rozmiar - 1);
	d = chrono::system_clock::now() - start;
	cout << "Quicksort: " << d.count();
	zapiszczas(d,"Quicksort", rozmiar,-1);
	cout << endl;


	for (int i = 0; i < rozmiar; i++)
	{
		pomocnicza1[(rozmiar - 1 - i)] = tablica[i];
	}

	start = chrono::system_clock::now();
	merge_sort(pomocnicza1, 0, rozmiar - 1);
	d = chrono::system_clock::now() - start;
	cout << "Sortowanie przez scalanie: " << d.count();
	zapiszczas(d,"Scalanie", rozmiar,-1);
	cout << endl;

	for (int i = 0; i < rozmiar; i++)
	{
		pomocnicza1[(rozmiar - 1 - i)] = tablica[i];
	}

	start = chrono::system_clock::now();
	IntroSort(pomocnicza1, rozmiar);
	d = chrono::system_clock::now() - start;
	cout << "Sortowanie introspektywne: " << d.count();
	zapiszczas(d,"Introspektywne", rozmiar,-1);
	cout << endl;

	//delete[] pomocnicza1;
}

//void wczytaj(int rozmiar, int ilosc)
//{
//	int* tablica = new int[rozmiar];
//	fstream plik;
//	string sciezka = to_string(rozmiar) + ".txt";
//	plik.open(sciezka, fstream::in);
//	for (int j = 0; j < ilosc; j++)
//	{
//		for (int i = 0; i < rozmiar; i++)
//		{
//			plik >> tablica[i];
//		}
//		cout << endl;
//		sortowanie(tablica, rozmiar); // wywo³anie algorytmów w funkcji wczytuj¹cej z pliku
//		sortowanie_odwrotne(tablica, rozmiar);
//	}
//
//	plik.close();
//
//}
//
//#endif SORTOWANIE_H


void wczytaj( int ilosc)
{
	int rozmiar;
	for (int i = 0; i < 5; i++)
	{
		if (i == 0) rozmiar = 10000;
		else if (i == 1) rozmiar = 50000;
		else if (i == 2) rozmiar = 100000;
		else if (i == 3) rozmiar = 500000;
		else if (i == 4) rozmiar = 1000000;
		int* tablica = new int[rozmiar];
		fstream plik;
		string sciezka = to_string(rozmiar) + ".txt";
		plik.open(sciezka, fstream::in);
		for (int j = 0; j < ilosc; j++)
		{
			for (int i = 0; i < rozmiar; i++)
			{
				plik >> tablica[i];
			}
			cout << endl;
			sortowanie(tablica, rozmiar); // wywo³anie algorytmów w funkcji wczytuj¹cej z pliku
			sortowanie_odwrotne(tablica, rozmiar);
		}

		plik.close();
	}
}

#endif SORTOWANIE_H
