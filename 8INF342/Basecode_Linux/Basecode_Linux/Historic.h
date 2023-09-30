#pragma once

#include "Settings.h"

void Message_ToLinux(string p_message);

/// @brief Ajoute un message dans un fichier TXT.
/// @param p_path Chemin du fichier TXT.
/// @param p_message Message à ajouter.
void Historic_Add(string p_path, string p_message, int p_messageCount)
{
    ofstream file(p_path, ios::app);

    if (file.fail())
    {
        cout << "ERROR - Historic_Add()" << endl;
        abort();
    }

    file << p_messageCount << '\t' << p_message << '\t' << 0 << endl;

    file.close();
}

/// @brief Affiche le contenu d'un fichier TXT.
/// @param p_path Chemin du fichier TXT.
/// @param p_messageCount Nombre de messages à afficher.
void Historic_Display(string p_path, int p_messageCount)
{
    ifstream file(p_path);

    if (file.fail())
    {
        cout << "ERROR - Historic_Display()" << endl;
        abort();
    }

    string line;

    while ((file.eof() == false) && (p_messageCount > 0))
    {
        getline(file, line);
        cout << line << endl;
        p_messageCount--;
    }

    file.close();
}

/// @brief Execute toutes les commandes d'un fichier TXT.
void Historic_Load(string p_path)
{
    ifstream file(p_path);

    if (file.fail())
    {
        cout << "ERROR - Historic_Display()" << endl;
        abort();
    }

    string line;
    string message;

    while (file.eof() == false)
    {
        getline(file, line);

        int pos1 = line.find('\t');
        int pos2 = line.find('\t', pos1 + 1);

        message.assign(line, pos1 + 1, pos2 - pos1 - 1);

        Message_ToLinux(message);
    }

    file.close();
}

/// @brief Découpe un message en plusieurs messages ("ls -m abc" -> "ls" "m" "abc").
/// @return true si erreur, false sinon.
void Message_ToCommands(string p_message, int parametersCount, string* p_parameters)
{
    assert(parametersCount);

    for (int i = 0; i < parametersCount; i++)
    {
        p_parameters[i].clear();
    }

    int size = p_message.size();

    if ((size == 0) || (p_message[0] == ' '))
    {
        return;
    }

    int parametersIdx = 0;
    int positionSep = 0;

    for (int i = 0; i < size; i++)
    {
        if (p_message[i] == ' ')
        {
            if (parametersIdx == parametersCount - 1)
            {
                size = i;
                break;
            }

            int count = i - positionSep;
            p_parameters[parametersIdx].assign(p_message, positionSep, count);
            parametersIdx++;
            positionSep = i + 1;
        }
    }

    int count = size - positionSep;
    p_parameters[parametersIdx].assign(p_message, positionSep, count);
}

/// @brief Exécute une commande Linux.
void Commands_ToLinux(int p_parametersCount, string p_parameters[])
{
    if (p_parameters[0] == "ls")
    {
    }
    else if (p_parameters[0] == "pwd")
    {
    }
    else if (p_parameters[0] == "man")
    {
    }
    else if (p_parameters[0] == "mkdir")
    {
    }
    else if (p_parameters[0] == "rmdir")
    {
    }
    else if (p_parameters[0] == "mv")
    {
    }
    else if (p_parameters[0] == "cat")
    {
    }
    else if (p_parameters[0] == "historic")
    {
        Historic_Display(HISTORIC_PATH_EXPORT, 5);
    }
    else
    {
        cout << "Command not found." << endl;
    }
}

void Message_ToLinux(string p_message)
{
    int parametersCount = 3;
    string* parameters = new string[parametersCount];

    Message_ToCommands(p_message, parametersCount, parameters);

    if (parameters[0] == "stop" || parameters[0] == "historic")
    {
		return;
	}

    cout << p_message << endl;

    Commands_ToLinux(parametersCount, parameters);
}
