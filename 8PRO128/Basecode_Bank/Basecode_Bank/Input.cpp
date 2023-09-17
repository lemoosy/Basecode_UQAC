#include "Input.h"

string Input_Message(string message)
{
    string res;

    cout << message << " ";

    getline(cin, res);

    system("cls");

    return res;
}

string Input_YesNo(string message)
{
    string res;

    do
    {
        res = Input_Message(message + " (o/n) :");
    }
    while ((res != "o") && (res != "n"));

    return res;
}

string Input_Mail(Bank& bank)
{
    string res;

    while (1)
    {
        res = Input_Message("Quel est votre adresse mail ?");

        if (bank.UserExist(res))
        {
            cout << "Cette adresse mail existe dans la banque." << endl;
        }
        else
        {
            return res;
        }
    }
}

string Input_Password(void)
{
    string res;

    while (1)
    {
        res = Input_Message(
            "Entrez un mot de passe (8 lettres minimum, au moins une majuscule et un chiffre) :"
        );

        if (res.size() >= 8)
        {
            bool maj = false;
            bool num = false;

            for (int i = 0; i < res.size(); i++)
            {
                if (('A' <= res[i]) && (res[i] <= 'Z'))
                {
                    maj = true;
                }

                if (('0' <= res[i]) && (res[i] <= '9'))
                {
                    num = true;
                }
            }

            if (maj && num)
            {
                return res;
            }
        }
    }
}

string Input_Phone(void)
{
    string res = Input_YesNo("Souhaitez-vous ajouter un numero de mobile ?");

    if (res == "n") return "";

    while (1)
    {
        res = Input_Message("Quel est votre numero de mobile (10 chiffres) ?");

        if (res.size() == 10)
        {
            bool num = true;

            for (int i = 0; i < res.size(); i++)
            {
                if ((res[i] < '0') || ('9' < res[i]))
                {
					num = false;
                    break;
				}
            }

            if (num)
            {
				return res;
			}
        }
    }
}

User* Input_UserCreate(Bank& bank)
{
    string mail = Input_Mail(bank);

    string password = Input_Password();

    User* user = new User(mail, password);

    user->m_name = Input_Message("Quel est votre nom ?");

    user->m_phone = Input_Phone();

    if (bank.AddUser(user))
    {
        return user;
    }

    delete user;
    
    return nullptr;
}

User* Input_UserConnect(Bank& bank)
{
    User* user = nullptr;

    string mail, password;

    for (int i = 0; (i < 5) && !user; i++)
    {
        mail = Input_Message("Quel est votre adresse mail ?");

        if (bank.UserExist(mail))
        {
            password = Input_Message("Quel est votre mot de passe ?");

            user = bank.Connect(mail, password);

            if (!user)
            {
                cout << "Mot de passe incorrect." << endl;
            }
        }
        else
        {
            cout << "Cette adresse mail n'existe pas dans la banque (" << 4 - i << ")." << endl;
        }
    }

    return user;
}

/// @brief Vérifie si une chaîne de caractères est un float positif.
bool __IsFloatPositive(string str)
{
    bool pt = false;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '.')
        {
            if (pt)
            {
                return false;
            }
            else
            {
                pt = true;
            }
        }
        else if ((str[i] < '0') || (str[i] > '9'))
        {
            return false;
        }
    }

    return true;
}

float Input_FloatPositive(string message)
{
    string res;

    while (1)
    {
        res = Input_Message(message);

        if (__IsFloatPositive(res))
        {
            return std::stof(res);
        }
    }
}
