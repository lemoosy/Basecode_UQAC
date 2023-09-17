#pragma once

#include "Settings.h"

/// @brief Classe représentant un noeud dans un arbre (AVL).
template <typename AVLData>
class AVLNode
{
public:

	/// @brief Valeur du noeud.
	AVLData* m_value;

	/// @brief Pointeur vers le parent.
	AVLNode<AVLData>* m_parent;

	/// @brief Pointeur vers l'enfant de gauche.
	AVLNode<AVLData>* m_left;

	/// @brief Pointeur vers l'enfant de droite.
	AVLNode<AVLData>* m_right;

	/// @brief Hauteur du noeud.
	int m_height;

	AVLNode(AVLData* value);

	/// @brief Détruit la valeur du noeud et le noeud.
	~AVLNode();

	/// @brief Détruit le sous-arbre du noeud (méthode récursive).
	void DestroyRec(void);

	/// @brief Lie un noeud à gauche du noeud.
	void SetLeft(AVLNode<AVLData>* node);

	/// @brief Lie un noeud à droite du noeud.
	void SetRight(AVLNode<AVLData>* node);

	/// @brief Met à jour la hauteur du noeud [max(L, R) + 1].
	void UpdateHeight(void);

	/// @brief Renvoie la différence de hauteur entre
	/// l'enfant de gauche et l'enfant de droite.
	int GetBalance(void) const;

	/// @brief Affiche le noeud et son sous-arbre sous forme d'une liste (méthode récursive).
	void PrintListRec(void) const;

	/// @brief Affiche le noeud et son sous-arbre sous forme d'un arbre (méthode récursive).
	void PrintTreeRec(int level = 0) const;
};

template <typename AVLData>
AVLNode<AVLData>::AVLNode(AVLData* value)
{
	m_value = value;
	m_parent = nullptr;
	m_left = nullptr;
	m_right = nullptr;
	m_height = 0;
}

template<typename AVLData>
AVLNode<AVLData>::~AVLNode()
{
	if (m_value)
	{
		delete m_value;
	}
}

template<typename AVLData>
void AVLNode<AVLData>::DestroyRec(void)
{
	if (m_left)
	{
		m_left->DestroyRec();
		delete m_left;
	}

	if (m_right)
	{
		m_right->DestroyRec();
		delete m_right;
	}
}

template <typename AVLData>
void AVLNode<AVLData>::SetLeft(AVLNode<AVLData>* node)
{
	m_left = node;

	if (node)
	{
		node->m_parent = this;
	}
}

template <typename AVLData>
void AVLNode<AVLData>::SetRight(AVLNode<AVLData>* node)
{
	m_right = node;

	if (node)
	{
		node->m_parent = this;
	}
}

template <typename AVLData>
void AVLNode<AVLData>::UpdateHeight(void)
{
	int L = (m_left ? m_left->m_height : -1);
	int R = (m_right ? m_right->m_height : -1);

	m_height = max(L, R) + 1;
}

template <typename AVLData>
int AVLNode<AVLData>::GetBalance(void) const
{
	int L = (m_left ? m_left->m_height : -1);
	int R = (m_right ? m_right->m_height : -1);

	return (R - L);
}

template <typename AVLData>
void AVLNode<AVLData>::PrintListRec(void) const
{
	if (m_left)
	{
		m_left->PrintListRec();
	}

	cout << *m_value << " ";

	if (m_right)
	{
		m_right->PrintListRec();
	}
}

template<typename AVLData>
void AVLNode<AVLData>::PrintTreeRec(int level) const
{
	if (m_right)
	{
		m_right->PrintTreeRec(level + 1);
	}

	for (int i = 0; i < level; i++)
	{
		putchar('\t');
	}

	cout << *m_value << endl;

	if (m_left)
	{
		m_left->PrintTreeRec(level + 1);
	}
}

/// @brief Classe représentant un arbre (AVL).
template <typename AVLData>
class AVLTree
{
private:

	/// @brief Nombre de noeuds dans l'arbre.
	int m_size;

	/// @brief Racine de l'arbre.
	AVLNode<AVLData>* m_root;
	
	/// @brief Remplace 'oldChild' par 'newChild',
	/// 'parent' est le parent de 'oldChild'.
	void Replace(AVLNode<AVLData>* parent, AVLNode<AVLData>* oldChild, AVLNode<AVLData>* newChild);

	/// @brief Fait une rotation à gauche (ce noeud et son enfant de droite).
	void RotateLeft(AVLNode<AVLData>* node);

	/// @brief Fait une rotation à droite (ce noeud et son enfant de gauche).
	void RotateRight(AVLNode<AVLData>* node);

	/// @brief Ré-équilibre l'arbre à partir d'un noeud jusqu'à la racine.
	void Balance(AVLNode<AVLData>* node);

public:

	AVLTree();

	~AVLTree();

	/// @brief Renvoie la taille de l'arbre (nombre de noeuds).
	inline int GetSize() const
	{
		return m_size;
	}

	/// @brief Vérifie si l'arbre est vide.
	inline bool IsEmpty() const
	{
		return (m_size == 0);
	}

	/// @brief Recherche une valeur dans l'arbre en log(n).
	/// @return true si la valeur existe, false sinon.
	bool Find(AVLData* value, AVLNode<AVLData>** res) const;

	/// @brief Insère une valeur dans l'arbre en log(n).
	/// @return true si la valeur est insérée, false sinon (existe déjà).
	bool Insert(AVLData* value);

