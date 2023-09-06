#pragma once

#include "Settings.h"

/// @brief Classe représentant un livre.
class Book
{
private:

	/// @brief Titre du livre.
	string m_title;

	/// @brief Auteur du livre.
	string m_author;

	/// @brief Nombre de pages du livre.
	int m_nbPages;

	/// @brief Prix du livre.
	float m_price;

public:

	Book(string title = "", string author = "", int nbPages = 0);

	/// @brief Affiche les informations du livre.
	void Print(void) const;

	/// @brief Retourne le titre du livre.
	string GetTitle(void) const;

	/// @brief Modifie le prix du livre.
	void SetPrice(float price);

	/// @brief Affiche les information d'un livre à l'aide de la commande cout.
	friend ostream& operator<<(ostream& stream, const Book& book);

	/// @brief Initialise les information d'un livre à l'aide de la commande cin.
	friend istream& operator>>(istream& stream, Book& book);
};
