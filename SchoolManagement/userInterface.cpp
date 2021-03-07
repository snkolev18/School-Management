#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include "structures.h"
#include "data.h"
#include "userInterface.h"
#include "checkers.h"
using namespace std;

void clearScreen()
{

#ifdef __linux__
	system("clear");
#else WIN32
	system("cls");
#endif

}


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

void displayBodyTeamsTable(vector<TEAM>& teams, int& maxSizeNames, int& maxSizeDescriptions, int& maxSizeDate, vector<int>& maxSizeStudents, int& maxSizeTeachers, int& maxSizeStatus)
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
		displayBodyTeamsTable(teams, maxSizeNames, maxSizeDescriptions, maxSizeDate, maxSizeStudents, maxSizeTeachers, maxSizeStatus);
		displayFooterTeamsTable(maxSizeNames, maxSizeDescriptions, maxSizeDate, maxSizeStudents, maxSizeTeachers, maxSizeStatus);
	}
	else
	{
		clearScreen();
		cout << ERROR_MSG_CR << "There are 0 teams" << CLOSE_ERR_MSG << endl;
	}
}

void displayHeaderStudentsAndTeachersTable(int& maxSize, int& maxSizeNames, int& maxSizeSurnames, int& maxSizeObject, int& maxSizeEmail, string object)
{

	cout << char(201);
	for (int i = 0; i < maxSizeNames; i++)
	{
		//═
		//cout << u8R"(═)";
		cout << char(205);
	}
	//╦
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
		if (teachers[i].teams.size() > 0)
		{
			cout << char(186);
			for (size_t j = 0; j < teachers[i].teams.size(); j++)
			{

				cout << teachers[i].teams[j];
				if (j < teachers[i].teams.size() - 1)
				{
					cout << ", ";
				}
			}
		}
		else
		{
			cout << char(186);
			displayNSpaces(maxSizeClass);
		}
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
	if (students.size() > 0)
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
	else
	{
		clearScreen();
		cout << setw(50) << ERROR_MSG_CR << "There are 0 students" << CLOSE_ERR_MSG;
	}
}

void displayTeachersInTable(vector<TEACHER>& teachers)
{
	if (teachers.size() > 0)
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
					team += ", ";
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
	else
	{
		clearScreen();
		cout << "There are 0 teachers";
	}
}

void displayTeamsUpdateMenu()
{
	cout << "1. Change team status " << endl;
	cout << "2. Change team description" << endl;
	cout << "3. Change team name" << endl;
	cout << "4. Change teacher" << endl;
	cout << "5. Change student" << endl;
}

void statusMenu()
{
	cout << "0. In use" << endl;
	cout << "1. Not Active" << endl;
	cout << "2. Archived" << endl;
}

bool filteringMenu(bool who, vector<STUDENT>& students, vector<TEACHER>& teachers)
{
	vector<STUDENT> foundStudentsByCriteria;
	string criteria;
	int op;

	try {

		if (who) {
			cout << "\n 1. Search by class (10A, 10B, 10V and so on)" << endl;
			cout << "2. Search by student's firstname" << endl;
			cout << "3. Search by student's surname" << endl;
			cout << "9. <- Back" << endl;

			checkChoiceInput(op);


			switch (op)
			{
			case 1:
				cin >> criteria;
				foundStudentsByCriteria = findStudentsByClass(students, criteria);
				displayStudentsInTable(foundStudentsByCriteria);
				foundStudentsByCriteria.clear();
				break;
			case 2:
				cin >> criteria;
				foundStudentsByCriteria = findStudentsByName(students, criteria);
				displayStudentsInTable(foundStudentsByCriteria);
				foundStudentsByCriteria.clear();
				break;
			case 3:
				cin >> criteria;
				foundStudentsByCriteria = findStudentsBySurname(students, criteria);
				displayStudentsInTable(foundStudentsByCriteria);
				foundStudentsByCriteria.clear();
			case 9:
				return false;
			default:
				break;
			}
			return true;
		}
		else {
			cout << "1. Search by teacher's firstname" << endl;
			cout << "2. Search by teacher's surname" << endl;
			cout << "3. Search teachers who have no teams assigned" << endl;
			cout << "9. <- Back" << endl;

			checkChoiceInput(op);
			switch (op)
			{
			case 1:
				cin >> criteria;
				foundStudentsByCriteria = findStudentsByClass(students, criteria);
				displayStudentsInTable(foundStudentsByCriteria);
				foundStudentsByCriteria.clear();
				break;
			case 2:
				cin >> criteria;
				foundStudentsByCriteria = findStudentsByName(students, criteria);
				displayStudentsInTable(foundStudentsByCriteria);
				foundStudentsByCriteria.clear();
				break;
			case 3:
				cin >> criteria;
				foundStudentsByCriteria = findStudentsBySurname(students, criteria);
				displayStudentsInTable(foundStudentsByCriteria);
				foundStudentsByCriteria.clear();
				break;
			case 9:
				return false;
			default:
				break;
			}
			return true;
		}
	}
	catch (const std::exception& ex)
	{
		cout << EXCEPTION_MSG_CR << ex.what() << CLOSE_EXC_MSG << endl;
	}
}

