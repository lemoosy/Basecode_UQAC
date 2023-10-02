#include "Professor.h"



Professor::Professor()
{
	m_name = "";
	m_date = 0;
	m_lessons = new List<string>;
	m_students = new List<string>;
}

Professor::~Professor()
{
	delete m_lessons;
	delete m_students;
}




int Professor::GetNbLesson() const
{
	return m_lessons->m_size;
}

int Professor::GetNbStudent() const
{
	return m_students->m_size;
}



void Professor::Print(void) const
{
	cout << "name\t\t" << m_name << endl;

	cout << "date\t\t" << m_date << endl;
	
	cout << "lessons\t\t";
	m_lessons->Print();
	cout << endl;

	cout << "students\t";
	m_students->Print();
	cout << endl;
}



void Professor::AddLesson(string lesson)
{
	string* valueInsert = new string(lesson);

	m_lessons->InsertFirst(valueInsert);
}

void Professor::AddStudent(string student)
{
	string* valueInsert = new string(student);

	m_students->InsertFirst(valueInsert);
}



bool Professor::HasLesson(string lesson) const
{
	return (m_lessons->IsIn(&lesson) != nullptr);
}



void Professor::Export(ofstream& file) const
{
	file << m_name << endl;
	file << m_date << endl;

	ListNode<string>* current = m_lessons->m_first;

	while (current)
	{
		file << *(current->m_value) << endl;
		current = current->m_next;
	}

	file << "&" << endl;

	current = m_students->m_first;

	while (current)
	{
		file << *(current->m_value) << endl;
		current = current->m_next;
	}

	file << "&" << endl;
}



ostream& operator<<(ostream& stream, Professor& professor)
{
	professor.Print();

	return stream;
}
