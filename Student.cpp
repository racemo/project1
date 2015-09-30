/*
 * Praktikum Informatik 1
 * Versuch 6.1: Templates und �berladen von Operatoren
 *
 * Datei:  Student.cpp
 * Inhalt: Studentenklasse mit Merkmalen eines Studenten
 */

#include "Student.h"

/**
 * @brief Standard constructor
 */
Student::Student()
{
	matNr = 0;
}

/**
 * @brief Constructor
 * @param matriculationnumber The matriculation number of the student.
 * @param name The name of the Student.
 * @param firstname The first name of the Student.
 */
Student::Student(const int matriculationnumber, const std::string name, const std::string firstname, const std::string date_of_birth):
	matNr(matriculationnumber), name(name), firstname(firstname), date_of_birth(date_of_birth)
{
}

/**
 * @brief Operator for comparing two Students.
 *
 * Operator == checks if two students have the same immatriculation number.
 *
 * @param stud Student to compare with.
 * @return If two students are the same true. Else false.
 */
bool Student::operator == (const Student& stud)
{
	if (matNr == stud.matNr)
		return true;
	else 
		return false;
}

/**
 * @brief Operator for comparing two Students.
 *
 * Operator <= checks if (this) student has immatriculation number smaller or equal to
 * the argument student.
 *
 * @param stud Student to compare with.
 * @return true if (this) student <= parameter student. Else false.
 */

bool Student::operator <= (const Student &stud)
{
	if(matNr <= stud.matNr)
		return true;
	else
		return false;
}

/**
 * @brief Operator for comparing two Students.
 *
 * Operator >= checks if (this) student has immatriculation number smaller or equal to
 * the argument student.
 * @param stud Student to compare with.
 * @return true if (this) student >= parameter student. Else false.
 */

bool Student::operator >= (const Student &stud)
{
	if(matNr >= stud.matNr)
		return true;
	else
		return false;
}

std::ostream& operator<< (std::ostream& out, Student &stud)
{
	/**
	 * Since operator<< is a friend of the Student class, we can access
	 * Student's members directly.
	*/
	out << stud.matNr << ", " << stud.name << ", " << stud.firstname << ", " <<
	stud.date_of_birth << std::endl;

	return out;
}
