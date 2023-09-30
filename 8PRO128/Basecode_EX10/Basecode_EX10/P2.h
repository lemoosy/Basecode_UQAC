#pragma once

#include "Settings.h"
#include "P1.h"

class Employee
{
private:

	Person person;
	double salary;

public:

	Employee();
	Employee(string name, double salary);
	
	void SetSalary(double salary);
	
	string GetName() const;
	double GetSalary() const;
};

Employee::Employee()
{
	person = Person();
	salary = 0;
}

inline Employee::Employee(string name, double salary)
{
	this->person = Person(name, 0);
	this->salary = salary;
}

inline void Employee::SetSalary(double salary)
{
	this->salary = salary;
}

inline string Employee::GetName() const
{
	return person.GetName();
}

inline double Employee::GetSalary() const
{
	return salary;
}
