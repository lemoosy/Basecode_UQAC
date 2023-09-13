#include "Bank.h"

Bank::Bank()
{
	m_users = new AVLTree<User>;
}

Bank::~Bank()
{
	delete m_users;
}

bool Bank::UserExist(string mail) const
{
	User* userSearch = new User(mail);

	bool found = m_users->IsIn(userSearch);

	delete userSearch;

	return found;
}

User* Bank::Connect(string mail, string password) const
{
	User* userSearch = new User(mail);

	AVLNode<User>* res = nullptr;
	bool found = m_users->Find(userSearch, &res);

	delete userSearch;

	if (found)
	{
		User* userFound = res->m_value;

		if (userFound->SamePassword(password))
		{
			return userFound;
		}
	}

	return nullptr;
}

bool Bank::AddUser(User* user)
{
	assert(user);

	return m_users->Insert(user);
}

bool Bank::RemoveUser(User* user)
{
	assert(user);

	return m_users->Remove(user);
}
