#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "structures.h"

using namespace std;

STUDENT inputStudent()
{
	STUDENT student;
	cout << "First name: ";
	cin >> student.name;
	cout << endl;
	cout << "Surname: ";
	cin >> student.surname;
	cout << endl;
	cout << "Class: ";
	cin >> student.grade;
	cout << endl;
	cout << "Email: ";
	cin >> student.email;
	return student;
}

TEACHER inputTeacher()
{
	TEACHER teacher;
	cout << "First name: ";
	cin >> teacher.name;
	cout << endl;
	cout << "Surname: ";
	cin >> teacher.surname;
	cout << endl;
	cout << "Email: ";
	cin >> teacher.email;
	return teacher;
}

bool checkForExistingEmailStudents(vector<STUDENT> students, string email)
{
	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i].email == email)
		{
			return true;
		}
	}
	return false;
}

bool checkForExistingEmailTeachers(vector<TEACHER> teachers, string email)
{
	for (size_t i = 0; i < teachers.size(); i++)
	{
		if (teachers[i].email == email)
		{
			return true;
		}
	}
	return false;
}

bool checkIfRoleIsWhiteListed(vector<string> whiteListedRoles, string role)
{
	for (size_t i = 0; i < whiteListedRoles.size(); i++)
	{
		if (whiteListedRoles[i] == role)
		{
			return true;
		}
	}
	return false;
}

STUDENT findStudentByEmail(vector<STUDENT> students, string email)
{

	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i].email == email)
		{
			return students[i];
		}
	}
}

int findIndexByEmailTeachers(vector<TEACHER> teachers, string email)
{
	for (size_t i = 0; i < teachers.size(); i++)
	{
		if (teachers[i].email == email)
		{
			return i;
		}
	}
	return -3; //Unique value if email not found
}

TEACHER findTeacherByEmail(vector<TEACHER> teachers, string email)
{
	for (size_t i = 0; i < teachers.size(); i++)
	{
		if (teachers[i].email == email)
		{
			return teachers[i];
		}
	}
}

CUSTOM_TEAM inputTeam(vector<string> whiteListedRoles, vector<STUDENT> students, vector<TEACHER>& teachers)
{
	CUSTOM_TEAM team;
	int nPeople;
	string email;
	string role;
	cout << "Team name: ";
	cin >> team.teamName;
	cout << "How many people are in this team: ";
	cin >> nPeople;
	for (int i = 0; i < nPeople; i++)
	{
		cout << "Enter the role of the student: ";
		cin >> role;
		//team.roles[i].role.push_back(role);
		while (!checkIfRoleIsWhiteListed(whiteListedRoles, team.roles[i].role))
		{
			cout << "This role does not exist" << endl;
			//Here should be printed all available roles
			cout << "Please enter role that exists: ";
			cin >> team.roles[i].role;
		}
		cout << "Enter the email of the student: ";
		cin >> email;
		while (!checkForExistingEmailStudents(students, email))
		{
			cout << "There is no student with this email" << endl;
			cout << "Please enter an email of a student: ";
			cin >> email;
		}
		team.students.push_back(findStudentByEmail(students, email));
		team.roles[i].student = email;
	}
	cout << "Enter the email of the consultant (teacher) of your team: ";
	cin >> email;
	while (!checkForExistingEmailTeachers(teachers, email))
	{
		cout << "There is no teacher with this email" << endl;
		cout << "Please enter an email of a teacher: ";
		cin >> email;
	}
	team.teacher = findTeacherByEmail(teachers, email);
	team.status = "In use";
	teachers[findIndexByEmailTeachers(teachers, email)].teams.push_back(team.teamName);
	return team;
}

string addRole()
{
	string role;
	cout << "Enter a name for the role: ";
	cin >> role;
	return role;
}

void writeRolesInTxt(vector<string> whiteListedRoles)
{
	ofstream file;
	file.open("roles.txt", ios::trunc);
	if (file.is_open())
	{
		for (size_t i = 0; i < whiteListedRoles.size(); i++)
		{
			file << whiteListedRoles[i] << endl;
		}
		file.close();
	}
}

vector<string> readRolesFromTxt()
{
	vector<string> roles;
	string line;
	ifstream file("roles.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			roles.push_back(line);
		}
		file.close();
	}
	return roles;
}

void removeRole(vector<string>& roles, int id)
{
	roles.erase(roles.begin() + id);
}
