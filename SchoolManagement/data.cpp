#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "structures.h"

using namespace std;

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

bool checkForExistingEmail(vector<STUDENT> students, vector<TEACHER> teachers, string email)
{
	if (checkForExistingEmailTeachers(teachers, email) or checkForExistingEmailStudents(students, email))
	{
		return true;
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

STUDENT inputStudent(vector<STUDENT> students,vector<TEACHER> teachers)
{
	STUDENT student;
	cout << "First name: ";
	getline(cin, student.name);
	cout << endl;
	cout << "Surname: ";
	getline(cin, student.surname);
	cout << endl;
	cout << "Class: ";
	getline(cin, student.grade);
	cout << endl;
	cout << "Email: ";
	getline(cin, student.email);
	while (checkForExistingEmail(students,teachers,student.email))
	{
		cout << "This email is already registered " << endl;
		cout << "Please enter new email: ";
		getline(cin, student.email);
	}
	return student;
}

TEACHER inputTeacher()
{
	TEACHER teacher;
	cout << "First name: ";
	getline(cin, teacher.name);
	cout << endl;
	cout << "Surname: ";
	getline(cin, teacher.surname);
	cout << endl;
	cout << "Email: ";
	getline(cin, teacher.email);
	return teacher;
}

CUSTOM_TEAM inputTeam(vector<string> whiteListedRoles, vector<STUDENT> students, vector<TEACHER>& teachers)
{
	CUSTOM_TEAM team;
	string email;
	string roleName;
	ROLES role;
	cout << "Team name: ";
	cin.ignore();
	getline(cin, team.teamName);
	for (size_t i=0;i<whiteListedRoles.size();i++)
	{
		cout << whiteListedRoles[i] << ":" << endl;
		cout << "Enter the email of the student: ";
		cin.ignore();
		getline(cin, email);
		while (!checkForExistingEmailStudents(students, email))
		{
			cout << "There is no student with this email" << endl;
			cout << "Please enter an email of a student: ";
			getline(cin, email);
		}
		team.students.push_back(findStudentByEmail(students, email));
		role.role = roleName;
		role.student = email;
		team.roles.push_back(role);
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

string addRole(vector<string> whiteListedRoles)
{
	string role;
	cout << "Enter a name for the role: ";
	getline(cin, role);
	while (checkIfRoleIsWhiteListed(whiteListedRoles, role))
	{
		cout << "This role is already existing" << endl;
		cout << "Please enter a new name for the role: ";
		getline(cin, role);
	}
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

void writeStudentsInTxt(vector<STUDENT> students)
{

}

void writeTeachersInTxt()
{

}
void writeTeamsInTxt()
{

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
