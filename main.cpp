/*
 * Praktikum Informatik 1
 * Versuch 6.1: Templates und �berladen von Operatoren
 *
 * Datei:  main.cpp
 * Inhalt: Hauptprogramm
 */

#include <iostream>
#include <string>
#include "Student.h"
#include "StackSpeicher.h"

int main()
{
	
	Student stud1(222222, "Lustig", "Peter", "21.9.1990");
	Student stud2(222222, "Lustig", "Peter", "21.9.1990");
	Student stud3(100001, "Super", "Mario", "1.10.1992");
	Student stud4(190019, "Guybrush", "Threepwood", "21.9.1998");
	Student stud5(808070, "Bilbo", "Baggins", "21.9.1987");
	Student stud6(666666, "A Wizard", "of Earthsea", "21.9.1991");
	Student stud7(432574, "Musashi", "Miyamoto", "21.9.1977");

	if (stud1 == stud2)
	{
		std::cout << "Stud1 und Stud2 sind gleich" << std::endl;
	}
	else
	{
		std::cout << "Stud1 und Stud2 sind nicht gleich" << std::endl;
	}
	
	StackSpeicher <7, Student> stack;

	stack.push(stud1);
	stack.push(stud2);
	stack.push(stud3);
	stack.push(stud4);
	stack.push(stud5);
	stack.push(stud6);
	stack.push(stud7);

	stack.sort();

	std::cout << stud7 << std::endl;

	return 0;
}
