#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#define _POSIX_THREAD_SAFE_FUNCTIONS
#include <time.h>
#include <ctime>
#include <stdio.h>
#include "structures.h"
#include "checkers.h"

using namespace std;

string TEAM::statusToString(STATUS stat)
{
	switch (stat)
	{
	case IN_USE:
		return "In use";
	case NOT_ACTIVE:
		return "Not active";
	case ARCHIVED:
		return "Archived";
	default:
		return "Unknown Status";
	}
}

void writeRolesInTxt(vector<string>& whiteListedRoles)
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
		logger.writeLogMsg(SEVERITY::INFO, "Roles were successfully written into roles.txt");
	}
}

void writeStudentsInTxt(vector<STUDENT>& students)
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
		logger.writeLogMsg(SEVERITY::INFO, "Students were successfully written into students.txt");
	}
}

void writeTeachersInTxt(vector<TEACHER>& teachers)
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
		logger.writeLogMsg(SEVERITY::INFO, "Teachers were successfully written into teachers.txt");
	}
}

void writeTeamsInTxt(vector<TEAM>& teams)
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
		logger.writeLogMsg(SEVERITY::INFO, "Teams were successfully written into teams.txt");
	}
}

STUDENT findStudentByEmail(vector<STUDENT>& students, string& email)
{

	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i].email == email)
		{
			return students[i];
		}
	}
}

TEACHER findTeacherByEmail(vector<TEACHER>& teachers, string& email)
{
	for (size_t i = 0; i < teachers.size(); i++)
	{
		if (teachers[i].email == email)
		{
			return teachers[i];
		}
	}
}

int findTeamByName(const vector<TEAM>& teams, const string name)
{
	for (size_t i = 0; i < teams.size(); i++)
	{
		if (teams.at(i).teamName == name)
		{
			return i;
		}
	}
}

int findIndexByEmailTeachers(vector<TEACHER>& teachers, string& email)
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

int findIndexByEmailStudents(vector<STUDENT>& students, string& email)
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

STUDENT inputStudent(vector<STUDENT>& students, vector<TEACHER>& teachers)
{
	STUDENT student;
	cout << "First name: ";
	getline(cin, student.name);
	while (!checkNameValidity(student.name))
	{
		cout << "That Student name is too long and doesnt't match our criteria" << endl;
		cout << "Re-Enter a the name: ";

		getline(cin, student.name);
	}
	cout << endl;
	cout << "Surname: ";
	getline(cin, student.surname);
	while (!checkNameValidity(student.surname))
	{
		cout << "That Student name is too long and doesnt't match our criteria" << endl;
		cout << "Re-Enter a the name: ";

		getline(cin, student.surname);
	}
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
	logger.writeLogMsg(SEVERITY::INFO, "Option X: Student was successfully added");
	return student;
}

TEACHER inputTeacher(vector<STUDENT>& students, vector<TEACHER>& teachers)
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
	logger.writeLogMsg(SEVERITY::INFO, "Option X: Teacher was successfully added");
	return teacher;
}

string getDate()
{
	int day, month, year, hour, minute, second;
	string days, months, years, hours, minutes, seconds;

	time_t timer = time(NULL);
	tm timerPtr{ 0 };
	char* err = asctime(localtime(&timer));

	if (err == NULL)
	{
		return "Couldn't convert time";
	}

	timerPtr = *localtime(&timer);


	day = timerPtr.tm_mday;
	month = timerPtr.tm_mon + 1;
	year = timerPtr.tm_year + 1900;
	hour = timerPtr.tm_hour;
	minute = timerPtr.tm_min;
	second = timerPtr.tm_sec;

	seconds = to_string(second);
	minutes = to_string(minute);
	hours = to_string(hour);
	days = to_string(day);
	months = to_string(month);
	if (months.length() < 2)
	{
		months = "0" + months;
	}
	if (days.length() < 2)
	{
		days = "0" + days;
	}
	if (hours.length() < 2)
	{
		hours = "0" + hours;
	}
	if (minutes.length() < 2)
	{
		minutes = "0" + minutes;
	}
	if (seconds.length() < 2)
	{
		seconds = "0" + seconds;
	}

	years = to_string(year);

	return years + '/' + months + '/' + days + " " + hours + ":" + minutes + ":" + seconds;

	//return "chicho ivo sadsa sad as as";

}