void handleUpdateTeamInfo(int option, vector<TEAM>& teams, vector<TEACHER>& teachers, vector<STUDENT>& students, int& teamID)
{
	STUDENT student;
	TEACHER teacher;
	string temporary;
	int status;

	switch (option)
	{
	case 1:
		statusMenu();
		cout << INFO_MSG_CR << "Set a new status: " << CLOSE_INFO_MSG;
		cin >> status;
		while (toStatus(status) == "Vania")
		{
			cout << ERROR_MSG_CR << "Invalid status, re-enter: " << CLOSE_ERR_MSG; cin >> status;
		}
		updateTeamStatus(teams[teamID], toStatus(status));
		break;
	case 2:
		cin.ignore();
		cout << INFO_MSG_CR << "Enter the new description: " << CLOSE_INFO_MSG;
		getline(cin, temporary);
		while (!checkTeamDescriptionLength(temporary))
		{
			cout << ERROR_MSG_CR << "Description length violates our criteria" << endl;
			cout << "Write shorter description: " << CLOSE_ERR_MSG;

			getline(cin, temporary);
		}
		updateTeamDescription(teams[teamID], temporary);
		break;
	case 3: {
		cin.ignore();
		cout << INFO_MSG_CR << "Enter the new name of the team: " << CLOSE_INFO_MSG;
		getline(cin, temporary);
		while (!checkTeamNameLength(temporary) or checkIfTeamNameIsUsed(teams, temporary))
		{
			cout << ERROR_MSG_CR << "That Team name is too long or there is already a team with that name" << endl;
			cout << "Re-Enter a shorter name: " << CLOSE_ERR_MSG;

			getline(cin, temporary);
		}

		string oldTeamName = teams[teamID].teamName;
		updateTeamName(teams[teamID], temporary);

		string teacherEmail = teams[teamID].teacher.email;
		int teacherId = findIndexOfTeacherByEmail(teachers, teacherEmail);
		//teachers[teacherId].teams
		for (size_t i = 0; i < teachers[teacherId].teams.size(); i++)
		{
			if (teachers[teacherId].teams[i] == oldTeamName)
			{
				teachers[teacherId].teams[i] = temporary;
				writeTeachersInTxt(teachers);
				break;
			}
		}

	}; break;
	case 4:
		teachersEmpty(teachers, students);

		cout << INFO_MSG_CR << "Enter the new teacher's email: " << CLOSE_INFO_MSG;
		cin >> temporary;
		teacher = findTeacherByEmail(teachers, temporary);

		updateTeamTeacher(teams[teamID], teacher);
		break;
	case 5:

		teachersEmpty(teachers, students);

		cout << INFO_MSG_CR << "Enter the new student's email: " << CLOSE_INFO_MSG;
		cin >> temporary;

		while (!checkEmailValidity(temporary))
		{
			cout << ERROR_MSG_CR << "Invalid, re-enter: " << CLOSE_ERR_MSG; cin >> temporary;
		}

		student = findStudentByEmail(students, temporary);
		temporary = "";

		cout << INFO_MSG_CR << "Enter the email of the student you want to replace: " << CLOSE_INFO_MSG;
		cin >> temporary;
		while (!checkEmailValidity(temporary))
		{
			cout << ERROR_MSG_CR << "Invalid, re-enter: " << CLOSE_ERR_MSG; cin >> temporary;
		}

		updateTeamStudent(teams[teamID], student, temporary);
		break;
		updateStudentData(students, teams);
		updateTeacherData(teachers, teams);
	default:
		break;
	}
}

