#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include "structures.h"
#include "functions.h"
#include "data.h"
#include "userInterface.h"
using namespace std;

void displayNSpaces(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " ";
	}
}

void displayHeaderStudentsTable(int& maxSize, int& maxSizeNames, int& maxSizeSurnames, int& maxSizeClass, int& maxSizeEmail)
{
	cout << char(201);
	for (int i = 0; i < maxSizeNames; i++)
	{
		cout << char(205);
	}
	cout << char(203);
	for (int i = 0; i < maxSizeSurnames; i++)
	{
		cout << char(205);
	}
	cout << char(203);
	for (int i = 0; i < maxSizeClass; i++)
	{
		cout << char(205);
	}
	cout << char(203);
	for (int i = 0; i < maxSizeEmail; i++)
	{
		cout << char(205);
	}
	cout << char(187) << endl;
	cout << char(186) << "Name";
	displayNSpaces(maxSizeNames - 4);
	cout << char(186) << "Surname";
	displayNSpaces(maxSizeSurnames - 7);
	cout << char(186) << "Class";
	displayNSpaces(maxSizeClass - 5);
	cout << char(186) << "Email";
	displayNSpaces(maxSizeEmail - 5);
	cout << char(186) << endl;
}

void displayBodyStudentsTable(vector<STUDENT>& students, int& maxSize, int& maxSizeNames, int& maxSizeSurnames, int& maxSizeClass, int& maxSizeEmail)
{
	for (size_t i = 0; i < students.size(); i++)
	{
		cout << char(204);
		for (int i = 0; i < maxSizeNames; i++)
		{
			cout << char(205);
		}
		cout << char(206);
		for (int i = 0; i < maxSizeSurnames; i++)
		{
			cout << char(205);
		}
		cout << char(206);
		for (int i = 0; i < maxSizeClass; i++)
		{
			cout << char(205);
		}
		cout << char(206);
		for (int i = 0; i < maxSizeEmail; i++)
		{
			cout << char(205);
		}
		cout << char(185) << endl;
		cout << char(186) << students[i].name;
		displayNSpaces(maxSizeNames - students[i].name.size());
		cout << char(186) << students[i].surname;
		displayNSpaces(maxSizeSurnames - students[i].surname.size());
		cout << char(186) << students[i].grade;
		displayNSpaces(maxSizeClass - students[i].grade.size());
		cout << char(186) << students[i].email;
		displayNSpaces(maxSizeEmail - students[i].email.size());
		cout << char(186) << endl;
	}
}

void displayFooterStudentsTable(int& maxSize, int& maxSizeNames, int& maxSizeSurnames, int& maxSizeClass, int& maxSizeEmail)
{
	cout << char(200);
	for (int i = 0; i < maxSizeNames; i++)
	{
		cout << char(205);
	}
	cout << char(202);
	for (int i = 0; i < maxSizeSurnames; i++)
	{
		cout << char(205);
	}
	cout << char(202);
	for (int i = 0; i < maxSizeClass; i++)
	{
		cout << char(205);
	}
	cout << char(202);
	for (int i = 0; i < maxSizeEmail; i++)
	{
		cout << char(205);
	}
	cout << char(188) << endl;
}

void displayStudentsInTable(vector<STUDENT>& students)
{
	int maxSizeNames, maxSizeSurnames, maxSizeEmail, maxSizeClass, maxSize;
	vector<string> names, surnames, emails, classes;
	for (size_t i = 0; i < students.size(); i++)
	{
		names.push_back(students[i].name);
		surnames.push_back(students[i].surname);
		emails.push_back(students[i].email);
		classes.push_back(students[i].grade);
	}
	maxSizeNames = maxSizeOfStrings(names);
	maxSizeSurnames = maxSizeOfStrings(surnames);
	maxSizeEmail = maxSizeOfStrings(emails);
	maxSizeClass = maxSizeOfStrings(classes);
	maxSize = maxSizeClass + maxSizeEmail + maxSizeNames + maxSizeSurnames;
	displayHeaderStudentsTable(maxSize, maxSizeNames, maxSizeSurnames, maxSizeClass, maxSizeEmail);
	displayBodyStudentsTable(students, maxSize, maxSizeNames, maxSizeSurnames, maxSizeClass, maxSizeEmail);
	displayFooterStudentsTable(maxSize, maxSizeNames, maxSizeSurnames, maxSizeClass, maxSizeEmail);
}

