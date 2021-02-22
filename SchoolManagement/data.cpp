#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "structures.h"
#include "checkers.h"

using namespace std;

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

int findIndexByEmailTeachers(vector<TEACHER>& teachers, string email)
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
int findIndexByEmailStudents(vector<STUDENT>& students, string email)
{
	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i].email == email)
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

STUDENT inputStudent(vector<STUDENT> students, vector<TEACHER> teachers)
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

	try
	{
		while (!checkGrade(student.grade))
		{
			cout << "This is cringe grade" << endl;
			cout << "Please enter a valid one: ";
			getline(cin, student.grade);
		}

	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}

	cout << endl;
	cout << "Email: ";
	getline(cin, student.email);
	while (checkForExistingEmail(students, teachers, student.email) or !checkEmailValidity(student.email))
	{
		cout << "This email is already registered or it's not valid " << endl;
		cout << "Please enter new email: ";
		getline(cin, student.email);
	}
	return student;
}

TEACHER inputTeacher(vector<STUDENT> students, vector<TEACHER> teachers)
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
	while (checkForExistingEmail(students, teachers, teacher.email) or !checkEmailValidity(teacher.email))
	{
		cout << "This email is already registered or it's not valid" << endl;
		cout << "Please enter new email: ";
		getline(cin, teacher.email);
	}
	return teacher;
}

TEAM inputTeam(vector<string>& whiteListedRoles, vector<STUDENT>& students, vector<TEACHER>& teachers)
{
	TEAM team;
	STUDENT student;
	string email;
	ROLE role;
	cout << "Team name: ";
	getline(cin, team.teamName);
	for (size_t i = 0; i < whiteListedRoles.size(); i++)
	{
		cout << whiteListedRoles[i] << ":" << endl;
		cout << "Enter the email of the student: ";
		getline(cin, email);
		while (!checkForExistingEmailStudents(students, email) or !checkEmailValidity(email))
		{
			cout << "There is no student with this email or it's incorrectly inputted" << endl;
			cout << "Please enter an email of a student: ";
			getline(cin, email);
		}
		role.student = findStudentByEmail(students, email);
		role.role = whiteListedRoles[i];
		team.roles.push_back(role);
	}
	cout << "Enter the email of the consultant (teacher) of your team: ";
	getline(cin, email);
	while (!checkForExistingEmailTeachers(teachers, email) or !checkEmailValidity(email))
	{
		cout << "There is no teacher with this email or it's incorrectly inputted" << endl;
		cout << "Please enter an email of a teacher: ";
		getline(cin, email);
	}
	team.teacher = findTeacherByEmail(teachers, email);
	team.status = "In use";
	cout << "Write the description of the team: ";
	getline(cin, team.description);
	teachers[findIndexByEmailTeachers(teachers, email)].teams.push_back(team.teamName);
	team.teacher.teams.push_back(team.teamName);
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
	ofstream file;
	file.open("students.txt", ios::trunc);
	if (file.is_open())
	{
		for (size_t i = 0; i < students.size(); i++)
		{
			file << students[i].delimitInfo() << endl;
		}
		file.close();
	}
}

void writeTeachersInTxt(vector<TEACHER> teachers)
{
	ofstream file;
	file.open("teachers.txt", ios::trunc);
	if (file.is_open())
	{
		for (size_t i = 0; i < teachers.size(); i++)
		{
			file << teachers[i].delimitInfo() << endl;
		}
		file.close();
	}
}

void writeTeamsInTxt(vector<TEAM> teams)
{
	ofstream file;
	file.open("teams.txt", ios::trunc);
	if (file.is_open())
	{
		for (size_t i = 0; i < teams.size(); i++)
		{
			file << teams[i].delimitInfo() << endl;
		}
		file.close();
	}
}

STUDENT parsedStudentInfo(string info)
{
	STUDENT studentInfo;

	studentInfo.name = info.substr(0, info.find('|'));
	info.erase(0, info.find('|') + 1);
	studentInfo.surname = info.substr(0, info.find('|'));
	info.erase(0, info.find('|') + 1);
	studentInfo.grade = info.substr(0, info.find('|'));
	info.erase(0, info.find('|') + 1);
	studentInfo.email = info.substr(0, info.find('|'));
	info.erase(0, info.find('|') + 1);
	return studentInfo;
}

vector<STUDENT> readStudentsFromTxt()
{
	vector<STUDENT> students;
	ifstream file;
	string info;
	file.open("students.txt");
	if (file.is_open())
	{
		while (getline(file, info))
		{
			students.push_back(parsedStudentInfo(info));
		}
	}
	return students;
}

TEACHER parsedTeacherInfo(string info)
{
	TEACHER teacherInfo;

	teacherInfo.name = info.substr(0, info.find('|'));
	info.erase(0, info.find('|') + 1);
	teacherInfo.surname = info.substr(0, info.find('|'));
	info.erase(0, info.find('|') + 1);
	teacherInfo.email = info.substr(0, info.find('|'));
	info.erase(0, info.find('|') + 1);
	while (info.find(';') != string::npos)
	{
		teacherInfo.teams.push_back(info.substr(0, info.find(';')));
		info.erase(0, info.find(';') + 1);
	}
	return teacherInfo;
}

TEAM parsedTeamInfo(string info)
{
	TEAM teamInfo;
	ROLE roles;
	teamInfo.teamName = info.substr(0, info.find('|'));
	info.erase(0, info.find('|') + 1);
	while (info.find(',') != string::npos)
	{
		roles.role = info.substr(0, info.find(':'));
		info.erase(0, info.find(':') + 1);
		roles.student = parsedStudentInfo(info.substr(0, info.find(',')));
		info.erase(0, info.find(',') + 1);
		teamInfo.roles.push_back(roles);
	}
	teamInfo.teacher = parsedTeacherInfo(info.substr(0, info.find(";|") + 1));
	info.erase(0, info.find(";|") + 2);
	teamInfo.dateCreation = info.substr(0, info.find('|'));
	info.erase(0, info.find('|') + 1);
	teamInfo.status = info.substr(0, info.find('|'));
	info.erase(0, info.find('|') + 1);
	teamInfo.description = info.substr(0, info.find('|'));
	info.erase(0, info.find('|') + 1);
	return teamInfo;
}

vector<TEAM> readTeamsFromTxt()
{
	vector<TEAM> teams;
	ifstream file;
	string info;
	file.open("teams.txt");
	if (file.is_open())
	{
		while (getline(file, info))
		{
			teams.push_back(parsedTeamInfo(info));
		}
	}
	return teams;
}

vector<TEACHER> readTeachersFromTxt()
{
	vector<TEACHER> teachers;
	ifstream file;
	string info;
	file.open("teachers.txt");
	if (file.is_open())
	{
		while (getline(file, info))
		{
			teachers.push_back(parsedTeacherInfo(info));
		}
	}
	return teachers;
}

vector<string> readRolesFromTxt()
{
	vector<string> roles;
	string info;
	ifstream file("roles.txt");
	if (file.is_open())
	{
		while (getline(file, info))
		{
			roles.push_back(info);
		}
		file.close();
	}
	return roles;
}

void removeStudentFromTeam(vector<ROLE>& students,string email)
{
	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i].student.email == email)
		{
			students.erase(students.begin() + i);
			break;
		}
	}
}
void addStudentToTeam(vector<ROLE>& students, ROLE student)
{
	students.push_back(student);
}
void removeRole(vector<string>& roles, int id)
{
	roles.erase(roles.begin() + id);
}
