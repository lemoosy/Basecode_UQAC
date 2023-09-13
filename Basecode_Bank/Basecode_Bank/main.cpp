#include "Bank.h"
#include "Settings.h"
#include "Input.h"

int main(void)
{
    // Création de la banque.
    Bank bank;

    // Variables qui vont nous servir à récupérer les réponses de l'utilisateur.
    string res, password;

    // Futur utilisateur.
    User* user = nullptr;
    
    while (1)
    {
        // On demande à l'utilisateur s'il est déjà client.
        res = Input_YesNo("Bonjour ! Nouveau client ?");

        // Si c'est un nouveau client, on lui créer un compte.
        if (res == "o")
        {
            user = Input_UserCreate(bank);
        }

        // Si ce n'est pas un nouveau client, on lui demande ses identifiants.
        else
        {
            user = Input_UserConnect(bank);

            // Si le programme ne trouve pas l'utilisateur dans la banque
            // au bout de 5 tentatives, on quitte le programme.
            if (!user)
            {
                cout << "Trop de tentatives, fermeture du programme." << endl;
                return EXIT_FAILURE;
            }
        }

        cout << "Bienvenue " << user->m_name << " !" << endl;

        _sleep(1000);

        // Boucle secondaire pour les actions de l'utilisateur.
        while (1)
        {
            system("cls");

            // Affichage des informations de l'utilisateur.
            user->Print();

            // Affichage des actions possibles de l'utilisateur.
            cout << "\n[1] Retirez de l'argent" << endl;
            cout << "[2] Deposez de l'argent" << endl;
            cout << "[3] Modifiez le mot de passe" << endl;
            cout << "[4] Deconnexion\n" << endl;

            // On demande à l'utilisateur ce qu'il veut faire.
            res = Input_Message("Que souhaitez-vous faire ?");

            if (res == "1")
            {
                user->RemoveMoney(Input_FloatPositive("Retirer de l'argent >>"));
            }
            else if (res == "2")
            {
                user->AddMoney(Input_FloatPositive("Deposer de l'argent >>"));
            }
            else if (res == "3")
            {
                res = Input_Message("Ancien mot de passe :");
                
                if (user->SamePassword(res))
                {
                    password = Input_Password();

                    bool b = user->ChangePassword(res, password);

                    assert(b);

                    cout << "Mot de passe modifie avec succes !" << endl;
                }
                else
                {
                    cout << "Mot de passe incorrect." << endl;
                }

                _sleep(1000);
            }
            else if (res == "4")
            {
                cout << "Au revoir " << user->m_name << " !" << endl;
                _sleep(2000);
                system("cls");
                break;
            }
        }
    }

    return EXIT_SUCCESS;
}