TEAM inputTeam(vector<string>& whiteListedRoles, vector<STUDENT>& students, vector<TEACHER>& teachers, vector<TEAM>& teams)
{
	TEAM team;
	STUDENT student;
	string email;
	ROLE role;

	if (students.empty()) {
		throw std::runtime_error("There are no students to add in a team");
	} else if (teachers.empty()) {
		throw std::runtime_error("There are no teachers to add in a team");
	}


	cin.ignore();
	cout << "Team name: ";
	getline(cin, team.teamName);
	while (!checkTeamNameLength(team.teamName) or checkIfTeamNameIsUsed(teams, team.teamName))
	{
		cout << "That Team name is too long or there is already a team with that name" << endl;
		cout << "Re-Enter a shorter name: ";

		getline(cin, team.teamName);
	}

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
	team.status = TEAM::statusToString(TEAM::IN_USE);

	cout << "Write the description of the team: ";
	getline(cin, team.description);
	while (!checkTeamDescriptionLength(team.description))
	{
		cout << "Description length violates our criteria" << endl;
		cout << "Write shorter description: ";

		getline(cin, team.description);
	}

	teachers[findIndexByEmailTeachers(teachers, email)].teams.push_back(team.teamName);
	team.dateCreation = getDate();
	team.teacher.teams.push_back(team.teamName);
	writeTeachersInTxt(teachers);
	logger.writeLogMsg(SEVERITY::INFO, "Option X: Team was successfully added");
	return team;
}

void addRole(vector<string>& whiteListedRoles)
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

	whiteListedRoles.push_back(role);
}

void removeRole(vector<string>& roles, int& id)
{
	roles.erase(roles.begin() + id);
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

TEACHER parsedTeacherInfo(string info)
{
	TEACHER teacherInfo;

	teacherInfo.name = info.substr(0, info.find('|'));
	info.erase(0, info.find('|') + 1);
	teacherInfo.surname = info.substr(0, info.find('|'));
	info.erase(0, info.find('|') + 1);

	while (info.find('=') != string::npos)
	{
		teacherInfo.teams.push_back(info.substr(0, info.find('=')));
		info.erase(0, info.find('=') + 1);
	}

	teacherInfo.email = info.substr(0, info.find('|'));
	info.erase(0, info.find('|') + 1);
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

void removeStudentFromTeam(vector<ROLE>& students, string& email)
{
	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i].student.email == email)
		{
			students[i].student = {};
			break;
		}
	}
}

void addStudentToTeam(vector<ROLE>& students, ROLE& student)
{
	students.push_back(student);
}

int maxSizeOfStrings(vector<string>& strings)
{
	int max = 0;

	for (size_t i = 0; i < strings.size(); i++)
	{
		if (strings[i].size() > max)
		{
			max = strings[i].size();
		}
	}

	return max;
}

void removeStudent(vector<STUDENT>& students, string email)
{
	for (size_t i = 0; i < students.size(); i++)
	{
		if (email == students[i].email)
		{
			students.erase(students.begin() + i);
		}
	}
}

void removeTeam(vector<TEAM>& teams, const string teamName)
{
	for (size_t i = 0; i < teams.size(); i++)
	{
		if (teamName == teams[i].teamName)
		{
			teams.erase(teams.begin() + i);
		}
	}
}

void removeTeacher(vector<TEACHER>& teachers, string email)
{
	for (size_t i = 0; i < teachers.size(); i++)
	{
		if (email == teachers[i].email)
		{
			teachers.erase(teachers.begin() + i);
		}
	}
}

