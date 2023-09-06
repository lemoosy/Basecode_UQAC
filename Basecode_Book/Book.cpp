#include "Book.h"

Book::Book(string title, string author, int nbPages)
{
	m_title = title;
	m_author = author;
	m_nbPages = nbPages;
	m_price = 0.0f;
}

void Book::Print(void) const
{
	cout << "Titre: " << m_title << endl;
	cout << "Auteur: " << m_author << endl;
	cout << "Nombre de pages: " << m_nbPages << '\n' << endl;
}

string Book::GetTitle(void) const
{
	return m_title;
}

void Book::SetPrice(float price)
{
	m_price = price;
}

ostream& operator<<(ostream& stream, const Book& book)
{
	book.Print();

	return stream;
}

istream& operator>>(istream& stream, Book& book)
{
	cout << "Titre : " << flush;
	getline(stream, book.m_title);

	cout << "Auteur : " << flush;
	getline(stream, book.m_author);

	cout << "Nombre de pages : " << flush;
	cin >> book.m_nbPages;

	if (cin.fail()) abort();

	return stream;
}
