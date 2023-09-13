#include "User.h"

User::User()
{
	m_mail = "";
	m_password = "";
	m_money = 0.0f;
	m_name = "";
	m_phone = "";
}

User::User(string mail)
{
	m_mail = mail;
	m_password = "";
	m_money = 0.0f;
	m_name = "";
	m_phone = "";
}

User::User(string mail, string password)
{
	m_mail = mail;
	m_password = password;
	m_money = 0.0f;
	m_name = "";
	m_phone = "";
}

void User::Print() const
{
	cout << "---------- " << m_name << " ----------\n" << endl;

	cout << "Mail\t" << m_mail << endl;
	
	if (m_phone.size() > 0)
	{
		cout << "Phone\t" << m_phone << endl;
	}

	cout << "Monnaie\t" << m_money << endl;
}

void User::AddMoney(float money)
{
	assert(money >= 0.0f);

	m_money += money;
}

void User::RemoveMoney(float money)
{
	assert(money >= 0.0f);

	m_money -= money;
}

bool User::ChangePassword(string passwordOld, string passwordNew)
{
	if (passwordOld != m_password)
	{
		return false;
	}

	m_password = passwordNew;
	
	return true;
}

bool User::SamePassword(string password)
{
	return (m_password == password);
}