void updateStudentData(vector<STUDENT>& students)
{
	ifstream file;
	file.open("students.txt", ios::in | ios::binary);
	file.seekg(0, ios::end);
	std::streamoff size = file.tellg();

	if (size == 0 or students.empty()) {
		//LOG::putLogMsg(SEVERITY::WARNING, "Exception thrown: Tried to update contents of a file that has no data");
		logger.writeLogMsg(SEVERITY::WARNING, "Option X clicked and Exception was thrown: Tried to update contents of a file that has no data");
		throw std::runtime_error("File with students has no data!");
	}
	else {
		string email;

		cin.ignore();
		cout << "Enter the email of the student that you want to edit: ";
		getline(cin, email);
		while (!checkForExistingEmailStudents(students, email) or !checkEmailValidity(email))
		{
			cout << ERROR_MSG_CR << "This email is not valid " << endl;
			cout << "Please try again: " << CLOSE_ERR_MSG;
			getline(cin, email);
		}

		int id = 0;

		for (size_t i = 0; i < students.size(); i++)
		{
			if (students[i].email == email)
			{
				id = i;
				break;
			}
		}

		cin >> students.at(id).name;
		while (!checkNameValidity(students.at(id).name))
		{
			cout << ERROR_MSG_CR << "Name is incorrect" << endl;
			cout << "Re-Enter a correct name: " << CLOSE_ERR_MSG;
			cin >> students.at(id).name;
		}

		cin >> students.at(id).surname;
		while (!checkNameValidity(students.at(id).surname))
		{
			cout << ERROR_MSG_CR << "Surname is incorrect" << endl;
			cout << "Re-Enter a correct surname: " << CLOSE_ERR_MSG;
			cin >> students.at(id).surname;
		}

		cin >> students.at(id).grade;
		try
		{
			while (!checkGrade(students.at(id).grade))
			{
				cout << ERROR_MSG_CR << "This is cringe grade" << endl;
				cout << "Please enter a valid one: " << CLOSE_ERR_MSG;
				cin >> students.at(id).grade;
			}

		}
		catch (const std::exception& ex)
		{
			cout << ex.what();
		}

		cin.ignore();
		cout << INFO_MSG_CR << "Enter new email of a student: " << CLOSE_INFO_MSG;
		getline(cin, students.at(id).email);
		while (!checkForExistingEmailStudents(students, students.at(id).email) or !checkEmailValidity(students.at(id).email))
		{
			cout << ERROR_MSG_CR << "This email is not valid " << endl;
			cout << "Please try again: " << CLOSE_ERR_MSG;
			getline(cin, students.at(id).email);
		}

		writeStudentsInTxt(students);
		logger.writeLogMsg(SEVERITY::INFO, "Student was successfully UPDATED");
	}
	//LOG::putLogMsg(SEVERITY::INFO, "Student was successfully updated");
}

void updateTeacherData(vector<TEACHER>& teachers)
{
	ifstream file;
	file.open("teachers.txt", ios::in | ios::binary);
	file.seekg(0, ios::end);
	std::streamoff size = file.tellg();

	if (size == 0 or teachers.empty()) {
		//LOG::putLogMsg(SEVERITY::WARNING, "Exception thrown: Tried to update contents of a file that has no data");
		logger.writeLogMsg(SEVERITY::WARNING, "Option X clicked and Exception was thrown: Tried to update contents of a file that has no data");
		throw std::runtime_error("File with teachers has no data for update!");
	}
	else {
		string email;

		cin.ignore();
		cout << INFO_MSG_CR << "Enter the email of the teacher that you want to edit: " << CLOSE_INFO_MSG;
		getline(cin, email);
		while (!checkForExistingEmailTeachers(teachers, email) or !checkEmailValidity(email))
		{
			cout << ERROR_MSG_CR << "This email is not valid " << endl;
			cout << "Please try again: " << CLOSE_ERR_MSG;
			getline(cin, email);
		}

		int id = 0;

		for (size_t i = 0; i < teachers.size(); i++)
		{
			if (teachers[i].email == email)
			{
				id = i;
				break;
			}
		}

		cout << endl;
		cout << INFO_MSG_CR << "Enter new first NAME of a teacher with email [ " 
			 << RESET_COLOR << email << CLOSE_RESET_COLOR
			 << INFO_MSG_CR << " ]" << " :" << CLOSE_INFO_MSG;

		getline(cin, teachers.at(id).name);
		while (!checkNameValidity(teachers.at(id).name))
		{
			cout << ERROR_MSG_CR << "Name is incorrect" << endl;
			cout << "Re-Enter a correct name: " << CLOSE_ERR_MSG;
			cin >> teachers.at(id).name;
		}

		cout << "Enter new first SURNAME of a teacher with email [ " << email << " ]" << " :";
		getline(cin, teachers.at(id).name);
		while (!checkNameValidity(teachers.at(id).surname))
		{
			cout << ERROR_MSG_CR << "Surname is incorrect" << endl;
			cout << "Re-Enter a correct surname: " << CLOSE_ERR_MSG;
			getline(cin, teachers.at(id).name);
		}


		cin.ignore();
		cout << INFO_MSG_CR << "Enter new email of a teacher: " << CLOSE_INFO_MSG;
		getline(cin, teachers.at(id).email);
		while (!checkForExistingEmailTeachers(teachers, teachers.at(id).email) or !checkEmailValidity(teachers.at(id).email))
		{
			cout << ERROR_MSG_CR << "This email is not valid " << endl;
			cout << "Please try again: " << CLOSE_ERR_MSG;
			getline(cin, teachers.at(id).email);
		}

		writeTeachersInTxt(teachers);
		logger.writeLogMsg(SEVERITY::INFO, "Teacher was successfully UPDATED");
	}
	//LOG::putLogMsg(SEVERITY::INFO, "Student was successfully updated");
}

