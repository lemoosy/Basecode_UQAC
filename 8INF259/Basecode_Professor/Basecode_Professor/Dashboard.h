#pragma once

#include "Key.h"
#include "List.h"
#include "Professor.h"
#include "Settings.h"

/// @brief Classe qui permet de stocker et de gérer les professeurs.
class Dashboard
{
private:



    /// @brief Liste des professeurs.
    List<Professor>* m_professors;

    /// @brief Liste des leçons/occurences.
    List<Key>* m_keys;



public:



    /// @brief Initialise la liste des professeurs (la liste est vide).
    Dashboard();

    /// @brief Détruit la liste des professeurs.
    ~Dashboard();



    /// @brief Importe les professeurs à partir d'un fichier TXT.
    /// @param path Chemin du fichier TXT.
    /// @return true si l'importation s'est bien passée, false sinon.
    bool ImportProfessors(string path);

    /// @brief Exporte les professeurs dans un fichier TXT.
    /// @param path Chemin du fichier TXT.
    /// @return true si l'importation s'est bien passée, false sinon.
    bool ExportProfessors(string path);



    /// @brief Insère un professeur à la liste des professeurs.
    void InsertProfessor(Professor* professor);

    /// @brief Supprime le(s) professeur(s) ayant le nom donné en paramètre.
    void RemoveProfessorByName(string name);



    /// @brief Cherche un professeur dans la liste des professeurs.
    /// @return Le professeur si trouvé, nullptr sinon.
    Professor* GetProfessorByName(string name) const;

    /// @brief Cherche un professeur dans la liste des professeurs ayant le moins de leçons.
    /// @return Le professeur si trouvé, nullptr sinon.
    Professor* GetProfessorWithMinimumLessons() const;
   
    /// @brief Cherche un professeur dans la liste des professeurs ayant le moins d'étudiants.
    /// @return Le professeur si trouvé, nullptr sinon.
    Professor* GetProfessorWithMinimumStudents() const;


    /// @brief Renvoie le cours le moins populaire.
    string GetLessPopularLesson() const;



    /// @brief Compte le nombre de professeurs qui enseignent la leçon donnée en paramètre.
    int GetOccLessonsByProfessors(string lesson) const;

    

    /// @brief Affiche tous les professeurs et leurs informations.
    void PrintProfessors() const;



    /// @brief Charge les entrées de l'application.
    /// @param path Chemin du fichier TXT.
    /// @return true si le chargement s'est bien passé, false sinon.
    bool LoadInputs(string path);
};