bool menu(vector<STUDENT>& students, vector<TEACHER>& teachers, vector<string>& whiteListedRoles, vector<TEAM>& teams, string name, string city, string address, bool& inputSchoolInfo)
{
	vector<STUDENT> foundStudentsByCriteria;
	string criteria;
	system("chcp 65001");
	cout << endl << u8R"( 
    ████████╗███████╗ █████╗ ███╗   ███╗███████╗ ██████╗ ███╗   ██╗██████╗ ██╗   ██╗██████╗  ██████╗ ███████╗████████╗
    ╚══██╔══╝██╔════╝██╔══██╗████╗ ████║██╔════╝██╔═══██╗████╗  ██║██╔══██╗██║   ██║██╔══██╗██╔════╝ ██╔════╝╚══██╔══╝
       ██║   █████╗  ███████║██╔████╔██║███████╗██║   ██║██╔██╗ ██║██████╔╝██║   ██║██║  ██║██║  ███╗█████╗     ██║   
       ██║   ██╔══╝  ██╔══██║██║╚██╔╝██║╚════██║██║   ██║██║╚██╗██║██╔══██╗██║   ██║██║  ██║██║   ██║██╔══╝     ██║   
       ██║   ███████╗██║  ██║██║ ╚═╝ ██║███████║╚██████╔╝██║ ╚████║██████╔╝╚██████╔╝██████╔╝╚██████╔╝███████╗   ██║   
       ╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝╚═════╝  ╚═════╝ ╚═════╝  ╚═════╝ ╚══════╝   ╚═╝   
                                                                                                                  
        )";
	cout << endl;
	if (inputSchoolInfo)
	{
		cout << "Name of the school: ";
		getline(cin, name);
		cout << "City: ";
		getline(cin, city);
		cout << "Address: ";
		getline(cin, address);
		writeSchoolInTxt(name, city, address);
		inputSchoolInfo = 0;
	}
	/*cout << R"(				/-----------------------------------\
					Welcome to the Menu!
				(1) |Add a student|
				(2) |Add a teacher|
				(3) |Add a role|
				(4) |Add a team|
				(5) |List of the students|
				(6) |List of the teachers|
				(7) |List of the teams|
				(8) |Delete a student|
				(9) |Delete a teacher|
				(10) |Delete a team|
				(11) |Update student's information|
				(12) |Update teacher's information|
				(18) | Visualize reports on criteria|
				\\-----------------------------------/)" << endl;*/

	cout << endl;
	cout << setw(60) << "/-----------------------------------\\" << endl;
	cout << "				Welcome to the Menu!" << endl;
	cout << "				(1) |Add a student|" << endl;
	cout << "				(2) |Add a teacher|" << endl;
	cout << "				(3) |Add a role|" << endl;
	cout << "				(4) |Add a team|" << endl;
	cout << "				(5) |List of the students|" << endl;
	cout << "				(6) |List of the teachers|" << endl;
	cout << "				(7) |List of the teams|" << endl;
	cout << "				(8) |Delete a student|" << endl;
	cout << "				(9) |Delete a teacher|" << endl;
	cout << "				(10) |Delete a team|" << endl;
	cout << "				(11) |Update student's information|" << endl;
	cout << "				(12) |Update teacher's information|" << endl;
	cout << "				(18) | Visualize reports on criteria|" << endl;
	cout << setw(60) << "\-----------------------------------/)" << endl;

	/*cout << u8R"(

			╔═══════════════════════════════════════╗
			║										║
			║  (1) |Add a student|			║
			║  (2) |Add a teacher|			║
			║  (3) |Add a role|				║
			║  (4) |Add a team|				║
			║  (5) |List of the students|	║
			║  (6) |List of the teachers|	║
			║  (7) |List of the teams|		║
			║  (8) |Delete a student|		║
			║  (9) |Delete a teacher|				║
			║  (10) |Delete a team|					║
			║  (11) |Update student's information|  ║
			║  (12) |Update teacher's information|  ║
			║  (18) | Visualize reports on criteria|║
			║										║
			║										║
			║										║
			╚═══════════════════════════════════════╝
		)";*/
	system("chcp 437");
	int option;
	int filter;
	bool filt = true;
	cout << setw(50) << "->: ";
	checkChoiceInput(option);

	try {
		switch (option)
		{
		case 1:
			cin.ignore();
			students.push_back(inputStudent(students, teachers));
			writeStudentsInTxt(students);
			break;

		case 2:
			cin.ignore();
			teachers.push_back(inputTeacher(students, teachers));
			writeTeachersInTxt(teachers);
			break;

		case 3:
			cin.ignore();
			addRole(whiteListedRoles);
			writeRolesInTxt(whiteListedRoles);
			break;
		case 4:
			teams.push_back(inputTeam(whiteListedRoles, students, teachers, teams));
			writeTeamsInTxt(teams);
			break;
		case 5:
			clearScreen();
			displayStudentsInTable(students);
			break;
		case 6:
			clearScreen();
			displayTeachersInTable(teachers);
			break;
		case 7: displayTeamsInTable(teams, whiteListedRoles);
			break;
		case 8: clearScreen(); deleteStudentData(students, teams); break;
		case 9: clearScreen(); deleteTeacherData(teachers, teams); break;
		case 10: clearScreen(); deleteTeamsData(teams);  break;
		case 11: clearScreen(); updateStudentData(students, teams); break;
		case 12: 
			clearScreen(); updateTeacherData(teachers, teams);
			// Doesn't update
			//writeTeamsInTxt(teams);
			break;
			/*case 14:
				try
				{
					cin >> criteria;
					foundStudentsByCriteria = findStudentsByClass(students, criteria);
					displayStudentsInTable(foundStudentsByCriteria);
					foundStudentsByCriteria.clear();
				}
				catch (const std::exception& ex)
				{
					cout << EXCEPTION_MSG_CR << ex.what() << CLOSE_EXC_MSG << endl;
				}
				break;
			case 15:
				try
				{
					cin >> criteria;
					foundStudentsByCriteria = findStudentsByName(students, criteria);
					displayStudentsInTable(foundStudentsByCriteria);
					foundStudentsByCriteria.clear();

				}
				catch (const std::exception& ex)
				{
					cout << EXCEPTION_MSG_CR << ex.what() << CLOSE_EXC_MSG << endl;
				}
				break;
			case 16:
				try
				{
					cin >> criteria;
					foundStudentsByCriteria = findStudentsBySurname(students, criteria);
					displayStudentsInTable(foundStudentsByCriteria);
					foundStudentsByCriteria.clear();

				}
				catch (const std::exception& ex)
				{
					cout << EXCEPTION_MSG_CR << ex.what() << CLOSE_EXC_MSG << endl;
				}
				break;*/
		case 17:
			updateTeamsData(teams, teachers, students);
			break;
		case 18:
			cout << "1. Filter students" << endl;
			cout << "2. Filter students" << endl;
			checkChoiceInput(filter);
			do {
				switch (filter)
				{
				case 1: filt = filteringMenu(1, students, teachers); break;
				case 2: filt = filteringMenu(0, students, teachers); break;
				default:
					break;
				}
			} while (filt);
			break;
		case 19:
			return false;
		default:
			cout << endl;
			cout << ERROR_MSG_CR << "|--------------------------|" << endl;
			cout << "Incorrect option, try again!" << endl;
			cout << "|--------------------------|" << CLOSE_ERR_MSG << endl;
		}
	}
	catch (const std::exception ex)
	{
		cout << EXCEPTION_MSG_CR << ex.what() << CLOSE_EXC_MSG << endl;
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