void deleteStudentData(vector<STUDENT>& students)
{
	ifstream file;
	file.open("students.txt", ios::in | ios::binary);
	file.seekg(0, ios::end);
	std::streamoff size = file.tellg();

	if (size == 0 or students.empty()) {
		//LOG::putLogMsg(SEVERITY::CRITICAL, "Exception thrown: Tried to delete contents of a file that has no data");
		logger.writeLogMsg(SEVERITY::CRITICAL, "Exception thrown: Tried to delete contents of a file that has no data");
		throw std::runtime_error("File with students has no data to delete!");
	}
	else {
		string email;

		cin.ignore();
		cout << INFO_MSG_CR << "Enter email of the student that you want to be delete: " << CLOSE_INFO_MSG;

		getline(cin, email);
		while (!checkForExistingEmailStudents(students, email) or !checkEmailValidity(email))
		{
			cout << ERROR_MSG_CR << "There is no student with this email or it's incorrectly inputted" << endl;
			cout << "Please enter an email of a student: " << CLOSE_ERR_MSG;
			getline(cin, email);
		}
		removeStudent(students, email);
		writeStudentsInTxt(students);
		logger.writeLogMsg(SEVERITY::INFO, "Student was successfully DELETED");
	}
}

void deleteTeacherData(vector<TEACHER>& teachers)
{
	ifstream file;
	file.open("teachers.txt", ios::in | ios::binary);
	file.seekg(0, ios::end);
	std::streamoff size = file.tellg();

	if (size == 0 or teachers.empty()) {
		//LOG::putLogMsg(SEVERITY::CRITICAL, "Exception thrown: Tried to delete contents of a file that has no data");
		logger.writeLogMsg(SEVERITY::CRITICAL, "Exception thrown: Tried to delete contents of a file that has no data");
		throw std::runtime_error("File with teachers has no data to delete!");
	}
	else {

		string email;

		cin.ignore();
		cout << INFO_MSG_CR << "Enter email of the teacher that you want to be delete: " << CLOSE_INFO_MSG;
		getline(cin, email);
		while (!checkForExistingEmailTeachers(teachers, email) or !checkEmailValidity(email))
		{
			cout << ERROR_MSG_CR << "There is no teachers with this email or it's incorrectly inputted" << endl;
			cout << "Please enter an email of a teacher: " << CLOSE_ERR_MSG;
			getline(cin, email);
		}
		removeTeacher(teachers, email);
		writeTeachersInTxt(teachers);
	}

}

