#pragma once

#include "Bank.h"
#include "Settings.h"

/// @brief Demande à l'utilisateur une réponse.
/// @param message Message à afficher.
/// @return Réponse de l'utilisateur.
string Input_Message(string message);

/// @brief Demande à l'utilisateur une réponse oui/non.
/// @param message Message à afficher.
/// @return "o" si oui, "n" si non.
string Input_YesNo(string message);

/// @brief Demande à l'utilisateur une adresse mail.
string Input_Mail(const Bank& bank);

/// @brief Demande à l'utilisateur un mot de passe.
string Input_Password(void);

/// @brief Demande à l'utilisateur un numéro de mobile.
string Input_Phone(void);

/// @brief Demande les informations de l'utilisateur et créer son compte.
User* Input_UserCreate(Bank& bank);

/// @brief Demandes les informations de l'utilisateur,
/// recherche son compte dans la banque et retourne l'utilisateur.
/// @return L'utilisateur s'il existe, nullptr sinon (au bout de 5 tentatives).
User* Input_UserConnect(Bank& bank);

/// @brief Demande à l'utilisateur un float positif.
float Input_FloatPositive(string message);
