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
	SCHOOL school;



	logger.open("logs.txt");
	logger.writeLogMsg(SEVERITY::INFO, "Program was executed successfully");
	vector<string> whiteListedRoles;
	whiteListedRoles = readRolesFromTxt();
	//vector<STUDENT> students;
	school.students = readStudentsFromTxt();
	//vector<TEACHER> teachers;
	school.teachers = readTeachersFromTxt();
	//vector<TEAM> teams;
	school.teams = readTeamsFromTxt();



	while (true)menu(school.students, school.teachers, whiteListedRoles, school.teams);

	logger.writeLogMsg(SEVERITY::INFO, "Program was terminated successfully");

	//LOGS::putLogMsg(SEVERITY::CRITICAL, "Ako ne rabotish.......");

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