void deleteTeamsData(vector<TEAM>& teams)
{
	ifstream file;
	file.open("teams.txt", ios::in | ios::binary);
	file.seekg(0, ios::end);
	std::streamoff size = file.tellg();

	if (size == 0 or teams.empty()) {
		//LOG::putLogMsg(SEVERITY::CRITICAL, "Exception thrown: Tried to delete contents of a file that has no data");
		logger.writeLogMsg(SEVERITY::CRITICAL, "Exception thrown: Tried to delete contents of a file that has no data");
		throw std::runtime_error("File with teams has no data to delete!");
	}
	else {


		string name;

		cin.ignore();
		cout << INFO_MSG_CR << "Enter the name of the team that you want to be deleted: " << CLOSE_INFO_MSG;
		getline(cin, name);

		int teamID = findTeamByName(teams, name);

		if (teams.at(teamID).status == TEAM::statusToString(TEAM::IN_USE))
		{
			while (!checkIfTeamNameIsUsed(teams, name))
			{
				cout << ERROR_MSG_CR << "This team name is invalid or doesn't exist " << CLOSE_ERR_MSG << endl;
				cout << ERROR_MSG_CR << "Please enter a correct name of a team: " << CLOSE_ERR_MSG;
				getline(cin, name);
			}
			removeTeam(teams, name);
			writeTeamsInTxt(teams);
		}
		else 
		{
			logger.writeLogMsg(SEVERITY::WARNING, "Exception thrown: Tried to delete contents of a team which status is set to IN_USE");
			throw std::runtime_error("Tried to delete a team that is currently being used. STATUS => In Use");
		}

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
void updateTeamStatus(TEAM& team, string& status)
{
	team.status = status;
}
void updateTeamDescription(TEAM& team, string& description)
{
	team.description = description;
}
void updateTeamName(TEAM& team, string& name)
{
	team.teamName = name;
}
void updateTeamTeacher(TEAM& team, TEACHER& teacher)
{
	team.teacher = teacher;
}
void updateTeamStudent(TEAM& team, STUDENT& student, string& studentForReplacement)
{
	for (size_t i = 0; i < team.roles.size(); i++)
	{
		if (team.roles[i].student.email == studentForReplacement)
		{
			team.roles[i].student = student;
		}
	}
}
void updateTeamsData(vector<TEAM>& teams,vector<TEACHER>& teachers,vector<STUDENT>& students)
{
	ifstream file;
	string temporary;
	TEACHER teacher;
	STUDENT student;
	file.open("teams.txt", ios::in | ios::binary);
	file.seekg(0, ios::end);
	std::streamoff size = file.tellg();
	int option;
	if (size == 0 or teams.empty()) {
		//LOG::putLogMsg(SEVERITY::WARNING, "Exception thrown: Tried to update contents of a file that has no data");
		logger.writeLogMsg(SEVERITY::WARNING, "Option X clicked and Exception was thrown: Tried to update contents of a file that has no data");
		throw std::runtime_error("File with teams has no data!");
	}
	else {
		string name;

		cin.ignore();
		cout << INFO_MSG_CR << "Enter the name of the team that you want to edit: " << CLOSE_INFO_MSG;
		getline(cin, name);
		int teamID = findTeamByName(teams, name);

		if (teams.at(teamID).status == TEAM::statusToString(TEAM::IN_USE))
		{
			while (!checkIfTeamNameIsUsed(teams, name))
			{
				cout << ERROR_MSG_CR << "This team name is invalid or doesn't exist " << endl;
				cout << "Please enter a correct name of a team: " << CLOSE_ERR_MSG;
				getline(cin, name);
			}
			displayTeamsUpdateMenu();
			cin >> option;
			switch (option)
			{
			case 1:
				cout << "Enter the new status: ";
				cin >> temporary;
				updateTeamStatus(teams[teamID], temporary);
				break;
			case 2:
				cout << "Enter the new description: ";
				cin >> temporary;
				updateTeamDescription(teams[teamID], temporary);
				break;
			case 3:
				cout << "Enter the new name of the team: ";
				cin >> temporary;
				updateTeamName(teams[teamID], temporary);
				break;
			case 4:
				cout << "Enter the new teacher's email: ";
				cin >> temporary;
				teacher = findTeacherByEmail(teachers, temporary);
				updateTeamTeacher(teams[teamID], teacher);
				break;
			case 5:
				cout << "Enter the new student's email: ";
				cin >> temporary;
				student=findStudentByEmail(students, temporary);
				cout << "Enter the email of the student you want to replace: ";
				cin >> temporary;
				updateTeamStudent(teams[teamID], student, temporary);
				break;
			default:
				break;
			}
			writeTeamsInTxt(teams);
			/*cout << INFO_MSG_CR << "Update the name of the team: " << CLOSE_INFO_MSG;
			getline(cin, teams.at(teamID).teamName);
			while (!checkTeamNameLength(teams.at(teamID).teamName))
			{
				cout << ERROR_MSG_CR << "That Team name is too long and invalid" << endl;
				cout << "Re-Enter a shorter name: " << CLOSE_ERR_MSG;

				getline(cin, teams.at(teamID).teamName);
			}

			cin.ignore();
			cout << INFO_MSG_CR <<"Put a new teacher to consult this team: " << CLOSE_INFO_MSG;
			getline(cin, teams.at(teamID).teacher.email);*/
			/*while (!checkForExistingEmailTeachers(teachers, email) or !checkEmailValidity(email))
			{
				cout << "There is no teacher with this email or it's incorrectly inputted" << endl;
				cout << "Please enter an email of a teacher: ";

				getline(cin, email);
			}*/

		}
	}
	
}

vector<STUDENT> findStudentsByClass(const vector<STUDENT>& students, const string& grade)
{
	if (students.empty()) 
	{
		throw runtime_error("No students to search for and filter!!!");
	}

	vector<STUDENT> foundStudents;
	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i].grade == grade)
		{
			foundStudents.push_back(students[i]);
		}
	}

	return foundStudents;
}