	/// @brief Vérifie si une valeur est dans l'arbre en log(n).
	/// @return true si la valeur se trouve dans l'arbre, false sinon.
	bool IsIn(AVLData* value) const;

	/// @brief Supprime une valeur dans l'arbre en log(n).
	/// @return true si la valeur est supprimée, false sinon (n'existe pas).
	bool Remove(AVLData* value);

	/// @brief Affiche les données sous forme d'une liste.
	void PrintList(void) const;

	/// @brief Affiche les données sous forme d'un arbre.
	void PrintTree(void) const;
};

template <typename AVLData>
void AVLTree<AVLData>::Replace(AVLNode<AVLData>* parent, AVLNode<AVLData>* oldChild, AVLNode<AVLData>* newChild)
{
	if (parent)
	{
		if (parent->m_left == oldChild)
		{
			parent->SetLeft(newChild);
		}
		else
		{
			parent->SetRight(newChild);
		}
	}
	else
	{
		if (newChild)
		{
			newChild->m_parent = nullptr;
		}

		m_root = newChild;
	}
}

template <typename AVLData>
void AVLTree<AVLData>::RotateLeft(AVLNode<AVLData>* node)
{
	AVLNode<AVLData>* parent = node->m_parent;
	AVLNode<AVLData>* child = node->m_right;

	node->SetRight(child->m_left);
	child->SetLeft(node);
	Replace(parent, node, child);

	node->UpdateHeight();
	child->UpdateHeight();
}

template <typename AVLData>
void AVLTree<AVLData>::RotateRight(AVLNode<AVLData>* node)
{
	AVLNode<AVLData>* parent = node->m_parent;
	AVLNode<AVLData>* child = node->m_left;

	node->SetLeft(child->m_right);
	child->SetRight(node);
	Replace(parent, node, child);

	node->UpdateHeight();
	child->UpdateHeight();
}

template <typename AVLData>
void AVLTree<AVLData>::Balance(AVLNode<AVLData>* node)
{
	while (node)
	{
		node->UpdateHeight();

		int balance = node->GetBalance();

		if (balance == +2)
		{
			if (node->m_right->GetBalance() == -1)
			{
				RotateRight(node->m_right);
			}

			RotateLeft(node);
		}
		else if (balance == -2)
		{
			if (node->m_left->GetBalance() == +1)
			{
				RotateLeft(node->m_left);
			}

			RotateRight(node);
		}

		node = node->m_parent;
	}
}

template <typename AVLData>
AVLTree<AVLData>::AVLTree()
{
	m_size = 0;
	m_root = nullptr;
}

template <typename AVLData>
AVLTree<AVLData>::~AVLTree()
{
	if (m_root)
	{
		m_root->DestroyRec();
		delete m_root;
	}
}

template <typename AVLData>
bool AVLTree<AVLData>::Find(AVLData* value, AVLNode<AVLData>** res) const
{
	if (m_root == nullptr)
	{
		*res = nullptr;
		return false;
	}

	AVLNode<AVLData>* curr = m_root;

	while (true)
	{
		if (*value < *(curr->m_value))
		{
			if (curr->m_left == nullptr)
			{
				*res = curr;
				return false;
			}

			curr = curr->m_left;
		}
		else if (*value > *(curr->m_value))
		{
			if (curr->m_right == nullptr)
			{
				*res = curr;
				return false;
			}

			curr = curr->m_right;
		}
		else
		{
			*res = curr;
			return true;
		}
	}
}

template <typename AVLData>
bool AVLTree<AVLData>::Insert(AVLData* value)
{
	if (IsEmpty())
	{
		m_root = new AVLNode<AVLData>(value);
	}
	else
	{
		AVLNode<AVLData>* res = nullptr;

		if (Find(value, &res))
		{
			return false;
		}
		else
		{
			AVLNode<AVLData>* node = new AVLNode<AVLData>(value);

			if (*value < *(res->m_value))
			{
				res->SetLeft(node);
			}
			else
			{
				res->SetRight(node);
			}

			Balance(res);
		}
	}

	m_size++;

	return true;
}

template<typename AVLData>
bool AVLTree<AVLData>::IsIn(AVLData* value) const
{
	AVLNode<AVLData>* res = nullptr;

	return Find(value, &res);
}

template<typename AVLData>
bool AVLTree<AVLData>::Remove(AVLData* value)
{
	AVLNode<AVLData>* res = nullptr;

	if (IsEmpty() || !Find(value, &res))
	{
		return false;
	}

	AVLNode<AVLData>* start = nullptr;

	if (res->m_left == nullptr)
	{
		Replace(res->m_parent, res, res->m_right);
		start = res->m_parent;
		delete res;
	}
	else if (res->m_right == nullptr)
	{
		Replace(res->m_parent, res, res->m_left);
		start = res->m_parent;
		delete res;
	}
	else
	{
		AVLNode<AVLData>* curr = res->m_left;

		while (curr->m_right)
		{
			curr = curr->m_right;
		}

		res->m_value = curr->m_value;
		Replace(curr->m_parent, curr, curr->m_left);
		start = curr->m_parent;
		delete curr;
	}

	Balance(start);

	m_size--;

	return true;
}

template <typename AVLData>
void AVLTree<AVLData>::PrintList(void) const
{
	printf("(size=%d) : ", m_size);

	if (m_root)
	{
		m_root->PrintListRec();
	}

	putchar('\n');
}

template<typename AVLData>
void AVLTree<AVLData>::PrintTree(void) const
{
	printf("(size=%d) : \n", m_size);

	if (m_root)
	{
		m_root->PrintTreeRec();
	}

	putchar('\n');
}
