#pragma once

#include "Settings.h"

/// @brief Classe représentant un utilisateur.
class User
{
private:

	/// @brief Adresse mail de l'utilisateur.
	string m_mail;

	/// @brief Mot de passe de l'utilisateur.
	string m_password;

	/// @brief Monnaie de l'utilisateur.
	float m_money;

public:

	/// @brief Nom de l'utilisateur.
	string m_name;

	/// @brief Numéro de mobile de l'utilisateur.
	string m_phone;

	User();

	User(string mail);

	User(string mail, string password);

	void Print() const;

	/// @brief Ajoute de la monnaie à l'utilisateur.
	void AddMoney(float money);

	/// @brief Retire de la monnaie à l'utilisateur.
	void RemoveMoney(float money);

	/// @brief Change le mot de passe de l'utilisateur.
	/// @return true si l'opération a réussi, false sinon.
	bool ChangePassword(string passwordOld, string passwordNew);

	/// @brief Vérifie si le mot de passe est le même que celui de l'utilisateur.
	bool SamePassword(string password);

	/// @brief Compare l'adresse mail de deux utilisateurs avec le signe ==.
	friend bool operator==(const User& user0, const User& user1)
	{
		return (user0.m_mail == user1.m_mail);
	}

	/// @brief Compare l'adresse mail de deux utilisateurs avec le signe >.
	friend bool operator>(const User& user0, const User& user1)
	{
		return (user0.m_mail > user1.m_mail);
	}

	/// @brief Compare l'adresse mail de deux utilisateurs avec le signe <.
	friend bool operator<(const User& user0, const User& user1)
	{
		return (user0.m_mail < user1.m_mail);
	}
};
