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

void displayHeaderTeamsTable(int& maxSizeNames, int& maxSizeDescriptions, int& maxSizeDate, vector<int>& maxSizeStudents, int& maxSizeTeachers, int& maxSizeStatus, vector<string>& whiteListedRoles)
{
	cout << char(201);
	for (int i = 0; i < maxSizeNames; i++)
	{
		cout << char(205);
	}
	cout << char(203);
	for (int i = 0; i < maxSizeDescriptions; i++)
	{
		cout << char(205);
	}
	cout << char(203);
	for (int i = 0; i < maxSizeDate; i++)
	{
		cout << char(205);
	}
	cout << char(203);
	for (size_t j = 0; j < whiteListedRoles.size(); j++)
	{
		for (int i = 0; i < maxSizeStudents[j]; i++)
		{
			cout << char(205);
		}
		cout << char(203);
	}
	for (int i = 0; i < maxSizeTeachers; i++)
	{
		cout << char(205);
	}
	cout << char(203);
	for (int i = 0; i < maxSizeStatus; i++)
	{
		cout << char(205);
	}
	cout << char(187) << endl;


	cout << char(186) << "Team";
	displayNSpaces(maxSizeNames - 4);
	cout << char(186) << "Description";
	displayNSpaces(maxSizeDescriptions - 11);
	cout << char(186) << "Date of setup";
	displayNSpaces(maxSizeDate - 13);
	for (size_t i = 0; i < whiteListedRoles.size(); i++)
	{
		cout << char(186) << whiteListedRoles[i];
		displayNSpaces(maxSizeStudents[i] - whiteListedRoles[i].size());
	}
	cout << char(186) << "Teacher";
	displayNSpaces(maxSizeTeachers - 7);
	cout << char(186) << "Status";
	displayNSpaces(maxSizeStatus - 6);
	cout << char(186) << endl;
}

void displayBodyTeamsTable(vector<TEAM>& teams,int& maxSizeNames, int& maxSizeDescriptions, int& maxSizeDate, vector<int>& maxSizeStudents, int& maxSizeTeachers, int& maxSizeStatus)
{
	for (size_t i = 0; i < teams.size(); i++)
	{
		cout << char(204);
		for (int i = 0; i < maxSizeNames; i++)
		{
			cout << char(205);
		}
		cout << char(206);
		for (int i = 0; i < maxSizeDescriptions; i++)
		{
			cout << char(205);
		}
		cout << char(206);
		for (int i = 0; i < maxSizeDate; i++)
		{
			cout << char(205);
		}
		cout << char(206);
		for (size_t j = 0; j < maxSizeStudents.size(); j++)
		{
			for (int i = 0; i < maxSizeStudents[j]; i++)
			{
				cout << char(205);
			}
			cout << char(206);
		}
		for (int i = 0; i < maxSizeTeachers; i++)
		{
			cout << char(205);
		}
		cout << char(206);
		for (int i = 0; i < maxSizeStatus; i++)
		{
			cout << char(205);
		}
		cout << char(185) << endl;


		cout << char(186) << teams[i].teamName;
		displayNSpaces(maxSizeNames - teams[i].teamName.size());
		cout << char(186) << teams[i].description;
		displayNSpaces(maxSizeDescriptions - teams[i].description.size());
		cout << char(186) << teams[i].dateCreation;
		displayNSpaces(maxSizeDate - teams[i].dateCreation.size());
		cout << char(186);
		for (size_t j = 0; j < maxSizeStudents.size(); j++)
		{
			cout << teams[i].roles[j].student.name << ' ' << teams[i].roles[j].student.surname;
			displayNSpaces(maxSizeStudents[j] - (teams[i].roles[j].student.name.size() + teams[i].roles[j].student.surname.size() + 1));
			cout << char(186);
		}
		cout << teams[i].teacher.name << ' ' << teams[i].teacher.surname;
		displayNSpaces(maxSizeTeachers - (teams[i].teacher.name.size() + teams[i].teacher.surname.size() + 1));
		cout << char(186) << teams[i].status;
		displayNSpaces(maxSizeStatus - teams[i].status.size());
		cout << char(186) << endl;
	}
}

void displayFooterTeamsTable(int& maxSizeNames, int& maxSizeDescriptions, int& maxSizeDate, vector<int>& maxSizeStudents, int& maxSizeTeachers, int& maxSizeStatus)
{
	cout << char(200);
	for (int i = 0; i < maxSizeNames; i++)
	{
		cout << char(205);
	}
	cout << char(202);
	for (int i = 0; i < maxSizeDescriptions; i++)
	{
		cout << char(205);
	}
	cout << char(202);
	for (int i = 0; i < maxSizeDate; i++)
	{
		cout << char(205);
	}
	cout << char(202);
	for (size_t i = 0; i < maxSizeStudents.size(); i++)
	{
		for (int j = 0; j < maxSizeStudents[i]; j++)
		{
			cout << char(205);
		}
		cout << char(202);
	}
	for (int i = 0; i < maxSizeTeachers; i++)
	{
		cout << char(205);
	}
	cout << char(202);
	for (int i = 0; i < maxSizeStatus; i++)
	{
		cout << char(205);
	}
	cout << char(188) << endl;
}

