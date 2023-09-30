#pragma once

#include "Settings.h"

class Person
{

private:

	string name; /* "" si inconnu */

	int age; /* 0 si inconnu */

public:

	Person();

	Person(string name, int age);

	string GetName() const;

	int GetAge() const;
};

Person::Person()
{
	name = "";
	age = 0;
}

inline Person::Person(string name, int page)
{
	this->name = name;
	this->age = page;
}

inline string Person::GetName() const
{
	return name;
}

inline int Person::GetAge() const
{
	return age;
}
