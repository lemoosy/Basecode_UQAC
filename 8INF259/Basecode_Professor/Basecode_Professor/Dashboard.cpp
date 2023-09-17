#include "Dashboard.h"



Dashboard::Dashboard()
{
    m_professors = new List<Professor>;
}

Dashboard::~Dashboard()
{
    delete m_professors;
}



bool Dashboard::ImportProfessors(string path)
{
    ifstream file(path);

    if (file.fail())
    {
        return false;
    }

    string res;

    while (file.eof() == false)
    {
        Professor* professor = new Professor;

        getline(file, res);
        professor->m_name = res;

        getline(file, res);
        professor->m_date = stoi(res);

        while (1)
        {
            getline(file, res);

            if (res == "&")
            {
                break;
            }

            professor->AddLesson(res);
        }

        while (1)
        {
            getline(file, res);

            if (res == "&")
            {
                break;
            }

            professor->AddStudent(res);
        }

        m_professors->InsertFirst(professor);
    }

    file.close();

    return true;
}

bool Dashboard::ExportProfessors(string path)
{
    ofstream file(path);

    if (file.fail())
    {
        return false;
    }

    ListNode<Professor>* current = m_professors->m_first;

    while (current)
    {
        Professor* professor = current->m_value;
        professor->Export(file);
        current = current->m_next;
    }

    return true;
}



void Dashboard::InsertProfessor(Professor* professor)
{
    m_professors->InsertFirst(professor);
}

void Dashboard::RemoveProfessorByName(string name)
{
    ListNode<Professor>* previous = nullptr;
    ListNode<Professor>* current = m_professors->m_first;

    while (current)
    {
        Professor* professor = current->m_value;

        if (professor->m_name == name)
        {
            ListNode<Professor>* next = current->m_next;

            if (previous)
            {
                previous->m_next = next;
            }
            else
            {
                m_professors->m_first = next;
            }

            delete current->m_value;
            delete current;

            m_professors->m_size--;

            current = next;
        }
        else
        {
            previous = current;
            current = current->m_next;
        }
    }
}



Professor* Dashboard::GetProfessorByName(string name) const
{
    ListNode<Professor>* current = m_professors->m_first;

    while (current)
    {
        Professor* professor = current->m_value;

        if (professor->m_name == name)
        {
            return professor;
        }

        current = current->m_next;
    }

    return nullptr;
}

Professor* Dashboard::GetProfessorWithMinimumLessons() const
{
    if (m_professors->IsEmpty())
    {
        return nullptr;
    }

    ListNode<Professor>* minimum = m_professors->m_first;
    ListNode<Professor>* current = minimum->m_next;

    while (current)
    {
        Professor* professorMinimum = minimum->m_value;
        Professor* professorCurrent = current->m_value;

        if (professorCurrent->GetNbLesson() < professorMinimum->GetNbLesson())
        {
            minimum = current;
        }
        else if (professorCurrent->GetNbLesson() == professorMinimum->GetNbLesson())
        {
            if (professorCurrent->m_date < professorMinimum->m_date)
            {
                minimum = current;
            }
        }

        current = current->m_next;
    }

    return minimum->m_value;
}

Professor* Dashboard::GetProfessorWithMinimumStudents() const
{
    if (m_professors->IsEmpty())
    {
        return nullptr;
    }

    ListNode<Professor>* minimum = m_professors->m_first;
    ListNode<Professor>* current = minimum->m_next;

    while (current)
    {
        Professor* professorMinimum = minimum->m_value;
        Professor* professorCurrent = current->m_value;

        if (professorCurrent->GetNbStudent() < professorMinimum->GetNbStudent())
        {
            minimum = current;
        }
        else if (professorCurrent->GetNbStudent() == professorMinimum->GetNbStudent())
        {
            if (professorCurrent->m_date < professorMinimum->m_date)
            {
                minimum = current;
            }
        }

        current = current->m_next;
    }

    return minimum->m_value;
}



int Dashboard::GetOccLessonsByProfessors(string lesson) const
{
    int res = 0;

    ListNode<Professor>* current = m_professors->m_first;

    while (current)
    {
        Professor* professor = current->m_value;
        res += professor->HasLesson(lesson);
        current = current->m_next;
    }

    return res;
}



void Dashboard::PrintProfessors() const
{
    ListNode<Professor>* current = m_professors->m_first;

    while (current)
	{
		Professor* professor = current->m_value;
        cout << professor << endl;
		current = current->m_next;
	}
}



bool Dashboard::LoadInputs(string path)
{
    ifstream file(path);

    if (file.fail())
    {
        return false;
    }

    string line;

    while (file.eof() == false)
    {
        getline(file, line);

        switch (line[0])
        {
        case '-':
        {
            line = line.substr(2);
            RemoveProfessorByName(line);
            cout << "Professor [" << line << "] is removed." << endl;
            break;
        }

        case '#':
        {
            Professor* professor = GetProfessorWithMinimumStudents();
            cout << "Professor with minimum students is [" << professor->m_name << "]." << endl;
            break;
        }

        case '*':
        {
            Professor* professor = GetProfessorWithMinimumLessons();
            cout << "Professor with minimum lessons is [" << professor->m_name << "]." << endl;
            break;
        }

        case '%':
        {
            line = line.substr(2);
            cout << "Lesson [" << line << "] is taken [" << GetOccLessonsByProfessors(line) << "] times by professors." << endl;
            break;
        }

        case '$':
        {
            bool res = ExportProfessors("../Data/FP_new.txt");
            
            if (!res)
            {
                cout << "ERROR - ExportProfessors()" << endl;
                goto LABEL_ERROR;
            }

            cout << "Professors are exported to [FP_new.txt]." << endl;

            break;
        }
        default:
        {
            cout << "ERROR - [" << line[0] << "]" << "is not a valid command." << endl;
            goto LABEL_ERROR;
        }
        }
    }

    file.close();

    return true;

LABEL_ERROR:

    file.close();

    return false;

}
