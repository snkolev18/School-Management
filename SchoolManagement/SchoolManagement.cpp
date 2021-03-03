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
	LOGS logs;
	if (logs.open("logs.log")) {
		vector<string> whiteListedRoles;
		whiteListedRoles = readRolesFromTxt();
		vector<STUDENT> students;
		students = readStudentsFromTxt();
		vector<TEACHER> teachers;
		teachers = readTeachersFromTxt();
		vector<TEAM> teams;
		teams = readTeamsFromTxt();

		menu(students, teachers, whiteListedRoles, teams);
		//logs.writeLogMsg(SEVERITY::INFO, "CHUPENDRA");
		LOGS::putLogMsg(SEVERITY::CRITICAL, "Ako ne rabotish.......");
	}

	vector<LOGS> audits = logs.readLogs();

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