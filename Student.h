/*
 * Praktikum Informatik 1
 * Versuch 6.1: Templates und �berladen von Operatoren
 *
 * Datei:  Student.h
 * Inhalt: Studentenklasse mit Merkmalen eines Studenten
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>


//Studenten Class
class Student
{
  public:
	Student();
	Student(const int matriculationnumber, const std::string name, const std::string firstname, const std::string date_of_birth);
	bool operator == (const Student &stud);
	bool operator <= (const Student &stud);
	bool operator >= (const Student &stud);

	friend std::ostream& operator<< (std::ostream& out, Student &stud);

  private:
	int matNr;
	std::string name;
	std::string firstname;
	std::string date_of_birth;
};

#endif // STUDENT_H

