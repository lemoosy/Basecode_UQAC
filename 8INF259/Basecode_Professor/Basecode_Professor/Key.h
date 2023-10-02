#pragma once

#include "Settings.h"

/// @brief Classe qui permet de stocker une leçon et son nombre d'occurences.
class Key
{
public:

    /// @brief Leçon.
    string m_lesson;

    /// @brief Nombre d'occurences.
    int m_occ;

    Key(string lesson, int occ)
    {
		m_lesson = lesson;
		m_occ = occ;
	}

    friend bool operator==(const Key& k1, const Key& k2)
    {
        return (k2.m_lesson == k2.m_lesson);
    }
};
