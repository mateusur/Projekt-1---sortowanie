#ifndef QUICKSORT_H
#define QUICKSORT_H

int podzial(int* tablica, int lewy, int prawy)
{
	int os = tablica[(lewy + prawy) / 2];
	int p = prawy;
	int l = lewy;
	int pom;
	while (l <= p)
	{
		while (tablica[l] < os) l++; // gdy element po lewej stornie mniejszy od osi -> szukaj dalej
		while (tablica[p] > os) p--; // gdy element po prawej stornie wiekszy od osi -> szukaj dalej
		if (l <= p)
		{
			pom = tablica[l]; // zamiana miejscami
			tablica[l] = tablica[p];
			tablica[p] = pom;
			l++;
			p--;
		}
	}
	return l;
}

void quick_sort(int* tablica, int lewy, int prawy) {
	if (lewy < prawy)
	{
		int q = podzial(tablica, lewy, prawy);
		quick_sort(tablica, lewy, q - 1);
		quick_sort(tablica, q + 1, prawy);
	}
}

#endif QUICKSORT
