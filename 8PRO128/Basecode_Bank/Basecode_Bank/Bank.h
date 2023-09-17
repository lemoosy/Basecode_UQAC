#pragma once

#include "AVL.h"
#include "Settings.h"
#include "User.h"

/// @brief Classe représentant une banque.
class Bank
{
private:

	/// @brief Structure de donnée qui permet de stocker les utilisateurs.
	/// On peut récupérer/ajouter/supprimer un utilisateur en log(n).
	AVLTree<User>* m_users;

public:

	Bank();

	~Bank();

	/// @brief Retourne le nombre d'utilisateurs dans la banque.
	inline int GetUsersCount(void) const
	{
		return m_users->GetSize();
	}

	/// @brief Vérifie si un utilisateur existe dans la banque.
	/// @return true si l'utilisateur existe, false sinon.
	bool UserExist(string mail) const;

	/// @brief Recherche un utilisateur dans la banque.
	/// @return L'utilisateur s'il existe, nullptr sinon.
	User* Connect(string mail, string password) const;

	/// @brief Ajoute un utilisateur dans la banque.
	/// @return true si l'opération a réussi, false sinon.
	bool AddUser(User* user);

	/// @brief Supprime un utilisateur dans la banque.
	/// @return true si l'opération a réussi, false sinon.
	bool RemoveUser(User* user);
};
