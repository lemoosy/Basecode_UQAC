#pragma once

#include "Settings.h"

class Adresse
{
public:

	int numero;

	string nom_rue;

	int numero_appart;

	string ville;

	string departement;

	int code_postal;

	Adresse();

	Adresse(int numero_appart);

	void Print();
};

Adresse::Adresse()
{
	numero = 0;

	nom_rue = "";

	numero_appart = 0;

	ville = "";

	departement = "";

	code_postal = 0;
}

inline Adresse::Adresse(int numero_appart)
{
	numero = 0;

	nom_rue = "";

	numero_appart = 0;

	ville = "";

	departement = "";

	code_postal = numero_appart;
}

inline void Adresse::Print()
{
	cout << "Numero: " << numero << endl;
	cout << "Nuom rue: " << nom_rue << endl;
	cout << "Num appart: " << numero_appart << endl;
	cout << "Ville: " << ville << endl;
	cout << "Departmeent: " << departement << endl;
	cout << "Code postal: " << code_postal << endl;
}
