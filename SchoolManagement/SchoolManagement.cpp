#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "structures.h"
#include "functions.h"
#include "data.h"
#include "userInterface.h"
using namespace std;

int main()
{
	vector<string> whiteListedRoles;
	whiteListedRoles = readRolesFromTxt();
	vector<STUDENT> students;
	vector<TEACHER> teachers;
	vector<TEAM> teams;

	string adminEmail = "1";
	string adminPass = "2";

	system("chcp 65001");
	mainMenu(adminEmail, adminPass, students, teachers, whiteListedRoles, teams);

	/*
	
	Tuka

	students.push_back(inputStudent(students,teachers));
	students.push_back(inputStudent(students,teachers));
	cout << '\n';
	teachers.push_back(inputTeacher(students,teachers));

	cout << "Create a team: " << endl;

	teams.push_back(inputTeam(whiteListedRoles, students, teachers));
	writeRolesInTxt(whiteListedRoles);
	writeStudentsInTxt(students);
	writeTeachersInTxt(teachers);
	writeTeamsInTxt(teams);
	*/
	/*
	ofstream file;

	file.open("students.txt", ios::app);


	vector<STUDENT> students;
	students.push_back({ "Stoyan", "Kolev", "10A", "SNKolev18@codingburgas.bg" });
	students.push_back({ "Jekata", "Velikov", "10A", "DMKalchev18@codingburgas.bg" });
	students.push_back({ "Ili qm", "Ili ne", "10A", "ILIQM18@codingburgas.bg" });
	students.push_back({ "Life", "Georgiev", "Turkey", "GKGeorgiev@codingburgas.bg" });


	if (file.is_open())
	{
		for (size_t i = 0; i < 4; i++)
		{
			file << students[i].delimitInfo();
			file << endl;
		}
		file.close();
	}
	*/
}