bool menu(vector<STUDENT>& students, vector<TEACHER>& teachers, vector<string>& whiteListedRoles, vector<TEAM>& teams)
{
	system("chcp 65001");
	cout << endl << u8R"( 
    ████████╗███████╗ █████╗ ███╗   ███╗███████╗ ██████╗ ███╗   ██╗██████╗ ██╗   ██╗██████╗  ██████╗ ███████╗████████╗
    ╚══██╔══╝██╔════╝██╔══██╗████╗ ████║██╔════╝██╔═══██╗████╗  ██║██╔══██╗██║   ██║██╔══██╗██╔════╝ ██╔════╝╚══██╔══╝
       ██║   █████╗  ███████║██╔████╔██║███████╗██║   ██║██╔██╗ ██║██████╔╝██║   ██║██║  ██║██║  ███╗█████╗     ██║   
       ██║   ██╔══╝  ██╔══██║██║╚██╔╝██║╚════██║██║   ██║██║╚██╗██║██╔══██╗██║   ██║██║  ██║██║   ██║██╔══╝     ██║   
       ██║   ███████╗██║  ██║██║ ╚═╝ ██║███████║╚██████╔╝██║ ╚████║██████╔╝╚██████╔╝██████╔╝╚██████╔╝███████╗   ██║   
       ╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝╚═════╝  ╚═════╝ ╚═════╝  ╚═════╝ ╚══════╝   ╚═╝   
                                                                                                                  
        )";
	system("chcp 850");
	cout << endl;
	cout << "/-----------------------------------\\" << endl;
	cout << "Welcome to the Menu!" << endl;
	cout << "(1) |Add Students|" << endl;
	cout << "(2) |Add Teachers|" << endl;
	cout << "(3) |Add Roles|" << endl;
	cout << "\\-----------------------------------/" << endl;

	int option, amount, counter = 0;
	cout << "->: "; cin >> option;


	switch (option)
	{
	case 1:
		cout << "Enter the amount of students: "; cin >> amount;
		while (counter < amount)
		{
			cin.ignore();
			students.push_back(inputStudent(students, teachers));
			writeStudentsInTxt(students);
			counter++;
		}
		counter = 0;
		break;

	case 2:
		cout << "Enter the amount of teachers: "; cin >> amount;
		while (counter < amount)
		{
			cin.ignore();
			teachers.push_back(inputTeacher(students, teachers));
			writeTeachersInTxt(teachers);
			counter++;
		}
		counter = 0;
		break;

	case 3:
		cout << "Enter the amount of teams: "; cin >> amount;
		while (counter < amount)
		{
			cin.ignore();
			teams.push_back(inputTeam(whiteListedRoles, students, teachers));
			writeRolesInTxt(whiteListedRoles);
			writeTeamsInTxt(teams);

			counter++;
		}
		counter = 0;
		break;
	case 4:
		displayStudentsInTable(students);
		break;
	case 9: return false;
	default:
		cout << endl;
		cout << "|--------------------------|" << endl;
		cout << "Incorrect input, try again!" << endl;
		cout << "|--------------------------|" << endl;
	}
	return true;
}

/*
void mainMenu(string adminEmail, string adminPass, vector<STUDENT> students, vector<TEACHER> teachers, vector<string> whiteListedRoles, vector<TEAM> teams)
{
	bool flag = false;
	string em, pass;

	while (flag == false)
	{
		system("cls");
		cout << endl << u8R"(
	████████╗███████╗ █████╗ ███╗   ███╗███████╗ ██████╗ ███╗   ██╗██████╗ ██╗   ██╗██████╗  ██████╗ ███████╗████████╗
	╚══██╔══╝██╔════╝██╔══██╗████╗ ████║██╔════╝██╔═══██╗████╗  ██║██╔══██╗██║   ██║██╔══██╗██╔════╝ ██╔════╝╚══██╔══╝
	   ██║   █████╗  ███████║██╔████╔██║███████╗██║   ██║██╔██╗ ██║██████╔╝██║   ██║██║  ██║██║  ███╗█████╗     ██║
	   ██║   ██╔══╝  ██╔══██║██║╚██╔╝██║╚════██║██║   ██║██║╚██╗██║██╔══██╗██║   ██║██║  ██║██║   ██║██╔══╝     ██║
	   ██║   ███████╗██║  ██║██║ ╚═╝ ██║███████║╚██████╔╝██║ ╚████║██████╔╝╚██████╔╝██████╔╝╚██████╔╝███████╗   ██║
	   ╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝╚═════╝  ╚═════╝ ╚═════╝  ╚═════╝ ╚══════╝   ╚═╝

		)";

		cout << u8R"(

											╔═════════════════════════════╗
											║                             ║
											║  EMAIL:                     ║
											║                             ║
											║  PASSW:                     ║
											║                             ║
											╚═════════════════════════════╝
		)";

		getline(cin, em);
		getline(cin, pass);

		if (em == adminEmail and pass == adminPass)
		{
			do {
				showMainMenu = menu(students, teachers, whiteListedRoles, teams);
			} while (showMainMenu != false);
		}
		else
		{
			flag = false;
		}
	}
}
*/