void displayTeamsInTable(vector<TEAM>& teams, vector<string> whiteListedRoles)
{
	if (teams.size() > 0)
	{
		int maxSizeNames, maxSizeDescriptions, maxSizeDate, maxSizeTeachers, maxSizeStatus, maxSize = 0;

		vector<int> maxSizeStudents;

		vector<string> teamNames, descriptions, dates, teacherNames, status, studentNames;

		for (size_t i = 0; i < teams.size(); i++)
		{
			teamNames.push_back(teams[i].teamName);
			descriptions.push_back(teams[i].description);
			dates.push_back(teams[i].dateCreation);
			teacherNames.push_back(teams[i].teacher.name + ' ' + teams[i].teacher.surname);
			status.push_back(teams[i].status);
		}

		teamNames.push_back("Team");
		descriptions.push_back("Description");
		dates.push_back("Date of setup");
		teacherNames.push_back("Teacher");
		status.push_back("status");

		for (size_t i = 0; i < whiteListedRoles.size(); i++)
		{
			for (size_t j = 0; j < teams.size(); j++)
			{
				studentNames.push_back(teams[j].roles[i].student.name + ' ' + teams[j].roles[i].student.surname);
			}

			studentNames.push_back(whiteListedRoles[i]);

			maxSizeStudents.push_back(maxSizeOfStrings(studentNames));
			maxSize += maxSizeStudents[i];
			studentNames.clear();
		}

		maxSizeNames = maxSizeOfStrings(teamNames);
		maxSizeDescriptions = maxSizeOfStrings(descriptions);
		maxSizeDate = maxSizeOfStrings(dates);
		maxSizeTeachers = maxSizeOfStrings(teacherNames);
		maxSizeStatus = maxSizeOfStrings(status);

		maxSize = maxSizeDate + maxSizeNames + maxSizeDescriptions + maxSizeTeachers + maxSizeStatus;

		displayHeaderTeamsTable(maxSizeNames, maxSizeDescriptions, maxSizeDate, maxSizeStudents, maxSizeTeachers, maxSizeStatus, whiteListedRoles);
		displayBodyTeamsTable(teams,maxSizeNames, maxSizeDescriptions, maxSizeDate, maxSizeStudents, maxSizeTeachers, maxSizeStatus);
		displayFooterTeamsTable(maxSizeNames, maxSizeDescriptions, maxSizeDate, maxSizeStudents, maxSizeTeachers, maxSizeStatus);
	}
	else
	{
		cout << "There are 0 teams" << endl;
	}
}

void displayHeaderStudentsAndTeachersTable(int& maxSize, int& maxSizeNames, int& maxSizeSurnames, int& maxSizeObject, int& maxSizeEmail, string object)
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

	for (int i = 0; i < maxSizeObject; i++)
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
	displayNSpaces(maxSizeObject - object.size());
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

void displayBodyTeachersTable(vector<TEACHER>& teachers, int& maxSize, int& maxSizeNames, int& maxSizeSurnames, int& maxSizeClass, int& maxSizeEmail, vector<string> teams)
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

	names.push_back("Name");
	surnames.push_back("Surname");
	classes.push_back("Class");
	emails.push_back("Email");

	maxSizeNames = maxSizeOfStrings(names);
	maxSizeSurnames = maxSizeOfStrings(surnames);
	maxSizeEmail = maxSizeOfStrings(emails);
	maxSizeClass = maxSizeOfStrings(classes);

	maxSize = maxSizeClass + maxSizeEmail + maxSizeNames + maxSizeSurnames;

	displayHeaderStudentsAndTeachersTable(maxSize, maxSizeNames, maxSizeSurnames, maxSizeClass, maxSizeEmail, "Class");
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

	names.push_back("Name");
	surnames.push_back("Surname");
	teams.push_back("Teams");
	emails.push_back("Email");

	maxSizeNames = maxSizeOfStrings(names);
	maxSizeSurnames = maxSizeOfStrings(surnames);
	maxSizeEmail = maxSizeOfStrings(emails);
	maxSizeTeams = maxSizeOfStrings(teams);

	maxSize = maxSizeTeams + maxSizeEmail + maxSizeNames + maxSizeSurnames;

	displayHeaderStudentsAndTeachersTable(maxSize, maxSizeNames, maxSizeSurnames, maxSizeTeams, maxSizeEmail, "Teams");
	displayBodyTeachersTable(teachers, maxSize, maxSizeNames, maxSizeSurnames, maxSizeTeams, maxSizeEmail, teams);
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
		cout << "Enter the amount of roles: "; cin >> amount;
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
	case 7: displayTeamsInTable(teams, whiteListedRoles);
		break;
	case 8: 
		try
		{
			deleteStudentData(students);
		}
		catch (const std::exception& ex)
		{
			cout << ex.what();
		}
		break;
	case 9:
		try
		{
			updateStudentData(students);
		}
		catch (const std::exception& ex)
		{
			cout << ex.what();
		}
		break;
	case 10: return false;
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