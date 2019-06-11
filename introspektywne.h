#ifndef INTROSPEKTYWNE_H
#define INTROSPEKTYWNE_H
#define M_LN2 0.654

#include "quicksort.h"

void kopiec(int* tablica, int rozmiar_kopca, int indeks) {
	int lewy = (indeks + 1) * 2 - 1;
	int prawy = (indeks + 1) * 2;
	int max = 0;

	if (lewy < rozmiar_kopca && tablica[lewy] > tablica[indeks])
		max = lewy;
	else
		max = indeks;

	if (prawy < rozmiar_kopca && tablica[prawy] > tablica[max])
		max = prawy;

	if (max != indeks)
	{
		int pom = tablica[indeks];
		tablica[indeks] = tablica[max];
		tablica[max] = pom;

		kopiec(tablica, rozmiar_kopca, max);
	}
}

void kopcowanie(int* data, int count) {
	int heapSize = count;

	for (int p = (heapSize - 1) / 2; p >= 0; --p)
		kopiec(data, heapSize, p);

	for (int i = count - 1; i > 0; --i)
	{
		int temp = data[i];
		data[i] = data[0];
		data[0] = temp;

		--heapSize;
		kopiec(data, heapSize, 0);
	}
}

void wstawianie(int *tab, int rozmiar)
{
	int pom, j;
	for (int i = 1; i < rozmiar; i++)
	{
		//wstawienie elementu w odpowiednie miejsce
		pom = tab[i]; //ten element bêdzie wstawiony w odpowiednie miejsce
		j = i - 1;

		while (j >= 0 && tab[j] > pom)
		{
			tab[j + 1] = tab[j]; //przesuwanie elementów
			--j;
		}
		tab[j + 1] = pom; //wstawienie pom w odpowiednie miejsce
	}
}

void introsort_wybor(int* tablica, int N, int M)
{
	long i;
	if (M <= 0)
	{
		kopcowanie(tablica, N);
		return;
	}
	i = podzial(tablica, 0, N);
	if (i > 9)
		introsort_wybor(tablica, i, M - 1);
	if (N - 1 - i > 9)
		introsort_wybor(tablica + i + 1, N - 1 - i, M - 1);
}

void IntroSort(int* tablica, int N)
{
	introsort_wybor(tablica, N, (int)floor(2 * log(N) / M_LN2));
	wstawianie(tablica, N);
}

//void IntroSort(int* data, int count) 
//{
//	int partitionSize = podzial(data, 0, count - 1);
//
//	if (partitionSize < 16) 
//	{
//		wstawianie(data, count);
//	}
//	else if (partitionSize > (2 * log(count))) // wybor kopcowania
//	{
//		kopcowanie(data, count);
//	}
//	else
//	{
//		quick_sort(data, 0, count - 1); // wybor quicksorta
//	}
//}

#endif INTROSPEKTYWNE_H
