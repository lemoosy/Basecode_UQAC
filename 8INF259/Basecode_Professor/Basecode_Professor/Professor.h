#pragma once

#include "List.h"
#include "Settings.h"

/// @brief Classe représentant un professeur.
class Professor
{
public:



	/// @brief Nom du professeur.
	string m_name;

	/// @brief Nombre d'années d'expérience du professeur.
	int m_date;

	/// @brief Liste des cours du professeur.
	List<string>* m_lessons;

	/// @brief Liste des étudiants qui suivent les cours du professeur.
	List<string>* m_students;



	/// @brief Retourne le nombre de cours du professeur.
	int GetNbLesson() const;

	/// @brief Retourne le nombre d'étudiants qui suivent les cours du professeur.
	int GetNbStudent() const;



	/// @brief Initialise la liste des cours et la liste des étudiants (les listes sont vides).
	Professor();

	/// @brief Détruit la liste des cours et la liste des étudiants.
	~Professor();



	/// @brief Affiche les informations du professeur.
	void Print() const;



	/// @brief Ajoute un cours à la liste des cours du professeur.
	void AddLesson(string lesson);

	/// @brief Ajoute un étudiant à la liste des étudiants qui suivent les cours du professeur.
	void AddStudent(string student);



	/// @brief Vérifie si le professeur enseigne le cours donné en paramètre.
	/// @param lesson Cours à vérifier.
	/// @return true si le professeur enseigne le cours, false sinon.
	bool HasLesson(string lesson) const;



	/// @brief Écris dans un fichier TXT les informations du professeur.
	/// @param file Fichier TXT à écrire.
	void Export(ofstream& file) const;
};



/// @brief Surcharge de l'opérateur << pour afficher les informations du professeur à l'aide de la fonction Print().
ostream& operator<<(ostream& stream, Professor& professor);
