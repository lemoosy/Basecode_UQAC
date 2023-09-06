// 8PRO128 - Léonard LEMOOSY

#include "Settings.h"
#include "Book.h"

/// @brief Retourne le minimum d'un tableau d'entiers (exemple pré-incrémentation).
int GetMinimum(int tab[], int size)
{
	assert(size > 0);

	int res = INT_MAX;

	while (--size >= 0)
	{
		if (tab[size] < res)
		{
			res = tab[size];
		}
	}

	return res;
}

int main()
{
	// ---------- EX. 1 ----------

	cout << "1234 " << flush; // Vide le buffer.
	cout << "5678 " << endl; // Vide le buffer ET Saute une ligne.

	// Voir fonction operator>>() pour l'exemple.

	// ---------- EX. 2 ----------

	int a = 0;
	int b = (a++); // D'abord b = a, puis a += 1.
	// a = 1 et b = 0.

	int c = 0;
	int d = (++c); // D'abord c += 1, puis d = c.
	// c = 1 et d = 1.

	int size = 10;
	int tab[10] = { 8, 3, 4, 2, 0, 1, 7, 5, 6 };
	int res = GetMinimum(tab, size);

	// ---------- EX. 3 ----------

	// Création du premier livre.
	Book book1("Le Robert", "Alain Rey", 1000);
	book1.SetPrice(13.90f);
	cout << '\n' << book1;

	// Création du deuxième livre.
	Book* book2 = new Book("Genetic Programming", "John R. Koza", 836);
	book2->SetPrice(70.0f);
	cout << *book2;
	delete book2;

	// Création du troisième livre (on demande à l'utilisateur les données).
	Book book3;
	cin >> book3;

	return EXIT_SUCCESS;
}
