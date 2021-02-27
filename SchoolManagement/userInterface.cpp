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

void displayHeaderTable(int& maxSize, int& maxSizeNames, int& maxSizeSurnames, int& maxSizeClass, int& maxSizeEmail,string object)
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
	cout << char(186) << object;
	displayNSpaces(maxSizeClass - object.size());
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
void displayBodyTeachersTable(vector<TEACHER>& teachers, int& maxSize, int& maxSizeNames, int& maxSizeSurnames, int& maxSizeClass, int& maxSizeEmail,vector<string> teams)
{
	for (size_t i = 0; i < teachers.size(); i++)
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
		cout << char(186) << teachers[i].name;
		displayNSpaces(maxSizeNames - teachers[i].name.size());
		cout << char(186) << teachers[i].surname;
		displayNSpaces(maxSizeSurnames - teachers[i].surname.size());
		cout << char(186) << teams[i];
		displayNSpaces(maxSizeClass - teams[i].size());
		cout << char(186) << teachers[i].email;
		displayNSpaces(maxSizeEmail - teachers[i].email.size());
		cout << char(186) << endl;
	}
}
void displayFooterTable(int& maxSize, int& maxSizeNames, int& maxSizeSurnames, int& maxSizeClass, int& maxSizeEmail)
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
	displayHeaderTable(maxSize, maxSizeNames, maxSizeSurnames, maxSizeClass, maxSizeEmail,"Class");
	displayBodyStudentsTable(students, maxSize, maxSizeNames, maxSizeSurnames, maxSizeClass, maxSizeEmail);
	displayFooterTable(maxSize, maxSizeNames, maxSizeSurnames, maxSizeClass, maxSizeEmail);
}
void displayTeachersInTable(vector<TEACHER>& teachers)
{
	int maxSizeNames, maxSizeSurnames, maxSizeEmail, maxSizeTeams, maxSize;
	vector<string> names, surnames, emails, teams;
	string team;
	for (size_t i = 0; i < teachers.size(); i++)
	{
		names.push_back(teachers[i].name);
		surnames.push_back(teachers[i].surname);
		for (size_t j = 0; j < teachers[i].teams.size(); j++)
		{
			team += teachers[i].teams[j];
			if (j < teachers[i].teams.size() - 1)
			{
				team += ',';
			}
		}
		teams.push_back(team);
		emails.push_back(teachers[i].email);
	}
	maxSizeNames = maxSizeOfStrings(names);
	maxSizeSurnames = maxSizeOfStrings(surnames);
	maxSizeEmail = maxSizeOfStrings(emails);
	maxSizeTeams = maxSizeOfStrings(teams);
	maxSize = maxSizeTeams + maxSizeEmail + maxSizeNames + maxSizeSurnames;
	displayHeaderTable(maxSize, maxSizeNames, maxSizeSurnames, maxSizeTeams, maxSizeEmail,"Teams");
	displayBodyTeachersTable(teachers, maxSize, maxSizeNames, maxSizeSurnames, maxSizeTeams, maxSizeEmail,teams);
	displayFooterTable(maxSize, maxSizeNames, maxSizeSurnames, maxSizeTeams, maxSizeEmail);
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
	system("chcp 437");
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
		cin.ignore();
		while (counter < amount)
		{
			students.push_back(inputStudent(students, teachers));
			writeStudentsInTxt(students);
			counter++;
		}
		counter = 0;
		break;

	case 2:
		cout << "Enter the amount of teachers: "; cin >> amount;
		cin.ignore();
		while (counter < amount)
		{
			teachers.push_back(inputTeacher(students, teachers));
			writeTeachersInTxt(teachers);
			counter++;
		}
		counter = 0;
		break;

	case 3:
		cout << "Enter the amount of teams: "; cin >> amount;
		cin.ignore();
		while (counter < amount)
		{
			addRole(whiteListedRoles);
			writeRolesInTxt(whiteListedRoles);

			counter++;
		}
		counter = 0;
		break;
	case 4: 
		teams.push_back(inputTeam(whiteListedRoles, students, teachers));
		writeTeamsInTxt(teams);
		break;
	case 5:
		displayStudentsInTable(students);
		break;
	case 6:
		displayTeachersInTable(teachers);
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