vector<STUDENT> findStudentsByName(const vector<STUDENT>& students, const string& name)
{
	if (students.empty())
	{
		throw runtime_error("No students to search for or filter!!!");
	}

	vector<STUDENT> foundStudents;
	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i].name == name)
		{
			foundStudents.push_back(students[i]);
		}
	}

	return foundStudents;
}

vector<STUDENT> findStudentsBySurname(const vector<STUDENT>& students, const string& surname)
{
	if (students.empty())
	{
		throw runtime_error("No students to search for or filter!!!");
	}

	vector<STUDENT> foundStudents;
	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i].surname == surname)
		{
			foundStudents.push_back(students[i]);
		}
	}

	return foundStudents;
}

vector<TEACHER> findTeachersByName(const vector<TEACHER>& teachers, const string& name)
{
	if (teachers.empty())
	{
		throw runtime_error("No teachers to search for or filter!!!");
	}

	vector<TEACHER> foundTeachers;
	for (size_t i = 0; i < teachers.size(); i++)
	{
		if (teachers[i].name == name)
		{
			foundTeachers.push_back(teachers[i]);
		}
	}

	return foundTeachers;
}

vector<TEACHER> findTeachersBySurname(const vector<TEACHER>& teachers, const string& surname)
{
	if (teachers.empty())
	{
		throw runtime_error("No teachers to search for or filter!!!");
	}

	vector<TEACHER> foundTeachers;
	for (size_t i = 0; i < teachers.size(); i++)
	{
		if (teachers[i].surname == surname)
		{
			foundTeachers.push_back(teachers[i]);
		}
	}

	return foundTeachers;
}

vector<TEACHER> findTeachersByNoTeams(const vector<TEACHER>& teachers)
{
	if (teachers.empty())
	{
		throw runtime_error("No teachers to search for or filter!!!");
	}

	vector<TEACHER> foundTeachers;
	for (size_t i = 0; i < teachers.size(); i++)
	{
		if (teachers[i].teams.empty())
		{
			foundTeachers.push_back(teachers[i]);
		}
	}

	return foundTeachers;
}

vector<TEAM> findTeamsByTeacher(const vector<TEAM>& teams, const string& name)
{
	if (teams.empty())
	{
		throw runtime_error("No teams to search for or filter!!!");
	}

	vector<TEAM> foundTeams;
	for (size_t i = 0; i < teams.size(); i++)
	{
		if (teams[i].teacher.name==name)
		{
			foundTeams.push_back(teams[i]);
		}
	}

	return foundTeams;
}

vector<TEAM> findTeamsByStatus(const vector<TEAM>& teams, const string& status)
{
	if (teams.empty())
	{
		throw runtime_error("No teams to search for or filter!!!");
	}

	vector<TEAM> foundTeams;
	for (size_t i = 0; i < teams.size(); i++)
	{
		if (teams[i].status == status)
		{
			foundTeams.push_back(teams[i]);
		}
	}

	return foundTeams;
}